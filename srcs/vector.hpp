#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <algorithm>
# include <memory>
# include <cstddef>
# include <tgmath.h>
# include <iostream>
# include "Utility/random_access_iterator.hpp"
# include "Utility/iterator_traits.hpp"
# include "Utility/reverse_iterator.hpp"
# include "Utility/utility.hpp"

namespace ft {
    template<
            typename T,
            class Allocator = std::allocator<T>
    >
    class vector {
    public:
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef typename allocator_type::size_type size_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer;
        typedef typename ft::random_access_iterator<value_type> iterator;
        typedef typename ft::random_access_iterator<const value_type> const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

        // Member functions
        vector() {
            _sz = 0;
            _cap = 0;
            _alloc = Allocator();
            _arr = nullptr;
        }

        explicit vector(const Allocator &alloc) {
            _alloc = Allocator(alloc);
            _cap = 0;
            _sz = 0;
            _arr = nullptr;
        }

        explicit vector(size_type count,
                        const T &value = T(),
                        const Allocator &alloc = Allocator()) {

            if (count < 0)
                throw std::bad_alloc();
            else {
                _sz = count;
                _cap = count;
                _alloc = alloc;
                if (count == 0)
                    _arr = nullptr;
                _arr = _alloc.allocate(count);
                for (size_type i = 0; i < count; i++) {
                    _alloc.construct(_arr + i, value);
                }
            }
        }

        template<class InputIt>
        vector(InputIt first, InputIt last,
               const Allocator &alloc = Allocator()) {
            _sz = last - first;
            _cap = _sz;
            _alloc = alloc;
            _arr = _alloc.allocate(_cap);
            value_type *tmpData = _arr;

            for (InputIt it = first; it != last; ++tmpData, ++it)
                _alloc.construct(tmpData, it);
        }

        vector(const vector &other) {
            _sz = other._sz;
            _cap = other._cap;
            _alloc = other._alloc;
            _arr = _alloc.allocate(_cap);

            for (size_type i = 0; i < _sz; ++i)
                _alloc.construct(_arr + i, other[i]);
        }

        ~vector() {
            while (_sz > 0) {
                _sz--;
                _alloc.destroy(_arr + _sz);
            }
            _alloc.deallocate(_arr, _cap);
        }

        vector &operator=(const vector &other) {
            if (&other != this) {
                _sz = other._sz;
                _alloc.deallocate(_arr, _cap);
                _cap = other._cap;
                _arr = _alloc.allocate(_cap);

                for (size_type i = 0; i < _sz; i++) {
                    _alloc.construct(_arr + i, other[i]);
                }
            }
            return *this;
        }

        void assign(size_type count, const T &value) {
            clear();
            if (_cap < count) {
                if (_cap < count) {
                    if (_cap * 2 >= count)
                        reserve(_cap * 2);
                    else
                        reserve(count);
                }
                for (; _sz < count; ++_sz)
                    _alloc.construct(_arr + _sz, value);
            }
        }

        template<class InputIt>
        void assign(InputIt first, InputIt last) {
            clear();
            size_type distance = last - first;

            if (_cap < distance) {
                if (_cap * 2 >= distance)
                    reserve(_cap * 2);
                else
                    reserve(distance);
            }
            for (; first < last; ++_sz, ++first)
                _alloc.construct(_arr + _sz, first);
        }

        allocator_type get_allocator() const {
            return _alloc;
        }

        // Element access
        reference at(size_type pos) {
            if (pos >= _sz)
                throw std::out_of_range("Out of range");
            return _arr[pos];
        }

        const_reference at(size_type pos) const {
            if (pos >= _sz)
                throw std::out_of_range("Out of range");
            return _arr[pos];;
        }

        reference operator[](size_type pos) {
            return _arr[pos];
        }

        const_reference operator[](size_type pos) const {
            return _arr[pos];
        }

        reference front() {
            return _arr[0];
        }

        const_reference front() const {
            return _arr[0];
        }

        reference back() {
            return _arr[_sz - 1];
        }

        const_reference back() const {
            return _arr[_sz - 1];
        }

        T *data() {
            return _arr;
        }

        const T *data() const {
            return _arr;
        }

        //Iterators

        iterator begin() {
            return &_arr[0];
        }

        const_iterator begin() const {
            return &_arr[0];
        }

        iterator end() {
            return &_arr[_sz];
        }

        const_iterator end() const {
            return &_arr[_sz];
        }

        reverse_iterator rbegin() {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const {
            return reverse_iterator(end());
        }

        reverse_iterator rend() {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const {
            return reverse_iterator(begin());
        }

        //Capacity

        bool empty() const {
            return !_sz;
        }

        size_type size() const {
            return _sz;
        }

        size_type max_size() const {
            return std::numeric_limits<size_t>::max();
        }

        void reserve(size_type new_cap) {
            if (new_cap > _cap && new_cap < max_size()) {
                pointer tmp = _alloc.allocate(new_cap);
                try {
                    std::uninitialized_copy(_arr, _arr + _sz, tmp);
                }
                catch (...) {
                    _alloc.deallocate(tmp, new_cap);
                    throw;
                }
                _alloc.deallocate(_arr, _cap);
                _arr = tmp;
                _cap = new_cap;
            }
        }

        size_type capacity() const {
            return _cap;
        }

        //Modyfiers

        void clear() {
            erase(begin(), end());
        }

        iterator insert(iterator pos, const T &value) {
            size_type dist = pos - begin();
            if (_sz < _cap) {
                for (iterator it = end(); it != pos - 1; --it) {
                    _alloc.construct(&(*pos), value);
                }
                _alloc.construct(&(*pos), value);
                ++_sz;
            } else {
                value_type *tmp_data = _alloc.allocate(_cap ? _cap *= 2 : 1);
                size_type i = 0;
                for (iterator it = begin(); it != end(); ++it) {
                    if (it == pos) {
                        _alloc.construct(tmp_data + i, value);
                        ++i;
                    }
                    _alloc.construct(tmp_data + i, *it);
                    _alloc.destroy(&(*it));
                    ++i;
                }
                _alloc.deallocate(_arr, _cap);
                _arr = tmp_data;
                ++_sz;
            }
            return begin() + dist;
        }

        void insert(iterator pos, size_type count, const T &value) {
            if (_sz + count > _cap) {
                if (_sz + count >= _cap * 2)
                    _cap = _sz + count;
                else
                    _cap *= 2;
            }
            value_type *tmp_data = _alloc.allocate(_cap);
            value_type *p = tmp_data;
            for (int i = 0; begin() + i < pos; ++i) {
                _alloc.construct(tmp_data, *(begin() + i));
                ++tmp_data;
                _alloc.destroy(&(*(begin() + i)));
            }
            for (size_type i = 0; i < count; ++i) {
                _alloc.construct(tmp_data, value);
                ++tmp_data;
            }
            for (int i = 0; pos + i < end(); ++i) {
                _alloc.construct(tmp_data, *(pos + i));
                ++tmp_data;
                _alloc.destroy(&(*(pos * i)));
            }
            _alloc.deallocate(&(*begin()), _sz);
            _arr = p;
            _sz += count;
        }

        template<class InputIt>
        void insert(iterator pos,
                    InputIt first,
                    InputIt Last,
                    typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0) {
            size_type n = static_cast<size_type>(ft::distance(begin(), pos));
            size_type distance = static_cast<size_type>(ft::distance(begin(), pos));
            if (pos > end() || pos < begin())
                throw std::range_error("Index Error");
            value_type *tmp_data = _alloc.allocate(n);
            try {
                for (size_type i = 0; i < n; ++i)
                    _alloc.destroy(tmp_data + i, first++);
            }
            catch (...) {
                for (size_type i = 0; tmp_data + i != 0 && i < n; ++i)
                    _alloc.destroy(tmp_data + i);
                _alloc.deallocate(tmp_data, n);
                throw std::runtime_error("Error");
            }
            if (_cap == _sz && _cap)
                reserve(_cap * 2);
            if (_cap < _sz + n)
                reserve(_sz + n);
            for (size_type i = 0; _sz - i != distance; ++i) {
                _alloc.construct(_arr + _sz - 1 - i + n, _arr[_sz - i + 1]);
                _alloc.destroy(_arr + _sz - i - 1);
            }
            for (size_type i = 0; i < n; ++i) {
                _alloc.construct(_arr + distance + i, tmp_data[i]);
                _alloc.destroy(tmp_data + i);
                ++_sz;
            }
            _alloc.deallocate(tmp_data, n);
        }

        iterator erase(iterator pos) {
            if (pos + 1 == end())
                _alloc.destroy(&(*pos));
            else {
                for (int i = 0; pos + i + 1 < end(); ++i) {
                    _alloc.construct(&(*(pos + i)), *(pos + i + 1));
                    _alloc.destroy(&(*(pos + i + 1)));
                }
                _sz -= 1;
                return pos;
            }
        }

        iterator erase(iterator first, iterator last) {
            iterator tmp = first;
            size_type distance = ft::distance(first, last);

            for (; first < end() - distance; ++first) {
                _alloc.destroy(&(*first));
                _alloc.construct(&(*first), *(first + distance));
                _alloc.destroy(&(*(first + distance)));
            }
            _sz -= distance;
            return tmp;
        }

        void push_back(const T &value) {
            if (_cap == _sz)
                reserve(2 * _sz);
            _alloc.construct(_arr + _sz, value);
            ++_sz;
        }

        void pop_back() {
            --_sz;
            _alloc.destroy(_arr + _sz);
        }

        void resize(size_type count) {
            if (count > _cap) {
                reserve(count);
            }
            for (int i = 0; i < count; i++) {
                this->_alloc.construct(_arr + i);
            }
        }

        void resize(size_type count, T value = T()) {
            if (count < _sz) {
                for (; _sz > count; --_sz)
                    _alloc.destroy(&_arr[_sz]);
            } else if (count > _sz && count < max_size()) {
                if (count > _cap && count <= _cap * 2)
                    reserve(_cap * 2);
                else if (count > _cap * 2)
                    reserve(count);
                for (; _sz < count; ++_sz)
                    _alloc.construct(&_arr[_sz], value);
            }
        }

        void swap(vector &other) {
            ft::swap(_arr, other._arr);
            ft::swap(_cap, other._cap);
            ft::swap(_sz, other._sz);
        }

    private:
        value_type *_arr;
        size_type _sz;
        size_type _cap;
        Allocator _alloc;
    };

    template<typename T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs,
                    const vector<T, Alloc> &rhs) {
        const typename vector<T, Alloc>::size_type sz = lhs.size();
        return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template<typename T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs,
                    const vector<T, Alloc> &rhs) {
        return !(lhs == rhs);
    }

    template<typename T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs,
                   const vector<T, Alloc> &rhs) {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template<typename T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs,
                   const vector<T, Alloc> &rhs) {
        return rhs < lhs;
    }

    template<typename T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs,
                    const vector<T, Alloc> &rhs) {
        return !(lhs > rhs);
    }

    template<typename T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs,
                    const vector<T, Alloc> &rhs) {
        return !(lhs < rhs);
    }

    template<class T, class Allocator>
    void swap(ft::vector<T, Allocator> &lhs,
              ft::vector<T, Allocator> &rhs) {
        lhs.swap(rhs);
    }
}

#endif // VECTOR_HPP

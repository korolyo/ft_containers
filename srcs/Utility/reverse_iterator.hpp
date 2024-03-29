#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "utility.hpp"
# include "iterator_traits.hpp"
# include "is_integral.hpp"

namespace ft {

    template<class Iterator>
    class reverse_iterator {
    public:
        typedef Iterator iterator_type;
        typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
        typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
        typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
        typedef typename ft::iterator_traits<iterator_type>::reference reference;

        reverse_iterator() {}

        explicit reverse_iterator(iterator_type it) : _position(it) {}

        reverse_iterator(const reverse_iterator &it) : _position(it.base()) {}

        ~reverse_iterator() {}

        iterator_type base() const {
            return _position;
        }

        reference operator*() const {
            iterator_type tmp = _position;
            return *(--tmp);
        }

        reverse_iterator operator+(difference_type n) const {
            return reverse_iterator(_position - n);
        }

        reverse_iterator &operator++() {
            _position--;
            return *this;
        }

        reverse_iterator operator++(int) {
            reverse_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        reverse_iterator &operator+=(difference_type n) {
            _position -= n;
            return *this;
        }

        reverse_iterator &operator--() {
            _position++;
            return *this;
        }

        reverse_iterator &operator-=(difference_type n) {
            _position += n;
            return *this;
        }

        reverse_iterator operator-(difference_type n) const {
            return reverse_iterator(_position + n);
        }

        reverse_iterator operator--(int) {
            reverse_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        pointer operator->() const {
            return &(operator*());
        }

        reference operator[](difference_type n) const {
            return *(operator-(n));
        }

    private:
        Iterator _position;
    };

    template<class Iterator>
    bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return lhs.base() == rhs.base();
    }

    template<class Iterator>
    bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return lhs.base() != rhs.base();
    }

    template<class Iterator>
    bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return lhs.base() > rhs.base();
    }

    template<class Iterator>
    bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return lhs.base() >= rhs.base();
    }

    template<class Iterator>
    bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return lhs.base() < rhs.base();
    }

    template<class Iterator>
    bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return lhs.base() <= rhs.base();
    }

    template<class Iterator>
    reverse_iterator<Iterator>
    operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it) {
        return rev_it + n;
    }

    template<class Iterator>
    typename reverse_iterator<Iterator>::difference_type
    operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
        return lhs.base() - rhs.base();
    }
}

#endif // REVERSE_ITERATOR_HPP

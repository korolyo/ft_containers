#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include "Utility/Random_access_iterator.hpp"
#include "Utility/Iterator_traits.hpp"
#include "Utility/Reverse_iterator.hpp"
#include "Utility/Utility.hpp"

namespace ft
{
	template<
			typename T,
			class Allocator = std::allocator<T>
	>
	class Vector
	{
		typedef T														value_type;
		typedef Allocator												allocator_type;
		typedef size_t 													size_type;
		typedef value_type&												reference;
		typedef const value_type&										const_reference;
		typedef typename Allocator::pointer								pointer;
		typedef typename Allocator::const_pointer						const_pointer;
		typedef typename ft::Random_access_iterator<pointer>		    iterator;
		typedef typename ft::Random_access_iterator<const_pointer>		const_iterator;
		typedef typename ft::Reverse_iterator<iterator>					reverse_iterator;
		typedef typename ft::Reverse_iterator<const_iterator>			const_reverse_iterator;

	private:
		value_type	*_arr;
		size_type	_sz;
		size_type	_cap;
		Allocator	_alloc;

	public:
		// Member functions
		Vector() {
			_sz = 0;
			_cap = 0;
			_alloc = Allocator();
		}

		explicit Vector( const Allocator& alloc ) {
			this->_alloc = Allocator( alloc );
			_cap = 0;
			_sz = 0;
		}

		explicit Vector( size_type count,
						 const T& value = T(),
						 const Allocator& alloc = Allocator() ) {
			_sz = count;
			this->_alloc = alloc;
		}

		template< class InputIt >
		Vector( InputIt first, InputIt last,
				const Allocator& alloc = Allocator() ) {
			this->_sz = last - first;
			this->_alloc = alloc;
		}

		~Vector() {
			while (_sz > 0)
			{
                _sz--;
                _alloc.destroy(_arr + _sz);
			}
			_alloc.deallocate(_arr, _cap);
		}

		Vector( const Vector& other ) {
			int i = 0;

			while (i < other->_sz) {
				this->_arr[i] = other->_arr[i];
			}
		}

		Vector& operator=( const Vector& other ) {
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

		void assign( size_type count, const T& value ) {
			;
		}

		template< class InputIt >
		void assign( InputIt first, InputIt last ) {
			;
		}

		allocator_type get_allocator() const {
			return this->_alloc;
		}

		// Element access

		reference at( size_type pos ) {
			if (pos >= _sz)
				throw std::out_of_range("Out of range");
			return _arr[pos];
		}

		const_reference at( size_type pos ) const {
			if (pos >= _sz)
				throw std::out_of_range("Out of range");
			return _arr[pos];;
		}

		reference operator[]( size_type pos ) {
			return _arr[pos];
		}

		const_reference operator[]( size_type pos ) const {
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

		T* data() {
			return _arr;
		}

		const T* data() const {
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
			return _sz;
		}

		size_type size() const {
			return this->_sz;
		}

		size_type max_size() const {
			return std::numeric_limits<size_t>::max();
		}

		void reserve( size_type new_cap ) {
			if (new_cap <= _cap) {
				return ;
			}

			T* newarr = _alloc.allocate(new_cap);

			for (size_t i = 0; i < sz; i++) {
                _alloc.construct( newarr + i, _arr[i]);
			}
		}

		size_type capacity() const {
			return this->_cap;
		}

		//Modyfiers

		void clear() {
			erase(begin(), end());
		}

		iterator insert( iterator pos, const T& value ) {
			if (pos > this->_cap)
                reserve(pos);
            ft::Random_access_iterator<T>
            return iterator;
		}

		void insert( iterator pos, size_type count, const T& value ) {
			;
		}

		template< class InputIt >
		void insert( iterator pos,
					 InputIt first,
					 InputIt Last) {
			;
		}

		iterator erase( iterator pos ) {
			;
		}

		iterator erase( iterator first, iterator last ) {
			;
		}

		void push_back(const T& value) {
			if (_cap == _sz)
				reserve(2 * _sz);
            _alloc.construct(_arr + _sz, value);
			++_sz;
		}

		void pop_back() {
			--_sz;
            _alloc.destroy(_arr + _sz);
		}

		void resize( size_type count ) {
			if (count > _cap) {
				reserve(count);
			}
			for (int i = 0; i < count; i++) {
				this->_alloc.construct(_arr + i);
			}
		}

		void resize( size_type count, T value = T() ) {
			if (count > _cap) {
				reserve(count);
			}
			for (int i = 0; i < count; i++) {
				_alloc.construct(_arr + i);
			}
			if (count < _sz) {
				_sz = count;
			}
		}

		void swap( Vector &other ) {
			T* tmparr = this->_arr;
			this->_arr = other->_arr;
			other->_arr = tmparr;
		}
	};

	template<typename T, class Alloc>
	bool operator==(const Vector<T, Alloc>& lhs,
					const Vector<T, Alloc>& rhs) {
		const typename Vector<T, Alloc>::size_type sz = lhs.size();
		return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template<typename T, class Alloc>
	bool operator!=(const Vector<T, Alloc>& lhs,
					const Vector<T, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template<typename T, class Alloc>
	bool operator<(const Vector<T, Alloc>& lhs,
				   const Vector<T, Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<typename T, class Alloc>
	bool operator>(const Vector<T, Alloc>& lhs,
				   const Vector<T, Alloc>& rhs) {
		return rhs < lhs;
	}

	template<typename T, class Alloc>
	bool operator<=(const Vector<T, Alloc>& lhs,
					const Vector<T, Alloc>& rhs) {
		return !(lhs > rhs);
	}

	template<typename T, class Alloc>
	bool operator>=(const Vector<T, Alloc>& lhs,
					const Vector<T, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template<class T, class Allocator>
	void swap( ft::Vector<T,Allocator>& lhs,
			   ft::Vector<T,Allocator>& rhs ) {
		lhs.swap(rhs);
	}
}

#endif

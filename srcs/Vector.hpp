#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include "Random_access_iterator.hpp"
#include "Iterator_traits.hpp"
#include "Reverse_iterator.hpp"

namespace ft
{
	template<
			typename T,
			class Allocator = std::allocator<T>
	>
	class Vector
	{
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef size_t 											size_type;
		typedef value_type&										reference;
		typedef const value_type&								const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;
		typedef typename ft::Random_access_iterator<T>		    iterator;
		typedef typename ft::Random_access_iterator<T>		    const_iterator;
		typedef typename ft::Reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::Reverse_iterator<const_iterator>	const_reverse_iterator;

	private:
		value_type	*arr;
		size_type	sz;
		size_type	cap;
		Allocator	alloc;

	public:
		// Member functions
		Vector() {
			sz = 0;
			cap = 0;
			alloc = Allocator();
		}

		explicit Vector( const Allocator& alloc ) {
			this->alloc = Allocator( alloc );
			cap = 0;
			sz = 0;
		}

		explicit Vector( size_type count,
						 const T& value = T(),
						 const Allocator& alloc = Allocator() ) {
			sz = count;
			this->alloc = alloc;
		}

		template< class InputIt >
		Vector( InputIt first, InputIt last,
				const Allocator& alloc = Allocator() ) {
			this->sz = last - first;
			this->alloc = alloc;
		}

		~Vector() {
			while (sz > 0)
			{
                sz--;
                alloc.destroy(arr + sz);
			}
			alloc.deallocate(arr, cap);
		}

		Vector( const Vector& other ) {
			int i = 0;

			while (i < other->sz) {
				this->arr[i] = other->arr[i];
			}
		}

		Vector& operator=( const Vector& other ) {
			;
		}

		void assign( size_type count, const T& value ) {
			;
		}

		template< class InputIt >
		void assign( InputIt first, InputIt last ) {
			;
		}

		allocator_type get_allocator() const {
			return this->alloc;
		}

		// Element access

		reference at( size_type pos ) {
			if (pos >= sz)
				throw std::out_of_range("Out of range");
			return arr[pos];
		}

		const_reference at( size_type pos ) const {
			if (pos >= sz)
				throw std::out_of_range("Out of range");
			return arr[pos];;
		}

		reference operator[]( size_type pos ) {
			return arr[pos];
		}

		const_reference operator[]( size_type pos ) const {
			return arr[pos];
		}

		reference front() {
			return arr[0];
		}

		const_reference front() const {
			return arr[0];
		}

		reference back() {
			return arr[sz - 1];
		}

		const_reference back() const {
			return arr[sz - 1];
		}

		T* data() {
			return arr;
		}

		const T* data() const {
			return arr;
		}

		//Iterators

//		iterator begin() {
//			;
//		}
//
//		const_iterator begin() const {
//			;
//		}
//
//		iterator end() {
//			;
//		}
//
//		const_iterator end() const {
//			;
//		}
//
//		reverse_iterator rbegin() {
//			;
//		}
//
//		const_reverse_iterator rbegin() const {
//			;
//		}
//
//		reverse_iterator rend() {
//			;
//		}
//
//		const_reverse_iterator rend() const {
//			;
//		}

		//Capacity

		bool empty() const {
			return sz;
		}

		size_type size() const {
			return this->sz;
		}

		size_type max_size() const {
			return std::numeric_limits<size_t>::max();
		}

		void reserve( size_type new_cap ) {
			if (new_cap <= cap) {
				return ;
			}

			T* newarr = alloc.allocate(new_cap);

			for (size_t i = 0; i < sz; i++) {
                alloc.construct( newarr + i, arr[i]);
			}
		}

		size_type capacity() const {
			return this->cap;
		}

		//Modyfiers

		void clear() { //TODO: Check this!!
			for (; sz >= 0; --sz) {
                this->alloc.destroy(arr + sz);
			}
		}

		iterator insert( iterator pos, const T& value ) {
			;
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
			if (cap == sz)
				reserve(2 * sz);
            alloc.construct(arr + sz, value);
			++sz;
		}

		void pop_back() {
			--sz;
            alloc.destroy(arr + sz);
		}

		void resize( size_type count ) {
			if (count > cap) {
				reserve(count);
			}
			for (int i = 0; i < count; i++) {
				this->alloc.construct(arr + i);
			}
		}

		void resize( size_type count, T value = T() ) {
			if (count > cap) {
				reserve(count);
			}
			for (int i = 0; i < count; i++) {
				alloc.construct(arr + i);
			}
			if (count < sz) {
				sz = count;
			}
		}

		void swap( Vector &other ) {
			T* tmparr = this->arr;
			this->arr = other->arr;
			other->arr = tmparr;
		}

		template<class T, class Alloc>
		friend bool operator!=(const Vector<T,Allocator>& lhs,
						const Vector<T,Allocator>& rhs);

		template<class T, class Alloc>
		friend bool operator==(const Vector<T,Allocator>& lhs,
						const Vector<T,Allocator>& rhs);

		template<class T, class Alloc>
		friend bool operator<(const Vector<T,Allocator>& lhs,
					   const Vector<T,Allocator>& rhs);

		template<class T, class Alloc>
		friend bool operator<=(const Vector<T,Allocator>& lhs,
						const Vector<T,Allocator>& rhs);

		template<class T, class Alloc>
		friend bool operator>(const Vector<T,Allocator>& lhs,
					   const Vector<T,Allocator>& rhs);

		template<class T, class Alloc>
		friend bool operator>=(const Vector<T,Allocator>& lhs,
						const Vector<T,Allocator>& rhs);
	};

	template<typename T, class Alloc>
	bool operator!=(const Vector<T, Alloc>& lhs,
					const Vector<T, Alloc>& rhs) {

	}

	template<typename T, class Alloc>
	bool operator==(const Vector<T, Alloc>& lhs,
					const Vector<T, Alloc>& rhs) {

	}

	template<typename T, class Alloc>
	bool operator<(const Vector<T, Alloc>& lhs,
				   const Vector<T, Alloc>& rhs) {

	}

	template<typename T, class Alloc>
	bool operator<=(const Vector<T, Alloc>& lhs,
					const Vector<T, Alloc>& rhs) {

	}

	template<typename T, class Alloc>
	bool operator>(const Vector<T, Alloc>& lhs,
				   const Vector<T, Alloc>& rhs) {

	}

	template<typename T, class Alloc>
	bool operator>=(const Vector<T, Alloc>& lhs,
					const Vector<T, Alloc>& rhs) {

	}

	template<T, std::Allocator>
	void swap( ft::Vector<T,Allocator>& lhs,
			   ft::Vector<T,Allocator>& rhs ) {
		ft::Vector<T,Allocator> tmp;
		tmp = lhs;
		lhs.
		lhs = rhs;
		rhs = tmp;
	}
}

#endif

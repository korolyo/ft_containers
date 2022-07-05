#pragma once

#include <iostream>
#include <memory>

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
		typedef typename ft::random_access_iterator::			iterator;
		typedef typename ft::random_access_iterator				const_iterator;
		typedef typename Allocator::const_pointer				const_pointer;
		typedef typename ft::Reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::Reverse_iterator<const_iterator>	const_reverse_iterator;

	private:
		value_type	*arr;
		size_type	sz;
		size_type	cap; //количество выделенной памяти
		Allocator	alloc;

	public:
		// Member functions
		Vector() { }

		explicit Vector( const Allocator& alloc ) {
			;
		}

		explicit Vector( size_type count,
						 const T& value = T(),
						 const Allocator& alloc = Allocator()) {
			;
		}

		template< class InputIt >
		Vector( InputIt first, InputIt last,
				const Allocator& alloc = Allocator() ) {
			;
		}

		Vector( const Vector& other) {
			;
		}

		~Vector() {
			;
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
			if (i >= sz)
				throw std::out_of_range("Out of range");
			return arr[i];
		}

		const_reference at( size_type pos ) const {
			if (i >= sz)
				throw std::out_of_range("Out of range");
			return arr[i];;
		}

		reference operator[]( size_type i ) {
			return arr[i];
		}

		const_reference operator[]( size_type i ) const {
			return arr[i];
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
			;
		}

		const T* data() const {
			;
		}

		//Iterators

		iterator begin() {
			;
		}

		const_iterator begin() const {
			;
		}

		iterator end() {
			;
		}

		const_iterator end() const {
			;
		}

		reverse_iterator rbegin() {
			;
		}

		const_reverse_iterator rbegin() const {
			;
		}

		reverse_iterator rend() {
			;
		}

		const_reverse_iterator rend() const {
			;
		}

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
			;
		}

		size_type capacity() const {
			return this->cap;
		}

		//Modyfiers

		void clear() { //TODO: Check this!!
			for (; sz >= 0; --sz) {
				(arr + sz)->~T();
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
			new (arr + sz) T(value);
			++sz;
		}

		void pop_back() {
			--sz;
			(arr + sz)->~T();
		}

		void resize( size_type count ) {
			;
		}

		void resize( size_type count, T value = T() ) {
			;
		}

		void swap( Vector &other ) {
			;
		}

		template< T, Allocator >
		void swap( ft::Vector<T,Allocator>& lhs,
				   ft::Vector<T,Allocator>& rhs ) {
			;
		}

		template<T,Allocator>
		friend bool operator!=(const Vector<T,Allocator>& lhs,
						const Vector<T,Allocator>& rhs);

		template<T,Allocator>
		friend bool operator==(const Vector<T,Allocator>& lhs,
						const Vector<T,Allocator>& rhs);

		template<T,Allocator>
		friend bool operator<(const Vector<T,Allocator>& lhs,
					   const Vector<T,Allocator>& rhs);

		template<T,Allocator>
		friend bool operator<=(const Vector<T,Allocator>& lhs,
						const Vector<T,Allocator>& rhs);

		template<T,Allocator>
		friend bool operator>(const Vector<T,Allocator>& lhs,
					   const Vector<T,Allocator>& rhs);

		template<T,Allocator>
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
}
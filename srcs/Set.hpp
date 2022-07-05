#pragma once

#include <memory>

namespace ft {
	template<
			class Key,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<Key>
	> class Set {
		typedef Key												key_type;
		typedef Key												value_type;
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
	};
}
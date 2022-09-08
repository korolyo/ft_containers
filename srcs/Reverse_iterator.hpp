#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <memory>
#include "Iterator_traits.hpp"

namespace ft {

	template<typename Iter>
	struct Reverse_iterator {
        typedef Iter                                                    iterator_type;
        typedef typename ft::Iterator_traits<Iter>::value_type          value_type;
        typedef typename ft::Iterator_traits<Iter>::iterator_category   iterator_category;
        typedef typename ft::Iterator_traits<Iter>::difference_type     difference_type;
        typedef typename ft::Iterator_traits<Iter>::pointer             pointer;
        typedef typename ft::Iterator_traits<Iter>::reference           reference;

		Iter current;
	public:
        Reverse_iterator();

        template< class U >
        Reverse_iterator& operator=( const Reverse_iterator<U>& other );

        iterator_type base() const {
            return current;
        }

        reference operator*() const {
            Iter tmp = current;
            return *--tmp;
        }

        pointer operator->() const {
            return std::addressof(operator*());
        }

        reference operator[]( difference_type n ) const {
            return *(*this + n);
        }

        Reverse_iterator& operator++() {
            --current;
            return *this;
        }

        Reverse_iterator& operator--() {
            ++current;
            return *this;
        }

        Reverse_iterator operator++( int ) {
            Reverse_iterator tmp(*this);
            --current;
            return tmp;
        }

        Reverse_iterator operator--( int ) {
            Reverse_iterator tmp(*this);
            ++current;
            return tmp;
        }

        Reverse_iterator operator+( difference_type n) const {
            return Reverse_iterator(current - n);
        }

        Reverse_iterator operator-( difference_type n) const {
            return Reverse_iterator(current + n);
        }

        Reverse_iterator& operator+=( difference_type n) {
            current -= n;
            return *this;
        }

        Reverse_iterator& operator-=( difference_type n) {
            current += n;
            return *this;
        }

	};

    template< class Iterator1, class Iterator2 >
    bool operator==( const ft::Reverse_iterator<Iterator1>& lhs,
                     const ft::Reverse_iterator<Iterator2>& rhs ) {
        return rhs.base() == lhs.base();
    }

    template< class Iterator1, class Iterator2 >
    bool operator!=( const ft::Reverse_iterator<Iterator1>& lhs,
                     const ft::Reverse_iterator<Iterator2>& rhs ) {
        return rhs.base() != lhs.base();
    }

    template< class Iterator1, class Iterator2 >
    bool operator<( const ft::Reverse_iterator<Iterator1>& lhs,
                    const ft::Reverse_iterator<Iterator2>& rhs ) {
        return rhs.base() < lhs.base();
    }

    template< class Iterator1, class Iterator2 >
    bool operator<=( const ft::Reverse_iterator<Iterator1>& lhs,
                     const ft::Reverse_iterator<Iterator2>& rhs ) {
        return rhs.base() <= lhs.base();
    }

    template< class Iterator1, class Iterator2 >
    bool operator>( const ft::Reverse_iterator<Iterator1>& lhs,
                    const ft::Reverse_iterator<Iterator2>& rhs ) {
        return rhs.base() > lhs.base();
    }

    template< class Iterator1, class Iterator2 >
    bool operator>=( const ft::Reverse_iterator<Iterator1>& lhs,
                     const ft::Reverse_iterator<Iterator2>& rhs ) {
        return rhs.base() >= lhs.base();
    }
}

#endif

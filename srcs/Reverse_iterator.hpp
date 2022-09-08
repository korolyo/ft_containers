#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <memory>
#include "Iterator_traits.hpp"

namespace ft {

	template<typename Iter>
	struct Reverse_iterator {
        typedef typename Iter                                           iterator_type;
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
            return this->current;
        }

        reference operator*() const {
            Iter tmp = current;
            return *--tmp;
        }

        pointer operator->() const {
            return std::addressof(operator*());
        }

        void operator[]( difference_type n ) const {
            return base()[-n - 1];
        }

        Reverse_iterator& operator++() {
            return *this - 1;
        }

        Reverse_iterator& operator--() {
            return *this + 1;
        }

        Reverse_iterator operator++( int ) {
            Reverse_iterator tmp = this->base();
            this->base() - 1;
            return tmp;
        }

        Reverse_iterator operator--( int ) {
            Reverse_iterator tmp = this->base();
            this->base() + 1;
            return tmp;
        }

        Reverse_iterator operator+( difference_type n) const {
            return Reverse_iterator(base() - n);
        }

        Reverse_iterator operator-( difference_type n) const {
            return Reverse_iterator(base() + n);
        }

        Reverse_iterator& operator+=( difference_type n) {

            return *this - n;
        }

        Reverse_iterator& operator-=( difference_type n) {

            return *this + n;
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

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <memory>
#include "Iterator_traits.hpp"

namespace ft {

    template<typename T>
	struct Random_access_iterator
            : std::iterator<std::random_access_iterator_tag> {
        typedef std::random_access_iterator_tag iterator_category;
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               value_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;

        It itr;

        bool operator!=(It &it) {
            return this->value != it->value;
        }

        value_type &operator*(It it) {
            return ;
        }

        It* operator->( ) const {
            return this;
        }

        bool operator==(It &it) {
            return this->value == it.value;
        }

        It& operator++( void ) {
            return ;
        }

        It& operator--( void ) {
            return ;
        }

        It operator++(It &it) {
            return ;
        }

        It operator--(It &it) {
            return ;
        }

        It& operator--(int n) {
            return ;
        }

        bool operator>(It it1) {
            return ;
        }

        bool operator<(It it1) {
            return ;
        }

        bool operator<=(It it1) {
            return ;
        }

        bool operator>=(It it1) {
            return ;
        }

        It& operator+=(int n) {
            return ;
        }

        It operator+(int n) {
            return ;
        }

        It operator-=(int n) {
            return ;
        }

        difference_type operator-(It it1) {
            return ;
        }

        template< class InputIt, class Distance >
        void advance( InputIt& it, Distance n );

        template< class InputIt >
        typename ft::Iterator_traits<It>::difference_type
        distance( InputIt first, InputIt last );
    };
}

#endif

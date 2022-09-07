#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <memory>
#include "Iterator_traits.hpp"

namespace ft {

    template<typename T>
	struct Random_access_iterator {
        typedef typename ft::Iterator_traits<It>::iterator_category   random_access_iterator_tag;
        typedef typename ft::Iterator_traits<It>::value_type          value_type;
        typedef typename ft::Iterator_traits<It>::difference_type     difference_type;
        typedef typename ft::Iterator_traits<It>::pointer             pointer;
        typedef typename ft::Iterator_traits<It>::reference           reference;


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

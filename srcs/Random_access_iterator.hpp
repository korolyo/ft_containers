#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <memory>

namespace ft {
	struct Random_access_iterator {
        Random_access_iterator operator*(Random_access_iterator it);
        Random_access_iterator operator==(Random_access_iterator &it);
        Random_access_iterator operator++(Random_access_iterator &it);
        Random_access_iterator operator--(int n);
        Random_access_iterator operator>(Random_access_iterator it1, Random_access_iterator it2);
        Random_access_iterator operator<(Random_access_iterator it1, Random_access_iterator it2);
        Random_access_iterator operator<=(Random_access_iterator it1, Random_access_iterator it2);
        Random_access_iterator operator>=(Random_access_iterator it1);
        Random_access_iterator operator+=(Random_access_iterator &it1, int n);
        Random_access_iterator operator-=(Random_access_iterator &it1, int n);
        Random_access_iterator operator-(Random_access_iterator it1, Random_access_iterator it2);

        template< class InputIt, class Distance >
        void advance( InputIt& it, Distance n );

        template< class InputIt >
        typename ft::iterator_traits<InputIt>::difference_type
        distance( InputIt first, InputIt last );
    };
}

#endif

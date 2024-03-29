#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <memory>
# include <iterator>
# include "utility.hpp"
# include "is_integral.hpp"

namespace ft {

    template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
    struct iterators {
        typedef Distance difference_type;
        typedef T value_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };

    template<class Iter>
    struct iterator_traits {
        typedef typename Iter::difference_type difference_type;
        typedef typename Iter::value_type value_type;
        typedef typename Iter::pointer pointer;
        typedef typename Iter::reference reference;
        typedef typename Iter::iterator_category iterator_category;
    };

    template<class T>
    struct iterator_traits<T *> {
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template<class T>
    struct iterator_traits<const T *> {
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T *pointer;
        typedef const T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template < class Iter >
    ptrdiff_t distance( Iter first, Iter last )
    {
        ptrdiff_t	len(0);
        for ( Iter i = first; i != last; ++i, ++len ) {}
        return ( len );
    }
}

#endif // ITERATOR_TRAITS_HPP

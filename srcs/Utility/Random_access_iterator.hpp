#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <memory>
#include "Iterator_traits.hpp"

namespace ft {

    template <typename T>
    class random_access_iterator : ft::iterators<std::random_access_iterator_tag, T>
    {
    public:
        typedef T* iterator_type;
        typedef typename ft::iterators<std::random_access_iterator_tag, T>::iterator_category iterator_category;
        typedef typename ft::iterators<std::random_access_iterator_tag, T>::value_type value_type;
        typedef typename ft::iterators<std::random_access_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::iterators<std::random_access_iterator_tag, T>::pointer pointer;
        typedef typename ft::iterators<std::random_access_iterator_tag, T>::reference reference;

        random_access_iterator() {}
        random_access_iterator(pointer position): position_(position) {}
        ~random_access_iterator() {}

        random_access_iterator(const random_access_iterator &src) {
            *this = src;
        }

        pointer base() const {return position_;}

        random_access_iterator &operator=(const random_access_iterator &src) {
            if (this == &src)
                return (*this);
            position_ = src.base();
            return *this;
        }

        reference &operator*() {
            return (*position_);
        }

        pointer operator->() const {
            return &(operator*());
        }

        random_access_iterator operator+(difference_type n) const {
            return position_ + n;
        }

        random_access_iterator &operator++() {
            position_++;
            return *this;
        }

        random_access_iterator operator++(int) {
            random_access_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        random_access_iterator &operator+=(difference_type n) {
            position_ += n;
            return *this;
        }

        random_access_iterator operator-(difference_type n) const {
            return position_ - n;
        }

        random_access_iterator &operator--() {
            position_--;
            return (*this);
        }

        random_access_iterator operator--(int) {
            random_access_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        random_access_iterator &operator-=(difference_type n) {
            position_ -= n;
            return *this;
        }

        reference operator[](difference_type n) const {
            return *(operator+(n));
        }

        operator random_access_iterator<const T>(void) const {
            return (random_access_iterator<const T>(this->position_));
        }

    private:
        pointer position_;
    };

    template<class Iterator>
    bool operator!=(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs) {
        return lhs.base() != rhs.base();
    }

    template<class Iterator>
    bool operator==(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs) {
        return lhs.base() == rhs.base();
    }

    template<class Iterator>
    bool operator>=(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs) {
        return (lhs.base() >= rhs.base());
    }

    template<class Iterator>
    bool operator<=(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs) {
        return (lhs.base() <= rhs.base());
    }

    template<class Iterator>
    bool operator>(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs) {
        return (lhs.base() > rhs.base());
    }

    template<class Iterator>
    bool operator<(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs) {
        return (lhs.base() < rhs.base());
    }

    template<class Iterator>
    random_access_iterator<Iterator> operator+(
            typename random_access_iterator<Iterator>::difference_type n,
            const random_access_iterator<Iterator> &it) {
        return (it + n);
    }

    template<class Iterator>
    typename random_access_iterator<Iterator>::difference_type operator-(
            const random_access_iterator<Iterator> &lhs,
            const random_access_iterator<Iterator> &rhs) {
        return (lhs.base() - rhs.base());
    }
}

#endif

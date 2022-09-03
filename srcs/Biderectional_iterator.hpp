#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include <memory>

namespace ft {
	struct Bidirectional_iterator {
        Bidirectional_iterator operator*(Bidirectional_iterator it);
        Bidirectional_iterator operator==(Bidirectional_iterator it);
        Bidirectional_iterator operator++(int n);
        Bidirectional_iterator operator--(int n);
    };
}

#endif

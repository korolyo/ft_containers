#pragma once

#include <memory>

namespace ft {
	template< class Iter >
	struct Iterator_traits {
		;
	};

	template< class T >
	struct Iterator_traits<T*> {
		;
	};

	template< class T >
	struct Iterator_traits<const T*> {
		;
	};
}
#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <memory>

namespace ft {
	template<typename Itr>
	class reverse_iterator {
		Itr itr;
	public:
		constexpr explicit reverse_iterator(Itr itr): itr(itr) {}
		constexpr auto& operator*() {
			return *std::prev(itr); // <== returns the content of prev
		}
		constexpr auto& operator++() {
			--itr;
			return *this;
		}
		constexpr friend bool operator!=(reverse_iterator<Itr> a, reverse_iterator<Itr> b) {
			return a.itr != b.itr;
		}
	};
}

#endif

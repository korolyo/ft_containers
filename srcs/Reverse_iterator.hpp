#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <memory>

namespace ft {

	template<typename Itr>
	struct Reverse_iterator {
		Itr itr;
	public:
		explicit Reverse_iterator(Itr itr): itr(itr) {}
		auto& operator*() {
			return *std::prev(itr); // <== returns the content of prev
		}
		auto& operator++() {
			--itr;
			return *this;
		}
		friend bool operator!=(Reverse_iterator<Itr> a, Reverse_iterator<Itr> b) {
			return a.itr != b.itr;
		}
	};
}

#endif

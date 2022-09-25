#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
	template<
	    class T1,
		class T2
	> struct Pair {
	private:
		T1	first;
		T2	second;

	public:
		Pair() : first(), second() { }

		Pair( const T1& x, const T2& y ) : first(x), second(y) { }

		template< class U1, class U2 >
		Pair( const Pair<U1, U2>& p ) : first(p.first), second(p.second) { }

		Pair( const Pair& p ) = default;

        ~Pair() { }

		Pair& operator=( const Pair& other ) {
            if (this != &src) {
                first = src.first;
                second = src.second;
            }
            return *this;
        }
	};

	template< class T1, class T2 >
	bool operator==( const Pair<T1, T2>& lhs,
					const Pair<T1, T2>& rhs ) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template< class T1, class T2 >
	bool operator!=( const Pair<T1, T2>& lhs,
					const Pair<T1, T2>& rhs ) {
		return !(lhs == rhs);
	}

	template< class T1, class T2 >
	bool operator>( const Pair<T1, T2>& lhs,
					const Pair<T1, T2>& rhs ) {
        return lhs.first > rhs.first
                || (!(rhs.first > lhs.first) &&lhs.second > rhs.second);
	}

	template< class T1, class T2 >
	bool operator>=( const Pair<T1, T2>& lhs,
					const Pair<T1, T2>& rhs ) {
        return !(rhs > lhs);
	}

	template< class T1, class T2 >
	bool operator<( const Pair<T1, T2>& lhs,
					const Pair<T1, T2>& rhs ) {
        return rhs > lhs;
	}

	template< class T1, class T2 >
	bool operator<=( const Pair<T1, T2>& lhs,
					const Pair<T1, T2>& rhs ) {
		return !(lhs > rhs);
	}

    template< class T1, class T2 >
    std::pair<T1,T2> make_pair( T1 t, T2 u ) {
        return ft::pair<T1, T2>(t, u);
    }

    template<class Key, class T, class Compare = ft::less<Key> >
    class pair_compare
    {
    public:
        typedef ft::pair<const Key, T> value_type;
        typedef Compare key_compare;

        pair_compare(const key_compare &compare = key_compare()) : compare_(compare) {}

        bool operator()(const value_type &x, const value_type &y) const {
            return (compare_(x.first, y.first));
        }

    private:
        key_compare compare_;
    };
}

#endif

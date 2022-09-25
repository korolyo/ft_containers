#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
	template<
	    class T1,
		class T2
	> struct pair {
	private:
		T1	_first;
		T2	_second;

	public:
		pair() : _first(), _second() { }

		pair( const T1& x, const T2& y ) : _first(x), _second(y) { }

		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ) : _first(p.first), _second(p.second) { }

		pair( const pair& p ) = default;

        ~pair() { }

		pair& operator=( const pair& other ) {
            if (this != &other) {
                _first = other.first;
                _second = other.second;
            }
            return *this;
        }
	};

	template< class T1, class T2 >
	bool operator==( const pair<T1, T2>& lhs,
					const pair<T1, T2>& rhs ) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template< class T1, class T2 >
	bool operator!=( const pair<T1, T2>& lhs,
					const pair<T1, T2>& rhs ) {
		return !(lhs == rhs);
	}

	template< class T1, class T2 >
	bool operator>( const pair<T1, T2>& lhs,
					const pair<T1, T2>& rhs ) {
        return lhs.first > rhs.first
                || (!(rhs.first > lhs.first) &&lhs.second > rhs.second);
	}

	template< class T1, class T2 >
	bool operator>=( const pair<T1, T2>& lhs,
					const pair<T1, T2>& rhs ) {
        return !(rhs > lhs);
	}

	template< class T1, class T2 >
	bool operator<( const pair<T1, T2>& lhs,
					const pair<T1, T2>& rhs ) {
        return rhs > lhs;
	}

	template< class T1, class T2 >
	bool operator<=( const pair<T1, T2>& lhs,
					const pair<T1, T2>& rhs ) {
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

        pair_compare(const key_compare &cmpr = key_compare()) : _cmpr(compare) {}

        bool operator()(const value_type &x, const value_type &y) const {
            return (_cmpr(x.first, y.first));
        }

    private:
        key_compare _cmpr;
    };
}

#endif //PAIR_HPP

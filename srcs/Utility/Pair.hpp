//
// Created by Atom Collin on 7/5/22.
//
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
		Pair() { }

		Pair( const T1& x, const T2& y ) { }

		template< class U1, class U2 >
		Pair( const Pair<U1, U2>& p ) {
			;
		}

		Pair( const Pair& p ) = default;

		Pair& operator=( const Pair& other ) { }

		template< T1, T2 >
		friend Pair< T1,T2 > make_pair( T1 t, T2 u );

		template< T1, T2 >
		friend bool operator==( const Pair<T1, T2>& lhs,
								const Pair<T1, T2>& rhs );

		template< T1, T2 >
		friend bool operator!=( const Pair<T1, T2>& lhs,
								const Pair<T1, T2>& rhs );

		template< T1, T2 >
		friend bool operator>( const Pair<T1, T2>& lhs,
								const Pair<T1, T2>& rhs );

		template< T1, T2 >
		friend bool operator>=( const Pair<T1, T2>& lhs,
								const Pair<T1, T2>& rhs );

		template< T1, T2 >
		friend bool operator<( const Pair<T1, T2>& lhs,
								const Pair<T1, T2>& rhs );

		template< T1, T2 >
		friend bool operator<=( const Pair<T1, T2>& lhs,
								const Pair<T1, T2>& rhs );
	};

	template< class T1, class T2 >
	ft::Pair< T1,T2 > make_pair( T1 t, T2 u ) {
		;
	}

	template< class T1, class T2 >
	bool operator==( const Pair<T1, T2>& lhs,
					const Pair<T1, T2>& rhs ) {
		;
	}

	template< class T1, class T2 >
	bool operator!=( const Pair<T1, T2>& lhs,
					const Pair<T1, T2>& rhs ) {
		;
	}

	template< class T1, class T2 >
	bool operator>( const Pair<T1, T2>& lhs,
					const Pair<T1, T2>& rhs ) {
		;
	}

	template< class T1, class T2 >
	bool operator>=( const Pair<T1, T2>& lhs,
					const Pair<T1, T2>& rhs ) {
		;
	}

	template< class T1, class T2 >
	bool operator<( const Pair<T1, T2>& lhs,
					const Pair<T1, T2>& rhs ) {
		;
	}

	template< class T1, class T2 >
	bool operator<=( const Pair<T1, T2>& lhs,
					const Pair<T1, T2>& rhs ) {
		;
	}
}

template< class T1, class T2 >
std::pair<T1,T2> make_pair( T1 t, T2 u );

#endif

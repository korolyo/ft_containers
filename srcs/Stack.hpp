#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <Vector.hpp>
#include <

namespace ft {
	template<
	        class T,
			class Container = ft::Vector<T>
	> class Stack {
		typedef Container								container_type;
		typedef typename Container::value_type			value_type;
		typedef typename Container::size_type			size_type;
		typedef typename Container::reference			reference;
		typedef typename Container::const_reference		const_reference;
	public:

		explicit Stack( const Container& cont = Container() ) {
            c = cont;
        }

		reference top() {
			return c.back();
		}

		const_reference top() const {
			return c.back();
		}

		bool empty() const {
			return c.empty();
		}

		size_type size() const {
			return c.size();
		}

		void push( const value_type& value) {
			return c.push_back(value);
		}

		void pop() {
			return c.pop_back();
		}

		template< T, Container >
		friend bool operator==( const ft::Stack<T,Container>& lhs,
								const ft::Stack<T,Container>& rhs );

		template< T, Container >
		friend bool operator!=( const ft::Stack<T,Container>& lhs,
								const ft::Stack<T,Container>& rhs );

		template< T, Container >
		friend bool operator>( const ft::Stack<T,Container>& lhs,
								const ft::Stack<T,Container>& rhs );

		template< T, Container >
		friend bool operator>=( const ft::Stack<T,Container>& lhs,
								const ft::Stack<T,Container>& rhs );

		template< T, Container >
		friend bool operator<( const ft::Stack<T,Container>& lhs,
								const ft::Stack<T,Container>& rhs );

		template< T, Container >
		friend bool operator<=( const ft::Stack<T,Container>& lhs,
								const ft::Stack<T,Container>& rhs );

	private:
		Container c;
	};

	template< class T, class Container >
	bool operator==( const ft::Stack<T,Container>& lhs,
							const ft::Stack<T,Container>& rhs )
	{
		return lhs.c == rhs.c;
	}

	template< class T, class Container >
	bool operator!=( const ft::Stack<T,Container>& lhs,
					 const ft::Stack<T,Container>& rhs )
	{
        return lhs.c != rhs.c;
	}

	template< class T, class Container >
	bool operator>( const ft::Stack<T,Container>& lhs,
					 const ft::Stack<T,Container>& rhs )
	{
        return lhs.c > rhs.c;
	}

	template< class T, class Container >
	bool operator>=( const ft::Stack<T,Container>& lhs,
					 const ft::Stack<T,Container>& rhs )
	{
        return lhs.c >= rhs.c;
	}

	template< class T, class Container >
	bool operator<( const ft::Stack<T,Container>& lhs,
					 const ft::Stack<T,Container>& rhs )
	{
        return lhs.c < rhs.c;
	}

	template< class T, class Container >
	bool operator<=( const ft::Stack<T,Container>& lhs,
					 const ft::Stack<T,Container>& rhs )
	{
        return lhs.c <= rhs.c;
	}
}

#endif

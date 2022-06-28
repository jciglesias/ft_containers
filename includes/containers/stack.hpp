// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Stack.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/04 09:30:11 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/28 14:45:25 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef STACK_HPP
# define STACK_HPP

# include "../ft.hpp"
# include "vector.hpp"

template < class T, class Container >
class ft::stack
{
public:
	typedef T			value_type;
	typedef Container	container_type;
	typedef size_t		size_type;
/*
**constructors
*/
	explicit stack(const container_type &ctnr = container_type()) : c(ctnr){}
/*
**member fn
*/
	bool		empty() const { return c.empty(); }
	size_type	size() const { return c.size(); }
	value_type	&top() { return c.back(); }
	const value_type	&top() const { return c.back(); }
	void		push(const value_type &val) { c.push_back(val); }
	void		pop() { c.pop_back(); }
	friend bool ft::operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	friend bool ft::operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	friend bool ft::operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	friend bool ft::operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	friend bool ft::operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	friend bool ft::operator>= (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
protected:
	Container	c;
};

namespace ft{
	template < class T, class Container >
	inline bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
		return ( lhs.c == rhs.c );
	}

	template < class T, class Container >
	inline bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
		return (lhs.c != rhs.c);
	}

	template < class T, class Container >
	inline bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
		return (lhs.c < rhs.c);
	}

	template < class T, class Container >
	inline bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
		return (lhs.c <= rhs.c);
	}

	template < class T, class Container >
	inline bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
		return (lhs.c > rhs.c);
	}

	template < class T, class Container >
	inline bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
		return (lhs.c >= rhs.c);
	}
}

#endif

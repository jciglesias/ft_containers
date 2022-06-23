// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Stack.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/04 09:30:11 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/21 11:17:58 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef STACK_HPP
# define STACK_HPP

# include "../ft.hpp"
# include "Vector.hpp"

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
	explicit stack(const container_type &ctnr = container_type()) : _cntr(ctnr){}
/*
**member fn
*/
	bool		empty() const { return _cntr.empty(); }
	size_type	size() const { return _cntr.size(); }
	value_type	&top() { return _cntr.back(); }
	const value_type	&top() const { return _cntr.back(); }
	void		push(const value_type &val) { _cntr.push_back(val); }
	void		pop() { _cntr.pop_back(); }
	friend bool ft::operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	friend bool ft::operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	friend bool ft::operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	friend bool ft::operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	friend bool ft::operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	friend bool ft::operator>= (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
private:
	Container	_cntr;
};

namespace ft{
	template < class T, class Container >
	inline bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
		return ( lhs._cntr == rhs._cntr );
	}

	template < class T, class Container >
	inline bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
		return (lhs._cntr != rhs._cntr);
	}

	template < class T, class Container >
	inline bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
		return (lhs._cntr < rhs._cntr);
	}

	template < class T, class Container >
	inline bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
		return (lhs._cntr <= rhs._cntr);
	}

	template < class T, class Container >
	inline bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
		return (lhs._cntr > rhs._cntr);
	}

	template < class T, class Container >
	inline bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
		return (lhs._cntr >= rhs._cntr);
	}
}

#endif

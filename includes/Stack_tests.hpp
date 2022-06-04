// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Stack_tests.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/06/03 16:37:26 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/04 15:34:16 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef STACK_TESTS_HPP
# define STACK_TESTS_HPP

# include "Stack.hpp"
# include <stack>

template < class T >
void stack_test(T &x){
	for (int i = 0; i < 1000; i++)
		x.push(i);
	std::cout << x.size() << " :size\n";
	std::cout << x.top() << " :top\n";
	x.pop();
	std::cout << x.size() << " :size\n";
	T c;
	for (int i = 0; i < 99; i++)
		c.push(i);
	for (int i = 0; i < 99; i++){
		std::cout << (x == c) << "\n";
		x.pop();
		c.pop();
	}
}

#endif

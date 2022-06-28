// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Stack_tests.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/06/03 16:37:26 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/28 14:44:47 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef STACK_TESTS_HPP
# define STACK_TESTS_HPP

# include "stack.hpp"
# include <stack>

template < class T >
void stack_test(T &x){
	for (int i = 0; i < 1000; i++)
		x.push(i);
	std::cout << x.size() << " :size\n";
	std::cout << x.top() << " :top\n";
	std::cout << x.empty() << " :empty\n";
	x.pop();
	std::cout << x.size() << " :size\n";
	T c;
	for (int i = 0; i < 99; i++)
		c.push(i);
	std::cout << "stack == stack: " << (x == c) << std::endl;
	std::cout << "stack <= stack: " << (x <= c) << std::endl;
	std::cout << "stack >= stack: " << (x >= c) << std::endl;
	std::cout << "stack < stack: " << (x < c) << std::endl;
	std::cout << "stack > stack: " << (x > c) << std::endl;
	std::cout << "stack != stack: " << (x != c) << std::endl;
	for (int i = 0; i < 99; i++){
		x.pop();
		c.pop();
	}
	std::cout << "stack == stack: " << (x == c) << std::endl;
	std::cout << "stack <= stack: " << (x <= c) << std::endl;
	std::cout << "stack >= stack: " << (x >= c) << std::endl;
	std::cout << "stack < stack: " << (x < c) << std::endl;
	std::cout << "stack > stack: " << (x > c) << std::endl;
	std::cout << "stack != stack: " << (x != c) << std::endl;
}

#endif

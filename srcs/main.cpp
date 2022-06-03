// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/01 16:01:30 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/03 10:51:55 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Stack.hpp"
#include <stack>

void vector_test();
void map_test();

void stack_test(){
	ft::stack<int> a;
	std::stack<int> b;

	for (int i = 0; i < 100; i++){
		a.push(i);
		b.push(i);
	}
	if (a.size() == b.size())
		std::cout << "OK\n";
	else
		std::cout << "KO\n";
	if (a.top() == b.top())
		std::cout << "OK\n";
	else
		std::cout << "KO\n";
	a.pop();
	b.pop();
	if (a.size() == b.size())
		std::cout << "OK\n";
	else
		std::cout << "KO\n";
	ft::stack<int> c;
	for (int i = 0; i < 99; i++)
		c.push(i);
	for (int i = 0; i < 99; i++){
		if (a == c)
			std::cout << a.top() << " OK\n";
		else
			std::cout << c.top() << " != " << a.top() << " KO\n";
		a.pop();
		c.pop();
	}
}

int main()
{
//	vector_test();
//	map_test();
	stack_test();
}

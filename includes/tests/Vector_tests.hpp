// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vector_tests.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/06/03 16:41:33 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/04 15:16:24 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VECTOR_TESTS_HPP
# define VECTOR_TESTS_HPP

#include "Vector.hpp"
#include <vector>

template < class T >
void	cmpftstd(T a){
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	std::cout << a.max_size() << std::endl;
	for (unsigned long i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
}

template < typename T >
void vector_test(T &a){
	for (int i = 0; i < 1000; i++)
		a.push_back(i);
	std::cout << "vector:" << std::endl;
	cmpftstd(a);
	std::cout << "v.insert(--v.end(), 20)" << std::endl;
	a.insert(--a.end(), 20);
	cmpftstd(a);
	std::cout << "v.insert(v.begin(), 20)" << std::endl;
	a.insert(a.begin(), 20);
	cmpftstd(a);
	std::cout << "v.resize(2)" << std::endl;
	a.resize(2);
	cmpftstd(a);
	std::cout << "v.resize(5)" << std::endl;
	a.resize(5);
	cmpftstd(a);
	std::cout << "v.resize(6, 50)" << std::endl;
	a.resize(6, 50);
	cmpftstd(a);
	std::cout << "v.reserve(20)" << std::endl;
	a.reserve(20);
	cmpftstd(a);
	std::cout << "x.swap(y)" << std::endl;
	T c(5, 90);
	swap(a, c);
	cmpftstd(a);
	std::cout << "v.insert(v.begin(), 5, 10)" << std::endl;
	a.insert(a.begin(), 5, 10);
	cmpftstd(a);
	std::cout << "x.insert(x.begin(), y.begin(), y.end())" << std::endl;
	a.insert(a.begin(), c.begin(), c.end());
	cmpftstd(a);
	std::cout << "v.assign(20, 30)" << std::endl;
	a.assign(20, 30);
	cmpftstd(a);
	std::cout << "x.assign(y.begin(), y.end())" << std::endl;
	a.assign(c.begin(), c.end());
	cmpftstd(a);
	std::cout << "v.push_back(50)\n";
	a.push_back(50);
	cmpftstd(a);
	std::cout << "v.pop_back()\n";
	a.pop_back();
	cmpftstd(a);
	std::cout << "v.erase(v.begin())\n";
	a.erase(a.begin());
	cmpftstd(a);
	std::cout << "v.erase(v.begin(), v.begin() + 2)\n";
	a.erase(a.begin(), a.begin() + 2);
	cmpftstd(a);
	std::cout << "x > y: ";
	std::cout << (a > c) << std::endl;
	std::cout << "x < y: ";
	std::cout << (a < c) << std::endl;
	std::cout << "x == y: ";
	std:: cout << (a == c) << std::endl;
	std::cout << "x >= y: ";
	std::cout << (a >= c) << std::endl;
	std::cout << "x <= y: ";
	std::cout << (a <= c) << std::endl;
	std::cout << "x != y: ";
	std::cout << (a != c) << std::endl;
	std::cout << "v.clear()\n";
	a.clear();
	cmpftstd(a);
}
#endif

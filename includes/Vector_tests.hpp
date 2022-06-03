// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vector_tests.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/06/03 16:41:33 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/03 16:49:58 by jiglesia         ###   ########.fr       //
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
	std::cout << "vector:" << std::endl;
	cmpftstd(a);
	std::cout << "v.insert(--v.end(), 200)" << std::endl;
	a.insert(--a.end(), 200);
	cmpftstd(a);
	std::cout << "v.insert(v.begin(), 200)" << std::endl;
	a.insert(a.begin(), 200);
	cmpftstd(a);
	std::cout << "v.resize(2)" << std::endl;
	a.resize(2);
	cmpftstd(a);
	std::cout << "v.resize(5)" << std::endl;
	a.resize(5);
	cmpftstd(a);
	std::cout << "v.resize(6, 500)" << std::endl;
	a.resize(6, 500);
	cmpftstd(a);
	std::cout << "v.reserve(20)" << std::endl;
	a.reserve(20);
	cmpftstd(a);
	std::cout << "x.swap(y)" << std::endl;
	T c(5, 900);
	swap(a, c);
	cmpftstd(a);
	std::cout << "v.insert(v.begin(), 5, 100)" << std::endl;
	a.insert(a.begin(), 5, 100);
	cmpftstd(a);
	std::cout << "x.insert(x.begin(), y.begin(), y.end())" << std::endl;
	a.insert(a.begin(), c.begin(), c.end());
	cmpftstd(a);
	std::cout << "v.assign(20, 300)" << std::endl;
	a.assign(20, 300);
	cmpftstd(a);
	std::cout << "x.assign(y.begin(), y.end())" << std::endl;
	a.assign(c.begin(), c.end());
	cmpftstd(a);
	std::cout << "v.push_back(500)\n";
	a.push_back(500);
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

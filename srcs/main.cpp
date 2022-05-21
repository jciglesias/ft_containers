// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/01 16:01:30 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/16 18:36:32 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Vector.hpp"
#include <iostream>
#include <vector>
#include "Map.hpp"
#include <map>

template <class T, class Alloc>
void	cmpftstd(ft::vector<T, Alloc> a, std::vector<T, Alloc> b){
	if (a.size() != b.size()){
		std::cout << "KO\n";
		return ;
	}
 	else if (a.capacity() != b.capacity()){
		std::cout << "KO\n";
		return ;
	}
 	else if (a.max_size() != b.max_size()){
		std::cout << "KO\n";
		return ;
	}
	for (unsigned long i = 0; i < a.size(); i++){
		if (a[i] != b[i]){
			std::cout << "KO\n";
			return ;
		}
	}
	std::cout << "OK\n";
}

void vector_test()
{
	ft::vector<int> a(3, 100);
	std::vector<int> b(3, 100);

	std::cout << "ft::vector <-> std::vector" << std::endl;
	cmpftstd(a, b);
	std::cout << "v.insert(--v.end(), 200)" << std::endl;
	a.insert(--a.end(), 200);
	b.insert(--b.end(), 200);
	cmpftstd(a, b);
	std::cout << "v.insert(v.begin(), 200)" << std::endl;
	a.insert(a.begin(), 200);
	b.insert(b.begin(), 200);
	cmpftstd(a, b);
	std::cout << "v.resize(2)" << std::endl;
	a.resize(2);
	b.resize(2);
	cmpftstd(a, b);
	std::cout << "v.resize(5)" << std::endl;
	a.resize(5);
	b.resize(5);
	cmpftstd(a, b);
	std::cout << "v.resize(6, 500)" << std::endl;
	a.resize(6, 500);
	b.resize(6, 500);
	cmpftstd(a, b);
	std::cout << "v.reserve(20)" << std::endl;
	a.reserve(20);
	b.reserve(20);
	cmpftstd(a, b);
	std::cout << "x.swap(y)" << std::endl;
	ft::vector<int> c(5, 900);
	swap(a, c);
	std::vector<int> d(5, 900);
	swap(b, d);
	cmpftstd(a, b);
	std::cout << "v.insert(v.begin(), 5, 100)" << std::endl;
	a.insert(a.begin(), 5, 100);
	b.insert(b.begin(), 5, 100);
	cmpftstd(a, b);
	std::cout << "x.insert(x.begin(), y.begin(), y.end())" << std::endl;
	a.insert(a.begin(), c.begin(), c.end());
	b.insert(b.begin(), d.begin(), d.end());
	cmpftstd(a, b);
	std::cout << "v.assign(20, 300)" << std::endl;
	a.assign(20, 300);
	b.assign(20, 300);
	cmpftstd(a, b);
	std::cout << "x.assign(y.begin(), y.end())" << std::endl;
	a.assign(c.begin(), c.end());
	b.assign(d.begin(), d.end());
	cmpftstd(a, b);
	std::cout << "v.push_back(500)\n";
	a.push_back(500);
	b.push_back(500);
	cmpftstd(a, b);
	std::cout << "v.pop_back()\n";
	a.pop_back();
	b.pop_back();
	cmpftstd(a, b);
	std::cout << "v.erase(v.begin())\n";
	a.erase(a.begin());
	b.erase(b.begin());
	cmpftstd(a, b);
	std::cout << "v.erase(v.begin(), v.begin() + 2)\n";
	a.erase(a.begin(), a.begin() + 2);
	b.erase(b.begin(), b.begin() + 2);
	cmpftstd(a, b);
	std::cout << "x > y: ";
	if ((a > c) == (b > d)){
		std::cout << "OK" << std::endl;
	}
	else
		std::cout << "KO" << std::endl;
	std::cout << "x < y: ";
	if ((a < c) == (b < d)){
		std::cout << "OK" << std::endl;
	}
	else
		std::cout << "KO" << std::endl;
	std::cout << "x == y: ";
	if ((a == c) == (b == d)){
		std::cout << "OK" << std::endl;
	}
	else
		std::cout << "KO" << std::endl;
	std::cout << "x >= y: ";
	if ((a >= c) == (b >= d)){
		std::cout << "OK" << std::endl;
	}
	else
		std::cout << "KO" << std::endl;
	std::cout << "x <= y: ";
	if ((a <= c) == (b <= d)){
		std::cout << "OK" << std::endl;
	}
	else
		std::cout << "KO" << std::endl;
	std::cout << "x != y: ";
	if ((a != c) == (b != d)){
		std::cout << "OK" << std::endl;
	}
	else
		std::cout << "KO" << std::endl;
	std::cout << "v.clear()\n";
	a.clear();
	b.clear();
	cmpftstd(a, b);
}

void map_test()
{
	ft::map<char, int> a;
	std::map<char, int> b;

	a['a'] = 10;
	b['a'] = 10;
	a['b'] = 20;
	b['b'] = 20;
}

int main()
{
	vector_test();
	map_test();
}

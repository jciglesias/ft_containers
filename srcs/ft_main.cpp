// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/01 16:01:30 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/04 15:31:40 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Stack_tests.hpp"
#include "Map_tests.hpp"
#include "Vector_tests.hpp"

int main()
{
	ft::stack<int> s;
	ft::vector<int> v(3, 200);
	ft::map<char, int> m;
	vector_test(v);
	map_test(m);
	stack_test(s);
	ft::stack<char> a;
	ft::vector<char> b(3, 20);
	ft::map<char, char> c;
	stack_test(a);
	vector_test(b);
	map_test(c);
	ft::stack<unsigned long> d;
	ft::vector<unsigned long> e;
	ft::map<unsigned long, char> f;
	stack_test(d);
	vector_test(e);
	map_test(f);
	ft::stack<short, std::vector<short> > g;
	ft::vector<short> h;
	ft::map<short, int> i;
	stack_test(g);
	vector_test(h);
	map_test(i);
}

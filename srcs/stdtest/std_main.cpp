// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   std_main.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/06/03 15:04:18 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/04 15:31:25 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Stack_tests.hpp"
#include "Map_tests.hpp"
#include "Vector_tests.hpp"

int main()
{
	std::stack<int> s;
	std::vector<int> v(3, 200);
	std::map<char, int> m;
	vector_test(v);
	map_test(m);
	stack_test(s);
	std::stack<char> a;
	std::vector<char> b(3, 20);
	std::map<char, char> c;
	stack_test(a);
	vector_test(b);
	map_test(c);
	std::stack<unsigned long> d;
	std::vector<unsigned long> e;
	std::map<unsigned long, char> f;
	stack_test(d);
	vector_test(e);
	map_test(f);
	std::stack<short, std::vector<short> > g;
	std::vector<short> h;
	std::map<short, int> i;
	stack_test(g);
	vector_test(h);
	map_test(i);
}

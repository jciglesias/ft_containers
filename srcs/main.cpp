// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/01 16:01:30 by jiglesia          #+#    #+#             //
//   Updated: 2022/07/05 15:05:42 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Stack_tests.hpp"
#include "Map_tests.hpp"
#include "Vector_tests.hpp"

#ifdef M_FT
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

int main()
{
	NAMESPACE::stack<int> s;
	NAMESPACE::vector<int> v(3, 200);
	NAMESPACE::map<char, int> m;
	vector_test(v);
	map_test(m, M_RAN);
	stack_test(s);
	NAMESPACE::stack<char> a;
	NAMESPACE::vector<char> b(3, 20);
	NAMESPACE::map<char, char> c;
	stack_test(a);
	vector_test(b);
	map_test(c, M_RAN);
	NAMESPACE::stack<unsigned long> d;
	NAMESPACE::vector<unsigned long> e;
	NAMESPACE::map<unsigned long, char> f;
	stack_test(d);
	vector_test(e);
	map_test(f, M_RAN);
	NAMESPACE::stack<short, std::vector<short> > g;
	NAMESPACE::vector<short> h;
	NAMESPACE::map<short, int> i;
	stack_test(g);
	vector_test(h);
	map_test(i, M_RAN);
}

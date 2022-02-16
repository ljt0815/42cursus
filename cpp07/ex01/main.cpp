/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:01:34 by jitlee            #+#    #+#             */
/*   Updated: 2022/02/16 17:01:10 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void	print(T &t)
{
	std::cout << t << "\n";
}

int main(void)
{
	int i[4] = { 4, 3, 2, 1};
	double d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string s[3] = {"you", "me", "we"};

	iter(i, sizeof(i) / sizeof(int), print);
	iter(d, sizeof(d) / sizeof(double), print);
	iter(s, sizeof(s) / sizeof(std::string), print);
	return (0);
}

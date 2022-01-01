/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jitlee <jitlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:10:58 by jitlee            #+#    #+#             */
/*   Updated: 2022/01/01 19:32:36 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

std::string	strReplace(std::string str, std::string findStr, std::string replaceStr)
{
	int	findPos;
	while (str.find(findStr) != std::string::npos)
	{
		findPos = str.find(findStr);
		str.erase(findPos, findStr.length());
		str.insert(findPos, replaceStr);
	}
	return (str);
}

int	main(int ac, char *av[])
{
	std::ifstream	readFile;
	std::ofstream	saveFile;
	std::string		tmp;
	std::string		buf;
	if (ac != 4)
	{
		std::cout << "arguments only filename, str1, str2" << std::endl;
		return (1);
	}
	if (av[2][0] == 0 || av[3][0] == 0)
	{
		std::cout << "str is not emptyString" << std::endl;
		return (1);
	}
	readFile.open(av[1]);
	if (readFile.is_open())
		while (getline(readFile, tmp))
		{
			buf.append(tmp);
			buf.append("\n");
		}
	else
	{
		std::cout << "file Can't Open" << std::endl;
		return (1);
	}
	tmp = strReplace(buf, std::string(av[2]), std::string(av[3]));
	saveFile.open(std::string(av[1]) + ".replace");
	if (saveFile.is_open())
		saveFile.write(tmp.c_str(), tmp.length());
	else
	{
		std::cout << "Save Error" << std::endl;
		return (1);
	}
	readFile.close();
	saveFile.close();
}

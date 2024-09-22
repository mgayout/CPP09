/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:25:33 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/20 09:25:33 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char *arg) : _err(0)
{
	std::vector<std::string>	vec;
	std::string					str = arg;

	for (size_t i = 0; i != str.size();)
	{
		while (str[i] == ' ' && i < str.size())
			i++;
		size_t	last = i; 
		while (str[i] != ' ' && i < str.size())
			i++;
		std::string	copy = str.substr(last, i - last);

		vec.push_back(copy);
	}
	for (size_t i = 0; i != vec.size(); i++)
	{
		std::string	number = vec[i];

		for (size_t j = 0; j != number.size(); j++)
		{
			if (!isdigit(number[j]))
			{
				this->_err = 1;
				break;
			}
		}
		for (size_t k = 0; k != i; k++)
		{
			std::string	copy = vec[k];
			if (copy == number)
			{
				this->_err = 1;
				break;
			}
			long long max = std::strtoll(number.c_str(), NULL, 10);
			if (max > 2147483647)
			{
				this->_err = 1;
				break;
			}
		}
	}
	this->insert(vec);
}

PmergeMe::PmergeMe(int argc, char **argv) : _err(0)
{
	std::vector<std::string>	vec;
	std::string					str;

	for (int i = 1; i != argc; i++)
	{
		str = argv[i];
		vec.push_back(str);
		for (size_t j = 0; j != vec[i - 1].size(); j++)
		{
			if (!isdigit(vec[i - 1][j]))
			{
				this->_err = 1;
				break;
			}
		}
		for (int k = 0; k != (i - 1); k++)
		{
			if (vec[k] == vec[i - 1])
			{
				this->_err = 1;
				break;
			}
			long long max = std::strtoll(vec[i - 1].c_str(), NULL, 10);
			if (max > 2147483647)
			{
				this->_err = 1;
				break;
			}
		}
	}
	this->insert(vec);
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe()
{

}

int		PmergeMe::getErr()
{
	return this->_err;
}

void	PmergeMe::insert(std::vector<std::string> vec)
{
	int	cast;

	for (size_t i = 0; i != vec.size(); i++)
	{
		cast = std::atoi(vec[i].c_str());
		_arr.push_back(cast);
		_lst.push_back(cast);
	}
}

void	PmergeMe::init()
{
	std::cout << "Before: ";
	for	(size_t	i = 0; i != this->_arr.size(); i++)
		std::cout << this->_arr[i] << " ";
	std::cout << std::endl;

	clock_t start = std::clock();
	this->sortArr();
	clock_t end = std::clock();
	this->_time_arr = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

	start = std::clock();
	this->sortLst();
	end = std::clock();
	this->_time_lst = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

	std::cout << "After: ";
	for	(std::list<int>::iterator it = this->_lst.begin(); it != this->_lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << this->_arr.size() << " elements with std::vector : " << this->_time_arr << std::endl;
	std::cout << "Time to process a range of " << this->_lst.size() << " elements with std::list : " << this->_time_lst << std::endl;
}

void	PmergeMe::sortArr()
{

}

void	PmergeMe::sortLst()
{

}

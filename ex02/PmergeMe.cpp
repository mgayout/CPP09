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
		_dq.push_back(cast);
	}
}

void	PmergeMe::init()
{
	std::cout << "Before: ";
	for	(size_t	i = 0; i != this->_arr.size(); i++)
		std::cout << this->_arr[i] << " ";
	std::cout << std::endl;

	clock_t start1 = std::clock();
	this->sortArr(0, this->_arr.size() - 1);
	clock_t end1 = std::clock();
	this->_time_arr = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

	clock_t	start2 = std::clock();
	this->sortDq(0, this->_dq.size() - 1);
	clock_t	end2 = std::clock();
	this->_time_dq = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

	std::cout << "After: ";
	for	(size_t	i = 0; i != this->_dq.size(); i++)
		std::cout << this->_dq[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << this->_arr.size() << " elements with std::vector : " << this->_time_arr << " ms." << std::endl;
	std::cout << "Time to process a range of " << this->_dq.size() << " elements with std::deque : " << this->_time_dq << " ms." << std::endl;
}

void	PmergeMe::sortArr(int begin, int end)
{
	if (end - begin > this->_limit)
	{
		int	mid = (begin + end) / 2;

		this->sortArr(begin, mid);
		this->sortArr(mid + 1, end);
		this->mergeArr(begin, mid, end);
	}
	else
		this->insertArr(begin, end);
}

void	PmergeMe::mergeArr(int begin, int mid, int end)
{
	int	n1 = mid - begin + 1;
	int	n2 = end - mid;
	int	right_i = 0;
	int	left_i = 0;

	std::vector<int> left(this->_arr.begin() + begin, this->_arr.begin() + mid + 1);
	std::vector<int> right(this->_arr.begin() + mid + 1, this->_arr.begin() + end + 1);

	for (int i = begin; i <= end; i++)
	{
		if (right_i == n2)
		{
			this->_arr[i] = left[left_i];
			left_i++;
		}
		else if (left_i == n1)
		{
			this->_arr[i] = right[right_i];
			right_i++;
		}
		else if (right[right_i] > left[left_i])
		{
			this->_arr[i] = left[left_i];
			left_i++;
		}
		else
		{
			this->_arr[i] = right[right_i];
			right_i++;
		}
	}
}

void	PmergeMe::insertArr(int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		int	key = this->_arr[i + 1];
		int	j = i + 1;

		while (j > begin && this->_arr[j - 1] > key)
		{
			this->_arr[j] = this->_arr[j - 1];
			j--;
		}
		this->_arr[j] = key;
	}
}

void	PmergeMe::sortDq(int begin, int end)
{
	if (end - begin > this->_limit)
	{
		int	mid = (begin + end) / 2;

		this->sortDq(begin, mid);
		this->sortDq(mid + 1, end);
		this->mergeDq(begin, mid, end);
	}
	else
		this->insertDq(begin, end);
}

void	PmergeMe::insertDq(int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		int	key = this->_dq[i + 1];
		int	j = i + 1;

		while (j > begin && this->_dq[j - 1] > key)
		{
			this->_dq[j] = this->_dq[j - 1];
			j--;
		}
		this->_dq[j] = key;
	}
}

void	PmergeMe::mergeDq(int begin, int mid, int end)
{
	int	n1 = mid - begin + 1;
	int	n2 = end - mid;
	int	right_i = 0;
	int	left_i = 0;

	std::deque<int> left(this->_dq.begin() + begin, this->_dq.begin() + mid + 1);
	std::deque<int> right(this->_dq.begin() + mid + 1, this->_dq.begin() + end + 1);

	for (int i = begin; i <= end; i++)
	{
		if (right_i == n2)
		{
			this->_dq[i] = left[left_i];
			left_i++;
		}
		else if (left_i == n1)
		{
			this->_dq[i] = right[right_i];
			right_i++;
		}
		else if (right[right_i] > left[left_i])
		{
			this->_dq[i] = left[left_i];
			left_i++;
		}
		else
		{
			this->_dq[i] = right[right_i];
			right_i++;
		}
	}
}

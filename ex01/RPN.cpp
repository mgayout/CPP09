/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:58:34 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/17 16:58:34 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(char *arg)
{
	std::string	calcul = arg;
	int	size1, size2, size3;

	this->_err = 0;
	size1 = calcul.size();
	calcul.erase(std::remove(calcul.begin(), calcul.end(), ' '), calcul.end());
	size2 = calcul.size();
	if (size1 != ((size2 * 2) - 1))
	{
		this->_err = 1;
		return;
	}
	calcul.erase(std::remove(calcul.begin(), calcul.end(), '+'), calcul.end());
	calcul.erase(std::remove(calcul.begin(), calcul.end(), '-'), calcul.end());
	calcul.erase(std::remove(calcul.begin(), calcul.end(), '*'), calcul.end());
	calcul.erase(std::remove(calcul.begin(), calcul.end(), '/'), calcul.end());
	size3 = calcul.size();
	if (size2 != ((size3 * 2) - 1))
	{
		this->_err = 1;
		return;
	}
	for (size_t i = 0; i != calcul.size(); i++)
		if (!isdigit(calcul[i]))
		{
			this->_err = 1;
			return;
		}
	return;
}

RPN::RPN(const RPN& other) : _err(other._err)
{

}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return *this;
}

RPN::~RPN()
{

}

int		RPN::getErr()
{
	return this->_err;
}

void	RPN::init(char *arg)
{
	std::string	calcul = arg;

	for (size_t i = 0; i != calcul.size(); i++)
	{
		char	c = calcul[i];
		if (c == ' ')
			continue;
		else if (isdigit(c))
		{
			int	number = c - '0';
			this->calcul.push(number);
		}
		else if (c == '+' && this->calcul.size() >= 2)
		{
			double number = this->calcul.top();
			this->calcul.pop();
			number += this->calcul.top();
			this->calcul.pop();
			this->calcul.push(number);
		}
		else if (c == '-' && this->calcul.size() >= 2)
		{
			double number = this->calcul.top();
			this->calcul.pop();
			number = this->calcul.top() - number;
			this->calcul.pop();
			this->calcul.push(number);
		}
		else if (c == '*' && this->calcul.size() >= 2)
		{
			double number = this->calcul.top();
			this->calcul.pop();
			number *= this->calcul.top();
			this->calcul.pop();
			this->calcul.push(number);
		}
		else if (c == '/' && this->calcul.size() >= 2)
		{
			double number = this->calcul.top();
			this->calcul.pop();
			number = this->calcul.top() / number;
			this->calcul.pop();
			this->calcul.push(number);
		}
		else
		{
			std::cout << "Error: bad format" << std::endl;
			return;
		}
		//std::cout << this->calcul.top() << std::endl;
	}
	//std::cout << "final " << this->calcul.top() << std::endl;
	std::cout << this->calcul.top() << std::endl;
}

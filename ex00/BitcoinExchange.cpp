/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:13:11 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/16 17:02:31 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _error("")
{
	std::ifstream	file("data.csv");

	if (!file)
		std::cout << "Error: 'data.csv' not found" << std::endl;
	else
		this->fillMap((char*)"data.csv", true);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _error(other._error)
{

}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	
}

void	BitcoinExchange::fillMap(char *arg, bool b)
{
	std::ifstream	file(arg);
	std::string		line;
	std::string		first;
	std::string		second;

	for (std::string line; std::getline(file, line) && b;)
	{
		if (line != "date,exchange_rate")
		{
			first = line.substr(0, 10);
			second = line.substr(11, line.size());
			_data.insert(std::make_pair(first, second));	
		}
	}

	for (std::string line; std::getline(file, line) && !b;)
	{
		first = line.substr(0, 12);
		second = line.substr(12, line.size());
		_input.insert(std::make_pair(first, second));	
	}
}

void	BitcoinExchange::init(char *arg)
{
	std::ifstream	file;

	file.open(arg);
	if (!file.is_open())
		std::cout << "Error: parameter have to be a readable file" << std::endl;
	else
		this->fillMap(arg, false);

	
}

//for (std::map<std::string, std::string>::iterator it = _data.begin(); it != _data.end(); it++)
			//std::cout << it->first << " | " << it->second << std::endl;
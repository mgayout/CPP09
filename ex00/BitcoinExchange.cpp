/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:13:11 by mgayout           #+#    #+#             */
/*   Updated: 2024/10/14 08:58:48 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _err(0)
{
	std::ifstream	file("test/data.csv");
	std::string		line, date, value;

	if (!file.is_open())
	{
		std::cout << "Error: 'data.csv' not found" << std::endl;
		this->_err = 1;
		return;	
	}
	while (std::getline(file, line))
	{
		if (line == "date,exchange_rate" || !line.size())
			continue;
		if (line.size() >= 11)
		{
			date = line.substr(0, 10);
			value = line.substr(11, line.size() - 11);
		}
		if (line.size() >= 11 && this->checkDate(date) && this->checkValue(value, false) && line.find(',') == 10)
			this->_data.insert(std::make_pair(date, value));
	}
	if (!this->_data.size())
		this->_err = 1;
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _err(other._err)
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

int		BitcoinExchange::getErr()
{
	return this->_err;
}

int		BitcoinExchange::checkDate(std::string date)
{
	std::string	newDate = date;
	std::string	year, month, day;
	int			y, m, d;

	if (date[4] != '-' || date[7] != '-')
		return 0;
	newDate.erase(std::remove(newDate.begin(), newDate.end(), '-'), newDate.end());
	for (size_t i = 0; i != newDate.size(); i++)
		if (!std::isdigit(newDate[i]))
			return 0;
	year = newDate.substr(0, 4);
	month = newDate.substr(4, 2);
	day = newDate.substr(6, 2);
	y = std::atoi(year.c_str());
	m = std::atoi(month.c_str());
	d = std::atoi(day.c_str());
	if (!m || m > 12)
		return 0;
	if (m == 2)
	{
		if (y % 4 == 0 && (!d || d > 29))
			return 0;
		else if (y % 4 != 0 && (!d || d > 28))
			return 0;
	}
	else if (((m < 8 && m % 2 != 0) || (m > 7 && m % 2 == 0)) && (!d || d > 31))
		return 0;
	else if (((m < 8 && m % 2 == 0) || (m > 7 && m % 2 != 0)) && (!d || d > 30))
		return 0;
	return 1;
}

int		BitcoinExchange::checkValue(std::string value, bool b)
{

	std::string	newValue = value;;
	double		d;

	if (value.find('.'))
		newValue.erase(std::remove(newValue.begin(), newValue.end(), '.'), newValue.end());
	for (size_t i = 0; i != newValue.size(); i++)
		if (!std::isdigit(newValue[i]))
			return 0;
	if (b)
	{
		d = std::atof(value.c_str());
		if (d < 0 || d > 1000)
			return 0;
	}
	return 1;
}

void	BitcoinExchange::init(char *arg)
{
	std::ifstream	file(arg);
	std::string		line, date, value, split;
	bool			line1 = false;

	if (!file.is_open())
	{
		std::cout << "Error: file not found" << std::endl;
		return;	
	}
	while (std::getline(file, line))
	{
		if (!line.size())
			continue;
		if (!line1 && line == "date | value")
		{
			line1 = true;
			continue;
		}
		if (line.size() >= 13)
		{
			date = line.substr(0, 10);
			value = line.substr(13, line.size() - 13);
			split = line.substr(10, 3);
		}
		if (line.size() >= 13 && this->checkDate(date) && this->checkValue(value, true) && split == " | ")
			this->compare(date, value);
		else
			std::cout << "Error: bad format => " << line << std::endl;
	}
	file.close();
}

void	BitcoinExchange::compare(std::string date, std::string value)
{
	double	rate, vvalue;

	for (std::map<std::string, std::string>::iterator it = _data.begin(); it != _data.end(); it++)
	{
		rate = std::atof(it->second.c_str());
		vvalue = std::atof(value.c_str());
		if (it->first == date && rate == vvalue)
			this->find(date, rate, vvalue);
	}
}

void	BitcoinExchange::find(std::string date, double rate, double value)
{
	double result = rate * value;

	std::cout << date << " => " << std::fixed << std::setprecision(2) << result << std::endl;
}

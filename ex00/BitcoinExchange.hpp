/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:13:42 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/17 16:39:58 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
#include <limits>
#include <iomanip>
#include <cstdlib>
# include <fstream>
# include <string>
# include <map>


class BitcoinExchange
{
	private:
			const std::string				_file;
			int									_err;
			std::map<std::string, std::string>	_data;

	public:
			BitcoinExchange();
			BitcoinExchange(const BitcoinExchange& other);
			BitcoinExchange& operator=(const BitcoinExchange& other);
			~BitcoinExchange();
			
			int		getErr();

			int		checkDate(std::string date);
			int		checkValue(std::string value, bool b);
			void	init(char* arg);
			void	compare(std::string date, std::string value);
			void	find(std::string date, double rate, double value);

};


#endif
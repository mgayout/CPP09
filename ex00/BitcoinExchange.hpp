/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:13:42 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/16 15:24:39 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>


class BitcoinExchange
{
	private:
			const std::string				_file;
			const std::string				_error;
			std::map<std::string, std::string>	_data;
			std::map<std::string, std::string>	_input;

	public:
			BitcoinExchange();
			BitcoinExchange(const BitcoinExchange& other);
			BitcoinExchange& operator=(const BitcoinExchange& other);
			~BitcoinExchange();
			
			void	fillMap(char *arg, bool b);
			void	init(char* arg);
};


#endif
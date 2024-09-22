/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:12:48 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/19 11:45:02 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{	
	if (argc != 2)
	{
		std::cout << "Error: btc needs 1 parameter" << std::endl;
		return 1;
	}
	BitcoinExchange	*btc = new BitcoinExchange();

	if (btc->getErr())
		std::cout << "Error: bad data.csv file" << std::endl;
	else
		btc->init(argv[1]);

	delete btc;

	return 0;
}

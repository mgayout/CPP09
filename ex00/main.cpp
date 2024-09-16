/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:12:48 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/16 15:38:09 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{	
	BitcoinExchange	*btc = new BitcoinExchange();

	if (argc != 2)
		std::cout << "Error: btc needs 1 parameter" << std::endl;
	else
		btc->init(argv[1]);

	

	delete btc;

	return 0;
}

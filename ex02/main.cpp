/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:23:40 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/20 09:23:40 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: this program needs at least 1 parameter" << std::endl;
		return 1;
	}
	PmergeMe	*pm;

	if (argc == 2)
		pm = new PmergeMe(argv[1]);
	else
		pm = new PmergeMe(argc, argv);

	if (pm->getErr())
	{
		std::cout << "Error: bad format" << std::endl;
		delete pm;
		return 1;
	}

	pm->init();

	delete pm;

	return 0;
}

//shuf -i 0-100000 -n 1000 | tr '\n' ' '
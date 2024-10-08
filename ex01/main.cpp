/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:57:10 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/17 16:57:10 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: This program needs 1 parameter." << std::endl;
		return 1;
	}
	RPN	*rpn = new RPN(argv[1]);

	if (rpn->getErr())
	{
		std::cout << "Error: bad format" << std::endl;
		delete rpn;
		return 1;
	}
	rpn->init(argv[1]);

	delete rpn;

	return 0;
}

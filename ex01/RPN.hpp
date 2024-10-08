/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:57:38 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/17 16:57:38 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <limits>
# include <iomanip>
# include <cstdlib>
# include <string>
# include <stack>

class	RPN
{
	public:
			RPN(char *arg);
			RPN(const RPN& other);
			RPN& operator=(const RPN& other);
			~RPN();

			int		getErr();
			void	init(char *arg);

	private:
			std::stack<double>	calcul;
			int		_err;
};

#endif
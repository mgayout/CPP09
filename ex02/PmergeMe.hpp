/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:25:56 by mgayout           #+#    #+#             */
/*   Updated: 2024/09/20 09:25:56 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <limits>
# include <iomanip>
# include <cstdlib>
# include <string>
# include <vector>
# include <list>
# include <ctime>

class	PmergeMe
{
	public:
			PmergeMe(char *arg);
			PmergeMe(int argc, char **argv);
			PmergeMe(const PmergeMe& other);
			PmergeMe& operator=(const PmergeMe& other);
			~PmergeMe();

			int		getErr();
			void	insert(std::vector<std::string> vec);
			void	init();
			void	sortArr();
			void	sortLst();

	private:
			std::vector<int>	_arr;
			std::list<int>		_lst;
			int					_err;
			double				_time_arr;
			double				_time_lst;


};

#endif
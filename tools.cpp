/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 19:56:03 by aribeiro          #+#    #+#             */
/*   Updated: 2017/06/05 18:12:07 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lead.hpp"

long double string2num(const std::string & text)
{
	std::stringstream ss(text);
	long double result;
	return (ss >> result ? result : 0);
}

int			verif_value(int type, long double value)
{
	if (type != FLOAT && type != DOUBLE)
	{
		if (type == INT8 && value < INT8_MIN)
			return 14;
		if (type == INT8 && value > INT8_MAX)
			return 15;
		if (type == INT16 && value < INT16_MIN)
			return 14;
		if (type == INT16 && value > INT16_MAX)
			return 15;
		if (type == INT32 && value < INT32_MIN)
			return 14;
		if (type == INT32 && value > INT32_MAX)
			return 15;
	}
	//search underflow
	else if (type == FLOAT && value < -FLT_MAX)
		return 14;
	else if (type == DOUBLE && value < -DBL_MAX)
		return 14;
	//search overflow
	else if (type == FLOAT && value > FLT_MAX)
		return 15;
	else if (type == DOUBLE && value > DBL_MAX)
		return 15;

	return 7; // ok
}

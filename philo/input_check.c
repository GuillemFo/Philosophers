/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:08:14 by gforns-s          #+#    #+#             */
/*   Updated: 2024/04/15 17:16:01 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long			i;
	unsigned char	*str1;
	unsigned int	sign;
	unsigned int	result;

	result = 0;
	i = 0;
	sign = 1;
	str1 = (unsigned char *)str;
	while (str1[i] == ' ' || (str1[i] >= 9 && str1[i] <= 13))
		i++;
	if (str1[i] == '-')
		sign = -1;
	if (str1[i] == '-' || str1[i] == '+')
		i++;
	while (str1[i] >= 48 && str1[i] <= 57)
	{
		result = result * 10 + str1[i] - '0';
		i++;
	}
	return (result * sign);
}

bool	ft_isdigit(int val)
{
	if (val >= '0' && val <= '9')
		return (true);
	else
		return (false);
}

bool	is_ok_digit(char *s)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	if (!s)
		return (false);
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			return (false);
		i++;
	}
	if (s[i] == '\0')
		return (false);
	while (s[i])
	{
		result = result * 10 + s[i] - '0';
		i++;
	}
	if (result > INT_MAX)
		return (false);
	return (true);
}

bool	is_digit_str(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (false);
	if (s[i] == '+')
		i++;
	if (s[i] == '\0')
		return (false);
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	check_input_valid(char **av)
{
	if (is_digit_str(av[1]) == false || is_ok_digit(av[1]) == false)
		return (false);
	if (is_digit_str(av[2]) == false || is_ok_digit(av[2]) == false)
		return (false);
	if (is_digit_str(av[3]) == false || is_ok_digit(av[3]) == false)
		return (false);
	if (is_digit_str(av[4]) == false || is_ok_digit(av[4]) == false)
		return (false);
	if (av[5])
	{
		if (is_digit_str(av[5]) == false || is_ok_digit(av[5]) == false)
			return (false);
	}
	return (true);	
}

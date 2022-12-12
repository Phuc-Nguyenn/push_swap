/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_correct_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:17:30 by phunguye          #+#    #+#             */
/*   Updated: 2022/12/06 15:35:03 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_good_int(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '-' || av[i] == '+') && av[1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	is_nb_zero(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '-' || av[i] == '+') && av[1] != '\0')
		i++;
	while (av[i] == 0)
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	contains_duplicates(char **av)
{
	int	i;
	int	j;
	int	longer_list;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (ft_strlen(av[i]) > ft_strlen(av[j]))
				longer_list = ft_strlen(av[i]);
			else
				longer_list = ft_strlen(av[j]);
			if (j != i && ft_strncmp(av[i], av[j], longer_list) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	input_correct_check(char **av)
{
	int	i;
	int	nb_zeros;

	i = 1;
	nb_zeros = 0;
	while (av[i])
	{
		if (!is_good_int(av[i]))
			return (0);
		nb_zeros += is_nb_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (contains_duplicates(av))
		return (0);
	return (1);
}

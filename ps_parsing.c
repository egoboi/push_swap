/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:52:35 by fbrisson          #+#    #+#             */
/*   Updated: 2023/01/25 15:26:13 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_minimum(t_list **stack)
{
	t_list	*head;
	t_list	*minimum;
	int		has_minimum;

	minimum = NULL;
	has_minimum = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == 0) && ((!has_minimum) || (head->content < minimum->content)))
			{
				minimum = head;
				has_minimum = 1;
			}
			head = head->next;
		}
	}
	return (minimum);
}

void	ft_indexing_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_minimum(stack);
	while (head)
	{
		head->index = index++;
		head = get_minimum(stack);
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	long int	res;

	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		res = ((res * 10) + (str[i] - 48));
		i++;
	}
	return (res * sign);
}

t_list	*ft_master_parser(char **av)
{
	int		i;
	int		input;
	t_list	*list;

	list = NULL;
	i = 1;
	input = 0;
	while (av[i])
	{
		input = ft_atoi(av[i]);
		ft_lstadd_back(&list, ft_lstnew(input));
		i++;
	}
	if (!ft_check_duplicates(list))
		return (NULL);
	ft_indexing_stack(&list);
	return (list);
}

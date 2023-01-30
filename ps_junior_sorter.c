/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_junior_sorter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:26:24 by fbrisson          #+#    #+#             */
/*   Updated: 2023/01/26 10:01:20 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min(t_list **stack, int ref_value)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != ref_value)
			min = head->index;
	}
	return (min);
}

void	ft_sort_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = ft_get_min(stack_a, 0);
	next_min = ft_get_min(stack_a, min);
	if (head->index == min && head->next->index != next_min)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			swap_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
	else
	{
		if (head->next->index == min)
			rotate_a(stack_a);
		else
		{
			swap_a(stack_a);
			reverse_rotate_a(stack_a);
		}
	}
}

void	ft_sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = ft_get_distance(stack_a, 0);
	if (distance == 1)
		rotate_a(stack_a);
	else if (distance == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (distance == 3)
		reverse_rotate_a(stack_a);
	if (stack_is_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = ft_get_distance(stack_a, ft_get_min(stack_a, 0));
	if (distance == 1)
		rotate_a(stack_a);
	else if (distance == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (distance == 3)
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (distance == 4)
		reverse_rotate_a(stack_a);
	if (stack_is_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	ft_sort_4(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	ft_junior_sorter(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (stack_is_sorted(stack_a) || ft_list_size(*stack_a) == 0 \
		|| ft_list_size(*stack_a) == 1)
		return ;
	size = ft_list_size(*stack_a);
	if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		ft_sort_3(stack_a);
	else if (size == 4)
		ft_sort_4(stack_a, stack_b);
	else if (size == 5)
		ft_sort_5(stack_a, stack_b);
}

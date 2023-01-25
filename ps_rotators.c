/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotators.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:51 by fbrisson          #+#    #+#             */
/*   Updated: 2023/01/20 10:05:25 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	t_list	*last;

	if ((*stack_a == NULL) || ((*stack_a)->next == NULL))
		return ;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack_a;
	*stack_a = (*stack_a)->next;
	last->next->next = NULL;
	printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	t_list	*last;

	if ((*stack_b == NULL) || ((*stack_b)->next == NULL))
		return ;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack_b;
	*stack_b = (*stack_b)->next;
	last->next->next = NULL;
	printf("rb\n");
}

void	double_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	printf("rr\n");
}

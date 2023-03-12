/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:35:46 by spalta            #+#    #+#             */
/*   Updated: 2023/03/12 22:44:14 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack	*stack)
{
	int	tmp;

	tmp = stack->a->nbr;
	stack->a->nbr = stack->a->next->nbr;
	stack->a->next->nbr = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack	*stack)
{
	int	tmp;
	
	if (!stack->b)
		return ;
	if (p_lstsize(stack->b) >= 2)
	{
		tmp = stack->b->nbr;
		stack->b->nbr = stack->b->next->nbr;
		stack->b->next->nbr = tmp;
	}
	ft_printf("sb\n");
}

void	ss(t_stack	*stack)
{
	sa(stack);
	sb(stack);
	ft_printf("ss\n");
}

void	rra(t_stack	*stack, int i)
{
	t_data	*tmp;
	t_data	*tmp1;

	if (!stack->a || p_lstsize(stack->a) < 2)
		return;
	tmp = p_lstlast(stack->a);
	tmp1 = stack->a;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp1->next = NULL;
	p_lstadd_front(&stack->a, tmp);
	if (i)
		ft_printf("rra\n");
}

void	rrb(t_stack	*stack, int i)
{
	t_data	*tmp;
	t_data	*tmp1;
	
	if (!stack->b || p_lstsize(stack->b) < 2)
		return;
	tmp = p_lstlast(stack->b);
	tmp1 = stack->b;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp1->next = NULL;
	p_lstadd_front(&stack->b, tmp);
	if (i)
		ft_printf("rrb\n");
}

void	rrr(t_stack	*stack)
{
	rra(stack, 0);
	rrb(stack, 0);
	ft_printf("rrr\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:52:37 by spalta            #+#    #+#             */
/*   Updated: 2023/03/12 22:48:39 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_step(t_data *b)
{
	int	i;
	int	min;

	i = 0;
	min = b->total_step[i++];
	while (i < 4)
	{
		if (b->total_step[i] < min)
			min = b->total_step[i];
		i++;
	}
	b->min_step = min;
}

void	push_a(t_stack *stack, t_data *b)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < 4)
	{
		if (b->total_step[i] == b->min_step)
			break;
		i++;
	}
	
	if (i == 0)
	{
		tmp = abs(b->down - b->target->down);
		if (b->down > b->target->down)
			while (b->target->down--)
				rrr(stack);
		else
			while (b->down--)
				rrr(stack);
		if (b->down == 0 || b->down == -1)
			while(tmp--)
				rra(stack, 1);
		else
			while (tmp--)
				rrb(stack, 1);
		pa(stack);
	}
	if (i == 1)
	{
		tmp = abs(b->up - b->target->up);
		if (b->up > b->target->up)
			while (b->target->up--)
				rr(stack);
		else
			while (b->up--)
				rr(stack);
		if (b->up == 0 || b->up == -1)
			while(tmp--)
				ra(stack, 1);
		else
			while (tmp--)
				rb(stack, 1);
		pa(stack);
	}
	if (i == 2)
	{
		while (b->down--)
			rrb(stack, 1);
		while (b->target->up--)
			ra(stack, 1);
		pa(stack);
	}
	if (i == 3)
	{
		while (b->up--)
			rb(stack, 1);
		while (b->target->down--)
			rra(stack, 1);
		pa(stack);
	}
}

void	min_step_inx_b(t_stack *stack)
{
	t_data	*tmp;
	int		min_step;
	
	tmp = stack->b;
	min_step = tmp->min_step;
	while (tmp)
	{
		if (tmp->min_step < min_step)
			min_step = tmp->min_step;
		tmp = tmp->next;
	}
	tmp = stack->b;
	while (tmp)
	{
		if (tmp->min_step == min_step)
			break;
		tmp = tmp->next;
	}
	push_a(stack, tmp);
}

void	start_push(t_stack	*stack)
{
	min_step_inx_b(stack);
}

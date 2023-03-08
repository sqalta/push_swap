/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:01:37 by spalta            #+#    #+#             */
/*   Updated: 2023/03/08 15:23:10 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	cpy_stack_a(t_stack *stack) 
{
	t_data	*cpy_a = NULL;
	t_data	*n_lst;
	t_data	*tmp;

	tmp = stack->a;
	while (tmp)
	{
		n_lst = p_lstnew(tmp->nbr);
		p_lstadd_back(&cpy_a, n_lst);
		tmp = tmp->next;
	}
	stack->a_cpy = cpy_a;
}

void	inx_stacka(t_stack	*stack)
{
	t_data	*tmp1;
	t_data	*tmp2;
	int		inx;

	tmp1 = stack->a;
	tmp2 = stack->a_cpy;
	while (tmp1)
	{
		inx = 1;
		while (tmp2)
		{
			if (tmp1->nbr == tmp2->nbr)
			{
				tmp1->inx = inx;
				tmp2 = stack->a_cpy;
				break;
			}
			inx++;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	sort_stacka(t_stack	*stack)
{
	t_data	*tmp;
	t_data	*tmp1;
	int 	swap;
	
	cpy_stack_a(stack);
	tmp = stack->a_cpy;
	tmp1 = stack->a_cpy;
	while (stack->a_cpy->next)
	{
		if (stack->a_cpy->nbr > stack->a_cpy->next->nbr)
		{
			swap = stack->a_cpy->nbr;
			stack->a_cpy->nbr = stack->a_cpy->next->nbr;
			stack->a_cpy->next->nbr = swap;
			stack->a_cpy = tmp;
		}
		else
			stack->a_cpy = stack->a_cpy->next;
	}
	stack->a_cpy = tmp;
	inx_stacka(stack);
	print_list(stack->a);
}
// Adım 1 = stack_a'yı kopyalıyorum. 
// Adım 2 = kopyalanmış stack_a'yı sıralıyorum.
// Adım 3 = daha sonra stack_a'daki numarayı stack b'de kaçıncı sırada olduğuna bakıp indexliyorum.!
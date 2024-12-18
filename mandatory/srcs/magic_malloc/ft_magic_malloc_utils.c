/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic_malloc_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:18:58 by galambey          #+#    #+#             */
/*   Updated: 2024/04/01 16:42:36 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	del(void *content)
{
	free(content);
	content = NULL;
}

int	ft_check(void *data, void *data_ref)
{
	return (data == data_ref);
}

void	ft_list_remove(t_list **begin_list, t_list **lst, t_list **prev)
{
	if ((*lst)->next == NULL)
	{
		if ((*lst) == *begin_list)
			*begin_list = NULL;
		if (*prev)
			(*prev)->next = NULL;
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
	else if (*lst == *begin_list)
	{
		*begin_list = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = *begin_list;
	}
	else
	{
		(*prev)->next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = (*prev)->next;
	}
}

void	ft_list_remove_if(t_list **begin_list, void *p, int (*cmp)())
{
	t_list	*prev;
	t_list	*lst;

	lst = *begin_list;
	prev = NULL;
	while (lst)
	{
		if (cmp(lst->content, p))
		{
			ft_list_remove(begin_list, &lst, &prev);
			break ;
		}
		else
		{
			prev = lst;
			lst = lst->next;
		}
	}
}

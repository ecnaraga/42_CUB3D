/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:18:58 by galambey          #+#    #+#             */
/*   Updated: 2024/04/09 09:28:26 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_list	*ft_lstnew_malloc(size_t size)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (temp == NULL)
		return (NULL);
	temp->content = malloc(size);
	if (temp->content == NULL)
		return (free(temp), temp = NULL);
	temp->next = NULL;
	return (temp);
}

static t_list	*ft_lstnew_add(void *addr)
{
	t_list	*temp;

	if (!addr)
		return (NULL);
	temp = malloc(sizeof(t_list));
	if (temp == NULL)
		return (free(addr), addr = NULL);
	temp->content = addr;
	temp->next = NULL;
	return (temp);
}

static void	*ft_magic_add_mlc(t_list **mlc, int rule, void *p, int size)
{
	t_list	*head;
	t_list	*tmp;

	head = *mlc;
	if (rule == MLC)
		tmp = ft_lstnew_malloc(size);
	else
		tmp = ft_lstnew_add(p);
	if (!tmp)
		return (NULL);
	if (*mlc)
	{
		while ((*mlc)->next)
			(*mlc) = (*mlc)->next;
		(*mlc)->next = tmp;
		*mlc = head;
	}
	else
		*mlc = tmp;
	return (tmp->content);
}

/*
Garbagge collector : Store in a linked list all the address malloc
4 rules:
	- Malloc : MLC, adds the address to the linked list and returns the
		address of the malloc element.
	- Add : adds a malloc element to the linked list and returns it
	- Free : free a malloc element and remove it from the linked list
	- Flush : free all
rule : choice of the rule
size : if the rule asked is MLC, size of the element to malloc
addr : if the rule is add or free, address of the elemnt sent

If error malloc, return NULL
*/
void	*mcgic(void *p, size_t size, int rule)
{
	static t_list	*mlc;

	if (!p && rule == ADD)
		return (NULL);
	if (!p && rule == FREE)
		return (NULL);
	if (rule == MLC || rule == ADD)
		return (ft_magic_add_mlc(&mlc, rule, p, size));
	else if (rule == FREE)
		ft_list_remove_if(&mlc, p, ft_check);
	else
		ft_lstclear(&mlc, del);
	return (NULL);
}

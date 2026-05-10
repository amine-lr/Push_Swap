/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:57:10 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 19:57:10 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

/*void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->content = malloc(10); 
	node->next = NULL;

	ft_lstdelone(node, del);
	printf("Done! Node and content freed.\n");
	return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:10:24 by molariou          #+#    #+#             */
/*   Updated: 2026/04/25 14:17:06 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	if (!content)
		return (NULL);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*int main()
{
    t_list *new_elem = ft_lstnew(NULL);

	if (!new_elem)
		printf("Failed to create node with NULL content.\n");
	else
		printf("Node created with NULL content, which is unexpected.\n");
    if (new_elem)
        printf("node created.\n");
    return 0;
}*/

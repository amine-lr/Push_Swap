/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:10:09 by molariou          #+#    #+#             */
/*   Updated: 2026/04/25 13:10:09 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*int main(void)
{
	t_list *node1 = ft_lstnew("First");
	t_list *node2 = ft_lstnew("Second");
	t_list *node3 = ft_lstnew("Last One");
	t_list *last;

	// Build the list: node1 -> node2 -> node3
	node1->next = node2;
	node2->next = node3;

	// Test 1: Find the last node
	last = ft_lstlast(node1);
	printf("Last node content: %s\n", (char *)last->content);

	// Test 2: Single node list
	last = ft_lstlast(node3);
	printf("Single node test: %s\n", (char *)last->content);

	// Test 3: Empty list
	last = ft_lstlast(NULL);
	if (last == NULL)
		printf("Empty list handled correctly ✓\n");

	return (0);
}*/
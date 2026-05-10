/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:10:12 by molariou          #+#    #+#             */
/*   Updated: 2026/04/25 13:10:12 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*#include <ctype.h>
// Example function to map: makes string uppercase
void	*map_toupper(void *content)
{
	char	*str = ft_strdup((char *)content);
	int		i = 0;
	if (!str) return (NULL);
	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
	return (str);
}

void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *list = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("world")));

	t_list *new_list = ft_lstmap(list, map_toupper, del_content);

	t_list *tmp = new_list;
	while (tmp)
	{
		printf("%s ", (char *)tmp->content); // Should print HELLO WORLD
		tmp = tmp->next;
	}
	
	ft_lstclear(&list, del_content);
	ft_lstclear(&new_list, del_content);
	return (0);
}*/
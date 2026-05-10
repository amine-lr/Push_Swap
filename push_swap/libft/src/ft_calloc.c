/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:23:23 by molariou          #+#    #+#             */
/*   Updated: 2026/04/27 22:14:57 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
/*int main(void)
{
    size_t num = 4;
    int    *my_arr;
    int    *real_arr;
    size_t i;

    my_arr = ft_calloc(num, sizeof(int));
    real_arr = calloc(num, sizeof(int));

    if (!my_arr || !real_arr)
        return (1);

    printf("ft_calloc: ");
    for (i = 0; i < num; i++)
        printf("[%d] ", my_arr[i]); // Should all be 0

    printf("\nreal_calloc: ");
    for (i = 0; i < num; i++)
        printf("[%d] ", real_arr[i]); // Should all be 0
    printf("\n");

    free(my_arr);
    free(real_arr);
    return (0);
}*/
/*#include <stdint.h> // For SIZE_MAX

int main(void)
{
    void *ptr;

    printf("--- Testing ft_calloc Edge Cases ---\n");

    // Test 1: Zero nmemb or Zero size
    // Standard calloc returns either NULL or a unique pointer you can free.
    ptr = ft_calloc(0, 10);
    printf("1. ft_calloc(0, 10): %p\n", ptr);
    free(ptr);

    // Test 2: Potential Overflow
    // This should return NULL because the total exceeds size_t
    ptr = ft_calloc(SIZE_MAX, 2);
    if (ptr == NULL)
        printf("2. Overflow check: PASSED (Returned NULL)\n");
    else
    {
        printf("2. Overflow check: FAILED (Allocated memory incorrectly)\n");
        free(ptr);
    }

    // Test 3: Standard NULL failure test
    // We can't easily force malloc to fail, but we can try to allocate 
    // an impossible amount of memory.
    ptr = ft_calloc(1, (size_t)-1); // Max possible size_t
    if (ptr == NULL)
        printf("3. Impossible allocation: PASSED (Returned NULL)\n");
    else
        free(ptr);

    return (0);
}*/
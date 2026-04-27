/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:57:53 by soel-had          #+#    #+#             */
/*   Updated: 2025/11/05 18:31:01 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (!big || !little)
		return (NULL);
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	j = 0;
	while (big[j] && j + little_len <= len)
	{
		i = 0;
		while (j + i < len && big[j + i] == little[i])
		{
			i++;
			if (i == little_len)
				return ((char *)(big + j));
		}
		j++;
	}
	return (NULL);
}

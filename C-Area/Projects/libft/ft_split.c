/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:54:22 by soel-had          #+#    #+#             */
/*   Updated: 2026/01/02 09:28:19 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_length(const char *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[i + len] && s[i + len] != c)
		len++;
	return (len);
}

static size_t	number_of_words(const char *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (counter);
}

static void	*free_split(char **str, size_t j)
{
	while (j > 0)
	{
		j--;
		free(str[j]);
	}
	free(str);
	return (NULL);
}

static char	*fill_word(const char *s, char c, size_t *i)
{
	size_t	len;
	size_t	j;
	char	*word;

	len = word_length(s, c, *i);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
		word[j++] = s[(*i)++];
	word[j] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	words;

	if (!s)
		return (NULL);
	words = number_of_words(s, c);
	str = malloc((words + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		str[j] = fill_word(s, c, &i);
		if (!str[j])
			return (free_split(str, j));
		j++;
	}
	str[j] = NULL;
	return (str);
}

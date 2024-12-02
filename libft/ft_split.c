/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:14:48 by saylital          #+#    #+#             */
/*   Updated: 2024/07/19 11:52:10 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *string, char delimiter)
{
	size_t	count_words;

	count_words = 0;
	while (*string != '\0')
	{
		while (*string == delimiter && *string != '\0')
			string++;
		if (*string != '\0')
			count_words++;
		while (*string != '\0' && *string != delimiter)
			string++;
	}
	return (count_words);
}

static void	free_arrays(char **words, size_t n)
{
	while (n > 0)
	{
		n--;
		free(words[n]);
	}
	free(words);
}

static char	**word_splitter(char const *s, char **ptrarray, char c)
{
	size_t		i;
	size_t		len;
	char const	*word;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			break ;
		word = s;
		while (*s != '\0' && *s != c)
			s++;
		len = s - word;
		ptrarray[i] = ft_substr(word, 0, len);
		if (ptrarray[i] == NULL)
		{
			free_arrays(ptrarray, i);
			return (NULL);
		}
		i++;
	}
	ptrarray[i] = NULL;
	return (ptrarray);
}

char	**ft_split(char const *s, char c)
{
	size_t		total_words;
	char		**word_array;

	if (!s)
		return (NULL);
	total_words = word_counter(s, c);
	word_array = malloc((total_words + 1) * sizeof(char *));
	if (word_array == NULL)
		return (NULL);
	word_array = word_splitter(s, word_array, c);
	return (word_array);
}

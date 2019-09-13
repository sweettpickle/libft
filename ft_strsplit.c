/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:37:34 by cdoreah           #+#    #+#             */
/*   Updated: 2019/09/13 22:36:19 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words(char const *str, char c)
{
	int			i;

	i = 0;
	while (*str)
	{
		if ((*str != c && *(str + 1) == c)
		|| ((*str) != c && *(str + 1) == '\0'))
			i++;
		str++;
	}
	return (i);
}

static char		*skip_c(char const *str, char c)
{
	while (*str == c && *str)
		str++;
	return ((char *)str);
}

static int		len_w(const char *str, char c)
{
	size_t		i;

	i = 0;
	while (*str != c && *str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

static void		ft_clear(char **mas, size_t i)
{
	while (i--)
		free(mas[i]);
	free(mas);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**mas;
	size_t		w;
	size_t		i;

	if (!s)
		return (NULL);
	w = words(s, c);
	if ((!(mas = (char **)malloc(sizeof(char *) * (w + 1)))) || (w > w + 1))
		return (NULL);
	i = 0;
	while (i < w)
	{
		s = skip_c(s, c);
		if (!(mas[i] = ft_strnew(len_w(s, c))))
		{
			ft_clear(mas, i);
			return (NULL);
		}
		ft_strncpy(mas[i++], s, len_w(s, c));
		s += len_w(s, c);
	}
	mas[i] = NULL;
	return (mas);
}

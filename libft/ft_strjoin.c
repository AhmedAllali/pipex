/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 04:57:04 by ahallali          #+#    #+#             */
/*   Updated: 2023/01/04 18:13:05 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sz_s1;
	size_t	sz_s2;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	if (!s2)
		return ((char *)s1);
	sz_s1 = ft_strlen(s1);
	sz_s2 = ft_strlen(s2);
	ptr = (char *)malloc((sz_s1 + sz_s2 + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, sz_s1 + 1);
	ft_strlcat(ptr, s2, (sz_s1 + sz_s2 +1));
	return (ptr);
}

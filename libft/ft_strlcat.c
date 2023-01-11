/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:02:24 by ahallali          #+#    #+#             */
/*   Updated: 2023/01/05 09:19:41 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	sz_d;
	size_t	sz_s;

	i = 0;
	sz_s = ft_strlen(src);
	if (dstsize == 0)
		return (sz_s + dstsize);
	sz_d = ft_strlen (dst);
	if (sz_d > dstsize)
		return (sz_s + dstsize);
	while (src[i] != 0 && i + sz_d < dstsize - 1)
	{
		dst[sz_d + i] = src[i];
		i++;
	}
	dst[sz_d + i] = 0;
	return (sz_d + sz_s);
}

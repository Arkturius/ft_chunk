/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgramati <rgramati@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:51:12 by rgramati          #+#    #+#             */
/*   Updated: 2024/09/23 20:43:22 by rgramati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include <ft_chunk.h>

int	main(void)
{
	t_chunk		*floats;
	float		tmp;
	uint32_t	i;

	floats = ft_chunk_init("floats", sizeof(float));
	i = 0;
	while (i < 1024)
	{
		tmp = 3.14 * i;
		if (!ft_chunk_push(floats, &tmp, sizeof(tmp)))
			break ;
		i++;
	}
	ft_chunk_clear(floats, FT_CHUNK_FREE);
}

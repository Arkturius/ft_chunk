// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   accessors.c                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rgramati <rgramati@student.42angouleme.fr  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/09/27 01:42:35 by rgramati          #+#    #+#             //
//   Updated: 2024/09/27 02:06:38 by rgramati         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <unistd.h>

#include <ft_chunk.h>

void	*ft_chunk_at(t_chunk *chunk, uint32_t index)
{
	return (&chunk->data[index * chunk->alignment]);
}

void	*ft_chunk_it_next(t_chunk *chunk)
{
	if (chunk->iterator.it == NULL)
		chunk->iterator.it = chunk->iterator.start;
	else
	{
		chunk->iterator.it += chunk->alignment;
		chunk->iterator.index++;
		if (chunk->iterator.it > chunk->iterator.end)
		{
			chunk->iterator.it = NULL;
			chunk->iterator.index = 0;
		}
	}
	return (chunk->iterator.it);
}

void	*ft_chunk_it_prev(t_chunk *chunk)
{
	chunk->iterator.it -= chunk->alignment;
	chunk->iterator.index--;
	if (chunk->iterator.it < chunk->iterator.start)
	{
		chunk->iterator.it = NULL;
		chunk->iterator.index = 0;
	}
	return (chunk->iterator.it);
}

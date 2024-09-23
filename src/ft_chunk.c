/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgramati <rgramati@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:44:58 by rgramati          #+#    #+#             */
/*   Updated: 2024/09/23 20:23:11 by rgramati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

#include <ft_chunk.h>

t_chunk	*ft_chunk_init(const char *name, uint32_t elem_size)
{
	t_chunk		*chunk;
	uint32_t	offset;

	chunk = malloc(sizeof(*chunk));
	if (chunk && name)
	{
		offset = ft_twos_power_raise(elem_size);
		chunk->capacity = FT_CHUNK_DATA_CAP / offset;
		chunk->alignment = offset;
		chunk->elem_size = elem_size + !elem_size;
		chunk->size = 0;
		ft_memcopy(chunk->name, (void *)name, ft_min(ft_strsize(name), 15));
		ft_memzero(chunk->data, FT_CHUNK_DATA_CAP);
		if (!chunk->alignment || !chunk->capacity)
		{
			free(chunk);
			chunk = NULL;
		}
	}
	return (chunk);
}

void	ft_chunk_clear(t_chunk *chunk, uint32_t flags)
{
	uint32_t	param;
	void		*ptr;

	param = flags & 0xFF;
	flags &= ~(0xFF);
	if (!chunk)
		return ;
	if (flags & FT_CHUNK_WIPE)
	{
		chunk->size -= param;
		ptr = (void *)(&chunk->data + chunk->alignment * (chunk->size - 1));
		ft_memzero(ptr, param * chunk->alignment);
	}
	if (flags & FT_CHUNK_NULL)
		ft_memzero(chunk, 32);
	if (flags & FT_CHUNK_FREE)
		free(chunk);
}

void	*ft_chunk_alloc(t_chunk *chunk)
{
	void	*ptr;

	ptr = NULL;
	if (chunk)
	{
		if (chunk->size >= chunk->capacity)
			return (ptr);
		ptr = (void *)(&chunk->data + chunk->alignment * chunk->size);
		chunk->size++;
	}
	return (ptr);
}

void	*ft_chunk_push(t_chunk *chunk, void *elem, uint32_t elem_size)
{
	void	*ptr;

	ptr = NULL;
	if (chunk && elem)
	{
		if (elem_size != chunk->elem_size)
			return (ptr);
		if (chunk->size >= chunk->capacity)
			return (ptr);
		ptr = (void *)(&chunk->data) + chunk->alignment * chunk->size;
		chunk->size++;
		ft_memcopy(ptr, elem, elem_size);
	}
	return (ptr);
}

void	*ft_chunk_pop(t_chunk *chunk, void *elem)
{
	void	*ptr;

	ptr = NULL;
	if (chunk && elem)
	{
		if (chunk->size == 0)
			return (ptr);
		chunk->size--;
		ptr = (void *)(&chunk->data + chunk->alignment * chunk->size);
		ft_memcopy(elem, ptr, chunk->elem_size);
	}
	return (elem);
}

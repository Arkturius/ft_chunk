/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgramati <rgramati@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:45:12 by rgramati          #+#    #+#             */
/*   Updated: 2024/09/23 20:38:12 by rgramati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHUNK_H
# define FT_CHUNK_H

# include <stdint.h>

/* ************************************************************************** */

# define FT_CHUNK_DATA_CAP	4032

typedef struct s_chunk_iter
{
	void		*it;
	void		*start;
	void		*end;
	uint32_t	index;
}	t_chunk_iter;

/**
 * @struct	s_chunk		Describes a memory chunk
 *
 * @uint32_t	(capacity)	Maximum capacity of the chunk.
 * @uint32_t	(size)		Actual size of the chunk.
 * @uint32_t	(alignment)	Alignment factor of the concerned data.
 * @uint32_t	(elem_size)	Element size.
 */
typedef struct s_chunk
{
	uint32_t		capacity;
	uint32_t		size;
	uint32_t		alignment;
	uint32_t		elem_size;
	char			name[8];
	t_chunk_iter	iterator;
	struct s_chunk	*next;
	uint8_t			data[FT_CHUNK_DATA_CAP];
}	t_chunk;

/**
 * @enum	e_chunk_flags
 *
 * 	FT_CHUNK_ZERO : clear chunk data space.
 *	FT_CHUNK_NULL : reset chunk settings.
 *	FT_CHUNK_FREE : frees the chunk.
 *					is also FT_CHUNK_ZERO | FT_CHUNK_NULL
 *	FT_CHUNK_WIPE : erase values from the chunk.
 *					can be ORed with a number of values to
 *					erase multiple values.
 */
enum	e_chunk_flags
{
	FT_CHUNK_ZERO = 1 << 8,
	FT_CHUNK_NULL = 1 << 9,
	FT_CHUNK_WIPE = 1 << 10,
	FT_CHUNK_FREE = FT_CHUNK_ZERO | FT_CHUNK_NULL | 1 << 11
};

/**
 * @brief	Init a memory chunk.
 *
 * @param		(name)		A name for the memory chunk (15 chars max).
 * @param		(elem_size)	Element size, pass sizeof(elem) to setup correctly.
 *
 * @returns	A pointer to a memory chunk.
 */
t_chunk
*ft_chunk_init(const char *name, uint32_t elem_size);

/**
 * @brief	Perform clear operations on a memory chunk.
 *
 * @param		(chunk)		Chunk pointer.
 * @param		(flags)		Combination of e_chunk_flags.
 */
void
ft_chunk_clear(t_chunk *chunk, uint32_t flags);

/**
 * @brief	Get the element at a certain index on a memory chunk.
 *
 * @param		(chunk)		Chunk pointer.
 * @param		(index)		The index.
 *
 * @returns	A pointer to this element (depending on chunk alignment);
 */
void
*ft_chunk_at(t_chunk *chunk, uint32_t index);

/**
 * @brief	Allocate space on a memory chunk for a new element.
 *
 * @param		(chunk)		Chunk pointer.
 *
 * @returns	A pointer to the allocated space.
 */
void
*ft_chunk_alloc(t_chunk *chunk);

/**
 * @brief	Pushes an element on a memory chunk.
 *
 * @param		(chunk)		Chunk pointer.
 * @param		(elem)		Opaque pointer to source data.
 * @param		(elem_size)	Element size of source.
 *
 * @note	A safe way to use this is by passing both the adress and the size
 *			of a static object.
 *			ft_chunk_push(example_chunk, &object, sizeof(object));
 *
 * @returns A pointer to the pushed element.
 */
void
*ft_chunk_push(t_chunk *chunk, void *elem, uint32_t elem_size);

/**
 * @brief	Pops an element from a memory chunk.
 *
 * @param		(chunk)		Chunk pointer.
 * @param		(elem)		Opaque pointer to store the popped data.
 *							Can be NULL if you dont need to save this.
 *
 * @returns	Destination pointer, so elem.
 */
void
*ft_chunk_pop(t_chunk *chunk, void *elem);

/**
 *
 */
void
*ft_chunk_it_next(t_chunk *chunk);

/* * UTILS ****************************************************************** */

// Raises to the next power of 2
uint32_t
ft_twos_power_raise(uint32_t x);

// Min function
uint32_t
ft_min(uint32_t a, uint32_t b);

// ft_strlen clone
uint32_t
ft_strsize(const char *str);

// ft_bzero clone
void
ft_memzero(void *ptr, uint32_t n);

// ft_memcpy clone
void
ft_memcopy(void *dst, void *src, uint32_t n);

/* ************************************************************************** */

#endif

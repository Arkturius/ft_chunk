# ft_chunk (v 0.2)

Small library implementation of memory chunks.

- Init and destroy.
- Push, Pop and Flexible Alloc.
- (WIP) Iterators.

## Usage
```bash
$ make # :)

$ cc your_code.c ft_chunk.a -o your_code
```

## Example
Init a chunk of floats and fill them with multiples of PI

```c
#include <stdint.h>
#include <stdio.h>

#include <ft_chunk.h>

int	main(void)
{
	t_chunk		*floats;
	float		tmp;
	uint32_t	i;

	printf("size of iterator is : %zu\n", sizeof(t_chunk_iter));
	printf("size of chunk is : %zu\n", sizeof(t_chunk));

	floats = ft_chunk_init("floats", sizeof(float));
	i = 0;
	while (i < 1024)
	{
		tmp = 3.14 * i;
		if (!ft_chunk_push(floats, &tmp, sizeof(tmp)))
			break ;
		i++;
	}

// Still implementing iterators

	// void	*ptr;
	//
	// ptr = ft_chunk_it_next(floats);
	// while (ptr)
	// {
	// 	printf("ptr = %p |  value = %f\n", ptr, *(float *)ptr);
	// 	ptr = ft_chunk_it_next(floats);
	// }
	//
	// ptr = ft_chunk_it_next(floats);
	// while (ptr)
	// {
	// 	printf("ptr = %p |  value = %f\n", ptr, *(float *)ptr);
	// 	ptr = ft_chunk_it_next(floats);
	// }

	ft_chunk_clear(floats, FT_CHUNK_FREE);
}
```

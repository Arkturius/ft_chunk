# ft_chunk (v 0.1)

Small library implementation of memory chunks.

## Usage
```bash
$ make # :)

$ cc your_code.c ft_chunk.a -o your_code
```

## Example
Init a chunk of floats and fill them with multiples of PI

```c
#include <stdint.h>

#include <ft_chunk.h>

int	main(void)
{
	t_chunk		*floats;
	float		tmp;
	uint32_t	i;

	floats = ft_chunk_init("floats", sizeof(float));
	i = 0;
	while (i < floats->capacity)
	{
		tmp = 3.14 * i;
		if (!ft_chunk_push(floats, &tmp, sizeof(tmp)))
			break ;
		i++;
	}
	ft_chunk_clear(floats, FT_CHUNK_FREE);
}
```

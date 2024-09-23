# ft_chunk (v 0.1)

Small library implementation of memory chunks.

## Usage
```bash
$ make # :)
```
Then compile with ft_chunk.a

## Example
Init a chunk of vectors

```c
#include <stdint.h>

#include <ft_chunk.h>

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec;

int main(void)
{
	t_chunk		*vecs;
	t_vec		tmp;
	uint32_t	i;

	vecs = ft_chunk_init("vectors", sizeof(t_vec));
	i = 0;
	while (i < 1024)
	{	
		tmp = (t_vec){0, 0, 0 ,0};
		if (!ft_chunk_push(vecs, &tmp, sizeof(tmp)))
			break ;
		i++;
	}
}
```

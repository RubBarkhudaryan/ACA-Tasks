#include <stdio.h>
#include <stdalign.h>

/*12 bytes, align 4 bytes*/
typedef struct s_list
{
	int		i1;		// 4 bytes
	char	c1;		// 1 byte + 3 bytes padding = 4 bytes
	int		i2;		// 4 bytes
}	t_list;

/*
	4 + 1 + 3 (padding) + 4 = 12
	12 % 4(alignment) == 0 nothing to add
*/

/*32 bytes, align 8 bytes*/
typedef struct s_struct
{
	int		i1;		// 4 bytes	-> align 4 bytes
	t_list	lst1;	// 12 bytes	-> align 4 bytes
	t_list	*lst2;	// 8 bytes	-> align 8 bytes -> this is bigger align so everything is computed by this value
	int		i2;		// 4 bytes	-> align 4 bytes
}	t_struct;

/*
	4 + 12 + 8 + 4 = 28 bytes
	28 % 8(alignment) != 0 so we add extra 4 bytes 28 + 4 = 32
	32 % 8 == 0
*/

int	main(void)
{
	printf("sizeof(t_list)   = %zu, align = %zu\n", sizeof(t_list), alignof(t_list));
	printf("sizeof(t_struct)  = %zu, align = %zu\n", sizeof(t_struct), alignof(t_struct));
	return (0);
}

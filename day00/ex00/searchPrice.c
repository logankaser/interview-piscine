#include <string.h>
#include "header.h"

int	searchPrice(struct s_art **arts, char* name)
{
	for (unsigned i = 0; arts[i]; ++i)
	{
		if (strcmp(name, arts[i]->name) == 0)
			return arts[i]->price;
	}
	return -1;
}

#include "ft_printf.h"

size_t ft_strlen(const char *s) 
{
    const char *start; 

    start = s; 
    while (*s++) 
        ;
    return (s - start - 1); 
}

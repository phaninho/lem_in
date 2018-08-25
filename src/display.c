#include "lem_in.h"

void	display(t_room *begin)
{
    ft_putchar('L');
    ft_putnbr(begin->fourmiz_nb);
    ft_putchar('-');
    ft_putnbr(begin->room_num);
    ft_putchar(' ');
}

int     jump_line(t_room *begin, t_env *e)
{
    ft_putchar('\n');
    if (begin->fourmiz_nb == 0 && begin->tube == e->end)
        return (1);
    return (0);
}

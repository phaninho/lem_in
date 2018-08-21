#include "lem_in.h"

void	display(t_room *begin)
{
    ft_putchar('L');
    ft_putnbr(begin->fourmiz_nb);
    ft_putchar('-');
    ft_putnbr(begin->room_num);
    ft_putchar(' ');
}

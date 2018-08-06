#include "lem_in.h"

int check_error(t_env *e)
{
    if (e->start == -1)
    {
        ft_putendl("Error, no start point");
        return (1);
    }
    else if (e->end == -1)
    {
        ft_putendl("Error, no end point");
        return (2);
    }
    else if (e->fourmiz == 0)
    {
        ft_putendl("Error, no fourmiz");
        return (3);
    }
    else if (e->r->room_num == -1)
    {
        ft_putendl("Error, no room connections");
        return (4);
    }
    return (0);
}

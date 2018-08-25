#include "lem_in.h"

void	make_fourmiz_advance(t_env *e, int i)
{
    t_room      *begin;

    while (i >= 0)
    {
        begin = e->r;
        while (begin->room_num != e->short_way[i])
            begin = begin->next;
        if (!begin->free)
        {
            begin->free = 1;
            begin->fourmiz_nb = 1;
        }
        else if (begin->fourmiz_nb < e->fourmiz)
            begin->fourmiz_nb++;
        else
        {
            begin->fourmiz_nb = 0;
            begin->free = 0;
        }
        if (begin->fourmiz_nb)
            display(begin);
        i--;
    }
    ft_putchar('\n');
}

int     fourmiz_on_field(t_env *e)
{
    t_room      *begin;

    begin = e->r;
    while (begin)
    {
        if (begin->free)
            return (1);
        begin = begin->next;
    }
    return (0);
}

int 	advance_last_fourmiz(t_env *e, int i)
{
    t_room      *begin;

    while (i >= 0)
    {
        begin = e->r;
        while (begin->room_num != e->short_way[i])
            begin = begin->next;
        if (begin->fourmiz_nb < e->fourmiz && begin->fourmiz_nb)
            begin->fourmiz_nb++;
        else
        {
            begin->fourmiz_nb = 0;
            begin->free = 0;
        }
        if (begin->fourmiz_nb)
            display(begin);
        else
            break;
        i--;
    }
    // if (begin->fourmiz_nb == 0 && begin->tube == e->end)
    //    return (1);
    // else if (begin->fourmiz_nb != e->fourmiz || begin->room_num != e->end)
    //     ft_putchar('\n');
    return (jump_line(begin, e));
}

void	send_fourmiz(t_env *e)
{
    int         fourmiz_counter;
    int         i;

    i = 0;
    fourmiz_counter = 1;
    while (fourmiz_counter <= e->fourmiz || i < e->short_lenght)
    {
        if (i == e->short_lenght)
            break;
        make_fourmiz_advance(e, i);
        if (fourmiz_counter <= e->fourmiz)
            fourmiz_counter++;
        if (i < e->short_lenght)
            i++;
    }
    while (fourmiz_on_field(e))
    {
        if (advance_last_fourmiz(e, i - 1))
            break;
    }
}

int     path_loader(t_env *e, t_room *begin, int i)
{
    while (e->short_way[i] != e->end)
    {
        if (e->short_way[i - 1] == begin->room_num)
        {
            if (check_loop(e->short_way, begin->tube, i))
                return (1);
            e->short_way[i] = begin->tube;
            e->short_lenght++;
            if (begin->room_num != e->end)
                i++;
            else
                break;
            begin = e->r;
        }
        else if (begin->next)
            begin = begin->next;
        else
            break;
    }
    if (e->short_way[i - 1] != e->end && !begin->next)
        return (way_error());
    return (0);
}

bool    path_finder(t_env *e)
{
    int i;

    i = 0;
    e->short_way = ft_memalloc(e->max_room);
    e->short_way[e->max_room + 1] = -1;
    e->short_way[i] = e->start;
    if (path_loader(e, e->r, 1))
        return (1);
    send_fourmiz(e);
    return (0);
}

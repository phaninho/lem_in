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

void	advance_last_fourmiz(t_env *e, int i)
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
    if (begin->fourmiz_nb != e->fourmiz && begin->room_num != e->end)
        ft_putchar('\n');
}

void	send_fourmiz(t_env *e)
{
    int         fourmiz_counter;
    int         i;

    i = 0;
    fourmiz_counter = 1;
    while (fourmiz_counter <= e->fourmiz || e->short_way[i] != -1)
    {
        //------------> TODO <--------------
        make_fourmiz_advance(e, i);
        if (fourmiz_counter <= e->fourmiz)
            fourmiz_counter++;
        if (e->short_way[i] != -1)
            i++;
        // ------------> TODO <-------------
    }
    while (fourmiz_on_field(e))
        advance_last_fourmiz(e, i - 1);
}

void	path_loader(t_env *e, t_room *begin, int i)
{
    while (e->short_way[i] != e->end)
    {
        if (e->short_way[i - 1] == begin->room_num)
        {
            printf("entre dans room %d link to %d\n", begin->room_num, begin->tube);
            e->short_way[i] = begin->tube;
            begin = e->r;
            i++;
        }
        else if (begin->next)
            begin = begin->next;
        else
            break;
    }
}

bool    path_finder(t_env *e)
{
    int i;

    i = 0;
    e->short_way = ft_memalloc(e->max_room);
    e->short_way[e->max_room + 1] = -1;
    e->short_way[i] = e->start;
    path_loader(e, e->r, 1);
    // Debug
    // t_room  *begin;
    // begin = e->r;
    //
    // while (begin)
    // {
    //     printf("room %d\n", begin->room_num);
    //     begin = begin->next;
    // }
    // while (e->short_way[i] != -1)
    // {
    //     printf("in %d room n = %d\n",i,  e->short_way[i]);
    //     i++;
    // }
    send_fourmiz(e);
    //
    return (0);
}

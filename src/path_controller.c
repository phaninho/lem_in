#include "lem_in.h"

void	make_fourmiz_advance(t_env *e, int fourmiz_counter, int i)
{
    t_room      *begin;

    begin = e->r;
    while (begin->room_num != e->short_way[i])
        begin = begin->next;
    printf("dans M A F %d pour %d max %d\n", begin->room_num, e->short_way[i], e->max_room);
    if (fourmiz_counter == e->fourmiz)
        printf("dans M A F %d pour %d max %d\n", e->end, e->short_way[i], e->max_room);
}

void	send_fourmiz(t_env *e)
{
    int         fourmiz_counter;
    int         i;
    // int     next_room_avaible;
    // t_room  *begin;

    i = 0;
    fourmiz_counter = 1;
    // next_room_avaible = 0;
    while (fourmiz_counter <= e->fourmiz)
    {
        //------------> TODO <--------------
        make_fourmiz_advance(e, fourmiz_counter, i);
        // begin = e->r;
        // while (begin)
        // {
        // //     if (begin->room_num == e->short_way[i] && !begin->free)
        // //     {
        // //         begin->fourmiz_nb = fourmiz_counter;
        // //         begin->free = 1;
        // //         break;
        // //     }
            // begin = begin->next;
        // }
        // printf("fourmiz_counter => %d\n", fourmiz_counter);
        // if (begin->room_num == e->start && !begin->free)
            fourmiz_counter++;
            i++;
        // begin = begin->next;

        // ------------> TODO <-------------
    }
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
    t_room  *begin;
    int i;

    i = 0;
    e->short_way = ft_memalloc(e->max_room);
    e->short_way[e->max_room + 1] = -1;
    begin = e->r;
    e->short_way[i] = e->start;
    path_loader(e, begin, 1);
    // Debug
    // while (e->short_way[i] != -1)
    // {
    //     printf("in %d room n = %d\n",i,  e->short_way[i]);
    //     i++;
    // }
    send_fourmiz(e);
    //
    return (0);
}

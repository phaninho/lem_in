#include "lem_in.h"


void	init_env(t_env *e)
{
        e->fourmiz = 0;
        e->short_lenght = 0;
        e->count_line = 0;
        e->start = -1;
        e->end = -1;
        e->max_room = 0;
        e->short_way = NULL;
        e->line = NULL;
        e->r->room_num = -1;
        e->r->tube = -1;
        e->r->fourmiz_nb = -1;
        e->r->free = 0;
        e->r->next = NULL;
}

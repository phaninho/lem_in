#include "lem_in.h"


int      find_start(char * coord, t_env *e)
{
    char *c;

    if (!(c = (char *)malloc(sizeof(char) * (coord - e->line + 1))))
        return (0);
    ft_strncpy(c, coord - 1, coord - e->line);
    e->start = ft_atoi(c);
    return (1);
}

int      find_end(char * coord, t_env *e)
{
    char *c;

    if (!(c = (char *)malloc(sizeof(char) * (coord - e->line + 1))))
        return (0);
    ft_strncpy(c, coord - 1, coord - e->line);
    e->end = ft_atoi(c);
    return (1);
}

void	room_recorder(t_env *e)
{
    char **split;

    split = ft_strsplit(e->line, '-');
    if (e->r->room_num == -1 && e->r->next == NULL)
    {
        e->r->room_num = e->start;
        e->r->room_num = ft_atoi(split[0]);
        e->r->tube = ft_atoi(split[1]);
        e->r->next = NULL;
    }
    else
    {
        t_room *new;
        t_room *last;

        last = e->r;
        while (last->next)
            last = last->next;
        new = new_node(split);
        last->next = new;
    }
}

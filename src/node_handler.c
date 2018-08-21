#include "lem_in.h"

t_room      *new_node(char **split)
{
    t_room *new;

    new = NULL;
    if (!(new = (t_room *)malloc(sizeof(t_room))))
        return (NULL);
    new->room_num = ft_atoi(split[0]);
    new->tube = ft_atoi(split[1]);
    new->next = NULL;
    return (new);
}

t_room      *last_node(int end)
{
    t_room  *new;

    new = NULL;
    if (!(new = (t_room *)malloc(sizeof(t_room))))
        return (NULL);
    new->room_num = end;
    new->tube = -1;
    new->next = NULL;
    return (new);
}

void	   add_last_node(t_env *e)
{
    t_room  *last;

    last = e->r;
    while (last->next)
        last = last->next;
    last->next = last_node(e->end);
}

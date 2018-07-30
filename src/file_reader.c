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

t_room      *new_node(char **split)
{
    t_room *new;

    new = NULL;
    if (!(new = (t_room *)malloc(sizeof(t_room))))
        return (NULL);
    new->room_num =ft_atoi(split[0]);
    new->tube = ft_atoi(split[1]);
    new->next = NULL;
    return (new);
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

void	parsing_checker(t_env *e)
{
    char *addr = NULL;

    if (!e->count_line)
    {
        e->fourmiz = ft_atoi(e->line);
        e->count_line++;
    }
    if (ft_strstr(e->line, "##start"))
    {
        get_next_line(0, &(e->line));
        addr = ft_strchr(e->line, ' ');
        find_start(addr, e);
    }
    else if (ft_strstr(e->line, "##end"))
    {
        get_next_line(0, &(e->line));
        addr = ft_strchr(e->line, ' ');
        find_end(addr, e);
    }
    else if ((addr = ft_strchr(e->line, '-')))
        room_recorder(e);
}

int	read_file(t_env *e)
{

    int ret;

    while ((ret = get_next_line(0, &(e->line))) > 0)
        parsing_checker(e);
    return(ret);
}

void	init_env(t_env *e)
{
        e->fourmiz = 0;
        e->count_line = 0;
        e->start = -1;
        e->end = -1;
        e->line = NULL;
        e->r->room_num = -1;
        e->r->tube = -1;
        e->r->free = 0;
        e->r->next = NULL;
}

int main()
{
    t_env   e;

    init_env(&e);
    read_file(&e);


// --> debug
    ft_putstr("\n\nrecap\n");
    t_room *begin;
    begin = e.r;
    while (begin)
    {
        printf("r_n: %d, tube: %d \n", begin->room_num, begin->tube);
        begin = begin->next;
    }
// <--
    return (0);
}

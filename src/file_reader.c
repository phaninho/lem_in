#include "lem_in.h"

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

void	path_loader(int *way, t_room *begin, int i)
{
    while (begin)
    {
        way[i] = begin->tube;
        printf("in room n %d\n", way[i]);
        begin = begin->next;
    }
}

bool    path_finder(t_env *e)
{
    t_room  *begin;
    int i;

    i = -1;
    e->short_way = ft_memalloc(e->max);
    e->short_way[e->max] = -1;
    begin = e->r;
    e->short_way[++i] = e->start;
    path_loader(e->short_way, begin, i);

    printf("in room n %d\n", e->short_way[i]);
    // while (begin)
    // {
    //     e->short_way[++i] = begin->tube;
    //     printf("in room n %d\n", e->short_way[i]);
    //     begin = begin->next;
    // }
    return (0);
}


int	read_file(t_env *e)
{

    int ret;

    while ((ret = get_next_line(0, &(e->line))) > 0)
        parsing_checker(e);
    if (check_error(e))
        return (-1);
    return(ret);
}

int main()
{
    t_env   e;

    init_env(&e);
    if ((read_file(&e)) == -1)
        return (1);

// --> debug
    ft_putstr("\nrecap\n");
    t_room *begin;
    begin = e.r;
    printf("fourmiz number %d\n", e.fourmiz);
    printf("start = %d --- end = %d\n", e.start, e.end);
    while (begin)
    {
        printf("r_n: %d, tube: %d \n", begin->room_num, begin->tube);
        begin = begin->next;
    }
// <--

    if (path_finder(&e))
        return (1);
    return (0);
}

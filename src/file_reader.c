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

void	path_loader(t_env *e, t_room *begin, int i)
{
    while (e->short_way[i] != e->end)
    {
        if (e->short_way[i - 1] == begin->room_num)
        {
            printf("entre dans room %d link to %d\n", begin->room_num, begin->tube );
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

void	send_fourmiz(t_env *e)
{
    (void)e;
    // int     fourmiz_counter;
    // t_room  begin;
    //
    // fourmiz_counter = 1;
    // while (e->fourmiz >= fourmiz_counter)
    // {
    //     begin = e->r;
    //     while (begin)
    //     {
    //         // quelques choses
    //     }
    //     fourmiz_counter++;
    // }
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
    while (e->short_way[i] != -1)
    {
        printf("in %d room n = %d\n",i,  e->short_way[i]);
        i++;
    }
    send_fourmiz(e);
    //
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

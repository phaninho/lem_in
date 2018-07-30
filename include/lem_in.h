#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include <stdbool.h>

typedef struct      s_room
{
    int             room_num;
    int             tube;
    bool            free;
    struct s_room   *next;
}                   t_room;

typedef struct      s_env
{
    int             fourmiz;
    int             count_line;
    int             start;
    int             end;
    char            *line;
    t_room          *r;
}                   t_env;


#endif

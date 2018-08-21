#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include <stdbool.h>

typedef struct      s_room
{
    bool            free;
    int             room_num;
    int             tube;
    int             fourmiz_nb;
    struct s_room   *next;
}                   t_room;

typedef struct      s_env
{
    char            *line;
    int             fourmiz;
    int             reach_end;
    int             count_line;
    int             start;
    int             end;
    int             max_room;
    int             *short_way;
    t_room          *r;
}                   t_env;

int                 check_error(t_env *e);
void	            init_env(t_env *e);
t_room              *new_node(char **split);
void	            add_last_node(t_env *e);
int                 find_start(char * coord, t_env *e);
int                 find_end(char * coord, t_env *e);
void	            room_recorder(t_env *e);
void	            parsing_checker(t_env *e);
bool                path_finder(t_env *e);
void	           	display(t_room *begin);

#endif

// accimoto 0169881616
// 11 juillet tentavive ducati a refuser
// demander pourquoi plus ordonner de laisser partir la moto ensuite joindre accimoto pour la recuperer
//
//
// ducati
// 0183810270
// nanterre 9 av rueil

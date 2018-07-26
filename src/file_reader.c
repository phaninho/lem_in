#include "lem_in.h"

int	read_file()
{
    int fd = 0;
    char *line;
    int ret;

    // if ((fd = open(av, O_RDONLY)) < 0)
    // {
    //     ft_putstr("erreur lors de l'ouverture du fichier");
    //     return (-1);
    // }
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        ft_putendl(line);
    }
    return(1);
}

int main()
{
    return (read_file());
}

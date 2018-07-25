#include "lem_in.h"

int	read_file(char *av)
{
    int fd;
    char *line;
    int ret;

    if ((fd = open(av, O_RDONLY)) < 0)
    {
        ft_putstr("erreur lors de l'ouverture du fichier");
        return (-1);
    }
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        ft_putendl(line);
    }
    return(1);
}

int main(int ac, char **av)
{
    if (ac < 2)
        ft_putstr("il manque un argument");
    else
        return (read_file(av[1]));
    return(0);
}

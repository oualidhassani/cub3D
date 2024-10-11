#include "cub3D.h"

int main(int ac, char **av)
{
	if (ac > 2 || ac < 2)
		print_errors("Error need : .cub \n");
    t_thegame game;
    game.height = 0;
    game.width = 0;
    check_name(av);
    read_the_map(&game, av[1]);
    if(stocking_on_the_map(&game, av[1]) == 1)
        print_errors("there is smntg wrong check again");
    
    return(0);
}
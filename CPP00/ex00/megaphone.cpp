#include <iostream>
#include <cstring>

void	no_megaphone()
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void	megaphone(int ac, char **av)
{
	char	c;
	for (int i = 1; i < ac; i++)
	{
		if (i != 1)
			std::cout << " ";
		for (int j = 0; av[i][j]; j++)
		{
			c = toupper(av[i][j]);
			std::cout << c;
		}
	}
	std::cout << std::endl;
}


int main(int ac, char **av)
{
	if (ac > 1)
		megaphone(ac, av);
	else
		no_megaphone();
	return 0;
}
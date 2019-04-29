/*
** EPITECH PROJECT, 2018
** get
** File description:
** bytecode
*/

int get_bytecode(int bytecode, int nbr)
{
	int value[3] = {64, 16, 4};

	for (int i = 0; i < nbr - 1; i++) {
		if (value[i] * 2 < bytecode)
			bytecode -= value[i] * 2;
		if (value[i] < bytecode)
			bytecode -= value[i];
	}
	if (bytecode >= value[nbr - 1] + value[nbr - 1] * 2)
		return (2);
	if (bytecode >= value[nbr - 1] * 2)
		return (4);
	return (1);
}

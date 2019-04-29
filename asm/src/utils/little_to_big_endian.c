/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** convert an integer from little to big endian
*/

unsigned int little_to_big_endian(int nb)
{
	int b0 = 0;
	int b1 = 0;
	int b2 = 0;
	int b3 = 0;
	int res = 0;

	b0 = (nb & 0x000000ff) << 24;
	b1 = (nb & 0x0000ff00) << 8;
	b2 = (nb & 0x00ff0000) >> 8;
	b3 = (nb & 0xff000000) >> 24;
	res = b0 | b1 | b2 | b3;
	return ((unsigned int)res);
}

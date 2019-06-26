//
// Created by Juan Villalobos Quiros on 07/05/2019.
//

#include <stdio.h>
#include <stdlib.h>

#include "gol.h"

int main()
{
	struct gol gol;
	int i = 0;

	gol_init(&gol);
	do {
		printf("\033cIteration %d\n", i++);
		gol_print(&gol);
		gol_step(&gol);
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}
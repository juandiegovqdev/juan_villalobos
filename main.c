//
// Created by Juan Villalobos Quiros on 07/05/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "gol.h"

int main()
{
	int i = 0;
	bool mundos[2][TAM_X][TAM_Y];

	gol_init(mundos[0]);
	do {
		printf("\033cIteration %d\n", i++);
		gol_print(mundos[0]);
		gol_step(mundos[0], mundos[1]);
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}
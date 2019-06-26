#ifndef _GOL_H_
#define _GOL_H_

#include <stdbool.h>

#define TAM_X 10
#define TAM_Y 20

void gol_init(bool mundo[TAM_X][TAM_Y]);
void gol_print(bool mundo[TAM_X][TAM_Y]);
void gol_step(bool mundoa[TAM_X][TAM_Y], bool mundob[TAM_X][TAM_Y]);
int gol_count_neighbors(bool mundo[TAM_X][TAM_Y], int x, int y);
bool gol_get_cell(bool mundo[TAM_X][TAM_Y], int x, int y);

#endif
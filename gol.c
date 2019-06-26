#include "gol.h"

#include <stdio.h>

void gol_init(struct gol *gol)
{
	gol->mundo = 0;

	for (int i = 0; i < TAM_X; i++)
		for (int j = 0; j < TAM_Y; j++)
			gol->mundos[gol->mundo][i][j] = false;

	// Glider
	gol->mundos[gol->mundo][0][1] = true;
	gol->mundos[gol->mundo][1][2] = true;
	gol->mundos[gol->mundo][2][0] = true;
	gol->mundos[gol->mundo][2][1] = true;
	gol->mundos[gol->mundo][2][2] = true;
}

void gol_print(const struct gol *gol)
{
	for (int i = 0; i < TAM_X; i++) {
		for (int j = 0; j < TAM_Y; j++) {
			printf("%s", gol->mundos[gol->mundo][i][j] ?
				" #" : " .");
		}
		printf("\n");
	}
	printf("\n");
}

void gol_step(struct gol *gol)
{
	for (int i = 0; i < TAM_X; i++) {
		for (int j = 0; j < TAM_Y; j++) {
			int n = gol_count_neighbors(gol, i, j);
			gol->mundos[!gol->mundo][i][j] =
				(gol->mundos[gol->mundo][i][j] && n == 2)
				|| n == 3;
		}
	}

	gol->mundo = !gol->mundo;
}

int gol_count_neighbors(const struct gol *gol, int x, int y)
{
	int count = 0;

	count += gol_get_cell(gol, x - 1, y + 1);
	count += gol_get_cell(gol, x - 0, y + 1);
	count += gol_get_cell(gol, x + 1, y + 1);
	count += gol_get_cell(gol, x - 1, y + 0);
	count += gol_get_cell(gol, x + 1, y + 0);
	count += gol_get_cell(gol, x - 1, y - 1);
	count += gol_get_cell(gol, x - 0, y - 1);
	count += gol_get_cell(gol, x + 1, y - 1);

	return count;
}

bool gol_get_cell(const struct gol *gol, int x, int y)
{
	// Fix coords
	if (x >= TAM_X)
		x = 0;
	else if (x < 0)
		x = TAM_X - 1;

	if (y >= TAM_Y)
		y = 0;
	else if (y < 0)
		y = TAM_Y - 1;

	return gol->mundos[gol->mundo][x][y];
}
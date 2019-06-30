#include <stdio.h>
#include <stdlib.h>
#include "gol.h"

#define GET_CELL(gol, x, y) (gol->mundos[wt][x * gol->y + y])

enum mundo {
        ACTUAL,
        SIGUIENTE,
};

static int count_neighbors(const struct gol *gol, int x, int y);
static bool get_cell(const struct gol *gol, enum mundo wt, int x, int y);
static void set_cell(struct gol *gol, enum mundo wt, int x, int y, bool a);

bool gol_alloc(struct gol *gol, int x, int y)
{
    for (int k = ACTUAL; k <= SIGUIENTE; k++) {
        gol->mundos[k] = (bool *)malloc(x * y * sizeof(bool));
        if (!gol->mundos[k]) {
            return 0;
        }
    }
    gol->x = x;
    gol->y = y;
    return 1;
}

void gol_free(struct gol *gol)
{
    for (int k = ACTUAL; k <= SIGUIENTE; k++) {
    free(gol->mundos[k]);
    }
}

void gol_init(struct gol *gol)
{
    for (int x = 0; x < gol->x; x++) {
        for (int y = 0; y < gol->y; y++) { 
                set_cell(gol, ACTUAL, x, y, 0);
        }
    }
            set_cell(gol, ACTUAL, 0, 1, 1);
            set_cell(gol, ACTUAL, 1, 2, 1);
            set_cell(gol, ACTUAL, 2, 0, 1);
            set_cell(gol, ACTUAL, 2, 1, 1);
            set_cell(gol, ACTUAL, 2, 2, 1);
}

void gol_print(struct gol *gol)
{
    for (int x = 0; x < gol->x; x++) {
        for (int y = 0; y < gol->y; y++) {
            printf("%c ", get_cell(gol, ACTUAL, x, y)? '#' : '.');
        }
        printf("\n");
    }
}

void gol_step(struct gol *gol)
{
    for (int x = 0; x < gol->x; x++) {
        for (int y = 0; y < gol->y; y++) {
            int an = count_neighbors(gol, x, y);
            if (get_cell(gol, ACTUAL, x, y)) {
                   bool a = (an == 2) || (an == 3);
                   set_cell(gol, SIGUIENTE, x, y, a);
            }   else {      
                        bool a = an == 3;
                        set_cell(gol, SIGUIENTE, x, y, a);
                }
        }      
    }
    bool *swap = gol->mundos[ACTUAL];
    gol->mundos[ACTUAL] = gol->mundos[SIGUIENTE];
    gol->mundos[SIGUIENTE] = swap;
}

static int count_neighbors(const struct gol *gol, int x, int y)
{
    int anc = 0;
    
    anc += get_cell(gol, ACTUAL, x - 1, y + 1);
    anc += get_cell(gol, ACTUAL, x, y + 1);
    anc += get_cell(gol, ACTUAL, x + 1, y + 1);
    
    anc += get_cell(gol, ACTUAL, x - 1, y);
    anc += get_cell(gol, ACTUAL, x + 1, y);
    
    anc += get_cell(gol, ACTUAL, x - 1, y - 1);
    anc += get_cell(gol, ACTUAL, x, y - 1);
    anc += get_cell(gol, ACTUAL, x + 1, y - 1);
    
    return anc;         
}

static bool get_cell(const struct gol *gol, enum mundo wt, int x, int y)
{
    if(x >= gol->x)
        x = 0;
    else if (x < 0)
        x = gol->x - 1;
    if(y >= gol->y)
        y = 0;
    else if (y < 0)
        y = gol->y - 1;
    return GET_CELL(gol, x, y);
}

static void set_cell(struct gol *gol, enum mundo wt, int x, int y, bool a)
{
    GET_CELL(gol, x, y) = a;
}
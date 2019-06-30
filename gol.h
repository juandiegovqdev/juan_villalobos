#ifndef _GOL_H_
#define _GOL_H_

#include <stdbool.h>

struct gol {
    bool *k;
    bool *mundos[2];
    int x;
    int y;
};

bool gol_alloc(struct gol *gol, int x, int y);
void gol_free(struct gol *gol);
void gol_init(struct gol *gol);
void gol_print(struct gol *gol);
void gol_step(struct gol *gol);

#endif
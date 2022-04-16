#ifndef FIGURE_H
#define FIGURE_H

#include <cstdio>

#include "points.h"
#include "edges.h"
#include "action_data.h"
#include "errors.h"

struct figure
{
    point_t center;
    points_t points;
    edges_t edges;
};

using figure_t = struct figure;

figure_t &figure_init(void);

void free_figure(figure_t &figure);

error_t fread_figure(figure_t &figure, FILE *fin);

error_t download_figure(figure_t &figure, const char *filename);

error_t move_figure(figure_t &figure, const move_t &move);

error_t scale_figure(figure_t &figure, const scale_t &scale);

error_t rotate_figure(figure_t &figure, const rotate_t &rotate);

error_t save_figure(figure_t &figure, const char *filename);

#endif // FIGURE_H

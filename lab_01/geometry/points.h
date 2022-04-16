#ifndef POINTS_H
#define POINTS_H

#include <cstdio>
#include <cstdlib>

#include "point.h"
#include "errors.h"

struct points
{
    point_t *array_points;
    int size;
};

using points_t = struct points;

void points_default(points_t &points);

error_t allocate_points(points_t &points);

void free_points(points_t &points);

error_t fread_inf_about_points(points &points, FILE *fin);

error_t fread_amount_points(points_t &points, FILE *fin);

error_t fread_all_points(points_t &points, FILE *fin);

error_t move_all_points(points_t &points, const move_t &coeff);

error_t rotate_all_points(points_t &points, const point_t &r_center, const rotate_t &coeff);

error_t scale_all_points(points_t &points, const point_t &s_center, const scale_t &coeff);

error_t save_all_points(const points_t &points, FILE *fout);

#endif // POINTS_H

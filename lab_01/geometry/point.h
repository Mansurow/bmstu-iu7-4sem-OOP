#ifndef POINT_H
#define POINT_H

#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "action_data.h"
#include "errors.h"

struct point
{
    double x;
    double y;
    double z;
};

using point_t = struct point;

void point_default(point_t &point);

error_t fread_point(point_t &point, FILE *fin);

void move_point(point_t &point, const move_t &move);

void rotate_point(point_t &point, const point_t &r_center, const rotate_t &rotate);

void scale_point(point_t &point, const point_t &s_center, const scale_t &scale);

error_t save_point(const point_t &point, FILE *fout);

#endif // POINT_H

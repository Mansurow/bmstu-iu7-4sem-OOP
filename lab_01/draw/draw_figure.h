#ifndef DRAW_FIGURE_H
#define DRAW_FIGURE_H

#include <QGraphicsScene>

#include "figure.h"
#include "points.h"

struct drawview
{
    QGraphicsScene *scene;
    double width;
    double height;
};

struct line
{
    point_t first_point;
    point_t second_point;
};

using drawview_t = struct drawview;

using line_t = struct line;

point_t conversion(point_t point, const drawview_t &view);

line_t get_points(const drawview_t &view, const edge_t &edge, const point_t *array_points);

error_t draw_line(const drawview_t &view, const point_t &p1, const point_t &p2);

error_t draw_lines(const drawview_t &view, const points_t &points, const edges_t &edges);

error_t draw_figure(const figure_t &figure, drawview_t &view);

error_t clear_scene(const drawview_t &view);

#endif // DRAW_FIGURE_H

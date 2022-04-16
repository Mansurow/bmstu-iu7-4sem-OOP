#include "draw_figure.h"

point_t conversion(point_t point, const drawview_t &view)
{
    point.x += view.width / 2;
    point.y += view.height / 2;

    return point;
}

line_t get_points(const drawview_t &view, const edge_t &edge, const point_t *array_points)
{
    line_t line;

    line.first_point = conversion(array_points[edge.first_point], view);
    line.second_point = conversion(array_points[edge.second_point], view);

    return line;
}

error_t clear_scene(const drawview_t &view)
{
    if (!view.scene)
        return SCENE_WRONG_ERROR;

    view.scene->clear();
    return SUCCESS;
}

error_t draw_line(const drawview_t &view, const point_t &p1, const point_t &p2)
{
    if (!view.scene)
        return SCENE_WRONG_ERROR;

    view.scene->addLine(p1.x, p1.y, p2.x, p2.y);
    return SUCCESS;
}

error_t draw_lines(const drawview_t &view, const points_t &points, const edges_t &edges)
{
    error_t rc = SUCCESS;
    if (points.array_points == NULL || edges.array_edges == NULL)
        rc = MEMORY_ALLOCATE_ERROR;
    else if (!view.scene)
        rc = SCENE_WRONG_ERROR;
    else
    {
        line_t line;
        for (int i = 0; rc == SUCCESS && i < edges.size; i++)
        {
            line = get_points(view, edges.array_edges[i], points.array_points);
            rc = draw_line(view, line.first_point, line.second_point);
        }
    }

    return rc;
}

error_t draw_figure(const figure_t &figure, drawview_t &view)
{
    error_t rc = clear_scene(view);
    if (!rc)
        rc = draw_lines(view, figure.points, figure.edges);

    return rc;
}

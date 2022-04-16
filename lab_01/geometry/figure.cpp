#include "figure.h"

figure_t &figure_init(void)
{
    static figure_t figure;

    point_default(figure.center);

    points_default(figure.points);

    edges_default(figure.edges);

    return figure;
}

void free_figure(figure_t &figure)
{
    free_points(figure.points);
    free_edges(figure.edges);
}

error_t fread_figure(figure_t &figure, FILE *fin)
{
    if (fin == NULL)
        return FILE_OPEN_ERROR;

    figure = figure_init();

    error_t rc = fread_inf_about_points(figure.points, fin);
    if (rc == SUCCESS)
    {
        rc = fread_inf_about_edges(figure.edges, fin);
        if (rc)
            free_points(figure.points);
    }

    return rc;
}

error_t download_figure(figure_t &figure, const char *filename)
{
    if (filename == NULL)
        return FILE_OPEN_ERROR;

    error_t rc = SUCCESS;
    FILE *fin = fopen(filename, "r");
    if (fin == NULL)
        rc = FILE_OPEN_ERROR;
    else
    {
        figure_t current_figure;

        rc = fread_figure(current_figure, fin);
        fclose(fin);
        if (rc == SUCCESS)
        {
            free_figure(figure);
            figure = current_figure;
        }

    }
    return rc;
}

error_t move_figure(figure_t &figure, const move_t &move)
{
    move_point(figure.center, move);
    return move_all_points(figure.points, move);
}

error_t scale_figure(figure_t &figure, const scale_t &scale)
{
    return scale_all_points(figure.points, figure.center, scale);
}

error_t rotate_figure(figure_t &figure, const rotate_t &rotate)
{
    return rotate_all_points(figure.points, figure.center, rotate);
}

error_t save_figure(figure_t &figure, const char *filename)
{
    error_t rc = SUCCESS;
    if (filename == NULL)
        rc = FILE_WRITE_ERROR;
    else if (!figure.points.array_points ||
             !figure.edges.array_edges)
        rc = NOT_DATA_WRITE_ERROR;
    else
    {
        FILE *fout = fopen(filename, "w");
        if (fout == NULL)
            rc = FILE_WRITE_ERROR;
        else
        {
            rc = save_all_points(figure.points, fout);
            if (rc == SUCCESS)
                rc = save_all_edges(figure.edges, fout);
            fclose(fout);
        }
    }
    return rc;
}

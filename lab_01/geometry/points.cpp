#include "points.h"

void points_default(points_t &points)
{
    points.array_points = NULL;
    points.size = 0;
}

error_t allocate_points(points_t &points)
{
    error_t rc = SUCCESS;
    if (points.size <= 0)
        rc = SIZE_POINTS_ERROR;
    else
    {
        point_t *temp_array = (point_t *) malloc(points.size * sizeof(point_t));
        if (!temp_array)
            rc = MEMORY_ALLOCATE_ERROR;
        else
            points.array_points = temp_array;
    }

    return rc;
}

void free_points(points_t &points)
{
    free(points.array_points);
    points_default(points);
}

error_t fread_inf_about_points(points &points, FILE *fin)
{
    if (fin == NULL)
        return FILE_OPEN_ERROR;

    error_t rc = fread_amount_points(points, fin);
    if (!rc)
    {
        rc = allocate_points(points);
        if (!rc)
        {
            rc = fread_all_points(points, fin);
            if (rc)
                free_points(points);
        }
    }
    return rc;
}

error_t fread_amount_points(points_t &points, FILE *fin)
{
    error_t rc = SUCCESS;
    if (fin == NULL)
        rc = FILE_OPEN_ERROR;
    else if (fscanf(fin, "%d", &points.size) != 1)
        rc = READ_FILE_ERROR;
    else if (points.size <= 0)
        rc = SIZE_POINTS_ERROR;

    return rc;
}

error_t fread_all_points(points_t &points, FILE *fin)
{
    error_t rc = SUCCESS;
    if (fin == NULL)
        rc = FILE_OPEN_ERROR;
    else if (points.size <= 0)
        rc = SIZE_POINTS_ERROR;
    else if (!points.array_points)
        rc = MEMORY_ALLOCATE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < points.size; i++)
            rc = fread_point(points.array_points[i], fin);

    return rc;
}

error_t move_all_points(points_t &points, const move_t &coeff)
{
    if (!points.array_points)
        return FIGURE_NOT_LOADED;

    for (int i = 0; i < points.size; i++)
        move_point(points.array_points[i], coeff);

    return SUCCESS;
}

error_t rotate_all_points(points_t &points, const point_t &r_center, const rotate_t &coeff)
{
    if (!points.array_points)
        return FIGURE_NOT_LOADED;

    for (int i = 0; i < points.size; i++)
        rotate_point(points.array_points[i], r_center, coeff);

    return SUCCESS;
}

error_t scale_all_points(points_t &points, const point_t &s_center, const scale_t &coeff)
{
    error_t rc = SUCCESS;
    if (!points.array_points)
        rc = FIGURE_NOT_LOADED;
    else if (coeff.kx == 0 || coeff.ky == 0 || coeff.kz == 0)
        rc = COEFF_SCALE_ERROR;
    else
        for (int i = 0; i < points.size; i++)
            scale_point(points.array_points[i], s_center, coeff);

    return rc;
}

error_t save_all_points(const points_t &points, FILE *fout)
{
    error_t rc = SUCCESS;
    if (!points.array_points)
        rc = NOT_DATA_WRITE_ERROR;
    else if (0 > fprintf(fout, "%d\n", points.size))
        rc = FILE_WRITE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < points.size; i++)
            rc = save_point(points.array_points[i], fout);

    return rc;
}

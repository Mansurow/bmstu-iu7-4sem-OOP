#include "point.h"

inline double to_radians(const double &angle) {
    return angle * (M_PI / 180);
}

static void rotate_xp(point_t &point, const point_t &r_center, const double angle)
{
    double r_cos = cos(to_radians(angle));
    double r_sin = sin(to_radians(angle));
    double y = point.y;

    point.y = (point.y - r_center.y)  * r_cos + (point.z - r_center.z) * r_sin + r_center.y;
    point.z = -(y - r_center.y) * r_sin + (point.z - r_center.z) * r_cos + r_center.z;
}

static void rotate_yp(point_t &point, const point_t &r_center, const double angle)
{
    double r_cos = cos(to_radians(angle));
    double r_sin = sin(to_radians(angle));
    double x = point.x;

    point.x = (point.x - r_center.x) * r_cos + (point.z - r_center.z) * r_sin + r_center.x;
    point.z = -(x - r_center.x) * r_sin + (point.z - r_center.z) * r_cos + r_center.z;
}

static void rotate_zp(point_t &point, const point_t &r_center, const double angle)
{
    double r_cos = cos(to_radians(angle));
    double r_sin = sin(to_radians(angle));
    double x = point.x;

    point.x = (point.x - r_center.x) * r_cos + (point.y - r_center.y)* r_sin + r_center.x;
    point.y = -(x - r_center.x) * r_sin + (point.y - r_center.y) * r_cos + r_center.y;
}

void point_default(point_t &point)
{
    point.x = 0.0;
    point.y = 0.0;
    point.z = 0.0;
}

error_t fread_point(point_t &point, FILE *fin)
{
    error_t rc = SUCCESS;
    if (fin == NULL)
        rc = FILE_OPEN_ERROR;
    else if(fscanf(fin, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
        rc = READ_FILE_ERROR;

    return rc;
}

void move_point(point_t &point, const move_t &move)
{
    point.x += move.dx;
    point.y += move.dy;
    point.z += move.dz;
}

void rotate_point(point_t &point, const point_t &r_center, const rotate_t &rotate)
{
    rotate_xp(point, r_center, rotate.angle_x);
    rotate_yp(point, r_center, rotate.angle_y);
    rotate_zp(point, r_center, rotate.angle_z);
}

void scale_point(point_t &point, const point_t &s_center, const scale_t &scale)
{
    point.x = (point.x - s_center.x) * scale.kx + s_center.x;
    point.y = (point.y - s_center.y) * scale.ky + s_center.y;
    point.z = (point.z - s_center.z) * scale.kz + s_center.z;
}

error_t save_point(const point_t &point, FILE *fout)
{
    int rc = fprintf(fout, "%lf %lf %lf\n", point.x,
                                            point.y,
                                            point.z);
    if (0 > rc)
        return FILE_WRITE_ERROR;
    return SUCCESS;
}

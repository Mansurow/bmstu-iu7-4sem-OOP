#ifndef ACTION_DATA_H
#define ACTION_DATA_H

struct move
{
    double dx;
    double dy;
    double dz;
};

struct rotate
{
    double angle_x;
    double angle_y;
    double angle_z;
};

struct scale
{
    double kx;
    double ky;
    double kz;
};

using move_t = struct move;
using rotate_t = struct rotate;
using scale_t = struct scale;

#endif // ACTION_DATA_H

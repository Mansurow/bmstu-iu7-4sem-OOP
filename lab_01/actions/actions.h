#ifndef ACTIONS_H
#define ACTIONS_H

// подключить все для работы
#include "figure.h"
#include "draw_figure.h"
#include "action_data.h"
#include "errors.h"

enum action
{
    SAVE,
    DOWNLOAD,
    ROTATE,
    MOVE,
    SCALE,
    DRAW,
    QUIT
};

struct request
{
    enum action action;
    union
    {
        const char *filename;
        drawview_t view;
        rotate_t rotate;
        move_t move;
        scale_t scale;
    };
};

using request_t = struct request;

error_t manager_actions(request_t &request);

#endif // ACTIONS_H

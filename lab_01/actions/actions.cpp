#include "actions.h"

error_t manager_actions(request_t &request)
{
    static figure_t figure = figure_init();
    error_t rc = SUCCESS;
    switch (request.action)
    {
        case SAVE:
            rc = save_figure(figure, request.filename);
            break;
        case DOWNLOAD:
            rc = download_figure(figure, request.filename);
            break;
        case MOVE:
            rc = move_figure(figure, request.move);
            break;
        case SCALE:
            rc = scale_figure(figure, request.scale);
            break;
        case ROTATE:
            rc =  rotate_figure(figure, request.rotate);
            break;
        case DRAW:
            rc = draw_figure(figure, request.view);
            break;
        case QUIT:
            free_figure(figure);
            break;
        default:
            rc = COMMAND_UNDEFINED;
    }

    return rc;
}

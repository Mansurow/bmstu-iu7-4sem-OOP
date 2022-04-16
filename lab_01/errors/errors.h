#ifndef ERRORS_H
#define ERRORS_H

#include <QMessageBox>

enum error
{
    SUCCESS,
    FILE_OPEN_ERROR,
    FILE_EMPTY_ERROR,
    READ_FILE_ERROR,
    FILE_CLOSE_ERROR,
    FILE_WRITE_ERROR,
    FIGURE_NOT_LOADED,
    SIZE_POINTS_ERROR,
    SIZE_EDGES_ERROR,
    SCENE_WRONG_ERROR,
    MEMORY_ALLOCATE_ERROR,
    COEFF_SCALE_ERROR,
    NOT_DATA_WRITE_ERROR,
    COMMAND_UNDEFINED
};

using error_t = enum error;

void error_message(error_t &error);

#endif // ERRORS_H

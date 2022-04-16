#include "errors.h"

void error_message(error_t &error)
{
    switch (error)
    {
        case FILE_OPEN_ERROR:
            QMessageBox::critical(NULL, "Ошибка!", "Не удалось открыть файл");
            break;
        case FILE_CLOSE_ERROR:
            QMessageBox::critical(NULL, "Ошибка!", "Не удалось закрыть файл");
            break;
        case READ_FILE_ERROR:
            QMessageBox::critical(NULL, "Ошибка!", "Не удалось прочитать файл!");
            break;
        case FILE_WRITE_ERROR:
            QMessageBox::critical(NULL, "Ошибка!", "При записи файла были даны некорректные данные!");
            break;
        case MEMORY_ALLOCATE_ERROR:
            QMessageBox::critical(NULL, "Ошибка!", "Не удалось выделить память!");
            break;
        case SIZE_POINTS_ERROR:
            QMessageBox::critical(NULL, "Ошибка!", "Кол-во точек в файле должно быть > 0!");
            break;
        case SIZE_EDGES_ERROR:
            QMessageBox::critical(NULL, "Ошибка!", "Кол-во ребер в файле должно быть > 0!");
            break;
        case SCENE_WRONG_ERROR:
            QMessageBox::critical(NULL, "Ошибка!", "При попытке нарисовать, фигуру произошла ошибка!");
            break;
        case COEFF_SCALE_ERROR:
            QMessageBox::critical(NULL, "Ошибка!", "Коэффициенты масштабирования не должны равняться 0!");
            break;
        case NOT_DATA_WRITE_ERROR:
            QMessageBox::information(NULL, "Информация!", "Нет данных фигуры для записи!");
            break;
        case FIGURE_NOT_LOADED:
            QMessageBox::information(NULL, "Информация!", "Фигура не загружена!");
            break;
        default:
            QMessageBox::critical(NULL, "Ошибка!", "Что-то пошло не по плану...");
    };
}

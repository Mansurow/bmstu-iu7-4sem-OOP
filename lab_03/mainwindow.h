#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QFileDialog>

#include <BaseCommand.h>
#include <CameraCommand.h>
#include <ModelCommand.h>
#include <ModelsCommand.h>
#include <SceneCommand.h>
#include <Exceptions.h>
#include <BaseDrawer.h>
#include <DrawerSolution.h>
#include <QtFactory.h>
#include <Facade.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addCameraBtn_clicked();

    void on_loadModelBtn_clicked();
    void on_deleteModelBtn_clicked();
    void on_deleteModelsBtn_clicked();

    void on_cameraCB_currentIndexChanged(int index);

    void on_deleteCameraBtn_clicked();

    void on_upBtn_clicked();

    void on_rigthBtn_clicked();

    void on_downBtn_clicked();

    void on_leftBtn_clicked();

    void on_moveBtn_clicked();

    void on_scaleBtn_clicked();

    void on_rotateBtn_clicked();

    void on_moveAllBtn_clicked();

    void on_scaleAllBtn_clicked();

    void on_rotateAllBtn_clicked();
    void on_rightUpBtn_clicked();

    void on_rigntDownBtn_clicked();

    void on_leftDownBtn_clicked();

    void on_leftUpBtn_clicked();

protected:
    void setupScene();
    void updateScene();
    void checkCamExist();
    void checkModelsExist();
    void checkCamDelete();

private:
    Ui::MainWindow *ui;
    //QGraphicsScene *_scene;
    std::shared_ptr<QGraphicsScene> _scene;
    std::shared_ptr<Facade> _facade;
    std::shared_ptr<BaseDrawer> _drawer;

    std::vector<std::size_t> _models;
    std::vector<std::size_t> _cameras;
    std::size_t _camInd = 0;
    std::size_t _modInd = 0;
};
#endif // MAINWINDOW_H

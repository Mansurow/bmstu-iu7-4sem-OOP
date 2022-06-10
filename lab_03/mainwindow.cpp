#include <cmath>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupScene();

    _facade = std::make_shared<Facade>(Facade());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupScene()
{
    _scene = std::make_shared<QGraphicsScene>(this);

    ui->graphicsView->setScene(_scene.get());
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    auto cont = ui->graphicsView->contentsRect();
    _scene->setSceneRect(0, 0, cont.width(), cont.height());
    _camInd = 1;

    auto solution(new DrawerSolution<QtFactory, QGraphicsScene>());
    _drawer = solution->createDrawer(_scene.get());
}

void MainWindow::updateScene()
{
    auto scene = std::make_shared<Scene>();
    ClearScene clear_cmd(_drawer);
    _facade->execute(clear_cmd);

    GetScene get_scene_cmd(scene);
    _facade->execute(get_scene_cmd);

    DrawScene draw_cmd(scene, _drawer);
    _facade->execute(draw_cmd);
}

void MainWindow::checkCamExist()
{
    if (!_cameras.size())
    {
        std::string msg = "No camera found.";
        throw CameraException(msg);
    }
}

void MainWindow::checkModelsExist()
{
    if (!_models.size())
    {
        std::string msg = "No models found.";
        throw ModelException(msg);
    }
}

void MainWindow::checkCamDelete()
{
    if (_cameras.size() <= 1 && _models.size())
    {
        std::string msg = "Can not delete the last camera with the loaded models";
        throw CameraException(msg);
    }
}

void MainWindow::on_addCameraBtn_clicked()
{
    auto cont = ui->graphicsView->contentsRect();

    auto id = std::make_shared<size_t>(0);
    Point location(cont.width() / 2.0, cont.height() / 2.0, 0.0);
    Point direction(0, 0, 0);
    AddCamera addCMD(id, location, direction);

    _facade->execute(addCMD);
    _cameras.push_back(*id);

    updateScene();

    auto cam = ui->cameraCB;

    std::string camName = std::string("Camera") + std::to_string(_camInd++);
    cam->addItem(QString(camName.data()));

    ui->cameraCB->setCurrentIndex(ui->cameraCB->count() - 1);
}

void MainWindow::on_loadModelBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Добавьте камеру!");
        return;
    }

    auto path = QFileDialog::getOpenFileName(nullptr, "Загрузка модели", "../lab_03/data/cube.txt");

    if (path.isNull())
        return;

    std::shared_ptr<BaseObject> model = std::make_shared<CarcassModel>();
    auto id = std::make_shared<size_t>(0);
    std::string pathFileName = path.toStdString();

    try
    {
        LoadModel load_cmd(model, pathFileName);
        _facade->execute(load_cmd);

        AddModel add_cmd(id, model);
        _facade->execute(add_cmd);
    }
    catch (const BaseException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Ошибка при загрузке файла!");
        return;
    }

    _models.push_back(*id);
    updateScene();
    _modInd++;
    auto fileName = QFileInfo(path.toUtf8().data()).fileName();
    QString figName = QString("CarcasModel") + QString::number(_modInd) + QString(" load from ") + QString(fileName);
    ui->modelsCB->addItem(figName);
    ui->modelsCB->setCurrentIndex(ui->modelsCB->count() - 1);
}

void MainWindow::on_deleteModelBtn_clicked()
{
    try
    {
        checkModelsExist();
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет загруженных моделей!");
        return;
    }

    std::size_t id = _models.at(ui->modelsCB->currentIndex());
    RemoveModel cmd(id);
    _facade->execute(cmd);

    _models.erase(_models.begin() + ui->modelsCB->currentIndex());
    ui->modelsCB->removeItem(ui->modelsCB->currentIndex());

    updateScene();
}

void MainWindow::on_deleteModelsBtn_clicked()
{
    try
    {
        checkModelsExist();
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет загруженных моделей!");
        return;
    }

    for (int i = ui->modelsCB->count() - 1; i >= 0; --i)
    {
        std::size_t id = _models.at(i);
        RemoveModel cmd(id);
        _facade->execute(cmd);

        _models.erase(_models.begin() + i);
        ui->modelsCB->removeItem(i);
    }

    updateScene();
}


void MainWindow::on_cameraCB_currentIndexChanged(int index)
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    std::size_t id = _cameras.at(index);
    SetCamera cmd(id);
    _facade->execute(cmd);

    updateScene();
}


void MainWindow::on_deleteCameraBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }

    try
    {
        checkCamDelete();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Это последняя камера! Для удаления удалите модели!");
        return;
    }

    std::size_t id = _cameras.at(ui->cameraCB->currentIndex());
    RemoveCamera cmd(id);
    _facade->execute(cmd);

    _cameras.erase(_cameras.begin() + ui->cameraCB->currentIndex());
    ui->cameraCB->removeItem(ui->cameraCB->currentIndex());

    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    updateScene();
}

void MainWindow::on_upBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = make_shared<Camera>();

    GetMainCamera get_camera(camera);
   _facade->execute(get_camera);

    MoveCamera move_cmd(camera, 0, 10, 0);
    _facade->execute(move_cmd);

    updateScene();
}

void MainWindow::on_downBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = make_shared<Camera>();

    GetMainCamera get_camera(camera);
   _facade->execute(get_camera);

    MoveCamera move_cmd(camera, 0, -10, 0);
    _facade->execute(move_cmd);

    updateScene();
}

void MainWindow::on_rigthBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    //std::size_t id = _cameras.at(ui->cameraCB->currentIndex());
    auto camera = make_shared<Camera>();

    GetMainCamera get_camera(camera);
   _facade->execute(get_camera);

    MoveCamera move_cmd(camera, -10, 0, 0);
    _facade->execute(move_cmd);

    updateScene();
}

void MainWindow::on_rightUpBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = make_shared<Camera>();

    GetMainCamera get_camera(camera);
   _facade->execute(get_camera);

    MoveCamera move_cmd(camera, -10, 10, 0);
    _facade->execute(move_cmd);

    updateScene();
}

void MainWindow::on_rigntDownBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = make_shared<Camera>();

    GetMainCamera get_camera(camera);
   _facade->execute(get_camera);

    MoveCamera move_cmd(camera, -10, -10, 0);
    _facade->execute(move_cmd);

    updateScene();
}

void MainWindow::on_leftBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = make_shared<Camera>();

    GetMainCamera get_camera(camera);
   _facade->execute(get_camera);

    MoveCamera move_cmd(camera, 10, 0, 0);
    _facade->execute(move_cmd);

    updateScene();
}

void MainWindow::on_leftUpBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = make_shared<Camera>();

    GetMainCamera get_camera(camera);
   _facade->execute(get_camera);

    MoveCamera move_cmd(camera, 10, 10, 0);
    _facade->execute(move_cmd);

    updateScene();
}

void MainWindow::on_leftDownBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = make_shared<Camera>();

    GetMainCamera get_camera(camera);
   _facade->execute(get_camera);

    MoveCamera move_cmd(camera, 10, -10, 0);
    _facade->execute(move_cmd);

    updateScene();
}


void MainWindow::on_moveBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет каркасных фигур!");
        return;
    }

    shared_ptr<BaseObject> model = std::make_shared<CarcassModel>();

    GetSceneObject get_object_cmd(model, _models.at(ui->modelsCB->currentIndex()));
    _facade->execute(get_object_cmd);

    MoveModel move_cmd(model, ui->dxDSB->value(), ui->dyDSB->value(), ui->dzDSB->value());
    _facade->execute(move_cmd);

    updateScene();
}

void MainWindow::on_moveAllBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    auto composite = std::make_shared<Composite>();
    GetSceneObjects get_objs(composite);
    _facade->execute(get_objs);

    MoveModels move_cmd(composite,
            ui->dxDSB->value(),
            ui->dyDSB->value(),
            ui->dzDSB->value());

    _facade->execute(move_cmd);
    updateScene();
}

void MainWindow::on_scaleBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    shared_ptr<BaseObject> model = std::make_shared<CarcassModel>();

    GetSceneObject get_object_cmd(model, _models.at(ui->modelsCB->currentIndex()));
    _facade->execute(get_object_cmd);


    ScaleModel scale_cmd(model,
            ui->kxDSB->value(),
            ui->kyDSB->value(),
            ui->kzDSB->value());
    _facade->execute(scale_cmd);

    updateScene();
}

void MainWindow::on_scaleAllBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    auto composite = std::make_shared<Composite>();
    GetSceneObjects get_objs(composite);
    _facade->execute(get_objs);

    ScaleModels scale_cmd(composite,
            ui->kxDSB->value(),
            ui->kyDSB->value(),
            ui->kzDSB->value());
    _facade->execute(scale_cmd);

    updateScene();
}

void MainWindow::on_rotateBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    shared_ptr<BaseObject> model = std::make_shared<CarcassModel>();

    GetSceneObject get_object_cmd(model, _models.at(ui->modelsCB->currentIndex()));
    _facade->execute(get_object_cmd);

    RotateModel rotate_cmd(model,
            ui->oxDSB->value() * M_PI / 180,
            ui->oyDSB->value() * M_PI / 180,
            ui->ozDSB->value() * M_PI / 180);
    _facade->execute(rotate_cmd);

    updateScene();
}

void MainWindow::on_rotateAllBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    auto composite = std::make_shared<Composite>();
    GetSceneObjects get_objs(composite);
    _facade->execute(get_objs);

    RotateModels rotate_cmd(composite,
            ui->oxDSB->value() * M_PI / 180,
            ui->oyDSB->value() * M_PI / 180,
            ui->ozDSB->value() * M_PI / 180);
    _facade->execute(rotate_cmd);

    updateScene();
}


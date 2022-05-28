# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = lab_03

QT = core gui widgets

HEADERS = \
   $$PWD/adapters/composite/CompositeAdapter.h \
   $$PWD/adapters/composite/DrawCompositeAdapter.h \
   $$PWD/adapters/model/DrawCarcassModelAdapter.h \
   $$PWD/adapters/model/ModelAdapter.h \
   $$PWD/adapters/BaseAdapter.h \
   $$PWD/commands/BaseCommand.h \
   $$PWD/commands/CameraCommand.h \
   $$PWD/commands/ModelCommand.h \
   $$PWD/commands/ModelsCommand.h \
   $$PWD/commands/SceneCommand.h \
   $$PWD/drawer/AbstractFactory.h \
   $$PWD/drawer/BaseDrawer.h \
   $$PWD/drawer/DrawerSolution.h \
   $$PWD/drawer/DrawerSolution.hpp \
   $$PWD/drawer/QtDrawer.h \
   $$PWD/drawer/QtFactory.h \
   $$PWD/exceptions/Exceptions.h \
   $$PWD/facade/Facade.h \
   $$PWD/load/builders/camera/BaseCameraBuilder.h \
   $$PWD/load/builders/camera/CameraBuilder.h \
   $$PWD/load/builders/model/BaseModelBuilder.h \
   $$PWD/load/builders/model/ModelBuilder.h \
   $$PWD/load/builders/scene/BaseSceneBuilder.h \
   $$PWD/load/builders/scene/SceneBuilder.h \
   $$PWD/load/builders/BaseBuilder.h \
   $$PWD/load/directors/camera/BaseCameraDirector.h \
   $$PWD/load/directors/camera/FileCameraDirector.h \
   $$PWD/load/directors/loader/BaseLoader.h \
   $$PWD/load/directors/loader/FileCarcassModelLoader.h \
   $$PWD/load/directors/model/BaseModelDirector.h \
   $$PWD/load/directors/model/FileModelDirector.h \
   $$PWD/load/directors/scene/BaseSceneDirector.h \
   $$PWD/load/directors/scene/FileSceneDirector.h \
   $$PWD/load/directors/BaseDirector.h \
   $$PWD/load/moderators/camera/CameraLoadModerator.h \
   $$PWD/load/moderators/creators/CameraLoadModeratorCreator.h \
   $$PWD/load/moderators/creators/ModelLoadModeratorCreator.h \
   $$PWD/load/moderators/creators/ModeratorSolution.h \
   $$PWD/load/moderators/creators/SceneLoadModeratorCreator.h \
   $$PWD/load/moderators/model/ModelLoadModerator.h \
   $$PWD/load/moderators/scene/SceneLoadModerator.h \
   $$PWD/load/moderators/BaseLoadModerator.h \
   $$PWD/managers/creators/DrawManagerCreator.h \
   $$PWD/managers/creators/LoadManagerCreator.h \
   $$PWD/managers/creators/ManagerSolution.h \
   $$PWD/managers/creators/SceneManagerCreator.h \
   $$PWD/managers/creators/TransformManagerCreator.h \
   $$PWD/managers/draw/DrawManager.h \
   $$PWD/managers/load/LoadManager.h \
   $$PWD/managers/scene/SceneManager.h \
   $$PWD/managers/transform/TransformManager.h \
   $$PWD/managers/BaseManager.h \
   $$PWD/matrix/errors/errors.hpp \
   $$PWD/matrix/iterator/const_matrix_iterator.h \
   $$PWD/matrix/iterator/const_matrix_iterator.hpp \
   $$PWD/matrix/iterator/matrix_iterator.h \
   $$PWD/matrix/iterator/matrix_iterator.hpp \
   $$PWD/matrix/matrix/matrix.h \
   $$PWD/matrix/matrix/matrix.hpp \
   $$PWD/matrix/matrix/matrix_base.hpp \
   $$PWD/objects/invisibleobject/Camera.h \
   $$PWD/objects/invisibleobject/InVisibleObject.h \
   $$PWD/objects/visibleobject/carcassmodel/CarcassModel.h \
   $$PWD/objects/visibleobject/carcassmodel/Data.h \
   $$PWD/objects/visibleobject/carcassmodel/Edge.h \
   $$PWD/objects/visibleobject/carcassmodel/Point.h \
   $$PWD/objects/visibleobject/BaseModel.h \
   $$PWD/objects/visibleobject/VisibleObject.h \
   $$PWD/objects/BaseObject.h \
   $$PWD/objects/Composite.h \
   $$PWD/scene/Scene.h \
   $$PWD/mainwindow.h \
   adapters/light/LightAdapter.h \
   objects/visibleobject/Light.h

SOURCES = \
   $$PWD/adapters/composite/DrawCompositeAdapter.cpp \
   $$PWD/adapters/model/DrawCarcassModelAdapter.cpp \
   $$PWD/commands/BaseCommand.cpp \
   $$PWD/commands/CameraCommand.cpp \
   $$PWD/commands/ModelCommand.cpp \
   $$PWD/commands/ModelsCommand.cpp \
   $$PWD/commands/SceneCommand.cpp \
   $$PWD/drawer/QtDrawer.cpp \
   $$PWD/drawer/QtFactory.cpp \
   $$PWD/facade/Facade.cpp \
   $$PWD/load/builders/camera/CameraBuilder.cpp \
   $$PWD/load/builders/model/ModelBuilder.cpp \
   $$PWD/load/builders/scene/SceneBuilder.cpp \
   $$PWD/load/directors/camera/FileCameraDirector.cpp \
   $$PWD/load/directors/loader/BaseLoader.cpp \
   $$PWD/load/directors/loader/FileCarcassModelLoader.cpp \
   $$PWD/load/directors/model/FileModelDirector.cpp \
   $$PWD/load/directors/scene/FileSceneDirector.cpp \
   $$PWD/load/moderators/camera/CameraLoadModerator.cpp \
   $$PWD/load/moderators/creators/CameraLoadModeratorCreator.cpp \
   $$PWD/load/moderators/creators/ModelLoadModeratorCreator.cpp \
   $$PWD/load/moderators/creators/SceneLoadModeratorCreator.cpp \
   $$PWD/load/moderators/model/ModelLoadModerator.cpp \
   $$PWD/load/moderators/scene/SceneLoadModerator.cpp \
   $$PWD/load/moderators/BaseLoadModerator.cpp \
   $$PWD/managers/creators/DrawManagerCreator.cpp \
   $$PWD/managers/creators/LoadManagerCreator.cpp \
   $$PWD/managers/creators/SceneManagerCreator.cpp \
   $$PWD/managers/creators/TransformManagerCreator.cpp \
   $$PWD/managers/draw/DrawManager.cpp \
   $$PWD/managers/load/LoadManager.cpp \
   $$PWD/managers/scene/SceneManager.cpp \
   $$PWD/managers/transform/TransformManager.cpp \
   $$PWD/matrix/errors/errors.cpp \
   $$PWD/matrix/matrix/matrix_base.cpp \
   $$PWD/objects/invisibleobject/Camera.cpp \
   $$PWD/objects/visibleobject/carcassmodel/CarcassModel.cpp \
   $$PWD/objects/visibleobject/carcassmodel/Data.cpp \
   $$PWD/objects/visibleobject/carcassmodel/Edge.cpp \
   $$PWD/objects/visibleobject/carcassmodel/Point.cpp \
   $$PWD/objects/visibleobject/BaseModel.cpp \
   $$PWD/objects/BaseObject.cpp \
   $$PWD/objects/Composite.cpp \
   $$PWD/scene/Scene.cpp \
   $$PWD/main.cpp \
   $$PWD/mainwindow.cpp \
   adapters/light/LightAdapter.cpp

INCLUDEPATH = \
    $$PWD/. \
    $$PWD/adapters \
    $$PWD/adapters/light \
    $$PWD/adapters/composite \
    $$PWD/adapters/model \
    $$PWD/commands \
    $$PWD/drawer \
    $$PWD/exceptions \
    $$PWD/facade \
    $$PWD/load/builders \
    $$PWD/load/builders/camera \
    $$PWD/load/builders/model \
    $$PWD/load/builders/scene \
    $$PWD/load/directors \
    $$PWD/load/directors/camera \
    $$PWD/load/directors/loader \
    $$PWD/load/directors/model \
    $$PWD/load/directors/scene \
    $$PWD/load/moderators \
    $$PWD/load/moderators/camera \
    $$PWD/load/moderators/creators \
    $$PWD/load/moderators/model \
    $$PWD/load/moderators/scene \
    $$PWD/managers \
    $$PWD/managers/creators \
    $$PWD/managers/draw \
    $$PWD/managers/load \
    $$PWD/managers/scene \
    $$PWD/managers/transform \
    $$PWD/matrix/iterator \
    $$PWD/matrix/matrix \
    $$PWD/objects \
    $$PWD/objects/invisibleobject \
    $$PWD/objects/visibleobject \
    $$PWD/objects/visibleobject/carcassmodel \
    $$PWD/scene

FORMS += \
    mainwindow.ui

DISTFILES += \
    data/cone.txt \
    data/cube.txt \
    data/tesseract.txt
#DEFINES = 


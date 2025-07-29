#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "task_list_model.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    TaskListModel taskModel;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("taskModel", &taskModel);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("TickQuickly", "Main");

    return app.exec();
}

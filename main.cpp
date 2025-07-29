#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>

#include "local_json_task_storage.h"
#include "task_list_model.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QString filePath = QDir::homePath() + "/.config/TickQuickly/tasks.json";
    LocalJsonTaskStorage storage(filePath);
    TaskListModel taskModel(storage);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("taskModel", &taskModel);

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
        []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    engine.loadFromModule("TickQuickly", "Main");

    return app.exec();
}

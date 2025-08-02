//
// Created by ice on 25-8-1.
//

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>

#include "model/task_list_model.h"
#include "sync/sync_manager.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    // 待办清单数据模型
    auto *taskModel = new TaskListModel();
    // 同步管理器
    SyncManager syncManager(taskModel);
    syncManager.startSync();

    QQmlApplicationEngine engine;
    // 注入数据模型到 QML 上下文
    engine.rootContext()->setContextProperty("taskModel", taskModel);

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
        []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    engine.loadFromModule("TickQuickly", "Main");

    return QGuiApplication::exec();
}


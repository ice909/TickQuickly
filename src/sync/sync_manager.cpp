//
// Created by ice on 25-8-2.
//

#include "sync_manager.h"
#include <QDebug>

SyncManager::SyncManager(TaskListModel* model, QObject* parent)
    : QObject(parent), m_taskModel(model), m_api(new Api(this)) {
    QObject::connect(m_taskModel, &TaskListModel::dirtyDataChanged, this,
                     &SyncManager::onDirtyDataChanged);
}

void SyncManager::startSync() {
    m_api->fetchTask();
    connect(m_api, &Api::tasksFetched, this, [this](const QList<Task>& tasks) {
        qDebug() << "SyncManager::startSync";
        m_taskModel->setTasks(tasks);
    });
}

void SyncManager::onDirtyDataChanged() {
    QList<Task> dirtyTasks = m_taskModel->getDirtyTasks();
    if (dirtyTasks.isEmpty()) {
        qDebug() << "No dirty tasks to sync";
        return;
    }
    m_api->syncTasks(dirtyTasks);

    connect(m_api, &Api::tasksSynced, this, [this]() {
        m_api->fetchTask();
    });
    connect(m_api, &Api::tasksFetched, this, [this](const QList<Task>& tasks) {
        m_taskModel->setTasks(tasks);
    });
}
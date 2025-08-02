//
// Created by ice on 25-8-2.
//

#include "sync_manager.h"
#include <QDebug>

SyncManager::SyncManager(TaskListModel* model, QObject* parent)
    : QObject(parent), m_taskModel(model), m_api(new Api(this)) {
}

void SyncManager::startSync() {
    m_api->fetchTask();
    connect(m_api, &Api::tasksFetched, this, [this](const QList<Task>& tasks) {
        qDebug() << "SyncManager::startSync";
        m_taskModel->setTasks(tasks);
    });
}

void SyncManager::onDirtyDataChanged() {
    // 处理本地数据变更
    // 这里可以添加具体的同步逻辑，比如调用API上传数据等
    qDebug() << "Dirty data changed, syncing...";
}
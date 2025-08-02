//
// Created by ice on 25-8-2.
//

#ifndef SYNC_MANAGER_H
#define SYNC_MANAGER_H
#include <QObject>

#include "api/api.h"
#include "model/task_list_model.h"


class SyncManager : public QObject {
    Q_OBJECT

public:
    explicit SyncManager(TaskListModel* model, QObject* parent = nullptr);
    void startSync();

public slots:
    void onDirtyDataChanged();

private:
    TaskListModel *m_taskModel;
    Api *m_api;
};


#endif //SYNC_MANAGER_H
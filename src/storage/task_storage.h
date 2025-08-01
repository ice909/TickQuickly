#pragma once
#include <QString>
#include <QList>
#include "model/task.h"

class TaskStorage {
  public:
    virtual ~TaskStorage() {}
    virtual QList<Task> loadTasks() = 0;
    virtual void saveTasks(const QList<Task> &tasks) = 0;
};
#pragma once
#include "task_storage.h"

class LocalJsonTaskStorage : public TaskStorage {
  public:
    LocalJsonTaskStorage(const QString &filename);
    QList<Task> loadTasks() override;
    void saveTasks(const QList<Task> &tasks) override;

  private:
    QString m_filename;
};
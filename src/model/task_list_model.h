#pragma once
#include <QAbstractListModel>

#include "task.h"
#include "task_storage.h"

class TaskListModel : public QAbstractListModel {
    Q_OBJECT
  public:
    enum Role {
        IdRole = Qt::UserRole + 1,
        TitleRole,
        ContentRole,
        StatusRole,
        DueDateRole,
        CreatedTimeRole,
        ModifiedTimeRole,
        PriorityRole,
        IsAllDayRole,
        IsFloatingRole,
        ProjectIdRole,
        ParentIdRole,
        ChildIdsRole,
        TagsRole
    };
    Q_ENUM(Role)

    explicit TaskListModel(TaskStorage &storage, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index,
                  int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    // 添加任务接口
    Q_INVOKABLE void addTask(const QString &title);

    // 可扩展更多Q_INVOKABLE接口

  private:
    TaskStorage &m_storage;
    QList<Task> m_tasks;
};
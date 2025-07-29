#pragma once
#include "task.h"
#include <QAbstractListModel>

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

    explicit TaskListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index,
                  int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    // 添加任务接口
    Q_INVOKABLE void addTask(const QString &title);

    // 可扩展更多Q_INVOKABLE接口

  private:
    QList<Task> m_tasks;
};
#pragma once
#include <QAbstractListModel>

#include "task.h"
#include "storage/task_storage.h"

class TaskListModel : public QAbstractListModel {
    Q_OBJECT
   public:
    enum Role {
        // 基础信息
        IdRole = Qt::UserRole + 1,
        TitleRole,
        ContentRole,
        ProjectIdRole,
        ParentIdRole,

        // 状态信息
        StatusRole,
        PriorityRole,
        ProgressRole,
        DeletedRole,

        // 人员信息
        CreatorRole,
        AssigneeRole,

        // 元数据
        EtagRole,
        KindRole,
        ReminderRole,
        TimeZoneRole,
        SortOrderRole,
        IsAllDayRole,
        IsFloatingRole,

        // 时间信息
        CreatedTimeRole,
        ModifiedTimeRole,
        DueDateRole,
        StartDateRole,
        ServerDueDateRole,
        ServerStartDateRole,

        // 列表字段
        ChildIdsRole,
        TagsRole,
        ExDateRole,
        RemindersRole,
        ItemsRole
    };
    Q_ENUM(Role)

    explicit TaskListModel(TaskStorage &storage, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    // 添加任务接口
    Q_INVOKABLE void addTask(const QString &title);

   private:
    TaskStorage &m_storage;
    QList<Task> m_tasks;
};

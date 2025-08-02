#pragma once
#include <QAbstractListModel>

#include "task.h"
#include "api/api.h"

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

    explicit TaskListModel(QObject* parent = nullptr);

    [[nodiscard]] int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    [[nodiscard]] QVariant
    data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    [[nodiscard]] QHash<int, QByteArray> roleNames() const override;

    void setTasks(const QList<Task> &tasks);

    // 添加任务接口
    Q_INVOKABLE void addTask(const QString& title);
signals:
    void dirtyDataChanged();

private:
    QList<Task> m_tasks;
};
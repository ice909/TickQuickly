#include "task_list_model.h"

#include <QUuid>

TaskListModel::TaskListModel(QObject *parent) : QAbstractListModel(parent) {}

int TaskListModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return m_tasks.size();
}

QVariant TaskListModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= m_tasks.size())
        return QVariant();

    const Task &task = m_tasks.at(index.row());
    switch (role) {
    case IdRole:
        return task.id;
    case TitleRole:
        return task.title;
    case ContentRole:
        return task.content;
    case StatusRole:
        return task.status;
    case DueDateRole:
        return task.dueDate;
    case CreatedTimeRole:
        return task.createdTime;
    case ModifiedTimeRole:
        return task.modifiedTime;
    case PriorityRole:
        return task.priority;
    case IsAllDayRole:
        return task.isAllDay;
    case IsFloatingRole:
        return task.isFloating;
    case ProjectIdRole:
        return task.projectId;
    case ParentIdRole:
        return task.parentId;
    case ChildIdsRole:
        return task.childIds;
    case TagsRole:
        return task.tags;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> TaskListModel::roleNames() const {
    return {{IdRole, "id"},
            {TitleRole, "title"},
            {ContentRole, "content"},
            {StatusRole, "status"},
            {DueDateRole, "dueDate"},
            {CreatedTimeRole, "createdTime"},
            {ModifiedTimeRole, "modifiedTime"},
            {PriorityRole, "priority"},
            {IsAllDayRole, "isAllDay"},
            {IsFloatingRole, "isFloating"},
            {ProjectIdRole, "projectId"},
            {ParentIdRole, "parentId"},
            {ChildIdsRole, "childIds"},
            {TagsRole, "tags"}};
}

void TaskListModel::addTask(const QString &title) {
    beginInsertRows(QModelIndex(), m_tasks.size(), m_tasks.size());
    Task newTask;
    newTask.id = QUuid::createUuid().toString(QUuid::WithoutBraces);
    newTask.title = title;
    m_tasks.append(newTask);
    endInsertRows();
}
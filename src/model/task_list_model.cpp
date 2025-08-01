#include "task_list_model.h"

#include <QDebug>
#include <QUuid>

TaskListModel::TaskListModel(TaskStorage &storage, QObject *parent)
    : QAbstractListModel(parent), m_storage(storage) {
    m_tasks = m_storage.loadTasks();
}

int TaskListModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return m_tasks.size();
}

QVariant TaskListModel::data(const QModelIndex &index, int role) const {
    if (!checkIndex(index)) return {};

    const Task &task = m_tasks.at(index.row());

    try {
        switch (role) {
            // 基础信息
            case IdRole:
                return task.id;
            case TitleRole:
                return task.title;
            case ContentRole:
                return task.content;
            case ProjectIdRole:
                return task.projectId;
            case ParentIdRole:
                return task.parentId;

            // 状态信息
            case StatusRole:
                return task.status;
            case PriorityRole:
                return task.priority;
            case ProgressRole:
                return task.progress;
            case DeletedRole:
                return task.deleted;

            // 人员信息
            case CreatorRole:
                return task.creator;
            case AssigneeRole:
                return task.assignee;

            // 元数据
            case EtagRole:
                return task.etag;
            case KindRole:
                return task.kind;
            case ReminderRole:
                return task.reminder;
            case TimeZoneRole:
                return task.timeZone;
            case SortOrderRole:
                return task.sortOrder;
            case IsAllDayRole:
                return task.isAllDay;
            case IsFloatingRole:
                return task.isFloating;

            // 时间信息
            case CreatedTimeRole:
                return task.createdTime;
            case ModifiedTimeRole:
                return task.modifiedTime;
            case DueDateRole:
                return task.dueDate.value_or("");
            case StartDateRole:
                return task.startDate.value_or("");
            case ServerDueDateRole:
                return task.serverDueDate.value_or("");
            case ServerStartDateRole:
                return task.serverStartDate.value_or("");

            // 列表字段
            case ChildIdsRole:
                return task.childIds;
            case TagsRole:
                return task.tags;
            case ExDateRole:
                return task.exDate;
            case RemindersRole:
                return task.reminders;
            case ItemsRole:
                return task.items;

            default:
                qWarning() << "Unknown role requested:" << role;
                return {};
        }
    } catch (const std::exception &e) {
        qCritical() << "Error accessing task data:" << e.what();
        return {};
    }
}

QHash<int, QByteArray> TaskListModel::roleNames() const {
    static const QHash<int, QByteArray> roles = {// 基础信息
                                                 {IdRole, "id"},
                                                 {TitleRole, "title"},
                                                 {ContentRole, "content"},
                                                 {ProjectIdRole, "projectId"},
                                                 {ParentIdRole, "parentId"},

                                                 // 状态信息
                                                 {StatusRole, "status"},
                                                 {PriorityRole, "priority"},
                                                 {ProgressRole, "progress"},
                                                 {DeletedRole, "deleted"},

                                                 // 人员信息
                                                 {CreatorRole, "creator"},
                                                 {AssigneeRole, "assignee"},

                                                 // 元数据
                                                 {EtagRole, "etag"},
                                                 {KindRole, "kind"},
                                                 {ReminderRole, "reminder"},
                                                 {TimeZoneRole, "timeZone"},
                                                 {SortOrderRole, "sortOrder"},
                                                 {IsAllDayRole, "isAllDay"},
                                                 {IsFloatingRole, "isFloating"},

                                                 // 时间信息
                                                 {CreatedTimeRole, "createdTime"},
                                                 {ModifiedTimeRole, "modifiedTime"},
                                                 {DueDateRole, "dueDate"},
                                                 {StartDateRole, "startDate"},
                                                 {ServerDueDateRole, "serverDueDate"},
                                                 {ServerStartDateRole, "serverStartDate"},

                                                 // 列表字段
                                                 {ChildIdsRole, "childIds"},
                                                 {TagsRole, "tags"},
                                                 {ExDateRole, "exDate"},
                                                 {RemindersRole, "reminders"},
                                                 {ItemsRole, "items"}};
    return roles;
}

void TaskListModel::addTask(const QString &title) {
    if (title.isEmpty()) {
        qWarning() << "Cannot add task with empty title";
        return;
    }

    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    Task newTask;
    newTask.id = QUuid::createUuid().toString(QUuid::WithoutBraces);
    newTask.title = title;
    newTask.createdTime = QDateTime::currentDateTime().toString(Qt::ISODate);
    newTask.modifiedTime = newTask.createdTime;

    m_tasks.append(newTask);
    endInsertRows();

    m_storage.saveTasks(m_tasks);
}

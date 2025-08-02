#pragma once
#include <QDateTime>
#include <QJsonArray>
#include <QJsonObject>
#include <QString>
#include <QStringList>
#include <optional>

enum class SyncStatus {
    Clean, // 已同步
    Dirty, // 本地有修改，未同步
    Syncing, // 正在同步
    Failed // 同步失败
};

struct Task {
    QString id;
    QString title;
    QString content;
    QString projectId;
    QString parentId; // 可选，若有父任务
    int status = 0;
    int priority = 0;
    int progress = 0;
    QString creator;
    QString assignee;
    QString etag;
    QString kind;
    QString reminder;
    QString timeZone;
    QString sortOrder;
    bool isAllDay = false;
    bool isFloating = false;
    int deleted = 0;

    QString createdTime;
    QString modifiedTime;
    std::optional<QString> dueDate;
    std::optional<QString> startDate;
    std::optional<QString> serverDueDate;
    std::optional<QString> serverStartDate;

    // 列表字段
    QStringList childIds;
    QStringList tags;
    QStringList exDate;
    QStringList reminders;
    QStringList items;

    [[nodiscard]] QJsonObject toJson() const {
        QJsonObject obj;
        obj["id"] = id;
        obj["title"] = title;
        obj["content"] = content;
        obj["projectId"] = projectId;
        obj["parentId"] = parentId;
        obj["status"] = status;
        obj["priority"] = priority;
        obj["progress"] = progress;
        obj["creator"] = creator;
        obj["assignee"] = assignee;
        obj["etag"] = etag;
        obj["kind"] = kind;
        obj["reminder"] = reminder;
        obj["timeZone"] = timeZone;
        obj["sortOrder"] = sortOrder;
        obj["isAllDay"] = isAllDay;
        obj["isFloating"] = isFloating;
        obj["deleted"] = deleted;
        obj["createdTime"] = createdTime;
        obj["modifiedTime"] = modifiedTime;
        if (dueDate) obj["dueDate"] = *dueDate;
        if (startDate) obj["startDate"] = *startDate;
        if (serverDueDate) obj["serverDueDate"] = *serverDueDate;
        if (serverStartDate) obj["serverStartDate"] = *serverStartDate;

        // 列表字段
        if (!childIds.isEmpty()) obj["childIds"] = QJsonArray::fromStringList(childIds);
        if (!tags.isEmpty()) obj["tags"] = QJsonArray::fromStringList(tags);
        if (!exDate.isEmpty()) obj["exDate"] = QJsonArray::fromStringList(exDate);
        if (!reminders.isEmpty()) obj["reminders"] = QJsonArray::fromStringList(reminders);
        if (!items.isEmpty()) obj["items"] = QJsonArray::fromStringList(items);
        return obj;
    }

    static Task fromJson(QJsonObject obj) {
        Task task;
        task.id = obj["id"].toString();
        task.title = obj["title"].toString();
        task.content = obj["content"].toString();
        task.projectId = obj["projectId"].toString();
        task.parentId = obj["parentId"].toString();
        task.status = obj["status"].toInt();
        task.priority = obj["priority"].toInt();
        task.progress = obj["progress"].toInt();
        task.creator = obj["creator"].toString();
        task.assignee = obj["assignee"].toString();
        task.etag = obj["etag"].toString();
        task.reminder = obj["reminder"].toString();
        task.timeZone = obj["timeZone"].toString();
        task.sortOrder = obj["sortOrder"].toString();
        task.isAllDay = obj["isAllDay"].toBool();
        task.isFloating = obj["isFloating"].toBool();
        task.deleted = obj["deleted"].toInt();
        task.createdTime = obj["createdTime"].toString();
        task.modifiedTime = obj["modifiedTime"].toString();
        task.dueDate = obj["dueDate"].toString();
        task.startDate = obj["startDate"].toString();
        task.serverDueDate = obj["serverDueDate"].toString();
        task.serverStartDate = obj["serverStartDate"].toString();
        return task;
    }
};
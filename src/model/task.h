#pragma once
#include <QDateTime>
#include <QJsonArray>
#include <QJsonObject>
#include <QString>
#include <QStringList>
#include <optional>

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

    // 时间字段，使用 QString 或 QDateTime，建议用 QString（如原JSON格式）
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
    QStringList items; // 若 items 是嵌套子任务，建议额外定义 struct

    // 你可以根据需要添加更多字段

    QJsonObject toJson() const {
        QJsonObject obj;
        obj["id"] = id;
        obj["title"] = title;
        obj["content"] = content;
        obj["projectId"] = projectId;
        obj["status"] = status;
        obj["priority"] = priority;
        obj["progress"] = progress;
        obj["parentId"] = parentId;
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
        obj["dueDate"] = dueDate.has_value() ? dueDate.value() : "";
        obj["startDate"] = startDate.has_value() ? startDate.value() : "";
        obj["serverDueDate"] =
            serverDueDate.has_value() ? serverDueDate.value() : "";
        obj["serverStartDate"] =
            serverStartDate.has_value() ? serverStartDate.value() : "";
        obj["childIds"] = QJsonArray::fromStringList(childIds);
        obj["tags"] = QJsonArray::fromStringList(tags);
        obj["exDate"] = QJsonArray::fromStringList(exDate);
        obj["reminders"] = QJsonArray::fromStringList(reminders);
        obj["items"] = QJsonArray::fromStringList(items);
        return obj;
    }
};
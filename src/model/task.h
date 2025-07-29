#pragma once
#include <QString>
#include <QStringList>
#include <QJsonObject>
#include <QJsonArray>

struct Task {
    QString id;
    QString title;
    QString content;
    int status = 0;
    QString dueDate;
    QString createdTime;
    QString modifiedTime;
    int priority = 0;
    bool isAllDay = false;
    bool isFloating = false;
    QString projectId;
    QString parentId;
    QStringList childIds;
    QStringList tags;

    QJsonObject toJson() const {
        QJsonObject obj;
        obj["id"] = id;
        obj["title"] = title;
        obj["content"] = content;
        obj["status"] = status;
        obj["dueDate"] = dueDate;
        obj["createdTime"] = createdTime;
        obj["modifiedTime"] = modifiedTime;
        obj["priority"] = priority;
        obj["isAllDay"] = isAllDay;
        obj["isFloating"] = isFloating;
        obj["projectId"] = projectId;
        obj["parentId"] = parentId;
        obj["childIds"] = QJsonArray::fromStringList(childIds);
        obj["tags"] = QJsonArray::fromStringList(tags);
        return obj;
    }
};
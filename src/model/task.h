#pragma once
#include <QString>
#include <QStringList>

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
};
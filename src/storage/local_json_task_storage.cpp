#include "local_json_task_storage.h"
#include <QFile>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDir>

LocalJsonTaskStorage::LocalJsonTaskStorage(const QString &filename)
    : m_filename(filename) {
    qWarning() << "LocalJsonTaskStorage initialized with file:" << m_filename;
}

QList<Task> LocalJsonTaskStorage::loadTasks() {
    QList<Task> tasks;
    QFile file(m_filename);
    if (!file.exists() || !file.open(QIODevice::ReadOnly | QIODevice::Text))
        return tasks;

    QByteArray data = file.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    if (error.error != QJsonParseError::NoError || !doc.isArray())
        return tasks;

    QJsonArray arr = doc.array();
    for (const QJsonValue &val : arr) {
        if (!val.isObject())
            continue;
        QJsonObject obj = val.toObject();
        Task task;
        task.title = obj.value("title").toString();
        // 这里可扩展更多字段
        tasks.push_back(task);
    }
    return tasks;
}

void LocalJsonTaskStorage::saveTasks(const QList<Task> &tasks) {
    QJsonArray arr;
    for (const auto &task : tasks) {
        arr.append(task.toJson());
    }
    QJsonDocument doc(arr);

    QFileInfo fileInfo(m_filename);
    QDir().mkpath(fileInfo.path());
    QFile file(m_filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
}
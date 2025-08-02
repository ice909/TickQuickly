#include "api.h"
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonDocument>

Api::Api(QObject* parent)
    : QObject(parent) {
}

// 获取全部任务
void Api::fetchTask() {
    QNetworkRequest request(QUrl(m_baseUrl + "/tasks"));
    auto reply = m_manager.get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            auto data = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(data);
            // 构建QList<Tasks>
            QJsonArray tasks = doc.array();
            QList<Task> list;
            for (auto task : tasks) {
                QJsonObject obj = task.toObject();
                list.emplace_back(Task::fromJson(obj));
            }
            emit tasksFetched(list);
        } else {
            emit errorOccurred(reply->errorString());
        }
        reply->deleteLater();
    });
}

// 新建任务
void Api::createTask(Task& task) {
    QNetworkRequest request(QUrl(m_baseUrl + "/tasks"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    auto reply = m_manager.post(request, QJsonDocument(task.toJson()).toJson());

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            const auto data = reply->readAll();
            const auto doc = QJsonDocument::fromJson(data);
            const auto result = CreateTaskResult::fromJson(doc.object());
            emit taskCreated(result);
        } else {
            emit errorOccurred(reply->errorString());
        }
        reply->deleteLater();
    });
}

// 更新任务
void Api::updateTask() {
}

// 删除单条任务
void Api::deleteTask() {
}

// 清空所有任务
void Api::clearTasks() {
}

void Api::syncTasks(QList<Task>& tasks) {
    QNetworkRequest request(QUrl(m_baseUrl + "/tasks/sync"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    auto tasksArr = QJsonArray();
    for (const auto& task : tasks) {
        tasksArr.append(task.toJson());
    }
    const QJsonObject body = QJsonObject{{"tasks", tasksArr}};

    auto reply = m_manager.post(request, QJsonDocument(body).toJson());

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            const auto data = reply->readAll();
            const auto doc = QJsonDocument::fromJson(data);
            QJsonObject obj = doc.object();
            if (bool success = obj["success"].toBool()) {
                emit tasksSynced();
            }else {
                emit errorOccurred("Sync failed!");
            }
        } else {
            emit errorOccurred(reply->errorString());
        }
        reply->deleteLater();
    });
}
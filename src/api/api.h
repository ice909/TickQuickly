#ifndef API_H
#define API_H

#include <QNetworkAccessManager>
#include <QObject>
#include "model/task.h"

class Api final : public QObject {
    Q_OBJECT

Q_SIGNALS:
    void tasksFetched(const QList<Task>& tasks);
    void taskCreated();
    void taskUpdated();
    void taskDeleted();
    void errorOccurred(const QString& error);

public:
    explicit Api(QObject* parent = nullptr);
    // 获取全部任务
    void fetchTask();
    // 新建任务
    void createTask();
    // 更新任务
    void updateTask();
    // 删除单条任务
    void deleteTask();
    // 清空所有任务
    void clearTasks();

private:
    QNetworkAccessManager m_manager;
    QString m_baseUrl = "http://localhost:3000";
};

#endif // API_H
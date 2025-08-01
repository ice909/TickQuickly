#ifndef API_H
#define API_H

#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QString>
#include <QObject>

class Api : QObject {
    Q_OBJECT
  public:
    explicit Api(QObject *parent = nullptr);
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
};

#endif // API_H

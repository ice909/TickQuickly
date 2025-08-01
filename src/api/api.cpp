#include "api.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>

Api::Api(QObject *parent)
    : QObject(parent)
{
}

// 获取全部任务
void Api::fetchTask()
{
}

// 新建任务
void Api::createTask()
{
}

// 更新任务
void Api::updateTask()
{
}

// 删除单条任务
void Api::deleteTask()
{
}

// 清空所有任务
void Api::clearTasks()
{
}
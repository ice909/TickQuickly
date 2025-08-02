//
// Created by ice on 25-8-2.
//

#ifndef RESPONSE_H
#define RESPONSE_H
#include <QJsonObject>
#include <QString>

struct CreateTaskResult {
    bool success{};
    QString id;
    static CreateTaskResult fromJson(const QJsonObject &json) {
        CreateTaskResult result;
        result.success = json["success"].toBool();
        result.id = json["id"].toString();
        return result;
    }
};

#endif //RESPONSE_H

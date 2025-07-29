#include "task_list_model.h"
#include <gtest/gtest.h>

TEST(TaskListModelTest, InitialData) {
    TaskListModel model;
    EXPECT_EQ(model.rowCount(), 2);
    QModelIndex idx = model.index(0, 0);
    EXPECT_EQ(model.data(idx, TaskListModel::TitleRole).toString(), "写日报");
}

TEST(TaskListModelTest, AddTask) {
    TaskListModel model;
    model.addTask("测试新任务");
    EXPECT_EQ(model.rowCount(), 3);
    QModelIndex idx = model.index(2, 0);
    EXPECT_EQ(model.data(idx, TaskListModel::TitleRole).toString(),
              "测试新任务");
}
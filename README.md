# TickQuickly

TickQuickly 是一个简洁的桌面任务管理工具，基于 Qt/QML 开发，支持本地 JSON 文件存储任务。适合需要轻量级 To-Do 管理的用户。

## 功能特性

- 添加任务：支持快速录入任务标题
- 任务列表：左侧展示所有任务
- 本地存储：任务数据保存在本地 JSON 文件中（`~/.config/TickQuickly/tasks.json`）
- 跨平台：基于 Qt6，支持 Windows、Linux、macOS

## 构建与运行

### 依赖

- Qt 6.8 及以上（需包含 QtQuick/QtQuick.Controls 模块）
- CMake 3.16 及以上
- Ninja（推荐）
- GTest（用于测试，可选）

### 构建步骤

```bash
git clone https://github.com/ice909/TickQuickly.git
cd TickQuickly
cmake -B build -G Ninja
cmake --build build
./build/appTickQuickly
```

### 运行测试

```bash
cmake --build build --target test_task_list_model
./build/test_task_list_model
```

## 目录结构

```
TickQuickly/
├── qml/                  # QML UI 文件
├── src/                  # 源码（模型、存储等）
├── tests/                # 单元测试
├── CMakeLists.txt        # CMake 构建脚本
└── main.cpp              # 程序入口
```

## 贡献

欢迎 Issues 和 PR！开发中欢迎提出建议。

## 许可

MIT License

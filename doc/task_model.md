# 任务模型

| 字段名       | 类型        | 示例值                         | 说明                                |
| ------------ | ----------- | ------------------------------ | ----------------------------------- |
| id           | String      | "6888a7f6d1db02607c2d37d8"     | 任务唯一标识符，24 字符十六进制格式 |
| title        | String      | ""                             | 任务标题/名称                       |
| content      | String      | ""                             | 任务详细内容/描述                   |
| projectId    | String      | "inbox1022220478"              | 所属项目/列表 ID                    |
| parentId     | String      | "68782f77bbd44da3e961fd48"     | 父任务 ID（用于子任务）             |
| childIds     | Array       | []                             | 子任务 ID 集合                      |
| dueDate      | Null/String | null                           | 任务截止日期(ISO 格式)              |
| startDate    | Null/String | null                           | 任务开始日期                        |
| isAllDay     | Boolean     | true                           | 是否为全天任务                      |
| priority     | Integer     | 0                              | 优先级(0-无,1-低,3-中,5-高)         |
| status       | Integer     | 0                              | 任务状态(0-未完成,1-已完成)         |
| deleted      | Integer     | 0                              | 是否已删除(0-否,1-是)               |
| createdTime  | String      | "2025-07-29T10:52:38.000+0000" | 创建时间(ISO 格式)                  |
| modifiedTime | String      | "2025-07-29T10:52:40.135+0000" | 最后修改时间                        |
| creator      | Number      | 1022220478                     | 创建者用户 ID                       |
| assignee     | Null/Number | null                           | 任务分配对象用户 ID                 |
| sortOrder    | Number      | 3298535211008                  | 排序权重值                          |
| isFloating   | Boolean     | false                          | 是否是无日期任务                    |
| timeZone     | String      | "Asia/Shanghai"                | 任务时区                            |
| reminders    | Array       | []                             | 提醒时间数组                        |
| reminder     | String      | ""                             | 旧版提醒设置(兼容字段)              |
| remindTime   | Null/String | null                           | 下次提醒时间                        |
| tags         | Array       | []                             | 标签 ID 数组                        |
| progress     | Integer     | 0                              | 进度百分比(0-100)                   |
| kind         | String      | "TEXT"                         | 任务类型(TEXT/CHECKLIST 等)         |
| etag         | String      | "qr7jhk8o"                     | 数据版本标识(用于同步)              |
| columnId     | String      | ""                             | 看板模式下所属列 ID                 |
| exDate       | Array       | []                             | 排除日期(用于重复任务)              |

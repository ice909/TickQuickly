import type {Task} from "@/types/task.ts";
import Dexie, {type Table} from 'dexie';

class TodoDatabase extends Dexie {
  tasks!: Table<Task>;  // 声明 todoItems 是 TodoItem 类型的表

  constructor() {
    super('TodoDatabase');
    this.version(1).stores({
      tasks: 'id, parentId, title, content, completed, createdAt, updatedAt, dueDate, priority, tags, sortOrder, expanded, deletedAt',
    });
  }

  // 添加待办事项
  async addTask(task: Task) {
    const now = new Date().toISOString();
    await this.tasks.add({...task, createdAt: now, updatedAt: now});
  }

  // 获取所有待办事项（未删除）
  async getAllTasks() {
    return this.tasks.filter(task => !task.deletedAt).toArray();
  }

  // 获取已删除的待办事项
  async getDeletedTasks() {
    return this.tasks.filter(task => !!task.deletedAt).toArray();
  }

  // 获取特定父任务的子任务
  async getSubtasks(parentId: string) {
    return this.tasks.where('parentId').equals(parentId).toArray();
  }

  // 更新待办事项
  async updateTask(id: string, updates: Partial<Task>) {
    return this.tasks.update(id, {...updates, updatedAt: new Date().toISOString()});
  }

  // 删除待办事项
  async deleteTask(id: string) {
    return this.tasks.delete(id);
  }

  // 软删除（标记为已删除）
  async softDeleteTask(id: string) {
    const now = new Date().toISOString();
    return this.tasks.update(id, {deletedAt: now, updatedAt: now});
  }
}

export default TodoDatabase;

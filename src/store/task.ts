import {create} from "zustand";
import {v4 as uuidv4} from "uuid";
import type {Task} from "@/types/task.ts";
import {db} from "@/db";

interface TaskStore {
  tasks: Task[];
  toggleTaskCompleted: (id: string) => void;
  addTask: (title: string) => void;
  loadTasks: () => Promise<void>;
  saveTaskToDB: (id: string) => Promise<void>;
  moveTask: (fromIndex: number, toIndex: number) => void;
}

const tasks: Task[] = []

const INIT_SORT_ORDER = -9000000000000000;

const getNextSortOrder = (tasks: Task[]) => {
  if (tasks.length === 0) return INIT_SORT_ORDER;
  return Math.max(...tasks.map(task => task.sortOrder)) + 1000;
};

function reorderTodoTasks(tasks: Task[]) {
  // 假设每个任务间隔 1000
  const step = 1000;
  return tasks.map((task, idx) => ({
    ...task,
    sortOrder: (tasks.length - idx) * step + INIT_SORT_ORDER, // 越靠前sortOrder越大
  }));
}

export const useTaskStore = create<TaskStore>((set, get) => ({
  tasks: tasks,
  //切换任务完成状态
  toggleTaskCompleted: (id: string) => {
    set((state) => {
      const updatedTasks = state.tasks.map(task =>
        task.id === id ? {...task, completed: !task.completed} : task
      );
      const updatedTask = updatedTasks.find(task => task.id === id);
      // 可以在 set 外执行副作用
      if (updatedTask) {
        db.updateTask(id, {completed: updatedTask.completed});
      }
      return {tasks: updatedTasks};
    });
  }
  ,
  //添加新任务
  addTask: (title: string) =>
    set((state: { tasks: Task[] }) => {
      const sortOrder = getNextSortOrder(state.tasks);
      const newTask: Task = {
        id: uuidv4(),
        title,
        content: "",
        sortOrder,
        parentId: "",
        completed: false
      };

      const _tasks = [newTask, ...state.tasks];
      console.log("Adding new task:", _tasks);
      db.addTask(newTask)
      return {tasks: _tasks};
    }),
  loadTasks: async () => {
    const tasks = await db.getAllTasks();
    console.log("Loaded tasks:", tasks);
    set({tasks});
  },
  saveTaskToDB: async (id) => {
    const task = get().tasks.find(t => t.id === id);
    if (task) {
      await db.tasks.put(task); // 或 db.tasks.update
    }
  },

  moveTask: (fromIndex: number, toIndex: number) => {
    if (fromIndex === toIndex) return;
    set((state) => {
      let todoTasks = state.tasks
        .filter(t => !t.completed)
        .sort((a, b) => b.sortOrder - a.sortOrder);

      const movedTask = todoTasks[fromIndex];
      todoTasks.splice(fromIndex, 1);
      todoTasks.splice(toIndex, 0, movedTask);

      // 判断是否需要重排（比如最后插入，或者差值太小）
      let needReorder = false;
      if (toIndex === 0) {
        const first = todoTasks[0];
        const second = todoTasks[1];
        if (second && first.sortOrder - second.sortOrder < 2) needReorder = true;
      } else if (toIndex === todoTasks.length - 1) {
        const last = todoTasks[todoTasks.length - 1];
        const prev = todoTasks[todoTasks.length - 2];
        if (prev && prev.sortOrder - last.sortOrder < 2) needReorder = true;
      } else {
        const before = todoTasks[toIndex - 1];
        const after = todoTasks[toIndex + 1];
        if (before && after && before.sortOrder - after.sortOrder < 2) needReorder = true;
      }

      if (needReorder) {
        // 全量重排
        todoTasks = reorderTodoTasks(todoTasks);
        // 批量更新数据库
        todoTasks.forEach(task => db.updateTask(task.id, { sortOrder: task.sortOrder }));
      } else {
        // 正常只更新被移动的那个
        let newOrder: number;
        const before = todoTasks[toIndex - 1];
        const after = todoTasks[toIndex + 1];
        if (before && after) {
          newOrder = (before.sortOrder + after.sortOrder) / 2;
        } else if (!before && after) {
          newOrder = after.sortOrder + 1000;
        } else if (before && !after) {
          newOrder = before.sortOrder - 1000;
        } else {
          newOrder = INIT_SORT_ORDER;
        }
        todoTasks[toIndex].sortOrder = newOrder;
        db.updateTask(todoTasks[toIndex].id, { sortOrder: newOrder });
      }

      // 拼回完整任务列表
      const allTasks = [
        ...todoTasks,
        ...state.tasks.filter(t => t.completed),
      ];
      return { tasks: allTasks };
    })
  }
}));
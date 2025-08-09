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
}

const tasks: Task[] = []

const INIT_SORT_ORDER = -9000000000000000;

const getNextSortOrder = (tasks: Task[]) => {
  if (tasks.length === 0) return INIT_SORT_ORDER;
  return Math.max(...tasks.map(task => task.sortOrder)) + 1000;
};

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
      console.log("Adding new task:", state.tasks);
      db.addTask(newTask)
      return {tasks: [newTask, ...state.tasks]};
    }),
  loadTasks: async () => {
    const tasks = await db.getAllTasks();
    console.log("Loaded tasks:", tasks);
    set({tasks});
    console.log(tasks);
  },
  saveTaskToDB: async (id) => {
    const task = get().tasks.find(t => t.id === id);
    if (task) {
      await db.tasks.put(task); // 或 db.tasks.update
    }
  },
}));
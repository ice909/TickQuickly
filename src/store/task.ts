import { create } from "zustand";
import { v4 as uuidv4 } from "uuid";

export interface Task {
  id: string;
  title: string;
  sortOrder: number;
  completed: boolean;
}

interface TaskStore {
  tasks: Task[];
  toggleTaskCompleted: (id: string) => void;
  addTask: (title: string) => void;
}

const tasks: Task[] = [

  { id: "1", title: "Sample Task", sortOrder: 1, completed: false },
  { id: "2", title: "Another Task", sortOrder: 2, completed: false },
  { id: "3", title: "Yet Another Task", sortOrder: 3, completed: true },
  { id: "4", title: "Task Four", sortOrder: 4, completed: false },
  { id: "5", title: "Task Five", sortOrder: 5, completed: true },
  { id: "6", title: "Task Six", sortOrder: 6, completed: false },
  { id: "7", title: "Task Seven", sortOrder: 7, completed: true },
  { id: "8", title: "Task Eight", sortOrder: 8, completed: false },
  { id: "9", title: "Task Nine", sortOrder: 9, completed: true },
  { id: "10", title: "Task Ten", sortOrder: 10, completed: false },
  { id: "11", title: "Task Eleven", sortOrder: 11, completed: true },
  { id: "12", title: "Task Twelve", sortOrder: 12, completed: false },
  { id: "13", title: "Task Thirteen", sortOrder: 13, completed: true },
  { id: "14", title: "Task Fourteen", sortOrder: 14, completed: false },
  { id: "15", title: "Task Fifteen", sortOrder: 15, completed: true },
  { id: "16", title: "Task Sixteen", sortOrder: 16, completed: false },
  { id: "17", title: "Task Seventeen", sortOrder: 17, completed: true },
  { id: "18", title: "Task Eighteen", sortOrder: 18, completed: false },
  { id: "19", title: "Task Nineteen", sortOrder: 19, completed: true },
  { id: "20", title: "Task Twenty", sortOrder: 20, completed: false }
]

const INIT_SORT_ORDER = -9000000000000000;

const getNextSortOrder = (tasks: Task[]) => {
  if (tasks.length === 0) return INIT_SORT_ORDER;
  return Math.max(...tasks.map(task => task.sortOrder)) + 1;
};

export const useTaskStore = create<TaskStore>((set) => ({
  tasks: tasks,
  //切换任务完成状态
  toggleTaskCompleted: (id: string) =>
    set((state: { tasks: Task[] }) => ({
      tasks: state.tasks.map((task: Task) =>
        task.id === id ? { ...task, completed: !task.completed } : task
      )
    }))
  ,
  //添加新任务
  addTask: (title: string) =>
    set((state: { tasks: Task[] }) => {
      const sortOrder = getNextSortOrder(state.tasks);
      const newTask: Task = {
        id: uuidv4(),
        title,
        sortOrder,
        completed: false
      };
      return { tasks: [newTask, ...state.tasks] };
    })
}));
import { create } from "zustand";
import { v4 as uuidv4 } from "uuid";

export interface Task {
  id: string;
  title: string;
  completed: boolean;
}

interface TaskStore {
  tasks: Task[];
  selectedTaskId: string | null;
  toggleTaskCompleted: (id: string) => void;
  addTask: (title: string) => void;
}

const tasks: Task[] = [

  { id: "1", title: "Sample Task", completed: false },
  { id: "2", title: "Another Task", completed: false },
  { id: "3", title: "Yet Another Task", completed: true },
  { id: "4", title: "Task Four", completed: false },
  { id: "5", title: "Task Five", completed: true },
  { id: "6", title: "Task Six", completed: false },
  { id: "7", title: "Task Seven", completed: true },
  { id: "8", title: "Task Eight", completed: false },
  { id: "9", title: "Task Nine", completed: true },
  { id: "10", title: "Task Ten", completed: false },
  { id: "11", title: "Task Eleven", completed: true },
  { id: "12", title: "Task Twelve", completed: false },
  { id: "13", title: "Task Thirteen", completed: true },
  { id: "14", title: "Task Fourteen", completed: false },
  { id: "15", title: "Task Fifteen", completed: true },
  { id: "16", title: "Task Sixteen", completed: false },
  { id: "17", title: "Task Seventeen", completed: true },
  { id: "18", title: "Task Eighteen", completed: false },
  { id: "19", title: "Task Nineteen", completed: true },
  { id: "20", title: "Task Twenty", completed: false }
]

export const useTaskStore = create<TaskStore>((set) => ({
  tasks: tasks,
  selectedTaskId: tasks.length > 0 ? tasks[0].id : null,
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
      const newTask: Task = {
        id: uuidv4(),
        title,
        completed: false
      };
      return { tasks: [newTask, ...state.tasks] };
    })
}));
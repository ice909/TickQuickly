import { create } from "zustand";

export const useTaskStore = create(() => ({
  tasks: [{ id: 1, title: "Sample Task", completed: false },
  { id: 2, title: "Another Task", completed: false },
  { id: 3, title: "Yet Another Task", completed: true },
  { id: 4, title: "Task Four", completed: false },
  { id: 5, title: "Task Five", completed: true }
  ]
}));
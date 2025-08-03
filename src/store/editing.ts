import { create } from "zustand";

interface EditingStore {
  editingTaskId: string | null;
  setEditingTaskId: (id: string | null) => void;
}

export const useEditingStore = create<EditingStore>((set) => ({
  editingTaskId: null,
  setEditingTaskId: (id) => set({ editingTaskId: id }),
}));
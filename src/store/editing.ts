import { create } from "zustand";

interface EditingStore {
  editingTaskId: string | null;
  setEditingTaskId: (id: string | null) => void;
  exitEditing: () => void;
}

export const useEditingStore = create<EditingStore>((set) => ({
  editingTaskId: null,
  setEditingTaskId: (id) => set({ editingTaskId: id }),
  exitEditing: () => set({ editingTaskId: null })
}));
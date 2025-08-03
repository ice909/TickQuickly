import { useEditingStore } from '@/store/editing';
import { useTaskStore } from '@/store/task';

export function TaskDetail() {
  const id = useEditingStore((state) => state.editingTaskId);
  const task = useTaskStore((state) =>
    state.tasks.find((task) => task.id === id)
  );
  return task ? (
    <div></div>
  ) : (
    <div className="flex-1 flex items-center justify-center bg-muted/30">
      <div className="text-center space-y-3">
        <div className="w-16 h-16 mx-auto bg-muted rounded-full flex items-center justify-center">
          <svg
            xmlns="http://www.w3.org/2000/svg"
            width="24"
            height="24"
            viewBox="0 0 24 24"
            fill="none"
            stroke="currentColor"
            strokeWidth="2"
            strokeLinecap="round"
            strokeLinejoin="round"
            className="lucide lucide-tag w-8 h-8 text-muted-foreground"
            aria-hidden="true"
          >
            <path d="M12.586 2.586A2 2 0 0 0 11.172 2H4a2 2 0 0 0-2 2v7.172a2 2 0 0 0 .586 1.414l8.704 8.704a2.426 2.426 0 0 0 3.42 0l6.58-6.58a2.426 2.426 0 0 0 0-3.42z"></path>
            <circle cx="7.5" cy="7.5" r=".5" fill="currentColor"></circle>
          </svg>
        </div>
        <div>
          <div className="font-medium text-foreground">选择一个任务</div>
          <div className="text-sm text-muted-foreground mt-1">
            <p>点击左侧任务查看详细信息</p>
          </div>
        </div>
      </div>
    </div>
  );
}

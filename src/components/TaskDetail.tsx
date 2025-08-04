import { useEditingStore } from '@/store/editing';
import { useTaskStore } from '@/store/task';
import TagIcon from '@/assets/icons/tag.svg';
import CloseIcon from '@/assets/icons/close.svg';

export function TaskDetail() {
  const { editingTaskId, exitEditing } = useEditingStore();
  const task = useTaskStore((state) =>
    state.tasks.find((task) => task.id === editingTaskId)
  );

  function renderEmptyState() {
    return (
      <div className="flex-1 flex items-center justify-center bg-muted/30">
        <div className="text-center space-y-3">
          <div className="w-16 h-16 mx-auto bg-muted rounded-full flex items-center justify-center">
            <img src={TagIcon} className="w-8 h-8 text-muted-foreground" />
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

  return task ? (
    <div className="flex-1">
      <div className="w-full flex justify-between items-center p-5">
        <h2>任务详情</h2>
        <button
          className="inline-flex justify-center items-center h-8 w-8 p-0 hover:bg-muted rounded-md cursor-pointer"
          onClick={exitEditing}
        >
          <img src={CloseIcon} className="w-4 h-4 text-muted-foreground" />
        </button>
      </div>
    </div>
  ) : (
    renderEmptyState()
  );
}

import { useEditingStore } from '@/store/editing';
import { useTaskStore } from '@/store/task';
import TagIcon from '@/assets/icons/tag.svg';
import CloseIcon from '@/assets/icons/close.svg';
import { Checkbox } from '@/components/ui/checkbox';
import { Input } from '@/components/ui/input';

export function TaskDetail() {
  const { editingTaskId, exitEditing } = useEditingStore();
  const task = useTaskStore((state) =>
    state.tasks.find((task) => task.id === editingTaskId)
  );
  const { toggleTaskCompleted } = useTaskStore();

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
      <div className="w-full flex flex-col justify-between gap-[14px] p-5 border-b-1 border-b-solid border-b-border">
        <div className="w-full flex justify-between items-center">
          <h2>任务详情</h2>
          <button
            className="inline-flex justify-center items-center h-8 w-8 p-0 hover:bg-muted rounded-md cursor-pointer"
            onClick={exitEditing}
          >
            <img src={CloseIcon} className="w-4 h-4 text-muted-foreground" />
          </button>
        </div>
        <div className='flex items-center gap-3'>
          <Checkbox
            checked={task.completed}
            onCheckedChange={() => {
              toggleTaskCompleted(task.id);
            }}
          />
          <Input value={task.title} onChange={(e) => {
            task.title = e.target.value;
            useTaskStore.setState((state) => ({
              tasks: state.tasks.map((t) =>
                t.id === task.id ? { ...t, title: e.target.value } : t
              )
            }));
          }} />
        </div>
      </div>
    </div>
  ) : (
    renderEmptyState()
  );
}

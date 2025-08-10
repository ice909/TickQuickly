import {Checkbox} from '@/components/ui/checkbox';
import {useEditingStore} from '@/store/editing';
import {useTaskStore} from '@/store/task';
import type {Task} from '@/types/task';
import {useSortable} from '@dnd-kit/sortable';
import {CSS} from '@dnd-kit/utilities';

interface TaskItemProps {
  task: Task;
}

export function TaskItem({task}: TaskItemProps) {
  const {toggleTaskCompleted} = useTaskStore();
  const {editingTaskId, setEditingTaskId} = useEditingStore();
  const {attributes, listeners, setNodeRef, transform, transition} =
    useSortable({id: task.id});
  const style = {
    transform: CSS.Translate.toString(transform),
    transition,
  };
  return (
    <div
      id={task.id}
      ref={setNodeRef}
      style={style}
      data-task-id={task.id}
      className={`cursor-pointer transition-colors ${
        editingTaskId === task.id
          ? 'bg-accent/80 border-l-3 border-l-solid border-l-primary'
          : 'hover:bg-accent/50'
      }`}
      onClick={() => {
        setEditingTaskId(task.id);
      }}
      {...attributes}
      {...listeners}
    >
      <div className="flex items-center gap-3 p-3 hover:bg-accent/50 border-b border-b-solid border-b-border/50">
        <Checkbox
          checked={task.completed}
          onCheckedChange={() => {
            toggleTaskCompleted(task.id);
          }}
        />
        <div
          className={`${
            task.completed ? 'line-through text-muted-foreground' : ''
          }`}
        >
          {task.title}
        </div>
      </div>
    </div>
  );
}

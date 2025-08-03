import { useTaskStore } from '@/store/task';
import { useEffect, useRef, useState } from 'react';
import { Input } from '@/components/ui/input';

export function CreateTask() {
  const { addTask } = useTaskStore();
  const [taskTitle, setTaskTitle] = useState('');
  const [isCreating, setIsCreating] = useState(false);
  const inputRef = useRef<HTMLInputElement>(null);

  useEffect(() => {
    if (isCreating && inputRef.current) {
      inputRef.current.focus();
    }
  }, [isCreating]);

  const handleAddTask = () => {
    if (taskTitle.trim()) {
      addTask(taskTitle);
      setTaskTitle('');
    }
    setIsCreating(false);
  };

  return (
    <div className="flex items-center h-[53px] border-b border-b-solid border-b-border">
      {!isCreating ? (
        <div
          className="flex-1 h-full cursor-pointer hover:bg-accent/50"
          onClick={() => setIsCreating(true)}
        >
          <div className="py-4 px-6 flex items-center">添加任务</div>
        </div>
      ) : (
        <div className="flex-1 h-full flex items-center p-4">
          <Input
            ref={inputRef}
            type="text"
            value={taskTitle}
            onChange={(e) => setTaskTitle(e.target.value)}
            placeholder="添加任务"
            onKeyDown={(e) => {
              if (e.key === 'Enter') {
                handleAddTask();
              }
            }}
          />
        </div>
      )}
    </div>
  );
}

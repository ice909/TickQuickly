import { useState } from 'react';
import { useTaskStore } from '../store/task';
import { TaskItem } from './TaskItem';
import { ScrollArea } from '@/components/ui/scroll-area';

export function TaskList() {
  const { tasks } = useTaskStore();
  const todoTasks = tasks.filter((task) => !task.completed);
  const completedTasks = tasks.filter((task) => task.completed);
  const [selectedTaskId] = useState<number | null>(
    todoTasks.length > 0 ? todoTasks[0].id : null
  );

  return (
    <div className="w-96 h-screen flex flex-col bg-background border-r border-r-solid border-r-border">
      <div className="p-6 border-b border-b-solid border-b-border">
        <h2 className="text-2xl font-semibold text-foreground">待办清单</h2>
        <p className="text-sm text-muted-foreground mt-1">
          {todoTasks.length} 个待完成任务, {completedTasks.length} 个已完成
        </p>
      </div>
      {/* 滚动区域 */}
      <ScrollArea className="flex-1 overflow-hidden">
        <div>
          {todoTasks.map((task) => (
            <div
              key={task.id}
              className={`cursor-pointer transition-colors ${
                selectedTaskId === task.id
                  ? 'bg-accent/80 border-l-3 border-l-solid border-l-primary'
                  : 'hover:bg-accent/50'
              }`}
            >
              <TaskItem task={task} />
            </div>
          ))}
        </div>
        <div className="my-4 border-b border-b-solid border-b-border"></div>
        <div className="pb-2">
          <div className="px-3 py-2 text-sm text-muted-foreground">已完成</div>
          {completedTasks.map((task) => (
            <div
              key={task.id}
              className={`cursor-pointer transition-colors ${
                selectedTaskId === task.id
                  ? 'bg-accent/80 border-l-3 border-l-pgrayrimary'
                  : 'hover:bg-accent/50'
              }`}
            >
              <TaskItem task={task} />
            </div>
          ))}
        </div>
      </ScrollArea>
    </div>
  );
}

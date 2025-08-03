import { useTaskStore } from '@/store/task';
import { TaskItem } from './TaskItem';
import { ScrollArea } from '@/components/ui/scroll-area';
import { AnimatePresence } from 'framer-motion';
import { CreateTask } from './CreateTask';

export function TaskList() {
  const { tasks } = useTaskStore();
  const todoTasks = tasks.filter((task) => !task.completed);
  const completedTasks = tasks.filter((task) => task.completed);

  return (
    <div className="w-96 h-screen flex flex-col bg-background border-r border-r-solid border-r-border">
      <div className="p-6 border-b border-b-solid border-b-border">
        <h2 className="text-2xl font-semibold text-foreground">待办清单</h2>
        <p className="text-sm text-muted-foreground mt-1">
          {todoTasks.length} 个待完成任务, {completedTasks.length} 个已完成
        </p>
      </div>
      <CreateTask />
      <ScrollArea className="flex-1 overflow-hidden">
        
        <div>
          <AnimatePresence>
            {todoTasks.map((task) => (
              <TaskItem task={task} key={task.id} />
            ))}
          </AnimatePresence>
        </div>
        <div className="my-4 border-b border-b-solid border-b-border"></div>
        <div className="pb-2">
          <div className="px-3 py-2 text-sm text-muted-foreground">已完成</div>
          <AnimatePresence>
            {completedTasks.map((task) => (
              <TaskItem task={task} key={task.id} />
            ))}
          </AnimatePresence>
        </div>
      </ScrollArea>
    </div>
  );
}

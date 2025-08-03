import { Checkbox } from "@/components/ui/checkbox"
import { useTaskStore } from '@/store/task';
import type { Task } from '@/store/task';
import { motion } from 'framer-motion';

interface TaskItemProps {
	task: Task;
}

export function TaskItem({ task }: TaskItemProps) {
	const { toggleTaskCompleted, selectedTaskId } = useTaskStore();
	return (
		<motion.div
			layout
			animate={{ opacity: 1 }}
			initial={{ opacity: 0 }}
			exit={{ opacity: 0 }}
      transition={{ duration: 0.3 }}
      data-task-id={task.id}
      className={`cursor-pointer transition-colors ${
        selectedTaskId === task.id
          ? 'bg-accent/80 border-l-3 border-l-solid border-l-primary'
          : 'hover:bg-accent/50'
      }`}
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
    </motion.div>
  );
}
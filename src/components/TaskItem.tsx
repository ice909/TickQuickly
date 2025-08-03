import { Checkbox } from "@/components/ui/checkbox"
import { useTaskStore } from '@/store/task';
import type { Task } from '@/store/task';

interface TaskItemProps {
	task: Task;
}

export function TaskItem({ task }: TaskItemProps) {
	const { toggleTaskCompleted } = useTaskStore();
	return (
		<div
			data-task-id={task.id}
			className="flex items-center gap-3 p-3 hover:bg-accent/50 border-b border-b-solid border-b-border/50"
		>
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
	);
}
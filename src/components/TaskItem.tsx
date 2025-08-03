import { Checkbox } from "@/components/ui/checkbox"
import { useState } from "react";

export function TaskItem({
    task: { id = 0, title = "", completed = false }
}) {
    const [selectedTaskId, setSelectedTaskId] = useState<boolean>(completed);
    return (
      <div
        data-task-id={id}
        className="flex items-center gap-3 p-3 hover:bg-accent/50 border-b border-b-solid border-b-border/50"
      >
        <Checkbox
          checked={selectedTaskId}
          onCheckedChange={(state) => {
            setSelectedTaskId(state === true);
          }}
                
        />
        <div className={`${selectedTaskId ? 'line-through text-muted-foreground' : ''}`}>{title}</div>
      </div>
    );
}
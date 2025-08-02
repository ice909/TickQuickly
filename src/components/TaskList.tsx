export function TaskList() { 
    return (
      <div className="w-96 flex flex-col bg-background border-r border-r-solid border-r-borderColor">
        <div className="p-6 border-b border-b-solid border-b-borderColor">
          <h2 className="text-2xl font-semibold text-foreground">待办清单</h2>
          <p className="text-sm text-muted-foreground mt-1">
            5 个待完成任务, 0 个已完成
          </p>
        </div>
        {/* 滚动区域 */}
        <div className="flex-1 overflow-y-auto">
          
        </div>
      </div>
    );
}
import {TaskDetail} from "./components/TaskDetail"
import {TaskList} from "./components/TaskList"
import {init as initDB} from "@/db";
import {useTaskStore} from "@/store/task.ts";
import {useEffect} from "react";

function App() {
  const loadTasks = useTaskStore(state => state.loadTasks);

  useEffect(() => {
    // 初始化数据库后再加载任务
    initDB().then(() => loadTasks());
  }, [loadTasks]);
  return (
    <div className="h-screen flex bg-background">
      <TaskList/>
      <TaskDetail/>
    </div>
  );
}

export default App

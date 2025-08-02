import { TaskDetail } from "./components/TaskDetail"
import { TaskList } from "./components/TaskList"


function App() {

  return (
    <>
      <div className="h-screen flex bg-background">
        <TaskList />
        <TaskDetail />
      </div>
    </>
  )
}

export default App

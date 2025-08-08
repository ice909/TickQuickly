import TodoDatabase from './db';

// 创建并导出数据库实例
const db = new TodoDatabase();

// 初始化数据库连接
async function init() {
    await db.open(); // 打开数据库
}

export { db, init };
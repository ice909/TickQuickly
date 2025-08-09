export interface Task {
    id: string;
    parentId: string;
    title: string;
    content: string;
    completed?: boolean;
    createdAt?: string;
    updatedAt?: string;
    dueDate?: string;
    priority?: number;
    tags?: string;
    sortOrder: number;
    expanded?: boolean;
    deletedAt?: string;
}
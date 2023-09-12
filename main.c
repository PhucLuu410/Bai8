#include <stdio.h>
#include <stdlib.h>

struct Queue 
{
    int array[100];
    int front;
    int rear;
    int size;
    int capacity;
};

struct Queue createQueue(unsigned int capacity) 
{
    struct Queue queue;
    queue.capacity = capacity;
    queue.front = 0;
    queue.rear = capacity - 1;
    queue.size = 0;
    return queue;
}

int isFull(struct Queue queue) 
{
    if (queue.capacity == queue.size)
    {
        printf("Full");
    }
}

int isEmpty(struct Queue queue) 
{
    if (queue.size == 0)
    {
        printf("Empty");
    }
}

struct Queue enqueue(struct Queue queue, int item) 
{
    if (queue.size == queue.capacity)
    {
        printf("Cannot add more item\n");
        return queue;
    }

    queue.rear = (queue.rear + 1) % queue.capacity;
    queue.array[queue.rear] = item;
    queue.size++;
    return queue;
}

struct Queue dequeue(struct Queue queue)
{
    if (queue.size == 0)
    {
        printf("Queue now empty\n");
        return queue;
    }
    queue.front = (queue.front + 1) % queue.capacity;
    queue.size--;
    return queue;
}

int main() {
    struct Queue queue = createQueue(5);

    // Thêm phần tử vào Queue
    queue=enqueue(queue, 20);
    queue=enqueue(queue, 30);
    queue=enqueue(queue, 40);
    queue=enqueue(queue, 50);


    // Lấy phần tử ra Queue
    queue=dequeue(queue);
    queue=dequeue(queue);
    queue=dequeue(queue);
    queue=dequeue(queue);
    queue=dequeue(queue);
    queue=dequeue(queue);
    // In ra phần tử ở đầu và cuối Queue
    printf("first:%d\n", queue.array[queue.front]);
    printf("last:%d\n", queue.array[queue.rear]);

    return 0;
}
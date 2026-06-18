/*14)Task Scheduler Using Circular Queue

Imagine you are designing a task scheduling system for a computer server that processes background jobs such as file backups, system updates, and report generation. The server can handle only a fixed number of tasks at a time, and tasks are processed in a First-Come-First-Served (FCFS) order.To efficiently reuse the available task slots, the system uses a circular scheduling mechanism. When a task is completed, its slot becomes available again, and new tasks can be placed in that position. This circular behavior ensures that the scheduler continuously reuses freed slots without wasting space.You are required to implement this system using a Circular Queue.



Problem Statement

Implement a circular queue for the task scheduling system where the following operations are supported:

Add a task: When a new job is submitted to the server, it is added to the queue. If the queue is full, the system should inform that no more tasks can be scheduled.
Remove a task: When a task is completed, it is removed from the front of the queue, freeing the slot for new tasks.
View the next task: The system should be able to check which task will be executed next without removing it.
Check if all slots are filled: The system should determine whether the task queue is full or empty.
You need to implement a CircularQueue class to handle the following operations:

enqueue(int taskID) – Adds a new task to the circular queue.
dequeue() – Removes the task at the front of the queue (completed task).
front() – Returns the task ID at the front without removing it.
isFull() – Checks if the queue is full.
isEmpty() – Checks if the queue is empty.


Input Format

The first line contains an integer representing the capacity of the circular queue.
The second line contains an integer representing the number of operations.
Each of the following lines contains one operation: enqueue, dequeue, front, isFull, or isEmpty.


Output Format

For enqueue: Print the task ID that was scheduled or "Scheduling failed" if the queue is full.
For dequeue: Print the task ID that was completed or "No task to remove" if the queue is empty.
For front: Print the task ID at the front or "No tasks scheduled" if the queue is empty.
For isFull: Print true if the queue is full, otherwise false.
For isEmpty: Print true if the queue is empty, otherwise false.


Sample Input 1
3
5
enqueue 10
enqueue 20
dequeue
font
isFull
Sample Output 1
Scheduled task: 10
Scheduled task: 20
C0mpleted task: 10
Next task: 20
false

Explanation

enqueue 10

Task 10 is added to the queue because the queue is not full.

Queue state: [10]

enqueue 20

Task 20 is added behind task 10.

Queue state: [10, 20]

dequeue

The first task in the queue (10) is removed since it has been completed.

Queue state after removal: [20]

front

The system checks the task at the front without removing it.

The next task to be processed is 20.

isFull

The queue capacity is 3, but only 1 task (20) is present.

Therefore, the queue is not full, so the result is false.*/

#include <stdio.h>
#include <string.h>

int queue[1000];
int front = 0, rear = -1, count = 0, cap;

int isFull()
{
    return count == cap;
}

int isEmpty()
{
    return count == 0;
}

void enqueue(int x)
{
    if(isFull())
    {
        printf("Scheduling failed\n");
        return;
    }

    rear = (rear + 1) % cap;
    queue[rear] = x;
    count++;

    printf("Scheduled task: %d\n", x);
}

void dequeue()
{
    if(isEmpty())
    {
        printf("No task to remove\n");
        return;
    }

    printf("Completed task: %d\n", queue[front]);

    front = (front + 1) % cap;
    count--;
}

void getFront()
{
    if(isEmpty())
    {
        printf("No tasks scheduled\n");
        return;
    }

    printf("Next task: %d\n", queue[front]);
}

int main()
{
    scanf("%d", &cap);

    int ops;
    scanf("%d", &ops);

    char cmd[20];
    int val;

    for(int i = 0; i < ops; i++)
    {
        scanf("%s", cmd);

        if(strcmp(cmd, "enqueue") == 0)
        {
            scanf("%d", &val);
            enqueue(val);
        }
        else if(strcmp(cmd, "dequeue") == 0)
        {
            dequeue();
        }
        else if(strcmp(cmd, "front") == 0)
        {
            getFront();
        }
        else if(strcmp(cmd, "isFull") == 0)
        {
            printf("%s\n", isFull() ? "true" : "false");
        }
        else if(strcmp(cmd, "isEmpty") == 0)
        {
            printf("%s\n", isEmpty() ? "true" : "false");
        }
    }

    return 0;
}


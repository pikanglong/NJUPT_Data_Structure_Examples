#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct Queue {
    int front;
    int rear;
    int maxSize;
    int *element;
} Queue;

void Create(Queue *Q, int mSize) {
    Q->maxSize = mSize;
    Q->element = (int *) malloc(sizeof(int) * mSize);
    Q->front = 0;
    Q->rear = 0;
}

void Destroy(Queue *Q) {
    free(Q->element);
    Q->maxSize = -1;
    Q->front = -1;
    Q->rear = -1;
}

void Clear(Queue *Q) {
    Q->front = 0;
    Q->rear = 0;
}

bool IsEmpty(Queue Q) {
    return Q.front == Q.rear;
}

bool IsFull(Queue Q) {
    return (Q.rear + 1) % Q.maxSize == Q.front;
}

bool Front(Queue Q, int *x) {
    if (IsEmpty(Q))
        return false;
    *x = Q.element[(Q.front + 1) % Q.maxSize];
    return true;
}

bool EnQueue(Queue *Q, int x) {
    if (IsFull(*Q))
        return false;
    Q->rear = (Q->rear + 1) % Q->maxSize;
    Q->element[Q->rear] = x;
    return true;
}

bool DeQueue(Queue *Q) {
    if (IsEmpty(*Q))
        return false;
    Q->front = (Q->front + 1) % Q->maxSize;
    return true;
}

int main() {
    int x;
    Queue queue;
    Create(&queue, 10);
    for (int i = 0; i < 9; i++)
        EnQueue(&queue, i);
    for (int i = 0; i < 5; i++) {
        Front(queue, &x);
        printf("%d ", x);
        DeQueue(&queue);
    }
    Destroy(&queue);
    return 0;
}
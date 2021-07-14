#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct Node {
    int element;
    struct Node *link;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

void Create(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

void Destroy(Queue *Q) {
    Node *p;
    while (Q->front != NULL) {
        p = Q->front;
        Q->front = Q->front->link;
        free(p);
    }
}

bool IsEmpty(Queue Q) {
    return Q.front == NULL;
}

bool Front(Queue Q, int *x) {
    if (IsEmpty(Q))
        return false;
    *x = Q.front->element;
    return true;
}

void EnQueue(Queue *Q, int x) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->element = x;
    p->link = NULL;
    if(Q->front == NULL) {
        Q->front = p;
        Q->rear = p;
    } else {
        Q->rear->link = p;
        Q->rear = p;
    }
}

bool DeQueue(Queue *Q) {
    if (IsEmpty(*Q))
        return false;
    Node *p = Q->front;
    Q->front = p->link;
    free(p);
    if (Q->front == NULL)
        Q->rear = NULL;
    return true;
}

int main() {
    int x;
    Queue queue;
    Create(&queue);
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
#include <cstdio>
#include <cstdlib>

using namespace std;

const int ERROR = 0;
const int OK = 1;

typedef struct Node {
    int element;
    struct Node *lLink;
    struct Node *rLink;
} Node;

typedef struct {
    struct Node *first;
    int n;
} DoubleList;

int Init(DoubleList *L) {
    L->first = NULL;
    L->n = 0;
    return OK;
}

int Find(DoubleList L, int i, int *x) {
    Node *p;
    if (i < 0 || i > L.n - 1)
        return ERROR;
    p = L.first;
    for (int j = 0; j < i; j++)
        p = p->rLink;
    *x = p->element;
    return OK;
}

int Insert(DoubleList *L, int i, int x) {
    Node *p, *q;
    if (i < -1 || i > L->n - 1)
        return ERROR;
    p = L->first;
    for (int j = 0; j < i; j++)
        p = p->rLink;
    q = (Node *) malloc(sizeof(Node));
    q->element = x;
    if (i > -1) {
        q->rLink = p->rLink;
        q->lLink = p;
        if (p->rLink != NULL)
            p->rLink->lLink = q;
        p->rLink = q;
    } else {
        q->lLink = NULL;
        q->rLink = L->first;
        if (q->rLink != NULL)
            q->rLink->lLink = q;
        L->first = q;
    }
    L->n++;
    return OK;
}

int Delete(DoubleList *L, int i) {
    Node *p, *q;
    if (!L->n)
        return ERROR;
    if (i < 0 || i > L->n - 1)
        return ERROR;
    q = L->first;
    p = L->first;
    for (int j = 0; j < i - 1; j++)
        q = q->rLink;
    if (i == 0) {
        if (L->first->rLink != NULL)
            L->first->rLink->lLink = NULL;
        L->first = L->first->rLink;
    } else {
        p = q->rLink;
        q->rLink = p->rLink;
        if (p->rLink != NULL)
            p->rLink->lLink = q;
    }
    free(p);
    L->n--;
    return OK;
}

int Output(DoubleList L) {
    Node *p;
    if (!L.n)
        return ERROR;
    p = L.first;
    while (p) {
        printf("%d ", p->element);
        p = p->rLink;
    }
    printf("\n");
    return OK;
}

void Destroy(DoubleList *L) {
    Node *p;
    while (L->first) {
        p = L->first->rLink;
        free(L->first);
        L->first = p;
    }
}

int main() {
    int x;
    DoubleList list;
    Init(&list);
    for (int i = 0; i < 9; i++)
        Insert(&list, i - 1, i);
    printf("The doubly linked list is: ");
    Output(list);
    Delete(&list, 0);
    printf("The doubly linked list is: ");
    Output(list);
    Find(list, 0, &x);
    printf("The searched value is: %d\n", x);
    Destroy(&list);
    return 0;
}
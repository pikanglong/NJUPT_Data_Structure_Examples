#include <cstdio>
#include <cstdlib>

using namespace std;

const int ERROR = 0;
const int OK = 1;

typedef struct Node {
    int element;
    struct Node *link;
} Node;

typedef struct {
    struct Node *first;
    int n;
} SingleList;

int Init(SingleList *L) {
    L->first = NULL;
    L->n = 0;
    return OK;
}

int Find(SingleList L, int i, int *x) {
    Node *p;
    if (i < 0 || i > L.n - 1)
        return ERROR;
    p = L.first;
    for (int j = 0; j < i; j++)
        p = p->link;
    *x = p->element;
    return OK;
}

int Insert(SingleList *L, int i, int x) {
    Node *p, *q;
    if (i < -1 || i > L->n - 1)
        return ERROR;
    p = L->first;
    for (int j = 0; j < i; j++)
        p = p->link;
    q = (Node *) malloc(sizeof(Node));
    q->element = x;
    if (i > -1) {
        q->link = p->link;
        p->link = q;
    } else {
        q->link = L->first;
        L->first = q;
    }
    L->n++;
    return OK;
}

int Delete(SingleList *L, int i) {
    Node *p, *q;
    if (!L->n)
        return ERROR;
    if (i < 0 || i > L->n - 1)
        return ERROR;
    q = L->first;
    p = L->first;
    for (int j = 0; j < i - 1; j++)
        q = q->link;
    if (i == 0)
        L->first = L->first->link;
    else {
        p = q->link;
        q->link = p->link;
    }
    free(p);
    L->n--;
    return OK;
}

int Output(SingleList L) {
    Node *p;
    if (!L.n)
        return ERROR;
    p = L.first;
    while (p) {
        printf("%d ", p->element);
        p = p->link;
    }
    printf("\n");
    return OK;
}

void Destroy(SingleList *L) {
    Node *p;
    while (L->first) {
        p = L->first->link;
        free(L->first);
        L->first = p;
    }
}

int main() {
    int x;
    SingleList list;
    Init(&list);
    for (int i = 0; i < 9; i++)
        Insert(&list, i - 1, i);
    printf("The singly linked list is: ");
    Output(list);
    Delete(&list, 0);
    printf("The singly linked list is: ");
    Output(list);
    Find(list, 0, &x);
    printf("The searched value is: %d\n", x);
    Destroy(&list);
    return 0;
}

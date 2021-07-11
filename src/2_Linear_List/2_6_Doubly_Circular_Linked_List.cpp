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
    // 注释中的是原始版本，易于理解。
    // 但第一个代码块中的代码在第三个代码块的条件下可以实现一样的结果，故对代码进行了简化。
//    if (i > -1) {
//        q->rLink = p->rLink;
//        q->lLink = p;
//        p->rLink->lLink = q;
//        p->rLink = q;
//    } else if (L->first == NULL) {
//        q->lLink = q;
//        q->rLink = q;
//        L->first = q;
//    } else {
//        q->rLink = L->first;
//        q->lLink = L->first->lLink;
//        L->first->lLink->rLink = q;
//        L->first->lLink = q;
//    }
    if (L->first != NULL) {
        q->rLink = p->rLink;
        q->lLink = p;
        p->rLink->lLink = q;
        p->rLink = q;
    } else {
        q->lLink = q;
        q->rLink = q;
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
        if (L->first == L->first->rLink) {
            L->first = NULL;
        } else {
            L->first->rLink->lLink = L->first->lLink;
            L->first->lLink->rLink = L->first->rLink;
            L->first = L->first->rLink;
        }
    } else {
        p = q->rLink;
        q->rLink = p->rLink;
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
    for (int i = 0; i < L.n; i++) {
        printf("%d ", p->element);
        p = p->rLink;
    }
    printf("\n");
    return OK;
}

void Destroy(DoubleList *L) {
    Node *p, *q;
    q = L->first;
    while (L->first) {
        if (L->first->rLink == q)
            p = NULL;
        else
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
    printf("The doubly circular linked list is: ");
    Output(list);
    Delete(&list, 0);
    printf("The doubly circular linked list is: ");
    Output(list);
    Find(list, 0, &x);
    printf("The searched value is: %d\n", x);
    Destroy(&list);
    return 0;
}

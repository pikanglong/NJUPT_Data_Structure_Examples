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
    struct Node *head;
    int n;
} HeaderList;

int Init(HeaderList *h) {
    h->head = (Node *) malloc(sizeof(Node));
    if (!h->head)
        return ERROR;
    h->head->link = h->head;
    h->n = 0;
    return OK;
}

int Find(HeaderList h, int i, int *x) {
    Node *p;
    if (i < 0 || i > h.n - 1)
        return ERROR;
    p = h.head->link;
    for (int j = 0; j < i; j++)
        p = p->link;
    *x = p->element;
    return OK;
}

int Insert(HeaderList *h, int i, int x) {
    if (i < -1 || i > h->n - 1)
        return ERROR;
    Node *p = h->head;
    for (int j = 0; j <= i; j++)
        p = p->link;
    Node *q = (Node *) malloc(sizeof(Node));
    q->element = x;
    q->link = p->link;
    p->link = q;
    h->n++;
    return OK;
}

int Delete(HeaderList *h, int i) {
    Node *p, *q;
    if (!h->n)
        return ERROR;
    if (i < 0 || i > h->n - 1)
        return ERROR;
    q = h->head;
    for (int j = 0; j < i; j++)
        q = q->link;
    p = q->link;
    q->link = p->link;
    free(p);
    h->n--;
    return OK;
}

int Output(HeaderList h) {
    Node *p;
    if (!h.n)
        return ERROR;
    p = h.head->link;
    while (p != h.head) {
        printf("%d ", p->element);
        p = p->link;
    }
    printf("\n");
    return OK;
}

void Destroy(HeaderList *h) {
    Node *p, *q;
    q = h->head->link;
    while (q != h->head) {
        p = q->link;
        free(q);
        q = p;
    }
    free(h->head);
}

int main() {
    int x;
    HeaderList list;
    Init(&list);
    for (int i = 0; i < 9; i++)
        Insert(&list, i - 1, i);
    printf("The circular linked list is: ");
    Output(list);
    Delete(&list, 0);
    printf("The circular linked list is: ");
    Output(list);
    Find(list, 0, &x);
    printf("The searched value is: %d\n", x);
    Destroy(&list);
    return 0;
}

#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct Node {
    int element;
    struct Node *link;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void Create(Stack *S) {
    S->top = NULL;
}

void Destroy(Stack *S) {
    Node *p;
    while (S->top) {
        p = S->top->link;
        free(S->top);
        S->top = p;
    }
}

// Clear函数内容和Destroy函数基本一致
//void Clear(Stack *S) {
//    Node *p;
//    while (S->top) {
//        p = S->top->link;
//        free(S->top);
//        S->top = p;
//    }
//}

//void Clear(Stack *S) {
//    while (!IsEmpty(*S)) {
//        Pop(S);
//    }
//}

bool IsEmpty(Stack S) {
    return S.top == NULL;
}

bool Top(Stack S, int *x) {
    if (IsEmpty(S))
        return false;
    *x = S.top->element;
    return true;
}

bool Push(Stack *S, int x) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->element = x;
    p->link = S->top;
    S->top = p;
}

bool Pop(Stack *S) {
    if (IsEmpty(*S))
        return false;
    Node *p = S->top;
    S->top = p->link;
    free(p);
    return true;
}

int main() {
    int x;
    Stack stack;
    Create(&stack);
    for (int i = 0; i < 9; i++)
        Push(&stack, i);
    for (int i = 0; i < 5; i++) {
        Top(stack, &x);
        printf("%d ", x);
        Pop(&stack);
    }
    Destroy(&stack);
    return 0;
}

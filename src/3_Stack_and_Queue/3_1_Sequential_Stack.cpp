#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct Stack {
    int top;
    int maxSize;
    int *element;
} Stack;

// 创建一个能容纳mSize个单元的空堆栈
void Create(Stack *S, int mSize) {
    S->maxSize = mSize;
    S->element = (int *) malloc(sizeof(int) * mSize);
    S->top = -1;
}

// 销毁一个已存在的堆栈，释放堆栈占用的空间
void Destroy(Stack *S) {
    S->maxSize = -1;
    free(S->element);
    S->top = -1;
}

// 清除堆栈中全部元素，但并不释放空间
void Clear(Stack *S) {
    S->top = -1;
}

// 判断堆栈是否已满，若是则返回true，否则返回false
bool IsFull(Stack S) {
    return S.top == S.maxSize - 1;
}

// 判断堆栈是否为空，若是则返回true，否则返回false
bool IsEmpty(Stack S) {
    return S.top == -1;
}

// 获取栈顶元素，并通过x返回。若操作成功，则返回true，否则返回false
bool Top(Stack S, int *x) {
    if (IsEmpty(S))
        return false;
    *x = S.element[S.top];
    return true;
}

// 在栈顶位置插入元素x（入栈操作）。若操作成功，则返回true，否则返回false
bool Push(Stack *S, int x) {
    if (IsFull(*S))
        return false;
    S->top++;
    S->element[S->top] = x;
    return true;
}

// 删除栈顶元素（出栈操作）。若操作成功，则返回true，否则返回false
bool Pop(Stack *S) {
    if (IsEmpty(*S))
        return false;
    S->top--;
    return true;
}

int main() {
    int x;
    Stack stack;
    Create(&stack, 10);
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

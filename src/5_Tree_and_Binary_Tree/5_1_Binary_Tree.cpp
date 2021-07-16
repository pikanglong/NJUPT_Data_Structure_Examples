#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

typedef struct BTNode {
    char element;
    struct BTNode *lChild;
    struct BTNode *rChild;
} BTNode;

typedef struct BinaryTree {
    BTNode *root;
} BinaryTree;

// 构造一棵空二叉树BT
void Create(BinaryTree *BT) {
    BT->root = NULL;
}

// 创建新结点，该结点的数据为x，ln和rn为该结点的左右孩子
BTNode* NewNode(char x, BTNode *ln, BTNode *rn) {
    BTNode *p = (BTNode *) malloc(sizeof(BTNode));
    p->element = x;
    p->lChild = ln;
    p->rChild = rn;
    return p;
}

// 若二叉树非空，则x为根结点的值，并返回true，否则返回false
bool Root(BinaryTree *BT, char *x) {
    if (BT->root) {
        *x = BT->root->element;
        return true;
    } else
        return false;
}

// 构造二叉树BT，根结点的值为e，left和right为根的左右子树
void MakeTree(BinaryTree *BT, char e, BinaryTree *left, BinaryTree *right) {
    if (BT->root || left==right)
        return;
    BT->root = NewNode(e, left->root, right->root);
    left->root = NULL;
    right->root = NULL;
}

void PreOrder(BTNode *t) {
    if(!t)
        return;
    printf("%c ", t->element);
    PreOrder(t->lChild);
    PreOrder(t->rChild);
}

void PreOrderTree(BinaryTree *BT) {
    PreOrder(BT->root);
}

void InOrder(BTNode *t) {
    if(!t)
        return;
    InOrder(t->lChild);
    printf("%c ", t->element);
    InOrder(t->rChild);
}

void InOrderTree(BinaryTree *BT) {
    InOrder(BT->root);
}

void PostOrder(BTNode *t) {
    if(!t)
        return;
    PostOrder(t->lChild);
    PostOrder(t->rChild);
    printf("%c ", t->element);
}

void PostOrderTree(BinaryTree *BT) {
    PostOrder(BT->root);
}

void LevelOrderTree(BinaryTree *tree) {
    queue<BTNode *> q;
    BTNode *p;
    if (!tree->root)
        return;
    q.push(tree->root);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        printf("%c ", p->element);
        if(p->lChild)
            q.push(p->lChild);
        if(p->rChild)
            q.push(p->rChild);
    }
}

void Clear(BTNode *t) {
    if(!t)
        return;
    Clear(t->lChild);
    Clear(t->rChild);
    free(t);
}

void ClearTree(BinaryTree *BT) {
    Clear(BT->root);
}

int main() {
    BinaryTree a, b, x, y, z;
    Create(&a);
    Create(&b);
    Create(&x);
    Create(&y);
    Create(&z);
    MakeTree(&y, 'E', &a, &b);
    MakeTree(&z, 'F', &a, &b);
    MakeTree(&x, 'C', &y, &z);
    MakeTree(&y, 'D', &a, &b);
    MakeTree(&z, 'B', &y, &x);
    PreOrderTree(&z);
    printf("\n");
    InOrderTree(&z);
    printf("\n");
    PostOrderTree(&z);
    printf("\n");
    LevelOrderTree(&z);
    printf("\n");
    ClearTree(&z);
    return 0;
}

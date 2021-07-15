#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct Triad {
    int row;
    int col;
    int value;
} Triad;

typedef struct SparseMatrix {
    int m;
    int n;
    int t;
    Triad table[1024];
} SparseMatrix;

bool Create(SparseMatrix *SM, int m, int n) {
    SM->m = m;
    SM->n = n;
    SM->t = 0;
}

bool Destroy(SparseMatrix *SM) {
    SM->m = -1;
    SM->n = -1;
    SM->t = -1;
}

bool Insert(SparseMatrix *SM, int m, int n, int x) {
    if (x == 0)
        return false;
    if (SM->t == 1024)
        return false;
    if (m < 0 || m >= SM->m || n < 0 || n >= SM->n)
        return false;
    if (SM->t == 0) {
        SM->table[0].row = m;
        SM->table[0].col = n;
        SM->table[0].value = x;
        SM->t++;
        return true;
    }
    for (int i = 0; i < SM->t; i++) {
        if (SM->table[i].row > m || SM->table[i].row == m && SM->table[i].col > n) {
            for (int j = SM->t - 1; j >= i; j--)
                SM->table[j + 1] = SM->table[j];
            SM->table[i].row = m;
            SM->table[i].col = n;
            SM->table[i].value = x;
            SM->t++;
            break;
        }
        if (i == SM->t - 1) {
            SM->table[i + 1].row = m;
            SM->table[i + 1].col = n;
            SM->table[i + 1].value = x;
            SM->t++;
            break;
        }
    }
    return true;
}

bool Delete(SparseMatrix *SM, int m, int n) {
    for (int i = 0; i < SM->t; i++) {
        if (SM->table[i].row == m && SM->table[i].col == n) {
            for (int j = i; j < SM->t - 1; j++)
                SM->table[j] = SM->table[j + 1];
            SM->t--;
            return true;
        }
    }
    return false;
}

// O(n+t)
void Transpose(SparseMatrix *SM) {
    SparseMatrix temp;
    int *num = (int *) malloc(sizeof(int) * SM->n);
    int *k = (int *) malloc(sizeof(int) * SM->n);
    temp.m = SM->n;
    temp.n = SM->m;
    temp.t = SM->t;
    if (SM->t > 0) {
        for (int i = 0; i < SM->n; i++)
            num[i] = 0;
        for (int i = 0; i < SM->t; i++)
            num[SM->table[i].col]++;
        k[0] = 0;
        for (int i = 1; i < SM->n; i++)
            k[i] = k[i-1] + num[i-1];
        for (int i = 0; i < SM->t; i++) {
            int j = k[SM->table[i].col]++;
            temp.table[j].row = SM->table[i].col;
            temp.table[j].col = SM->table[i].row;
            temp.table[j].value = SM->table[i].value;
        }
    }
    *SM = temp;
    free(num);
    free(k);
}

void Output(SparseMatrix SM) {
    for (int i = 0; i < SM.t; i++)
        printf("%d %d %d\n", SM.table[i].row, SM.table[i].col, SM.table[i].value);
}

int main() {
    SparseMatrix sm;
    Create(&sm, 30, 30);
    Insert(&sm, 1, 1, 4);
    Insert(&sm, 5, 1, 4);
    Insert(&sm, 1, 9, 1);
    Insert(&sm, 9, 8, 10);
    Output(sm);
    printf("\n");
    Transpose(&sm);
    Output(sm);
    Destroy(&sm);
    return 0;
}

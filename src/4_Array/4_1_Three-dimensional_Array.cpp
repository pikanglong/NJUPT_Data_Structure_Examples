#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct TDArray {
    int m1;
    int m2;
    int m3;
    int *array;
} TDArray;

bool CreateArray(TDArray *tdArray, int m1, int m2, int m3) {
    tdArray->m1 = m1;
    tdArray->m2 = m2;
    tdArray->m3 = m3;
    tdArray->array = (int *) malloc(m1 * m2 * m3 * sizeof(int));
    if (!tdArray->array)
        return false;
    return true;
}

bool DestroyArray(TDArray *tdArray) {
    if (!tdArray)
        return false;
    if (tdArray->array)
        free(tdArray->array);
    return true;
}

bool RetrieveArray(TDArray tdArray, int i1, int i2, int i3, int *x) {
    if (!tdArray.array)
        return false;
    if (i1 < 0 || i2 < 0 || i3 < 0 || i1 >= tdArray.m1 || i2 >= tdArray.m2 || i3 >= tdArray.m3)
        return false;
    *x = *(tdArray.array + i1 * tdArray.m2 * tdArray.m3 + i2 * tdArray.m3 + i3);
    return true;
}

bool StoreArrayItem(TDArray *tdArray, int i1, int i2, int i3, int x) {
    if (!tdArray->array)
        return false;
    if (i1 < 0 || i2 < 0 || i3 < 0 || i1 >= tdArray->m1 || i2 >= tdArray->m2 || i3 >= tdArray->m3)
        return false;
    *(tdArray->array + i1 * tdArray->m2 * tdArray->m3 + i2 * tdArray->m3 + i3) = x;
    return true;
}

int main() {
    int x;
    TDArray tdArray;
    CreateArray(&tdArray, 3, 4, 5);
    for (int i = 0; i < tdArray.m1; i++) {
        for (int j = 0; j < tdArray.m2; j++) {
            for (int k = 0; k < tdArray.m3; k++) {
                StoreArrayItem(&tdArray, i, j, k, i*31*31 + j*31 + k);
            }
        }
    }
    for (int i = 0; i < tdArray.m1; i++) {
        for (int j = 0; j < tdArray.m2; j++) {
            for (int k = 0; k < tdArray.m3; k++) {
                RetrieveArray(tdArray, i, j, k, &x);
                printf("%d ", x);
            }
            printf("\n");
        }
        printf("\n");
    }
    DestroyArray(&tdArray);
    return 0;
}

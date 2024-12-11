#include <stdio.h>

# define mMax 20
# define nMax 1000
struct Data {
    int attribute[mMax];
    int isSorted;
};

struct Weight {
    int index;
    int val;
};


int main()
{
    int N, M, tmp, returnIndex, result[nMax];
    struct Data data[nMax];
    struct Weight weight[mMax];

    //file
    FILE* fp = NULL;
    fp = fopen("./data.txt", "r");

    fscanf(fp, "%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        fscanf(fp, "%d", &weight[i].val);
        weight[i].index = i;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fscanf(fp, "%d", &data[i].attribute[j]);
            data[i].isSorted = 0;
        }
    }

    fscanf(fp, "%d", &returnIndex);

    fclose(fp);

    printf("\n");
    for (int i = M-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (weight[j].val > weight[j + 1].val) {
                tmp = weight[j].val;
                weight[j].val = weight[j + 1].val;
                weight[j + 1].val = tmp;
                tmp = weight[j].index;
                weight[j].index = weight[j + 1].index;
                weight[j + 1].index = tmp;
            }
        }
    }
    

    return 0;
}
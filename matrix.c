#include <stdio.h>
#include <stdlib.h>

struct
{
    int colS;
    int rowS;
    int* table;
} typedef matrix;

matrix CreateMat(int ,int);
int ReadMat(matrix m, int col, int row);
void WriteMat(matrix m, int col, int row, int val);

int main()
{
    char* buff = malloc(20);
    int input;

    matrix mat;
    int matCol;
    int matRow;

    mat = CreateMat(3,4);
    WriteMat(mat,2,2,1000);
    WriteMat(mat,0,1,8008132);
    printf("%d\n", ReadMat(mat,2,2));
    printf("%d\n", ReadMat(mat,0,1));

    for (int i = 0; i < mat.rowS * mat.colS; i++)
    {
        printf("debug: %d\n", mat.table[i]);
    }

    return 0;
}

matrix CreateMat(int col, int row)
{
    matrix m;
    m.table = malloc(sizeof(int) * (col * row));

    //Set every entry to 0 for safety
    for (int i = 0; i < (col * row); i++)
    {
        m.table[i] = 0;
    }

    m.colS = col;
    m.rowS = row;
    
    return m;
}

int ReadMat(matrix m, int col, int row)
{
    return m.table[row * m.rowS + col];
}

void WriteMat(matrix m, int col, int row, int val)
{
    m.table[row * m.rowS + col] = val;
}
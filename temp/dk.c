#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OCCUPIED 114514
#define ERROR 1919810
#define MAXN 3

typedef struct
{
    int x, y;
} id;

typedef struct
{
    int row, col;
    int mat[MAXN][MAXN];
    int err;
} matrix;

typedef struct
{
    int head, tail;
    id q[500];
} queue;

matrix direction, transform;
queue qq;

int n, occ[11][11];

void push(queue *q, id p)
{
    q->q[++q->tail] = p;
}

id pop(queue *q)
{
    return q->q[++q->head];
}

matrix err()
{
    matrix a;
    a.err = ERROR;
    return a;
}

void equ(matrix *a, matrix *b)
{
    *a = *b;
}

id pack(int a, int b)
{
    id p;
    p.x = a;
    p.y = b;
    return p;
}

matrix mul(matrix a, matrix b)
{
    if (a.col != b.row)
        return err();
    matrix c;
    int i, j, k;
    memset(&c, 0, sizeof(matrix));
    c.row = a.row;
    c.col = b.col;
    for (i = 1; i <= a.row; i++)
        for (j = 1; j <= b.col; j++)
        {
            for (k = 1; k <= a.col; k++)
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
        }
    return c;
}

void init()
{
    direction.row = 2;
    direction.col = 1;
    transform.row = 2;
    transform.col = 2;
    direction.mat[2][1] = 1;
    transform.mat[2][1] = -1;
    transform.mat[1][2] = 1;
    qq.head = qq.tail = 1;
    int i;
    for (i = 1; i <= n; i++)
        occ[0][i] = occ[n + 1][i] = occ[i][0] = occ[i][n + 1] = 1;
}

int main(void)
{
    scanf("%d", &n);
    init();
    int num = 1, i, j;
    push(&qq, pack(1, 1));
    while (qq.head != qq.tail)
    {
        id t = pop(&qq);
        if (!occ[t.x + direction.mat[1][1]][t.y + direction.mat[2][1]])
        {
            occ[t.x][t.y] = num++;
            push(&qq, pack(t.x + direction.mat[1][1], t.y + direction.mat[2][1]));
        }
        else
        {
            if (num == n * n)
            {
                occ[t.x][t.y] = num;
                break;
            }
            direction = mul(transform, direction);
            push(&qq, pack(t.x, t.y));
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%3d", occ[i][j]);
        if (i - n)
            putchar('\n');
    }
    system("pause");
    return 0;
}
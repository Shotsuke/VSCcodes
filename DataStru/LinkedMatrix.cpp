#include <iostream>
using namespace std;
#define MAXN 1005
class Node
{
public:
    int row, col;
    int data;
    Node *nextInRow = nullptr;
    Node *nextInColumn = nullptr;
    /*
    --------------------------------------
    |    row    |    col    |    data   |
    --------------------------------------
    | nextInRow(Right) | nextInCol(Down) |
    --------------------------------------
    */
    Node(int _row, int _col, int _data) : row(_row), col(_col), data(_data) {}
    Node() {}
    void set(int _row, int _col, int _data) { row = _row, col = _col, data = _data; }
};
class Matrix
{
    int rowN = 0, colN = 0, valueGrid = 0;

    Node *rows[MAXN];    // 对应于每一行的单链表，每个单链表中列号递增
    Node *columns[MAXN]; // 对应于每一列的单链表，每个单链表中行号递增

    Node *rowsEnd[MAXN];    // 对应于每一行的单链表的尾指针，每个单链表中列号递增
    Node *columnsEnd[MAXN]; // 对应于每一列的单链表的尾指针，每个单链表中行号递增
    /*
         c[1] c[2] c[3] c[4]
    r[1]  []---[]---[]---[]
          |    ↓    ↓    ↓
    r[2]  []------->[]-->[]
          |    ↓    ↓    |
    r[3]  []------->[]---|
          |    ↓    |    ↓
    r[4]  []-->[]------->[]
    */

public:
    int getcolN() { return colN; }
    int getrowN() { return rowN; }
    Matrix(int _rowN, int _colN) : rowN(_rowN), colN(_colN)
    {
        for (int i = 0; i <= _rowN; ++i)
        {
            rows[i] = nullptr;
            rowsEnd[i] = nullptr;
        }
        for (int i = 0; i <= _colN; ++i)
        {
            columns[i] = nullptr;
            columnsEnd[i] = nullptr;
        }
    }
    void addNode(Node *node)
    {
        if (columns[node->col] == nullptr)
        {
            columns[node->col] = node;
            columnsEnd[node->col] = node;
        }
        else
        {
            // Node *pre = nullptr;
            // Node *now = columns[node->col];
            // while (now != nullptr && (node->row > now->row))
            // {
            //     pre = now;
            //     now = now->nextInRow;
            // }
            // pre->nextInRow = node;
            // node->nextInRow = now;
            columnsEnd[node->col]->nextInRow = node;
            columnsEnd[node->col] = node;
        }

        if (rows[node->row] == nullptr)
        {
            rows[node->row] = node;
            rowsEnd[node->row] = node;
        }
        else
        {
            // Node *pre = nullptr;
            // Node *now = rows[node->row];
            // while (now != nullptr && (node->col > now->col))
            // {
            //     pre = now;
            //     now = now->nextInColumn;
            // }
            // pre->nextInColumn = node;
            // node->nextInColumn = now;
            rowsEnd[node->row]->nextInColumn = node;
            rowsEnd[node->row] = node;
        }

        valueGrid++;
        return;
    }
    void printMyself()
    {
        cout << valueGrid << endl;
        for (int i = 1; i <= rowN; ++i)
        {
            Node *now = rows[i];
            while (now != nullptr)
            {
                cout << now->row << " " << now->col << " " << now->data << endl;
                now = now->nextInColumn;
            }
        }
    }
    Matrix operator*(const Matrix &right)
    {
        // if (this->colN != right->rowN)
        // {
        //     return nullptr;
        // }
        Matrix res(this->rowN, right.colN);
        for (int resRow = 1; resRow <= this->rowN; ++resRow)
        {
            for (int resCol = 1; resCol <= right.colN; ++resCol)
            {
                int sum = 0;
                Node *nodeLeft = this->rows[resRow];
                Node *nodeRight = right.columns[resCol];
                while (nodeLeft != nullptr && nodeRight != nullptr)
                {
                    if (nodeLeft->col == nodeRight->row)
                    {
                        sum += nodeLeft->data * nodeRight->data;
                        nodeLeft = nodeLeft->nextInColumn;
                        nodeRight = nodeRight->nextInRow;
                    }
                    else if (nodeLeft->col < nodeRight->row)
                    {
                        nodeLeft = nodeLeft->nextInColumn;
                    }
                    else
                    {
                        nodeRight = nodeRight->nextInRow;
                    }
                }
                if (sum != 0)
                {
                    Node *valueGrid = new Node(resRow, resCol, sum);
                    res.addNode(valueGrid);
                }
            }
        }
        return res;
    }
};
signed main()
{
    freopen("25.in", "r", stdin);
    freopen(".out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int p, q, r;
    cin >> p >> q >> r;
    int m, n;
    Matrix Mat1(p, q), Mat2(q, r), ans(p, r);
    cin >> m;
    for (int k = 1; k <= m; ++k)
    {
        int i, j, d;
        cin >> i >> j >> d;
        Node *valueGrid = new Node(i, j, d);
        Mat1.addNode(valueGrid);
    }
    cin >> n;
    for (int k = 1; k <= n; ++k)
    {
        int i, j, d;
        cin >> i >> j >> d;
        Node *valueGrid = new Node(i, j, d);
        Mat2.addNode(valueGrid);
    }

    ans = Mat1 * Mat2;
    ans.printMyself();
    return 0;
}
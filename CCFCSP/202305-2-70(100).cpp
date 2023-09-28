#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
class Matrix
{
public:
    vector<vector<long long>> data;
    Matrix() {}
    void reverse()
    {
        vector<vector<long long>> res;
        for (int i = 0; i < data[0].size(); ++i)
        {
            vector<long long> temp;
            for (int j = 0; j < data.size(); ++j)
            {
                temp.push_back(data[j][i]);
            }
            res.push_back(temp);
        }
        data = res;
    }
    Matrix operator*(const Matrix &right)
    {
        Matrix res;
        for (int i = 0; i < this->data.size(); ++i)
        {
            vector<long long> line;
            for (int j = 0; j < right.data[0].size(); ++j)
            {
                long long grid = 0;
                for (int k = 0; k < this->data[0].size(); ++k)
                {
                    grid += this->data[i][k] * right.data[k][j];
                }
                line.push_back(grid);
            }
            res.data.push_back(line);
        }
        return res;
    }
    void show()
    {
        for (auto line : data)
        {
            for (auto row : line)
            {
                cout << row << " ";
            }
            cout << endl;
        }
    }
};
signed main()
{
    int n, d;
    cin >> n >> d;
    Matrix Q, K, V;
    for (int i = 0; i < n; ++i)
    {
        vector<long long> temp;
        for (int j = 0; j < d; ++j)
        {
            long long x;
            cin >> x;
            temp.push_back(x);
        }
        Q.data.push_back(temp);
    }
    for (int i = 0; i < n; ++i)
    {
        vector<long long> temp;
        for (int j = 0; j < d; ++j)
        {
            long long x;
            cin >> x;
            temp.push_back(x);
        }
        K.data.push_back(temp);
    }
    K.reverse();
    for (int i = 0; i < n; ++i)
    {
        vector<long long> temp;
        for (int j = 0; j < d; ++j)
        {
            long long x;
            cin >> x;
            temp.push_back(x);
        }
        V.data.push_back(temp);
    }

    Matrix res;
    res = Q * (K * V);
    //!!
    for (int i = 0; i < n; ++i)
    {
        long long x;
        cin >> x;
        for (int j = 0; j < d; ++j)
        {
            res.data[i][j] *= x;
        }
    }
    res.show();
    return 0;
}
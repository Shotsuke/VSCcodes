#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>

using namespace std;

/*介绍
给定一个使用出边邻接表表示的DAG图G，使用DFS框架和Visitor模式，实现拓扑排序

输入：
首先一个整数N，表示图G有N个顶点，标号为0、1、...、N-1。
接下来是N行整数，第i行（从0开始数）整数表示顶点i的出边的目标顶点。
第i行的第一个整数c表示从顶点i出发有c条边。
接下来是c个从小到大排列的、0~N-1之间的不重复的整数，表示i到这些整数代表的顶点之间有一条边。

输出：
N个整数，是图的顶点序号的拓扑排序

输入：
3
1 2
2 0 2
0

解释：
图G有3个顶点，编号为0，1，2
顶点0有一条出边，到达顶点2
顶点1有2条出边，到达顶点0，2
顶点2有没有出边

输出：

1 0 2

请大家 使用入度统计的方式进行拓扑排序，并且要求将PPT的算法中的queue，toplist，和inDegrees三个数据结果合并到同一个数组中。
这个实现主要包括：
1、使用数组下标，并且省略了Data字段的单链表的操作方法，包括：在头部插入一个结点，删除一个头部结点；在尾部添加一个结点（这个需要使用尾指针）
2、实现单链表的时候，尤其是带有尾指针的单链表时，需要考虑一些特殊情况。
3、因为一个DAG图有多个拓扑排序，我们限定如下：
    a、在inDegrees[w]--时，如果w的入度变为 0，那么w会被加入到queue的头部；
    b、在选取入度为0的顶点，加入到topoList的时候，总是从queue的头部选择;
    b、将顶点v加入到topList的时候，按照输入的邻接表的顺序将其后继结点的入度减去1；
    c、在初始时刻收集入度为0的结点时，按照从小到大，加入到queue单链表的头部；

因为这个题目的算法不复杂，所以主要是温习一下特殊的单链表的操作。

Input:
3
1 2
2 0 2
0

Output:
1 0 2

Input:
9
1 1
1 3
1 3
0
1 2
1 2
1 2
1 1
5 0 4 5 6 7

Output:
8 7 6 5 4 2 0 1 3
*/

class DAG_Graph
{
private:
    int verticeAccount;
    vector<vector<int>> outVertice;
    vector<int> inDegrees;
    vector<int> topoList;

    int *data;

    int *stackHead, *stackBack;
    int *topoHead, *topoBack;

public:
    DAG_Graph(int n, vector<vector<int>> _outVertice)
    {
        verticeAccount = n;
        outVertice = _outVertice;
        inDegrees.resize(n);
        for (int i = 0; i < outVertice.size(); ++i)
        {
            for (int j = 0; j < outVertice[i].size(); ++j)
            {
                inDegrees[outVertice[i][j]]++;
            }
        }
        data = new int(n);
        stackHead = new int;
        stackBack = new int;
        topoHead = new int;
        topoBack = new int;
        for (int i = 0; i < inDegrees.size(); ++i)
        {
            data[i] = inDegrees[i];
        }
    }
    void getTopoOrder()
    {
        topoHead = nullptr;
        topoBack = nullptr;
        stackHead = nullptr;
        stackBack = nullptr;
        // Let the first node pushed back into queue.
        for (int i = 0; i < verticeAccount; ++i)
        {
            if (data[i] == 0)
            {
                // push stack
                if (stackHead == nullptr)
                {
                    stackHead = data + i;
                    stackBack = data + i;
                }
                else
                {
                    int tmp = stackHead - data;
                    stackHead = data + i;
                    *stackHead = tmp;
                }
            }
        }

        getTopoOrder_dfs(stackHead - data);

        int *tmp = topoHead;
        while (tmp != topoBack)
        {
            cout << tmp - data << " ";
            tmp = data + *tmp;
        }
        cout << topoBack - data << endl;
    }
    void getTopoOrder_dfs(int index)
    {
        // node in the head of queue should be pushed back into topolist
        // pop stack
        if (stackHead != stackBack)
        {
            stackHead = data + *stackHead;
        }
        else
            stackHead = stackBack = nullptr;
        // push back
        if (topoHead == nullptr)
        {
            topoHead = data + index;
            topoBack = data + index;
        }
        else
        {
            *topoBack = index;
            topoBack = data + index;
        }

        // node neighboured with ith node should be indegree - 1
        for (int i = 0; i < outVertice[index].size(); ++i)
        {
            data[outVertice[index][i]]--;
            if (data[outVertice[index][i]] == 0)
            {
                if (stackHead == nullptr)
                {
                    stackHead = data + outVertice[index][i];
                    stackBack = data + outVertice[index][i];
                }
                else
                {
                    int tmp = stackHead - data;
                    stackHead = data + outVertice[index][i];
                    *stackHead = tmp;
                }
            }
        }

        if (stackHead != nullptr)
            getTopoOrder_dfs(stackHead - data);
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> _outVertice;

    for (int i = 0; i < n; ++i)
    {
        int outAccount;
        cin >> outAccount;

        vector<int> linkedVertice;
        for (int j = 0; j < outAccount; ++j)
        {
            int tmp;
            cin >> tmp;
            linkedVertice.push_back(tmp);
        }

        _outVertice.push_back(linkedVertice);
    }

    DAG_Graph graph(n, _outVertice);

    graph.getTopoOrder();

    return 0;
}
#include <iostream>
using namespace std;

class BTreeNode
{
public:
    int *keys;     // 存储键值的数组
    int t;         // 最小度
    BTreeNode **C; // 儿子节点的指针
    int n;         // 持有键值的个数
    bool leaf;     // 是否为叶子节点

public:
    BTreeNode(int _t, bool _leaf);

    // 寻找键值，返回第一个不小于键值k的节点的编号
    int findKey(int k)
    {
        int idx = 0;
        while (idx < n && keys[idx] < k)
            ++idx;
        return idx;
    }

    // 在（非满的）该节点中插入键值k
    void insertNonFull(int k)
    {
        int i = n - 1;
        if (leaf == true)
        {
            // 找到新键值key的位置，腾出位置插入
            while (i >= 0 && keys[i] > k)
            {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
            n = n + 1;
        }
        else
        {
            // 找到新键值key应当的位置
            while (i >= 0 && keys[i] > k)
                i--;

            if (C[i + 1]->n == 2 * t - 1)
            {
                splitChild(i + 1, C[i + 1]);
                // 分裂后，判断哪个孩子获得新key
                if (keys[i + 1] < k)
                    i++;
            }
            C[i + 1]->insertNonFull(k);
        }
    }

    // 将该节点的y孩子分裂. i是在y的child array C[]中的index编号.
    void splitChild(int i, BTreeNode *y)
    {
        // 新节点存储了y节点的t-1个键值
        BTreeNode *z = new BTreeNode(y->t, y->leaf);
        z->n = t - 1;

        for (int j = 0; j < t - 1; j++)
            z->keys[j] = y->keys[j + t];

        if (y->leaf == false)
        {
            for (int j = 0; j < t; j++)
                z->C[j] = y->C[j + t];
        }

        y->n = t - 1;

        for (int j = n; j >= i + 1; j--)
            C[j + 1] = C[j];
        C[i + 1] = z;

        // y 的键将移动到此节点。查找新密钥的位置并将所有较大的密钥向前移动一个空格
        for (int j = n - 1; j >= i; j--)
            keys[j + 1] = keys[j];

        keys[i] = y->keys[t - 1];
        // 增加键值数
        n = n + 1;
    }

    // 移除节点中的键值k
    void remove(int k)
    {
        int idx = findKey(k);
        // 如果将要移除的键值恰好在这个节点中
        if (idx < n && keys[idx] == k)
        {
            if (leaf)
                removeFromLeaf(idx);
            else
                removeFromNonLeaf(idx);
        }
        else
        {
            if (leaf)
            {
                cout << "The key " << k << " is does not exist in the tree\n";
                return;
            }

            // flag用于指示要删除的键值是否可能存在于当前节点的最后一个子节点。
            bool flag = ((idx == n) ? true : false);

            if (C[idx]->n < t)
                fill(idx);

            if (flag && idx > n)
                C[idx - 1]->remove(k);
            else
                C[idx]->remove(k);
        }
        return;
    }

    // 从叶子节点中移除键值，位于索引idx
    void removeFromLeaf(int idx)
    {
        for (int i = idx + 1; i < n; ++i)
            keys[i - 1] = keys[i];
        n--;
        return;
    }

    // 从非叶子节点中移除键值，位于索引idx
    void removeFromNonLeaf(int idx)
    {
        int k = keys[idx];

        // 前驱
        if (C[idx]->n >= t)
        {
            int pred = getPred(idx);
            keys[idx] = pred;
            C[idx]->remove(pred);
        }
        // 后继
        else if (C[idx + 1]->n >= t)
        {
            int succ = getSucc(idx);
            keys[idx] = succ;
            C[idx + 1]->remove(succ);
        }
        // 合并
        else
        {
            merge(idx);
            C[idx]->remove(k);
        }
        return;
    }

    // 获取键值k的前驱节点
    int getPred(int idx)
    {
        BTreeNode *cur = C[idx];
        while (!cur->leaf)
            cur = cur->C[cur->n];

        return cur->keys[cur->n - 1];
    }

    // 获取键值k的后继节点
    int getSucc(int idx)
    {
        BTreeNode *cur = C[idx + 1];
        while (!cur->leaf)
            cur = cur->C[0];

        return cur->keys[0];
    }

    // 如果子节点C[idx]的键值个数少于t-1，填充子节点
    void fill(int idx)
    {
        if (idx != 0 && C[idx - 1]->n >= t)
            borrowFromPrev(idx);

        else if (idx != n && C[idx + 1]->n >= t)
            borrowFromNext(idx);

        else
        {
            if (idx != n)
                merge(idx);
            else
                merge(idx - 1);
        }
        return;
    }

    // 从C[idx-1]节点借一个键值插入到C[idx]节点
    void borrowFromPrev(int idx)
    {
        BTreeNode *child = C[idx];
        BTreeNode *sibling = C[idx - 1];

        // 前移
        for (int i = child->n - 1; i >= 0; --i)
            child->keys[i + 1] = child->keys[i];

        if (!child->leaf)
        {
            for (int i = child->n; i >= 0; --i)
                child->C[i + 1] = child->C[i];
        }

        child->keys[0] = keys[idx - 1];

        if (!child->leaf)
            child->C[0] = sibling->C[sibling->n];

        keys[idx - 1] = sibling->keys[sibling->n - 1];

        child->n += 1;
        sibling->n -= 1;

        return;
    }

    // 从C[idx+1]节点借一个键值插入到C[idx]节点
    void borrowFromNext(int idx)
    {

        BTreeNode *child = C[idx];
        BTreeNode *sibling = C[idx + 1];

        child->keys[(child->n)] = keys[idx];

        if (!(child->leaf))
            child->C[(child->n) + 1] = sibling->C[0];

        keys[idx] = sibling->keys[0];

        for (int i = 1; i < sibling->n; ++i)
            sibling->keys[i - 1] = sibling->keys[i];

        if (!sibling->leaf)
        {
            for (int i = 1; i <= sibling->n; ++i)
                sibling->C[i - 1] = sibling->C[i];
        }

        child->n += 1;
        sibling->n -= 1;

        return;
    }

    // 合并C[idx]和C[idx+1]两个子节点
    void merge(int idx)
    {
        BTreeNode *child = C[idx];
        BTreeNode *sibling = C[idx + 1];

        child->keys[t - 1] = keys[idx];

        // 复制键值、孩子们
        for (int i = 0; i < sibling->n; ++i)
            child->keys[i + t] = sibling->keys[i];

        if (!child->leaf)
        {
            for (int i = 0; i <= sibling->n; ++i)
                child->C[i + t] = sibling->C[i];
        }

        for (int i = idx + 1; i < n; ++i)
            keys[i - 1] = keys[i];

        for (int i = idx + 2; i <= n; ++i)
            C[i - 1] = C[i];

        child->n += sibling->n + 1;
        n--;

        delete (sibling);
        return;
    }
};

class BTree
{
    BTreeNode *root;
    int t; // 最小度
public:
    BTree(int _t)
    {
        root = NULL;
        t = _t;
    }

    void insert(int k)
    {
        if (root == NULL)
        {
            root = new BTreeNode(t, true);
            root->keys[0] = k;
            root->n = 1;
        }
        else
        {
            if (root->n == 2 * t - 1)
            {
                BTreeNode *s = new BTreeNode(t, false);
                s->C[0] = root;

                s->splitChild(0, root);

                int i = 0;
                if (s->keys[0] < k)
                    i++;
                s->C[i]->insertNonFull(k);

                root = s;
            }
            else
                root->insertNonFull(k);
        }
    }

    void remove(int k)
    {
        if (!root)
        {
            cout << "The tree is empty\n";
            return;
        }
        root->remove(k);

        if (root->n == 0)
        {
            BTreeNode *tmp = root;
            if (root->leaf)
                root = NULL;
            else
                root = root->C[0];

            delete tmp;
        }
        return;
    }
};
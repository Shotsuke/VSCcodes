#include <iostream>
using namespace std;
class TreeNode
{
public:
    int key;
    int height = 1;
    int balanceFactor = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode *parent = nullptr;
    TreeNode(int key) : key(key) {}
    TreeNode(int key, TreeNode *parent)
        : key(key), parent(parent) {}
};

class AVLTree
{
private:
    TreeNode *root;

public:
    AVLTree()
    {
        root = nullptr;
    }
    void insert(int key)
    {
        if (root == nullptr)
        {
            root = new TreeNode(key);
            return;
        }

        TreeNode *current = root;
        TreeNode *parentOfCurrent = nullptr;
        TreeNode *lastNotZero = nullptr;
        TreeNode *parentOfLastNotZero = nullptr;

        while (current)
        {
            if (current->balanceFactor != 0)
            {
                parentOfLastNotZero = parentOfCurrent;
                lastNotZero = current;
            }

            if (key < current->key)
            {
                parentOfCurrent = current;
                current = current->left;
            }
            else if (key > current->key)
            {
                parentOfCurrent = current;
                current = current->right;
            }
            else
            {
                return;
            }
        }

        if (key < parentOfCurrent->key)
        {
            parentOfCurrent->left = new TreeNode(key, parentOfCurrent);
            current = parentOfCurrent->left;
        }
        else
        {
            parentOfCurrent->right = new TreeNode(key, parentOfCurrent);
            current = parentOfCurrent->right;
        }

        updateBalanceFactors(current, key, lastNotZero, parentOfLastNotZero);
    }

    void updateBalanceFactorsInRoad(TreeNode *current)
    {
        while (current != nullptr)
        {
            current->height = max((current->right ? current->right->height : 0),
                                  (current->left ? current->left->height : 0)) +
                              1;
            current->balanceFactor = (current->right ? current->right->height : 0) -
                                     (current->left ? current->left->height : 0);
            current = current->parent;
        }
    }

    TreeNode *rotateLeft(TreeNode *rotateNode)
    {

        TreeNode *right = rotateNode->right;
        // if (rotateNode->balanceFactor == 1)
        // {
        //     if (right->balanceFactor == 1)
        //     {
        //         right->balanceFactor = -2;
        //     }
        //     else
        //         right->balanceFactor = -1;
        //     rotateNode->balanceFactor = 0;
        // }
        // else
        // {
        //     if (right->balanceFactor == 2)
        //     {
        //         rotateNode->balanceFactor = -1;
        //     }
        //     else
        //         rotateNode->balanceFactor = 0;
        //     right->balanceFactor = 0;
        // }
        rotateNode->right = right->left;
        if (right->left)
            right->left->parent = rotateNode;

        right->left = rotateNode;
        right->parent = rotateNode->parent;
        rotateNode->parent = right;

        rotateNode->height = max((rotateNode->left ? rotateNode->left->height : 0),
                                 (rotateNode->right ? rotateNode->right->height : 0)) +
                             1; // 更新高度
        rotateNode->balanceFactor = (rotateNode->right ? rotateNode->right->height : 0) -
                                    (rotateNode->left ? rotateNode->left->height : 0);
        right->height = max((right->left ? right->left->height : 0),
                            (right->right ? right->right->height : 0)) +
                        1; // 更新高度
        right->balanceFactor = (right->right ? right->right->height : 0) -
                               (right->left ? right->left->height : 0);

        return right;
    }
    TreeNode *rotateRight(TreeNode *rotateNode)
    {
        TreeNode *left = rotateNode->left;

        // if (rotateNode->balanceFactor == -1)
        // {
        //     if (left->balanceFactor == -1)
        //     {
        //         left->balanceFactor = 2;
        //     }
        //     else
        //         left->balanceFactor = 1;
        //     rotateNode->balanceFactor = 0;
        // }
        // else
        // {
        //     if (left->balanceFactor == -2)
        //     {
        //         rotateNode->balanceFactor = 1;
        //     }
        //     else
        //         rotateNode->balanceFactor = 0;
        //     left->balanceFactor = 0;
        // }
        rotateNode->left = left->right;
        if (left->right)
            left->right->parent = rotateNode;

        left->right = rotateNode;
        left->parent = rotateNode->parent;
        rotateNode->parent = left;

        rotateNode->height = max((rotateNode->left ? rotateNode->left->height : 0),
                                 (rotateNode->right ? rotateNode->right->height : 0)) +
                             1; // 更新高度
        rotateNode->balanceFactor = (rotateNode->right ? rotateNode->right->height : 0) -
                                    (rotateNode->left ? rotateNode->left->height : 0);
        left->height = max((left->left != nullptr ? left->left->height : 0),
                           (left->right != nullptr ? left->right->height : 0)) +
                       1; // 更新高度
        left->balanceFactor = (left->right ? left->right->height : 0) -
                              (left->left ? left->left->height : 0);

        return left;
    }
    TreeNode *getBalanced(TreeNode *toBeBalanced)
    {
        if (toBeBalanced->balanceFactor > -2 &&
            toBeBalanced->balanceFactor < 2)
            return toBeBalanced;

        if (toBeBalanced->balanceFactor >= 2)
        {
            // right side heavy
            if (toBeBalanced->right && toBeBalanced->right->balanceFactor < 0)
                toBeBalanced->right = rotateRight(toBeBalanced->right);
            return rotateLeft(toBeBalanced);
        }
        else
        {
            if (toBeBalanced->left && toBeBalanced->left->balanceFactor > 0)
                toBeBalanced->left = rotateLeft(toBeBalanced->left);
            return rotateRight(toBeBalanced);
        }
    }

    void updateBalanceFactors(TreeNode *newNode, int key, TreeNode *lastNotZero, TreeNode *parentOfLastNotZero)
    {
        if (lastNotZero == nullptr)
        {
            updateBalanceFactorsInRoad(newNode);
        }
        else if (lastNotZero == root)
        {
            updateBalanceFactorsInRoad(newNode);
            root = getBalanced(root);
        }
        else
        {
            updateBalanceFactorsInRoad(newNode);
            if (parentOfLastNotZero->left &&
                parentOfLastNotZero->left == lastNotZero)
                parentOfLastNotZero->left = getBalanced(lastNotZero);
            else
                parentOfLastNotZero->right = getBalanced(lastNotZero);
            updateBalanceFactorsInRoad(lastNotZero);
        }
    }

    void deleteKey(int key)
    {
        root = deleteKey(root, key);
    }

    TreeNode *deleteKey(TreeNode *root, int key)
    {
        TreeNode *current = root;
        TreeNode *parentOfCurrent = nullptr;
        TreeNode *startBalance = nullptr;
        while (current)
        {
            if (key < current->key)
            {
                parentOfCurrent = current;
                current = current->left;
            }
            else if (key > current->key)
            {
                parentOfCurrent = current;
                current = current->right;
            }
            else
            {
                if (current->left == nullptr && current->right == nullptr)
                {
                    if (current == root)
                    {
                        delete current;
                        return nullptr;
                    }
                    startBalance = current->parent;
                    (startBalance->left == current) ? startBalance->left = nullptr : startBalance->right = nullptr;
                    delete current;
                    break;
                }
                else if (current->left == nullptr)
                {
                    TreeNode *temp = current->right;

                    if (parentOfCurrent == nullptr)
                    {
                        temp->parent = nullptr;
                        delete current;
                        return temp;
                    }
                    (parentOfCurrent->left == current) ? parentOfCurrent->left = temp : parentOfCurrent->right = temp;
                    temp->parent = parentOfCurrent;
                    startBalance = temp;
                    delete current;
                    break;
                }
                else if (current->right == nullptr)
                {
                    TreeNode *temp = current->left;

                    if (parentOfCurrent == nullptr)
                    {
                        temp->parent = nullptr;
                        delete current;
                        return temp;
                    }
                    (parentOfCurrent->left == current) ? parentOfCurrent->left = temp : parentOfCurrent->right = temp;
                    temp->parent = parentOfCurrent;
                    startBalance = temp;
                    delete current;
                    break;
                }
                else
                {
                    TreeNode *minRightSubtree = findMin(current->left);
                    startBalance = minRightSubtree->parent;
                    current->key = minRightSubtree->key;
                    if(minRightSubtree->left)
                    {
                        minRightSubtree->left->parent = startBalance;
                        if(startBalance->left == minRightSubtree) startBalance->left = minRightSubtree->left;
                        else startBalance->right = minRightSubtree->left;
                    }
                    else
                        (startBalance->left == current || startBalance == current) ? startBalance->left = nullptr : startBalance->right = nullptr;
                    delete minRightSubtree;
                    break;
                }
            }
        }
        if (root == nullptr)
        {
            return root;
        }

        updateBalanceFactorsInRoad(startBalance);
        // 更新平衡因子并重新平衡树
        while (startBalance != root && startBalance)
        {
            TreeNode *parentOfNow = startBalance->parent;

            if (parentOfNow->left == startBalance)
                parentOfNow->left = getBalanced(startBalance);
            else
            {
                parentOfNow->right = getBalanced(startBalance);
            }
            updateBalanceFactorsInRoad(startBalance);
            startBalance = startBalance->parent;
        }
        return getBalanced(root);
    }

    TreeNode *findMin(TreeNode *node)
    {
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node;
    }

    string print(TreeNode *node)
    {
        if (node == nullptr)
            return "";
        return "(" + print(node->left) +
               to_string(node->key) + "," + to_string(node->balanceFactor) +
               print(node->right) + ")";
    }
    void print()
    {
        cout << print(root) << endl;
    }
    bool check()
    {
        return check(root);
    }
    bool check(TreeNode* node)
    {
        bool flag = true;
        if(!node) return true;
        flag = abs(node->balanceFactor) < 2 &&
                ((node->right ? node->right->height : 0) - (node->left ? node->left->height : 0) == node->balanceFactor) &&
                node->height == max((node->left ? node->left->height : 0),
                                    (node->right ? node->right->height : 0)) +
                                    1 &&
                (node->right ? node->key  < node->right->key : true) &&
                (node->left ? node->key > node->left->key : true); // 更新高度
        
        return check(node->left) && check(node->right) && flag;
    }

};

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    AVLTree avl;
    // avl.insert(30492);
    // avl.insert(690);
    // avl.insert(21634);
    // avl.insert(5390);
    // avl.insert(13923);
    // avl.deleteKey(30492);
    // avl.print();

    // freopen("2.in", "r", stdin);
    // freopen("2.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int opt;
        int key;
        cin >> opt >> key;
        if (opt == 1)
        {
            avl.insert(key);
        }
        else
        {
            avl.deleteKey(key);
        }
        avl.print();
    }
    return 0;
}


// const int L = 60;

// void rd(int a[]) {
//     for (int i = 1; i <= L; i++)a[i] = i;
//     for (int i = 1; i <= L * L; i++) {
//         int p = rand() % L + 1, q = rand() % L + 1;
//         if (p == q)continue;
//         a[p] ^= a[q] ^= a[p] ^= a[q];
//     }
// }



// signed main()
// {    
//     int a[L + 1] = {0, 2, 4, 6, 5, 1, 3};
//     srand(time(0));
//     bool flag = true;
//     while (flag) {
//         AVLTree *test = new(AVLTree);
//         rd(a);
//         for (int i = 1; i <= L; i++) {
//             cout << "Insert " << a[i] << " ";
//             test->insert(a[i]);
//             // test->Write();
//             flag = flag && test->check();
//             if(!flag) cout<<endl<<a[i]<<endl;
//         }
//         test->print();
//         cout << endl;
//         a[1] = 1;
//         a[2] = 2;
//         a[3] = 3;
//         rd(a);
//         for (int i = 1; i <= L; i++) {
//             printf("Delete %d ", a[i]);
//             test->deleteKey(a[i]);
// //            test->print2();
//             flag = flag && test->check();
//             if(!flag) cout<<endl<<a[i]<<endl;
//         }
//         test->print();
//         delete test;
//         cout << endl;
//     }
// }
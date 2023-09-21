#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include <iostream>
#include <sstream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 这是一个经典的二叉树问题，我们可以使用递归的方法来解决。先序遍历的第一个元素总是树的根节点，我们可以使用这个信息来找到根节点在中序遍历中的位置，然后将中序遍历分为两部分，左边部分是左子树，右边部分是右子树。然后我们可以递归地对左子树和右子树进行同样的操作。
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeFromVectors(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

private:
    TreeNode* buildTreeFromVectors(vector<int>& preorder, int p_start, int p_end, vector<int>& inorder, int i_start, int i_end) {
        // 如果先序遍历的数组为空，那么返回null
        if (p_start == p_end) {
            return nullptr;
        }

        // 创建新的根节点
        int root_val = preorder[p_start];
        TreeNode* root = new TreeNode(root_val);

        // 在中序遍历中找到根节点的位置
        int i_root_index = 0;
        for (int i = i_start; i < i_end; i++) {
            if (root_val == inorder[i]) {
                i_root_index = i;
                break;
            }
        }

        // 左子树的元素个数
        int left_num = i_root_index - i_start;

        // 递归构造左子树和右子树
        // 左子树的起始位置，左子树的终止位置+1。右子树的起始位置，右子树的终止位置+1
        root->left = buildTreeFromVectors(preorder, p_start + 1, p_start + 1 + left_num, inorder, i_start, i_root_index);
        root->right = buildTreeFromVectors(preorder, p_start + 1 + left_num, p_end, inorder, i_root_index + 1, i_end);

        return root;
    }
};


// 用于打印二叉树
void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "null, ";
        return;
    }
    cout << root->val << ", ";
    printTree(root->left);
    printTree(root->right);
}
// 这段代码首先创建了一个Solution对象，然后使用给定的先序遍历和中序遍历序列来构造二叉树。然后，它打印出构造的二叉树。注意，这个打印函数假设二叉树的节点值都是唯一的，如果有重复的值，打印的结果可能会有误。
int main() {
    Solution solution;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = solution.buildTree(preorder, inorder);

    // 打印二叉树
    printTree(root);
    cout << endl;

    preorder = {-1};
    inorder = {-1};
    root = solution.buildTree(preorder, inorder);

    // 打印二叉树
    printTree(root);
    cout << endl;

    return 0;
}
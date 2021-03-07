/**
 * @file BST 二叉搜索树。高度平衡的BST主要实现有AVL树和红黑树，其中红黑树的使用更加的广泛。
 * 108有序数组生成BST，
*/
#include "treenode.h"

using namespace std;

class BSTSolution {
public:
    /**
     * @brief leetcode 108 convert-sorted-array-to-binary-search-tree
     *      将有序数组转换为二叉搜索树
     * @note 将一个按照升序排列的有序数组，转换为一颗高度平衡的二叉搜索树
    */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, nums.size() - 1);
    }
    // helper function
    TreeNode* createBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int idx = (left + right) / 2; // 中间偏左
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = createBST(nums, left, idx - 1);
        root->right = createBST(nums, idx + 1, right);
        return root;
    }
};


/**
 * @file BST 二叉搜索树。高度平衡的BST主要实现有AVL树和红黑树，其中红黑树的使用更加的广泛。
 *       108有序数组生成BST，235BST的最近公共祖先
*/
#include "treenode.hh"
#include <vector>

using namespace std;

class BSTSolution {
public:
    /**
     * @brief leetcode 108 convert-sorted-array-to-binary-search-tree
     *        将有序数组转换为二叉搜索树 easy
     *        将一个按照升序排列的有序数组，转换为一颗高度平衡的二叉搜索树
    */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, nums.size() - 1);
    }
    // helper function
    TreeNode* createBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int idx = (left + right) / 2; // 总是选择中间偏左
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = createBST(nums, left, idx - 1);
        root->right = createBST(nums, idx + 1, right);
        return root;
    }

    /**
     * @brief 235 lowest-common-ancestor-of-a-binary-search-tree
     *            BST的最近公共祖先 easy
     * @note 一个节点也可以是自己的祖先
     * @note 由于BST的特殊性，两个节点的最近公共祖先就是从根开始第一个满足 p < root < q
     *       的节点。准确点说，是第一个不满足(p,q 均小于root || p,q均大于root)的节点。 
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *node = root;
        while (node) {
            if (p->val < node->val && q->val < node->val) {
                node = node->left;
            } else if (p->val > node->val && q->val > node->val) {
                node = node->right;
            } else {
                return node;
            }
        }
    }
    
};


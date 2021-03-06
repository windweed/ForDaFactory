/**
 * @file 普通二叉树
 *       94中序遍历，100相同的树，101对称二叉树，102层序遍历，104最大深度，
 *       107层序遍历(自底向上), 110平衡二叉树，111最小深度，112路径总和，144前序遍历，
 *       145后序遍历，543二叉树的直径
*/
#include "treenode.hh"
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdint>

using namespace std;

class BinaryTreeSolution {
public:
    /**
     * @brief leetcode 100 same-tree 相同的树 easy
     *      给你两颗二叉树的根节点p和q，验证这两棵树是否相同
     *      如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的
    */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) { // both null
            return true;
        } else if (!p || !q) {// one null, the other one not null
            return false;
        } else if (p->val != q->val) { // root
            return false;
        } else {
            return isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right);
        }
    }
    /**
     * @brief leetcode 101 symmetric-tree 对称二叉树 easy
     *      给定一个二叉树，检查它是否是镜像对称的
     * @example 二叉树 [1,2,2,3,4,4,3] 是对称的
    */
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
    // helper function
    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p || !q) {
            return false;
        }

        return p->val == q->val &&
               check(p->left, q->right) &&
               check(p->right, q->left);
    }
    /**
     * @brief leetcode 104 maximum-depth-of-binary-tree 二叉树的最大深度 easy
    */
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    /**
     * @brief leetcode 107 binary-tree-level-order-traversal-ii 二叉树的层序遍历2
     *      给定一个二叉树，返回其节点值自底向上的层序遍历
     * @example 二叉树 [3,9,20,null,null,15,7] 自底向上的层序遍历为：
     *      [ [15,7], [9,20], [3] ]
    */
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        auto levelOrder = vector<vector<int>>();

        if (!root) {
            return levelOrder;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            for (size_t i = 0; i < q.size(); i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                // 准备下一轮
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            levelOrder.push_back(level);
        }
        reverse(levelOrder.begin(), levelOrder.end());
        return levelOrder;
    }

    /**
     * @brief leetcode 110 balanced-binary-tree 平衡二叉树 easy
     *      给定一个二叉树，判断它是否是高度平衡的
    */
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1
            && isBalanced(root->left)
            && isBalanced(root->right);
    }
    /**
     * @brief leetcode 111 minimum-depth-of-binary-tree 二叉树最小深度 easy
    */
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        // leaf
        if (!root->left && !root->right) {
            return 1;
        }

        // have child
        int min_depth = INT32_MAX;
        if (root->left) {
            min_depth = min(min_depth, minDepth(root->left));
        }
        if (root->right) {
            min_depth = min(min_depth, minDepth(root->right));
        }

        return min_depth + 1;
    }

    /**
     * @brief leetcode 112 path-sum 路径总和 easy
     *        给定二叉树和一个整数，判断树中是否存在一个 根节点到叶子节点的路径，此路径
     *        上所有节点值的和等于给定的整数。
    */
    bool hasPathSum(TreeNode* root, int target) { // recusive
        if (!root) {
            return false;
        }

        if (!root->left && !root->right) { // leaf
            return root->val == target;
        }

        return hasPathSum(root->left, target - root->val) ||
               hasPathSum(root->right, target - root->val);
    }
    // TODO hasPathSum BFS

    /**
     * @brief leetcode 94 binary-tree-inorder-traversal 二叉树中序遍历 mideum
    */
    vector<int> inOrderTraversal(TreeNode* root){
        auto res = vector<int>();
        inOrder(root, res);
        return res;
    }
    // inOrder helper function
    void inOrder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }

    /**
     * @brief leetcode 102 binary-tree-order-traversal 二叉树层序遍历  medium
    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        auto result = vector<vector<int>>();
        if (!root) {
            return result;
        }

        queue<TreeNode*> workq;
        workq.push(root);
        while(!workq.empty()) {
            auto level = vector<int>();
            for (int i = 0; i < workq.size(); i++) {
                TreeNode* node = workq.front();
                workq.pop();
                level.push_back(node->val);

                if (node->left) {
                    workq.push(node->left);
                }
                if (node->right) {
                    workq.push(node->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }

    /**
     * @brief leetcode 144 binary-tree-preorder-traversal 二叉树前序遍历 medium
    */
    vector<int> preOrderTraversal(TreeNode* root) {
        auto res = vector<int>();
        preOrder(root, res);
        return res;
    }
    // preOrder helper function
    void preOrder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }

        res.push_back(root->val);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }

    /**
     * @brief leetcode 145 binary-tree-postorder-traversal 二叉树后序遍历 mideum
    */
    vector<int> postOrderTraversal(TreeNode* root){
        auto res = vector<int>();
        postOrder(root, res);
        return res;
    }
    // postOrder helper function
    void postOrder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        postOrder(root->left, res);
        postOrder(root->right, res);
        res.push_back(root->val);
    }

    /**
     * @brief leetcode 543 diameter-of-binary-tree 二叉树的直径 easy
     *        给定一颗二叉树，计算它的直径长度。即任意两个节点路径最短路径中的最大值。
     *        这条路径可能穿过也可能不穿过根节点。
     *        两节点之间的路径长度是它们之间的边数。
     * @example Input: [1, [2,3], [4,5,null,null]], Output: 3。(4213)or(5213)
     * @note DFS
     *       0, 路径长等于该路径上的节点数减1。
     *          任意一条路径均可以看作由某节点为起点，从其左右儿子分别向下遍历的路径
     *          拼接得到。
     *       1，如何求的两个叶子节点之间的路径长度。(根节点左右儿子深度之和)
     *          若对于某节点，以其左儿子为根的子树最大深度为L,右子树最大深度为R，那么，
     *          以该节点为起点的路径经过节点数的最大值即为 L + R + 1
    */
    int ans543 = -1;
    int diameterOfBinaryTree(TreeNode* root) {
        ans543 = 1;
        depth543(root);
        return ans543 - 1;
    }
    // helper 计算某个节点的深度
    int depth543(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int L = depth543(node->left);
        int R = depth543(node->right);
        ans543 = max(ans543, L + R + 1); // 更新最大值
        return 1 + max(L , R);
    }

};

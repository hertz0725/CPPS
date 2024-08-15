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

// zig zag
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        std::queue<TreeNode*> tq;
        tq.push(root);
        auto last = tq.back();
        
        std::deque<int> level_dq;
        bool seq_order = true;

        std::vector<std::vector<int>> res_vec;

        while (!tq.empty()) {
            auto out = tq.front();
            tq.pop();
            
            if (seq_order) {
                level_dq.push_back(out->val);
            } else {
                level_dq.push_front(out->val);
            }

            if (out->left) {
                tq.push(out->left);
            }
            if (out->right) {
                tq.push(out->right);
            }

            if (out == last) {
                res_vec.push_back(std::vector<int>(
                    level_dq.begin(), level_dq.end()));
                seq_order = !seq_order;
                level_dq.clear();

                last = tq.back();
            }
        }

        return res_vec;
    }
};

// right side view
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }

        std::vector<int> res_vec;
        
        std::queue<TreeNode*> tq;
        tq.push(root);
        auto last = tq.back();

        while (!tq.empty()) {
            auto top = tq.front();
            tq.pop();

            if (top->left) {
                tq.push(top->left);
            }
            if (top->right) {
                tq.push(top->right);
            }

            if (top == last) {
                res_vec.push_back(top->val);
                last = tq.back();
            }
        }

        return res_vec;
    }
};

//  common anc
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }

        if (root == p || root == q) {
            return root;
        }

        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root;
        }

        return left ? left : right;
    }
};

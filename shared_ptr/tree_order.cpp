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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }

        std::vector<int> res_vec;
        std::stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            auto out = stk.top();

            if (out) {
                stk.pop();

                if (out->right) {
                    stk.push(out->right);
                }
                if (out->left) {
                    stk.push(out->left);
                }

                stk.push(out);
                stk.push(nullptr);
            } else {
                stk.pop();
                if (stk.empty()) {
                    break;
                }

                res_vec.push_back(stk.top()->val);
                stk.pop();
            }
        }

        return res_vec;
    }
};

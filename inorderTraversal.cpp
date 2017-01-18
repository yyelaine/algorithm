/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<TreeNode *> p;  
        vector<int> res;  
        while(root != NULL || p.size() != 0){  
            while(root != NULL){  
                p.push_back(root);  
                root = root->left;  
            }  
            root = p.back();  
            p.pop_back();  
            res.push_back(root->val);  
            root = root->right;  
        }  
        return res;  
    }
};
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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        int a = 1;  
        vector<TreeNode *> s;  
        vector<int> res;  
        if (root == NULL) return res;  
        while(a == 1){  
            while(root->left != NULL || root->right != NULL){  
                if(root->left != NULL){  
                    s.push_back(root);  
                    root = root->left;  
                }  
                else{  
                    s.push_back(root);  
                    root = root->right;  
                }  
            }  
            TreeNode *y = s.back();  
            while (root == y->right || y->right == NULL){  
                res.push_back(root->val);  
                s.pop_back();  
                if (s.size() == 0){  
                    a = 0;  
                    res.push_back(y->val);  
                    break;  
                }  
                root = y;  
                y = s.back();  
            }  
            if (root == y->left && y->right != NULL) {  
                res.push_back(root->val);   
                root = y->right;  
            }  
        }  
        return res;  
    }
};
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
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> inOrderData;
        inOrder(root, inOrderData);
        
        vector<int> ret;
        for(auto iter = inOrderData.begin() ; iter!=inOrderData.end() ; ++iter)
        {
            if((*iter) >= k1 && (*iter) <= k2)
            {
                ret.push_back(*iter);
            }//if
        }//for
        
        return ret;
        
    }
    
    void inOrder(TreeNode *root, vector<int> &ret)
    {
        if(root == NULL)
        {
            return ;
        }//if
        
        if(root->left != NULL)
        {
            inOrder(root->left , ret);
        }//if
        
        ret.push_back(root->val);
        
        if(root->right != NULL)
        {
            inOrder(root->right , ret);
        }
        
        return ;
    }
};
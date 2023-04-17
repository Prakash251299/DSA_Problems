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
    bool res = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode *p1, *q1;
        p1 = p;
        q1 = q;
        if(p==NULL and q==NULL){
            return res;
        }else{
            if(p==NULL and q!=NULL){
                res = false;
                return res;
            }else{
                if(p!=NULL and q==NULL){
                    res = false;
                    return res;
                }
            }
        }
        // bool res = true;
        if(p->val!=q->val){
            res = false;
            return res;
        }else{
            p = p->left;
            q = q->left;
            res = isSameTree(p,q);
            p1 = p1->right;
            q1 = q1->right;
            res = isSameTree(p1,q1);
        }
        return res;
    }
};
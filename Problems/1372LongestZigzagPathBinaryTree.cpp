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
    int max=0;
    void fun(TreeNode *q,string currDir,int count){
        if(q==NULL){
            return;
        }else{
            if(count>max){
                max = count;
            }
            if(currDir=="left"){
                fun(q->right,"right",count+1);
                fun(q->left,"left",1);
            }else{
                if(currDir=="right"){
                    fun(q->left,"left",count+1);
                    fun(q->right,"right",1);
                }
            }
        }
        return;
    }
    
    int longestZigZag(TreeNode* root) {
        int count=1;
        string currDir = "root";
        TreeNode *q = root;
        fun(q->left,"left",count);
        fun(q->right,"right",count);
        return max;
    }
};
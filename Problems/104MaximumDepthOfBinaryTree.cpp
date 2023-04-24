class Solution {
public:
    int max = 0;
    void fun(TreeNode *q, int count){
        if(q==NULL){
            return;
        }else{
            if(count>max){
                max = count;
            }
            fun(q->left,count+1);
            fun(q->right,count+1);
        }
        return;
    }
    int maxDepth(TreeNode* root) {
        TreeNode *q;
        q = root;
        int count=1;
        fun(q,count);
        return max;
    }
};
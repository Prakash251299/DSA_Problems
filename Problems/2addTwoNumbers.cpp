/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void fun(ListNode* l1){
        if(l1==NULL){
            return;
        }else{
            fun(l1->next);
            cout<<l1->val<<" ";
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newNode,*q,*r;
        // Use array in place of vector for faster performance
        vector<int>v1;
        vector<int>v2;
        vector<int>v;
        while(l1!=NULL){
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL){
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        int sum=0,c=0;
        for(int i=0;;i++){
            if(i>=v1.size() and i<v2.size()){
                sum = v2[i]+c;
            }else if(i>=v2.size() and i<v1.size()){
                sum = v1[i]+c;
            }else if(i<v1.size() and i<v2.size()){
                sum = v1[i]+v2[i]+c;
            }else{
                break;
            }
            v.push_back(sum%10);
            c = sum/10;
            cout<<c<<" ";
            sum = 0;
        }
        if(c!=0){
            v.push_back(c);
        }
        newNode = new ListNode(v[0]);
        r = newNode;
        q=r;
        for(int i=1;i<v.size();i++){
            newNode = new ListNode(v[i]);
            r->next = newNode;
            r = r->next;
        }
        return q;
    }
};
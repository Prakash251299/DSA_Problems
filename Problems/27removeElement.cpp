class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        vector<int> v;
        for(;i<nums.size();i++){
            if(nums[i]!=val){
                
            
v.push_back(nums[i]);
            }
            //cout<<"hi";
        }
        i=0;
        for(auto it:v){
            nums[i]=it;
            cout<<it;
            i++;
        }
        return i;
    }
};
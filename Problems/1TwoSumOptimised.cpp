class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>a = nums;
        int i=0,j=0,k=0;
        sort(nums.begin(),nums.end());
        vector<int>vec;
        j=nums.size()-1;
        for(i=0;;){
            if(i>=j){
                break;
            }else
            if(int(nums[i]+nums[j])==target){
                break;
            }else{
                if((nums[i]+nums[j])<target){
                    i++;
                }else{
                    j--;
                }
            }
        }

        int val1 = nums[i],val2 = nums[j];
        i=0,k=0;
        while(i<a.size()){
            if(a[i]==val1){
                vec.push_back(i);
            }else
            if(a[i]==val2){
                vec.push_back(i);
            }
            i++;
        }
        // cout<<vec[0]<<" "<<vec[1];
        return vec;
    }
};
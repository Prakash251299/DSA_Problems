class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v;
        int i=0,j=nums.size()-1,mid=0,k=0,l=0,found=0;
        for(i=0;i<=j;){
            mid = (i+j)/2;
            if(nums[mid]<target){
                i = mid+1;
            }else{
                if(nums[mid]>target){
                    j = mid-1;
                }else{
                    found = 1;
                    break;
                }
            }
        }
        if(found==1){
            cout<<mid;
            for(k=mid;k>=0;k--){
                if(nums[k]!=target){
                    // v.push_back(k+1);
                    break;
                }
            }
            v.push_back(k+1);
            for(l=mid;l<nums.size();l++){
                if(nums[l]!=target){
                    break;
                }
            }
            v.push_back(l-1);
        }else{
            v.push_back(-1);
            v.push_back(-1);
        }
        return v;
    }
};
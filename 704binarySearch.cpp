class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1,mid=0;
        while(1){
            mid = (i+j)/2;
            if(target==nums[mid]){
                break;
            }else{
                if(i>=j){
                    return -1;
                }
            }
            if(target<nums[mid]){
                j = mid-1;
            }
            if(target>nums[mid]){
                i = mid+1;
            }
        }
        return mid;
    }
};
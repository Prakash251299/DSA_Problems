class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1,mid=0;
        if(nums.size()==1){
            if(nums[0]==target){
                return 0;
            }else{
                if(nums[0]<target){
                    return 1;
                }else{
                    return 0;
                }
            }
        }
        for(;;){
            if(i>=j){
                if(nums[i]<target){
                    return i+1;
                }else{
                    if(nums[i]==target){
                        return i;
                    }
                    return i;
                }
                return i;
                // break;
            }
            mid = (i+j)/2;
            if(nums[mid]==target){
                return mid;
            }else{
                if(nums[mid]<target){
                    i=mid+1;
                }else{
                    j = mid-1;
                }
            }
            // nums[i]
        }
    }
};
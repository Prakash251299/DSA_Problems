class Solution {
    public int[] twoSum(int[] nums, int target) {
        int [] res = new int[2];
        for(int j=0;j<nums.length;j++){
            for(int k=0;k<nums.length;k++){
                if(j==k){
                    continue;
                }
                if(nums[j]+nums[k]==target){
                    res[0]=j;
                    res[1]=k;
                    return res;
                }
            }
        }
        return res;
    }
}
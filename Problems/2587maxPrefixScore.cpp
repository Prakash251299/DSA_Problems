class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        long long sum=0,count=0;
        for(int i=0;i<nums.size();i++){
            sum = sum+nums[i];
            if(sum>0){
                count++;
            }
        }
        return count;
    }
};
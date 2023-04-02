class Solution {
public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
            long long t = target;
            int i=0,j=0,k=0,l=0;
            long long sum=0,sum1=0;
            vector<vector<int>>v;
            sort(nums.begin(),nums.end());
            int n = nums.size();
            for(i=0;i<n-3;i++){
                for(j=i+1;j<n-2;j++){
                    sum1 = (long long)nums[i] + (long long)nums[j];
                    l=n-1;
                    for(k = j+1;k<l;){
                        sum = sum1 + (long long)nums[k] + (long long)nums[l];
                        if(sum<t){
                            k++;
                        }
                        if(sum==t){
                            v.push_back({nums[i], nums[j], nums[k], nums[l]});
                            
                            while(k<l && nums[k]==nums[k+1]){
                                k++;
                            }
                            while(k<l && nums[l]==nums[l-1]){
                                l--;
                            }
                            k++;l--;
                        }
                        if(sum>t){
                            l--;
                        }
                    }
                    while(nums[j]==nums[j+1] && j<n-2){
                        j++;
                    }
                }
                while(nums[i]==nums[i+1] && i<n-3){
                    i++;
                }
            }
            return v;
        }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
		set<vector<int>>s;
		vector<vector<int>> v;
            vector<int>v1;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0){
                break;
            }
            for(int j = i+1,k=nums.size()-1;j<k;){
            	int sum = nums[i]+nums[j]+nums[k];
                    if(sum==0){
                        /* It is faster but takes much space */
                        // s.insert({nums[i],nums[j],nums[k]});
                        /* Below code takes less space */
                    	v1.push_back(nums[i]);
                    	v1.push_back(nums[j]);
                    	v1.push_back(nums[k]);
                    	// sort(v1.begin(),v1.end());
                        s.insert(v1);
                        v1.pop_back();
                        v1.pop_back();
                        v1.pop_back();
                        j++;
                        k--;
                    }
                    else
                        if(sum>0){
                    	k--;
					}
					else{
						j++;
					}
            }
        }
		for(vector<int>v1:s){
        	v.push_back(v1);
		}
		return v;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>vec;
        unordered_map<int,string> m;
        int i=0;
        for(i=0;i<nums.size();i++){
            if(m[nums[i]]==""){
                m[target - nums[i]] = to_string(i);
            }else{
                vec.push_back(i);
                vec.push_back(stoi(m[nums[i]]));
                break;
            }
        }
        cout<<vec[0]<<" "<<vec[1];
        return vec;
    }
};
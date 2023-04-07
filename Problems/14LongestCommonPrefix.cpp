class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        int count=0;
        int matched=0;
        for(int i=0;i<strs[0].size();i++){
            matched=1;
            for(int j=0;j<strs.size()-1;j++){
                if(strs[j][i]==strs[j+1][i]){
                    // count++;
                }else{
                    matched = 0;
                    break;
                }
                // cout<<j<<i<<" ";
            }
            if(matched==0){
                break;
            }else{
                count++;
            }
        }
        cout<<count;
        for(int i=0;i<count;i++){
            s = s + strs[0][i];
        }
        return s;
    }
};
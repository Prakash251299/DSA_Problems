class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>a;
        int count=0,res = 0;
        for(int j=0;j<s.size();j++){
            for(int i=j;i<s.size();i++){
                a.insert(s[i]);
                count++;
                if(a.size()!=count){
                    if(count-1>res){
                        res = count-1;
                    }
                    a.clear();
                    count = 0;
                    break;
                }
            }
            if(count>res){
                res = count;
            }
        }
        return res;
    }
};
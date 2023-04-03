class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        int dir = 1; // Direction 0 -> down and 1 -> up
        vector<vector<char>> v;
        int i=0,j=0;
        for(i=0;i<numRows;i++){
            v.push_back({'-'});
        }
        i=0;
        while(i<s.size()){
            v[j].push_back(s[i]);
            i++;
            j=j+dir;
            if(j==numRows-1){
                dir = -1;
            }else{
                if(j==0){
                    dir = 1;
                }
            }
        }
        s = "";
        for(vector<char>v1:v){
            for(auto it:v1){
                if(it!='-')
                    s = s + it;
            }
        }
        return s;
    }
};
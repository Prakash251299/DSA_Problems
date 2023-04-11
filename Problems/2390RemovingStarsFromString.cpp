class Solution {
public:
    string removeStars(string s) {
        int n = s.size(),count=0,i=0,j=0;
        for(j=0;j<n;j++){
            if(s[j]!='*'){
                s[i] = s[j];
                i++;
            }else{
                i--;
                if(i<0){
                    i = 0;
                }
            }
        }
        // cout<<i;
        return s.substr(0,i);
        // return s;
    }
};
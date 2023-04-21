class Solution {
public:
    int strStr(string haystack, string needle) {
        // cout<<haystack.length();
        // cout<<(sizeof(haystack)/sizeof(haystack[0]));
        int res=0;
        for(int i=0;i<haystack.length();i++){
            res=i;
            for(int j=0;;j++){
                if(haystack[i]==needle[j]){
                    i++;
                    if(j==needle.length()-1){
                        return res;
                    }
                }else{
                    //    j=0;
                    break;
                }
            }
            i=res;
        }
        return -1;
    }
};

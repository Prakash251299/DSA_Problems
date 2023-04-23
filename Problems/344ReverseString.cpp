class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0,j=s.size()-1;
        char a;
        while(i<j){
            a = s[i];
            s[i] = s[j];
            s[j] = a;
            j--;i++;
        }
    }
};
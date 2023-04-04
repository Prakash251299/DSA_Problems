class Solution {
public:
    int partitionString(string s) {
       set<char> a;
        int j=0,count=0;
        for(int i=0;i<s.size();i++){
            a.insert(s[i]);
            if(i-j+1!=a.size()){
                count++;
                a.clear();
                a.insert(s[i]);
                j=i;
            }
        }
        count++;
        cout<<count;
        return count;
    }
};
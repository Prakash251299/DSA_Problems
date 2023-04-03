class Solution {
public:
    int isVowel(string words){
        if(words[0]=='a' or words[0]=='e' or words[0]=='i' or words[0]=='o' or words[0]=='u'){
            if(words[words.size()-1]=='a' or words[words.size()-1]=='e' or words[words.size()-1]=='i' or words[words.size()-1]=='o' or words[words.size()-1]=='u'){
                return 1;
            }
        }
        return 0;
    }
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        // cout<<words[0];
        // cout<<isVowel(words[0]);
        for(int i=left;i<=right;i++){
            if(isVowel(words[i])){
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int checkRoman(string s){
        if(s=="IV"){
            return 4;
        }else
        if(s=="IX"){
            return 9;
        }else
        if(s=="XL"){
            return 40;
        }else
        if(s=="XC"){
            return 90;
        }else
        if(s=="CD"){
            return 400;
        }else
        if(s=="CM"){
            return 900;
        }else
            return -1;
    }
    int roman(char s){
        if(s=='I'){
            return 1;
        }
        if(s=='V'){
            return 5;
        }
        if(s=='X'){
            return 10;
        }
        if(s=='L'){
            return 50;
        }
        if(s=='C'){
            return 100;
        }
        if(s=='D'){
            return 500;
        }
        if(s=='M'){
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int res=0,val=0;
        string temp="";
        // temp = s[0]+s[1];
        // string t = s[1];
        // temp.append(10,'g');
        // temp = s[0]+""+s[1];
        // cout<<s;
        for(int i=0;i<s.size();i++){
            val = -1;
            temp = "ab";
            if(i<s.size()-1){
               // cout<<s[0]<<s[1]<<" ";
                temp[0] = s[i];
                temp[1]=s[i+1];
                val = checkRoman(temp);
                 //cout<<temp<<" ";
            }
            if(val!=-1){
                res = res+val;
                i++;
            }else{
                res = res + roman(s[i]);
            }
        }
        // cout<<checkRoman(temp);
        // string s = ;
        return res;
    }
};
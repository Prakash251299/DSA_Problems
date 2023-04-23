class Solution {
public:
    int stringToInt(string s){
        int size=s.length(),a=0,multiplier=1,i=0;
        double res=0;
        if(s[0]=='+'||s[0]=='-'){
            if(s[i]=='-'){
                multiplier=-1;
            }
            for(i=1;i<size;i++){
                if(int(s[i])>=int('0') and int(s[i])<=int('9')){
                    res = res + (int(s[i]-int('0'))*pow(10,size-i-1));
                }
            }
        }else{
            for(i=0;i<size;i++){
                if(int(s[i])>=int('0') and int(s[i])<=int('9')){
                    res = res + (int(s[i]-int('0'))*pow(10,size-i-1));
                }
            }
        }
        res = res*multiplier;
        if(res<pow(-2,31)){
            res = pow(-2,31);
        }else{
            if(res>pow(2,31)-1){
                res = pow(2,31)-1;
            }
        }
        return res;
    }
    
    int myAtoi(string s) {
        vector<char>v;
        int stackSize=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' || s[i]=='+' || s[i]=='-' || s[i]==' '){
                if((s[i]=='-' || s[i]=='+') and stackSize==0){
                    v.push_back(s[i]);
                }else{
                    if(s[i]==' ' and stackSize==0 ){
                        stackSize--;
                    }else{
                    	if(s[i]==' ' and stackSize!=0){
                    		break;
						}else{
	                        if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
	                            v.push_back(s[i]);
	                        }else{
	                        	if(stackSize==1 and (v[0]=='-' || v[0]=='+')){
	                        		v.pop_back();
								}
	                            break;
	                        }
	                    }
	                }
                }
            }
            else{
            	break;
			}
            stackSize++;
        }
        string k = "";
        if(v.size()!=0 and v[0]=='+'){
        	v.erase(v.begin());
		}
        if(v.size()==1 and v[0]=='-'){
            v.erase(v.begin());
        }
        int res=0,mul=1;
            for(int i=0;i<v.size();i++){
                k = k+v[i];
            }
        res = stringToInt(k);
        return res;
    }
};
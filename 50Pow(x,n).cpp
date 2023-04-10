class Solution {
public:
    double myPow(double x, int n) {
        
        double y = x,m=n,res=0;
        if(n==0){
            return 1;
        }
        if(x==1){
            return 1;
        }
        if(x==-1){
            if(n%2==0){
                return 1;
            }else{
                return -1;
            }
        }
        if(n>=0){
            for(int i=1;i<n;i++){
                x = y*x;
            }
        }else{
            m = -1*m;
            for(long long i=1;i<m;i++){
                x = y*x;
                res = 1/x;
                if(res==0.00000){
                    return res;
                }
            }
            x = 1/x;
        }
        return x;
    }
};
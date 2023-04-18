class Solution {
public:
    bool isPerfectSquare(int num) {
        // bool val;
        int a = sqrt(num);
        if(a*a==num){
            return true;
        }
        return false;
    }
};
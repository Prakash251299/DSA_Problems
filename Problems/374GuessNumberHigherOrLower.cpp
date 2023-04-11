/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i=1,a = 0;
        for(i=int(n/2);;){
            a = guess(i);
            if(a==0){
                a = i;
                break;
            }
            if(a==1){
                i++;
            }
            if(a==-1){
                i--;
            }
        }
        return a;
    }
};
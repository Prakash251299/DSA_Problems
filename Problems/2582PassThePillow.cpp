class Solution {
    public int passThePillow(int n, int time) {
        if(n>time){
            return time+1;
        }
        else{
            n-=1;
            if((time/n)%2==0){
                return (time%n)+1;
            }
            else{
                return n-(time%n)+1;
            }
        }
    }
}
class Solution {
    public int maxArea(int[] height)     {
      int dist=height.length-1, j=0, k=dist,max=0,currArea=0;
        for(j=0;j!=k;){
            if(height[j]<=height[k]){
                currArea=dist*height[j];
                j++;
            }
            else{
                currArea=dist*height[k];
                k--;
 
            }
            if(currArea>max){
                max=currArea;
            }
            dist--;
        }
        return max;
    }
}
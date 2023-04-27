class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int i=0,j=0,k=0,max=heights[0],count=0;
        for(i=0;i<heights.size();i++){
            count=0;
            for(j=i;;j--){
                if(j>=0 and heights[j]>=heights[i]){
                    count++;
                }else{
                    break;
                }
            }
            for(j=i;;j++){
                if(j+1<heights.size() and heights[j+1]>=heights[i]){
                    count++;
                }else{
                    break;
                }
            }
            if(max<heights[i]*count){
                max = heights[i]*count;
            }
        }
        cout<<max;
        return max;
    }
};
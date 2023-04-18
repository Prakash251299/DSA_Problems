class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int i=0,j=0,req1=0,req2=0,n1=arr1.size(),n2=arr2.size(),count=0;
        sort(arr2.begin(),arr2.end());
        for(i=0;i<n1;i++){
            req1 = arr1[i]-d;
            req2 = arr1[i]+d;
            for(j=0;j<n2;j++){
                if(arr2[j]>req2){
                    break;
                }
                if(arr2[j]>=req1 and arr2[j]<=req2){
                    count++;break;
                }
            }
        }
        return n1-count;
    }
};
class Solution {
public:
    double merge(vector<int>a,vector<int>b){
        vector<int>v;
        int i=0,j=0;
        for(;;){
            if(i==a.size()){
                for(;j<b.size();j++){
                    v.push_back(b[j]);
                }
                break;
            }
            if(j==b.size()){
                for(;i<a.size();i++){
                    v.push_back(a[i]);
                }
                break;
            }
            if(i<a.size() && j<b.size()){
                if(a[i]<=b[j]){
                    v.push_back(a[i]);
                    i++;
                }
                else{
                    v.push_back(b[j]);
                    j++;
                }
            }
            // cout<<b[i]<<" ";
            // i++;
        }
        for(auto it:v){
            cout<<it<<" ";
        }
        // cout<<v[2];
        double d=0;
        // int val=0;
        int s = v.size();
        if(s%2==0){
            d=(double)(v[s/2]+v[s/2-1])/2;
        }
        else{
            // val = size/2;
            d = v[s/2];
        }
        // cout<<v.size()<<" ";
        
        // cout<<"hi";
        return d;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res;
        res = merge(nums1,nums2);
        return res;
    }
};
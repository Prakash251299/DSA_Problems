#include<iostream>
#include<vector>
using namespace std;
int merge(int *a, int a1, int b1, int a2, int b2){ // 0,3,4,6
    int i=a1,j=a2;
    int k = 0;
    int c[b2-a1+1];
    vector<int>v;
    while(true){
        if(i==b1+1){
            for(;j<=b2;j++){
                c[k] = a[j];
                k++;
            }
            break;
        }
        if(j==b2+1){
            for(;i<=b1;i++){
                c[k] = a[i];
                k++;
            }
            break;
        }
        if(a[i]<=a[j]){
            c[k] = a[i];
            k++;i++;
        }else{
            c[k] = a[j];
            k++;j++;
        }
    }
    for(i=0;i<k;i++){
        a[a1+i] = c[i];
    }
    return 0;
}
int mergeSort(int *a,int i,int j){
    if(i==j){
        return 0;
    }
    int mid = (i+j)/2;
    mergeSort(a,i,mid);
    mergeSort(a,mid+1,j);
    merge(a,i,mid,mid+1,j);
    return 0;
}
int main(){
    int arr[] = {3,5,8,2,6,7,8};
    // int arr[] = {3,5,8,10,6,7,9};
    mergeSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
     for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
         cout<<arr[i]<<" ";
     }
    return 0;
}
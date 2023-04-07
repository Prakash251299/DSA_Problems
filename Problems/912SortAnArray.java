class Solution {
    static int merge(int [] nums, int a, int mid, int b){
        int [] arr = new int[b-a+1];
        
        int j=a, k=mid+1,m=0,x=0;
        for(;;){
            if(j==mid+1||k==b+1){
                break;
            }
            if(nums[j]<=nums[k]){
                arr[m]=nums[j];
                j++;
                m++;
            }
            else{
                arr[m]=nums[k];
                k++;
                m++;
            }
        }
        if(j!=mid+1){
            for(x=j;x<mid+1;x++){
                arr[m]=nums[x];
                m++;
            }
        }
        if(k!=b+1){
            for(x=k;x<b+1;x++){
                arr[m]=nums[x];
                m++;
            }
        }
       // System.out.println("merging");
        for(x=a;x<=b;x++){
            nums[x]=arr[x-a];
            //System.out.print(nums[x]+" ");
        }
        //System.out.println();
        return 0;
    }
    static int mergesort(int[] nums, int a, int b){
        if(a==b){
            return 0;
        }
        int mid= (a+b)/2;
        mergesort(nums, a, mid);
        mergesort(nums, mid+1, b);
        
        merge(nums, a, mid, b);
        return 0;
    }
    public int[] sortArray(int[] nums) {
        mergesort(nums, 0, nums.length-1);
    
    return nums;
    }
}
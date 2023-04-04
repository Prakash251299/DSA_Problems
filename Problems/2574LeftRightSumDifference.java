class Solution {
    public int[] leftRigthDifference(int[] nums) {
        int [] leftSum=new int[nums.length];
        int [] rightSum=new int[nums.length];
        int sum=0;
        leftSum[0]=0;
        for(int i=0;i<nums.length-1;i++){
            sum=sum+nums[i];
            leftSum[i+1]=sum;
        }
        sum=0;
        rightSum[nums.length-1]=0;
        for(int i=nums.length-1;i>0;i--){

           sum=sum+nums[i];

           rightSum[i-1]=sum;

        }
        for(int i=0;i<nums.length;i++){
            //System.out.println(" "+rightSum[i]);
            nums[i]=leftSum[i]-rightSum[i];
            if(nums[i]<0){
                nums[i]=-1*nums[i];
            }
        }
    return nums;
    }
}
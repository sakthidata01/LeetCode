int maxSubArray(int* nums, int numsSize) {
    int maxsum = nums[0];
    int sum = 0;

    /*for(int i=0; i<numsSize; i++){
        int sum = 0;
        for(int j=i; j<numsSize; j++){
            sum = sum + nums[j];
                                                       // this is brute force method which is not accepted due to its time complexity.
                if(sum>maxsum){
            maxsum = sum;
            }
        }
    }
    return maxsum;
} */

    for(int i =0; i<numsSize;i++){
        sum = sum + nums[i];
        if(sum>maxsum){
            maxsum = sum;
        }
        if(sum<0){              //kadane's algorithm to reduce time complexity
            sum = 0;               // (if maxsum and sum both are -ve this alg is used)
        }
    }
    return maxsum;
}
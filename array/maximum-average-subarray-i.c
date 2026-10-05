double findMaxAverage(int* nums, int numsSize, int k) {
    int sum = 0;
    
    for(int i=0; i<k; i++){
        sum = sum + nums[i];
    }
    int j =0; 
    int maxsum = sum;

    for(int i=k; i<numsSize; i++){
        sum = sum - nums[j] + nums[i];
        j++;

        if(sum>maxsum){
            maxsum = sum;
        }
    }   
    double avg =(double)maxsum/k;
    
    return avg;
}
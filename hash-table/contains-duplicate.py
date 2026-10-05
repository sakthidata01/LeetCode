class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        nums.sort()
        for i in range(len(nums)-1):
            if(nums[i] == nums[i+1]):
                return True

        return False

        #  in c with 0[n2] solution:
        # bool containsDuplicate(int* nums, int numsSize) {
        #     for(int i=0; i<numsSize-1; i++){
        #         for(int j=i+1; j<numsSize; j++){
        #             if(nums[i]==nums[j]){
        #                 return true;
        #             }
        #         }
        #     }
        #     return false;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        int left = 1, right = 1;

        while(right < n){
            if(nums[left - 1] == nums[right]){
                right++;
            }
            else{
                nums[left] = nums[right];
                left++;
                right++;
                k++;
            }
        }

        return k + 1;
    }
};
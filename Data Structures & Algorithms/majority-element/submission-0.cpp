class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int votes = 1, n = nums.size();

        for(int i = 1; i < n; i++){
            if(nums[i] == candidate) votes++;
            else if(votes > 0) votes--;
            else{
                candidate = nums[i];
                votes = 1;
            }
        }

        return candidate;
    }
};
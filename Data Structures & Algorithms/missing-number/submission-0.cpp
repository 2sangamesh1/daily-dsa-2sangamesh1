class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        int i = 0;

        while(i < n){
            x = x ^ i ^ nums[i];
            i++;
        }

        return x ^ i;
    }
};
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int k = 2 * n;
        vector<int> ans(k);
        for(int i = 0; i < k; i++){
            ans[i] = nums[i % n];
        }
        return ans;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n - 1, 0);

        for(int i = 0; i < n; i++){
            res[nums[i]]++;
        }

        for(int i = 0; i < n; i++){
            if(res[i] > 1) return i;
        }

        return -1;
    }
};

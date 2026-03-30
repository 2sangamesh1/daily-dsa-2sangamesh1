class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        if(n == 0) return 0;

        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        int maxlen = 1, currlen = 1;
        for(auto num : st){
            if(st.find(num - 1) == st.end()){
                int x = num;
                while(st.find(x + 1) != st.end()){
                    currlen++;
                    x++;
                }
                maxlen = max(maxlen, currlen);
                currlen = 1;
            }
        } 
        return maxlen;
    }
};
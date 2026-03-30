class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int lastbit = n & 1;
            ans = ans << 1;
            ans = ans + lastbit;
            n = n >> 1;
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> freq(256, 0);
        int left = 0;
        int maxlen = 0;

        for(int right = 0; right < n; right++){
            if(freq[int(s[right])] == 0){
                freq[int(s[right])]++;
                maxlen = max(maxlen, right - left + 1);
            }
            else{
                while(s[left] != s[right]){
                    freq[int(s[left])]--;
                    left++;
                }
                left++;
            }
        }

        return maxlen;
    }
};

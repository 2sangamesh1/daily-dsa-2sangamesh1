class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 1;
        int start = 0;
        if(n <= 1) return s;
        
        for(int i = 0; i < n; i++){
            auto [l1, r1] = expandaroundcenter(s, i, i);
            auto [l2, r2] = expandaroundcenter(s, i, i + 1);

            if(r1 - l1 > maxlen){
                maxlen = r1 - l1 - 1;
                start = l1 + 1;
            }
            if(r2 - l2 > maxlen){
                maxlen = r2 - l2 - 1;
                start = l2 + 1;
            }
        }
        return s.substr(start, maxlen);
    }
private:
    pair<int, int> expandaroundcenter(string &s, int i, int j){
        int n = s.size();
        while(i >= 0 && j < n && s[i] == s[j]){
            i--;
            j++;
        }
        return {i, j};
    }
};
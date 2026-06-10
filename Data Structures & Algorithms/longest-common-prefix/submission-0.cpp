class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string s1 = strs[0], s2 = strs[n - 1];
        int k = min(s1.size(), s2.size());
        int i = 0;
        while(i < k){
            if(s1[i] != s2[i]) break;
            i++;
        }
        return s1.substr(0, i);
    }
};
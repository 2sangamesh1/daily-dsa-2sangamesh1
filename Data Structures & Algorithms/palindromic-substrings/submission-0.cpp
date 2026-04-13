class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            ans += expand(s, i, i);
            ans += expand(s, i, i + 1);
        }

        return ans;
    }
private:
    int expand(string s, int i, int j){
        int count = 0; int n = s.size();

        while(i > -1 && j < n && s[i] == s[j]){
            count++;
            i--;
            j++;
        }

        return count;
    }
};

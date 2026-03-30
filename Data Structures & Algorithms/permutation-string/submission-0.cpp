class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1 = s1.size(), n2 = s2.size();
        if(n1 > n2) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);


        for(int i = 0; i < n1; i++){
            freq1[s1[i] - 'a']++;
        }

        for(int i = 0; i < n1; i++){
            freq2[s2[i] - 'a']++;
        }
        int left = 0, right = n1 - 1;
        while(right < n2){
            if(check(freq1, freq2)) return true;

            freq2[s2[left] - 'a']--;
            left++;
            right++;
            freq2[s2[right] - 'a']++;
        }
        return false;
    }
private:
    bool check(vector<int> a, vector<int> b){

        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]){
                return false;
            }
        }

        return true;
    }
};

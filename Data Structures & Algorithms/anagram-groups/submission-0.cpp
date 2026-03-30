class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for(string &str : strs){
            vector<int> freq(26, 0);
            string key = "";

            for(char ch : str){
                freq[ch - 'a']++;
            }

            for(int i = 0; i < 26; i++){
                key += "#" + to_string(freq[i]);
            }

            mp[key].push_back(str); 
        }

        for(auto & it : mp){
            res.push_back(it.second);
        }

        return res;
    }
};

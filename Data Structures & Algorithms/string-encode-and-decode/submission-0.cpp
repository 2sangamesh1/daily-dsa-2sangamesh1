class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string &str : strs){
            res += to_string(str.size());
            res += '#';
            res += str;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        int n = s.size();

        while(i < n){
            string size1 = "";
            int j = i;
            while(s[i] != '#'){
                size1 += s[i];
                i++;
            }
            int size = stoi(size1);

            string word = s.substr(i + 1, size);
            res.push_back(word);
            i = i + size + 1;
        }

        return res;
    }
};

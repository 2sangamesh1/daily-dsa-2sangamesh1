class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string res = "";

        int n1 = a.size();
        int n2 = b.size();

        int i = 0;
        int limit = max(n1, n2);
        int carry = 0;

        while(i < limit){
            int num1 = 0, num2 = 0;
            if(i < n1) num1 = int(a[i] - '0');
            if(i < n2) num2 = int(b[i] - '0');

            i++;

            int sum = carry + num1 + num2;
            if(sum == 0){
                res += "0";
                carry = 0;
            }

            else if(sum == 1){
                res += "1";
                carry = 0;
            }

            else if(sum == 2){
                res += "0";
                carry = 1;
            }

            else{
                res += "1";
                carry = 1;
            }
        }
        if(carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
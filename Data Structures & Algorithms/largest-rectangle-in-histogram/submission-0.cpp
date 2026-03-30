class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector <int> lse(n);
        vector <int> rse(n);

        stack <int> st;

        for(int i = 0; i < n; i++){
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }


            if(st.empty()){
                lse[i] = -1;
            }

            else{
                lse[i] = st.top();
            }

            st.push(i);

        }


        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1; i > -1; i--){
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()){
                rse[i] = n;
            }

            else{
                rse[i] = st.top();
            }

            st.push(i);

        }

        int area = 0, currArea = 0;

        for(int i = 0; i < n; i++){
            currArea = (rse[i] - lse[i] - 1) * heights[i];

            area = max(area, currArea);
        }

        return area;
        
    }
};
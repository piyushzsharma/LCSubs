class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        //const long long MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous smaller (strictly smaller)
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next smaller OR equal
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

       int ans = 0;

        for(int i = 0; i < n; i++) {
            ans=max(ans,arr[i]*(right[i]-left[i]-1));
        }

        return ans;
    }
};
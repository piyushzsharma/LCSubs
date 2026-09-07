class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int n1;
        int n2;

        for(auto it:tokens){
            if(it=="+" || it=="-"|| it=="*" || it=="/") {
                n2=stoi(st.top());
                st.pop();
                n1=stoi(st.top());
                st.pop();
                int val;
                    if (it == "+") {
                        val=n1+n2;
                    }
                    else if (it == "-") {
                        val=n1-n2;
                        // subtraction
                    }
                    else if (it == "*") {
                        // multiplication
                        val=n1*n2;
                    }
                    else if (it == "/") {
                        // division
                        val=n1/n2;
                    }
                    st.push(to_string(val));

            }

            else st.push(it);
        }
        return stoi(st.top());
    }
};
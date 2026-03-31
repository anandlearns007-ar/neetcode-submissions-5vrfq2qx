class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i = 0; i < tokens.size(); i++)
        {
           if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*"|| tokens[i]=="/")
           {
               int top1 = st.top();
               st.pop();
               int top2 = st.top();
               st.pop();
               int curr;
               if(tokens[i] == "+")
               {
                  st.push(top1 + top2);
               }
               else if(tokens[i] == "-")
               {
                   st.push(top2 - top1);
               }
               else if(tokens[i]=="*")
               {
                   st.push(top2 * top1);
               }
               else
               {
                   st.push(top2 / top1);
               }
           }
           else
           {
               st.push(stoi(tokens[i]));
           }
        }
        return st.top();
    }
};

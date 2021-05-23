class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0) return true;
        if(s.size()==1) return false;
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')' || s[i]==']' || s[i]=='}')
            {
                if(st.size()==0) return false;
                char c = st.top();st.pop();
                if(s[i]==')' && c!='(') return false;
                if(s[i]=='}' && c!='{') return false;
                if(s[i]==']' && c!='[') return false;
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.size()==0;
    }
};

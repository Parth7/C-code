class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0) return {};
        vector<string> res;
        string str;
        int l = n;
        int r = 0;
        helper(res,str,l,r);
        return res;
    }
private:
    void helper( vector<string>&res,string &str,int l, int r)
    {
        if(l==0 && r==0)
        {
            return res.push_back(str);
        }
        if(l>0) helper(res,str+'(',l-1,r+1);
        if(r>0) helper(res,str+')',l,r-1);
    }
};
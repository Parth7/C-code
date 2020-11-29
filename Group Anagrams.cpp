class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        map<string,vector<string>>m;
        for(int i=0;i<s.size();i++)
        {
            string st = s[i];
            sort(st.begin(),st.end());
            m[st].push_back(s[i]);
        }
        vector<vector<string>> re;
        for(auto p:m)
        {
            re.push_back(p.second);
        }
        return re;
    }
};

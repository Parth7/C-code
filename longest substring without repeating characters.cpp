class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j = 0,maxl=0;
        unordered_set<char> se;
        while(i<s.size() && j<s.size())
        {
            if(se.find(s[j])==se.end())
            {
                se.insert(s[j]);
                j++;
            }
            else
            {
                se.erase(s[i]);
                i++;
            }
            maxl = max(maxl,j-i);
        }
        return maxl;
    }
};

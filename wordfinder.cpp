class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        vector<string> result;
        for(auto word : words)
        {
            if(helper1(board,word)) result.push_back(word);
        }
        return result;
    }
private:
    vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    bool isvalid(int ni,int nj,int n,int m)
    {
        return (ni>=0 && nj>=0 && ni<n && nj<m);
    }
    bool helper1(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==0 && board[i][j]==word[0])
                {
                    dp[i][j]=1;
                    ans = helper2(board,n,m,word,1,i,j,dp);
                    if(ans==0) dp[i][j]=0;
                    if(ans==1) return ans;
                }
            }
        }
        return ans;
    }
    bool helper2(vector<vector<char>>&board,int n,int m,string word,int c,int &i,int &j,vector<vector<int>> &dp)
    {
        if(c==word.size()) return true;
        int ans = 0;
        for(int k=0;k<4;k++)
        {
            int ni = i+dir[k].first;
            int nj = j+dir[k].second;
            if(isvalid(ni,nj,n,m) && dp[ni][nj]==0 && board[ni][nj]==word[c])
            {
                dp[ni][nj] =1;
                ans = helper2(board,n,m,word,c+1,i,j,dp);
                if(ans==0) dp[ni][nj]=0;
                if(ans==1) return true;
            }
        }
        return ans;
    }

};


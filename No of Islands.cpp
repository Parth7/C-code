class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' && dp[i][j]!='x')
                {
                    count++;
                    dp[i][j] = 'x';
                    helper(grid,dp,i,j);
                }
            }
        }
        return count;
    }
private:
    bool valid(int i,int j,int n ,int m)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }
    void helper(vector<vector<char>>&grid,vector<vector<int>>&dp,int row,int col)
    {
        int n = grid.size();
        int m = grid[0].size();
        static const vector<pair<int,int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
        for(int i=0;i<4;i++)
        {
            int nrow = row+dir[i].first;
            int ncol = col+dir[i].second;
            if(valid(nrow,ncol,n,m) && dp[nrow][ncol]!='x' && grid[nrow][ncol]=='1')
            {
                dp[nrow][ncol] = 'x';
                helper(grid,dp,nrow,ncol);
            }
        }
        return;
    }
};


// 
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto n:nums)
        {
            if(s.find(n)!=s.end()) return true;
            s.insert(n);
        }
        return false;
    }


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

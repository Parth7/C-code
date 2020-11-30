class Solution {
public:
    void setZeroes(vector<vector<int>>& ma) {
        //if(ma.size()==0) return;
        int n = ma.size();
        int m = ma[0].size();
        vector<int>row(n,1);
        vector<int>col(m,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ma[i][j]==0)
                {
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i]==0 || col[j]==0)
                {
                    ma[i][j]=0;
                }
            }
        }
        return;
    }
};

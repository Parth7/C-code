class Solution {
public:
    bool isvalid(int i, int j, int n, int m)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }
    bool builder(vector<vector<char>>&board,string&word,int index, int i, int j, int n, int m)
    {
        if(index==word.size()) 
        {
            return true;
        }
        static const vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        for( int c=0;c<4;c++)
        {
            int new_i = i+dir[c].first;
            int new_j = j+dir[c].second;
            board[i][j] = '*';
            if(isvalid(new_i,new_j,n,m) && word[index]==board[new_i][new_j])
            {
                 return builder(board,word,index+1,new_i,new_j,n,m);
            }
            board[i][j] = word[index];
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int index = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(word[index]==board[i][j])
                     return builder(board,word,index+1,i,j,n,m);
            }
        }
        return false;
    }
};
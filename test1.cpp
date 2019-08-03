//被围绕的区域
int position[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
class Solution {
public:
    void dfs(vector<vector<char>>& board,int row,int col,int i,int j)
    {
        board[i][j]='#';
        for(int k=0;k<4;++k)
        {
            int ni=i+position[k][0];
            int nj=j+position[k][1];
            if(ni>=row||ni<0||nj>=col||nj<0)
                continue;
            if(board[ni][nj]!='X'&&board[ni][nj]!='#')
                dfs(board,row,col,ni,nj);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        int row=board.size();
        int col=board[0].size();
        //第一行和最后一行
        for(int j=0;j<col;++j)
        {
            if(board[0][j]=='O')
                dfs(board,row,col,0,j);
            if(board[row-1][j]=='O')
                dfs(board,row,col,row-1,j);
        }
        for(int i=0;i<row;++i)
        {
            if(board[i][0]=='O')
                dfs(board,row,col,i,0);
            if(board[i][col-1]=='O')
                dfs(board,row,col,i,col-1);
        }
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                if(board[i][j]=='#')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};
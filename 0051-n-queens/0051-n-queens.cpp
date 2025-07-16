class Solution {
public:
bool issafe(int r,int c,vector<string> &board , int n)
{
   // bool f = true;
for(int i =0;i<n;i++)
{
    if(board[i][c]=='Q' && i!=r)
    {return false;}
}
for(int i =0;i<n;i++)
{
    if(board[r][i]=='Q' && i!=c)
    {return false;}
}
int x =r-1;int y =c-1;
while(x>=0 && y>=0)
{
    if(board[x][y]=='Q')
    {return false;}
    x--;y--;
}
int i1 = r + 1, j1 = c + 1;
while (i1 < n && j1 < n) {
    if (board[i1][j1] == 'Q') {
        return false;
    }
    i1++; j1++;
}

int i2 = r - 1, j2 = c + 1;
while (i2 >= 0 && j2 < n) {
    if (board[i2][j2] == 'Q') {
        return false;
    }
    i2--; j2++;
}

int i3 = r + 1, j3 = c - 1;
while (i3 < n && j3 >= 0) {
    if (board[i3][j3] == 'Q') {
        return false;
    }
    i3++; j3--;
}

return true;
}
void put(int row  ,vector<string> &board , int n,vector<vector<string>>  &ans)
{
    if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (issafe(row, col, board, n)) {
                board[row][col] = 'Q';
                put(row + 1, board, n, ans);
                board[row][col] = '.';
            }
        }
}
    vector<vector<string>> solveNQueens(int n) {
        //string s(n,'.');
  vector<string>  board;
  vector<vector<string>>  ans;
  string s(n,'.');
  for(int i =0;i<n;i++)
  {board.push_back(s);}
  int k =0;
  // i have put k queens as of now
  put(0,board,n,ans);
  return ans;
    }
};
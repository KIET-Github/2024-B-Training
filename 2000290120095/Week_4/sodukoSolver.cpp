#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<char>> &board,int row,int col,char c)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][col]==c)
        {
            return false;
        }
        if(board[row][i]==c)
        {
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
        {
            return false;
        }    
    }
    return true;

}

bool solve(vector<vector<char>> &board)
{
   for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j]=='.')
            {
                for(char c='1';c<='9';c++)
                {
                    if(isValid(board,i,j,c))
                    {
                        board[i][j]=c;
                        if(solve(board)==true)
                        return true;
                        else board[i][j]='.';
                    }
                }
                return false;
            }
        }
    } 
    return true;
}

int main()
{
    vector<vector<char>> board={
        {'.','.','.','8','.','.','.','.','9'},
        {'.','1','9','.','.','5','8','3','.'},
        {'.','4','3','.','1','.','.','.','7'},
        {'4','.','.','1','5','.','.','.','3'},
        {'.','.','2','7','.','4','.','1','.'},
        {'.','8','.','.','9','.','6','.','.'},
        {'.','7','.','.','.','6','3','.','.'},
        {'.','3','.','.','7','.','.','8','.'},
        {'9','.','4','5','.','.','.','.','1'},
        
    };
    solve(board);
    for(auto row:board)
    {
        for(auto col:row)
        {
            cout<<col<<" ";
        }
        cout<<endl;
    }

    
}
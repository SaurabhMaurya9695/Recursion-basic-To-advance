#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:

    bool valid(vector<vector<char>> &board,int x,int y,int po)
    {
        for(int i=0;i<board[0].size();i++)
        {
            if(board[x][i]-'0' == po)
                return false;
        }
        for(int i=0;i<board.size();i++)
        {
            if(board[i][y]-'0' == po)
                return false;
        }
        x=3*(x/3);
        y=3*(y/3);
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
           {
                if(board[i][j]-'0' == po)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board,int i,int j)
    {
        if(i == board.size())
            return true;
        
        int ni,nj;
        if(j == board[0].size()-1)
        {
            ni=i+1;
            nj=0;
        }
        else
        {       
            ni=i;
            nj=j+1;
        }
        if(board[i][j]!='.')
            return solve(board,ni,nj);
        else
        {
            for(int po=1;po<=9;po++)
            {
                if(valid(board,i,j,po) == true)
                {   
                    board[i][j]=po+'0';
                    if(solve(board,ni,nj))
                        return true;
                    else
                        board[i][j]='.';
                }
            }
        }
        return false;
    }
   
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        for(int i = 0; i < board.size() ; i ++){
            for(int j = 0 ; j < board[0].size() ; j ++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Solution sol ;
    vector<vector<char >> arr( 9 , vector<char>(9 , '.' )) ;
    for(auto &x : arr){
        for(auto &y : x){
            cin >> y;
        }
    }

    sol.solveSudoku(arr) ;
}
#include<bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>>& chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess.size(); j++) {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printKnightsTour(vector<vector<int>>& chess, int n, int r, int c, int upcomingMove) {
  //write your code here
  // we are standing at r,c position we have to place our knight in n * n matrix;
    if(r < 0 || c < 0 ||  r >=  chess.size()  || c >= chess[0].size() || chess[r][c] > 0){
        return ;
    }

    if(upcomingMove == n * n){
        chess[r][c] = upcomingMove;
        display(chess) ;
        chess[r][c] = 0;
        return;
    }

    // when you are entering with the call 
    chess[r][c] = upcomingMove;
    printKnightsTour(chess , n , r - 2 , c + 1 , upcomingMove + 1 );
    printKnightsTour(chess , n , r - 1 , c + 2 , upcomingMove + 1 );
    printKnightsTour(chess , n , r + 1 , c + 2 , upcomingMove + 1 );
    printKnightsTour(chess , n , r + 2 , c + 1 , upcomingMove + 1 );

    printKnightsTour(chess , n , r + 2 , c - 1 , upcomingMove + 1 );
    printKnightsTour(chess , n , r + 1 , c - 2 , upcomingMove + 1 );
    printKnightsTour(chess , n , r - 1 , c - 2 , upcomingMove + 1 );
    printKnightsTour(chess , n , r - 2 , c - 1 , upcomingMove + 1 );

    // when you are exit with the call 
    chess[r][c] = 0;



}

int main() {
    int n ;
    cin >> n ;
    int r , c;
    cin >> r >> c;
    vector<vector<int>> arr (n , vector<int>(n , 0));
    printKnightsTour(arr , n  , r , c , 1);

}
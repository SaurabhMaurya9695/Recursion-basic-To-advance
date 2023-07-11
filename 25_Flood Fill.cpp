#include<bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<int>> maze , int row , int col , string psf , vector<vector<int>> &visited) 
{
    // boundary cases
    if(row < 0 || col < 0 || row >= maze.size() || col >= maze[0].size() || maze[row][col] == 1 || visited[row][col] == true)
    {
         return;
    }
    else if(row == maze.size() - 1 && col == maze[0].size() - 1) // sr == dr && sc == dc
    {
         cout<<(psf) << endl;
         return;
    }

      visited[row][col] = true; // when we are entering in the maze
      
      floodfill(maze, row - 1, col, psf + "t", visited);
      floodfill(maze, row, col - 1, psf + "l", visited);
      floodfill(maze, row + 1, col, psf + "d", visited);
      floodfill(maze, row, col + 1, psf + "r", visited);
      
      visited[row][col] = false; //when our fun is ending then we have to remove the sign 
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    vector < vector < int >> vis(n, vector < int > (m));
    floodfill(arr ,  0 ,  0 , "" , vis);
}
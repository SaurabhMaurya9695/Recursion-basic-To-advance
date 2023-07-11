#include<bits/stdc++.h>
using namespace std ;

int MinPathSum(vector<vector<int>> arr , int sr , int sc , int dr , int dc , vector<vector<bool>> vis , string ans)
{
	// we have to move only down or right;
	// base case ;

	if(sr < 0 || sc < 0 || sr == dr || sc == dc || vis[sr][sc] == true){
		return INT_MAX;
	}

	if(sr == dr - 1 && sc == dc - 1){
		cout << ans << "\n" ;
		return arr[sr][sc];
	}

	// make calls ;
	vis[sr][sc] = true;
	int path1 = MinPathSum(arr , sr + 1 , sc , dr , dc , vis , ans + "d" );
	int path2 = MinPathSum(arr , sr , sc + 1 , dr , dc , vis , ans + "r" );
	vis[sr][sc] = false;

	return min(path1 , path2) + arr[sr][sc] ;
}
int main(){
	int n , m ;
	cin >> n >> m ;
	vector<vector<int>> arr (n , vector<int>(m)) ;
	for(int i = 0 ;i < n ; i ++){
		for(int j = 0 ; j < m ; j++){
			cin >> arr[i][j] ;
		}
	}

	// make sure we don't have to vis the same path again ;
	vector<vector<bool>> vis(n , vector<bool>(m , false)) ;
	cout << MinPathSum(arr , 0 , 0 , n , m , vis , "" ) << endl;
	return 0  ;
}
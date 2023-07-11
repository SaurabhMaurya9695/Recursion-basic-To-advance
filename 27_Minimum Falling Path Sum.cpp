#include<bits/stdc++.h>
using namespace std ;

//(row, col) to  (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1)
int MinFallingPathSum(vector<vector<int>> arr , int sr , int sc , int dr , int dc)
{
	// boundary case;
	if(sr < 0 || sc < 0 || sr == dr || sc == dc){
		return INT_MAX;
	}
	if(sr == dr - 1 ){ // we are at end ;
		return arr[sr][sc] ;
	}

	// we have to take min from all  the calls; 
	int a = MinFallingPathSum(arr , sr + 1 , sc - 1 , dr , dc) ;
	int b = MinFallingPathSum(arr , sr + 1 , sc , dr , dc) ;
	int c = MinFallingPathSum(arr , sr + 1 , sc + 1 , dr , dc) ;
	int minSum = min(a , min(b , c)) ;
	return minSum + arr[sr][sc] ;

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

	int res = INT_MAX ;
    for(int j = 0 ; j< m ; j++)
    {
        int ans = MinFallingPathSum(arr , 0 , j , n , m) ;
        res = min(res , ans) ;
    }

    cout << res << endl;
	return 0;
	
}
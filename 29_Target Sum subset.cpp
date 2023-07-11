#include<bits/stdc++.h>
using namespace std;


void solve(vector<int> arr , int idx , string ans , int sum , int target  )
{

  	  // base case
	  if(sum > target){
	      return;
	  }

	  if(idx == arr.size()){
	      if(sum == target){
	          cout<<(ans + ".") << endl;
	      }
	      return;
	  }

        solve(arr, idx + 1, ans + to_string(arr[idx]) + ", ", sum + arr[idx], target);
        solve(arr, idx + 1, ans , sum, target);
    
}
int main(){
  int n ;
  cin>> n;
  vector<int>arr(n );
  for(int i = 0 ; i < n ; i++)
  {
    cin>> arr[i];
  }
  int target ;
  cin>> target;

  solve(arr , 0 ,""  , 0,  target);
}
#include<bits/stdc++.h>
using namespace std ;
#define ll long long

// don't forget to includen idx
void solve(ll n , ll open , ll close , string ans  , int idx){

	if(idx  == 2 * n){
		cout << ans << endl;
		return;
	}
	if(close > open) {
		return ;
	}

	// add
	if(open < n){
		solve(n , open + 1 , close , ans + '(' , idx + 1) ;
	}

	if(close < open){
		solve(n , open  , close + 1 , ans + ')' , idx + 1) ;
	}

	// not add ;

}

int main(){
	ll n ;
	cin >> n ;
	//generate all parenthesis ;

	solve(n , 0 , 0 ,"" ,0) ;
}
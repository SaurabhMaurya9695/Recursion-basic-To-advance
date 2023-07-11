#include<bits/stdc++.h>
using namespace std ;
#define ll long long

// we have to find n^x ;
int solve(int n , int x){
    //base case ;

    //expectation : n^x gives us -> n*n*n*........x times;
    //faith : n^(x-1) -> n*n*n*n ..... x-1 times;
    //meet  : n^x = n * (n ^ (x - 1)) ;
    // if we multiply the val of n on the returned val of n ^ (x - 1) then our exp meet;

    // base case ;
    if( x == 0 ){
        return 1;
    }

    //postorder calls ;
    int catched_val = solve(n , x - 1) ;
    int val = n ;
    return n * catched_val ;

}

int main(){
    int n , x;
    cin >> n >> x;
    cout << solve(n, x) << endl ;
    return  0 ;
}
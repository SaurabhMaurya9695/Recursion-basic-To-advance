#include<bits/stdc++.h>
using namespace std ;
#define ll long long

// we have to find n^x ;
int solve(int n , int x){
    //base case ;

    //expectation : n^x gives us -> n*n*n*........x times;
    //faith : n^(x/2) -> n*n*n*n ..... x / 2 times;
    //meet  : n^x = n ^ (x / 2) * n ^ (x / 2) ;
    // if we multiply the val of n on the returned val of n ^ (x / 2) then our exp meet;
    //but for the odd case we have to multiply one more n of the returned val;
    // base case ;
    if( x == 0 ){
        return 1;
    }

    //postordercalls ;
    int xNby2 = solve(n , x / 2);
    //postorder work ;
    int ans = xNby2 * xNby2;

    //just checking the condition 
    if(x % 2 == 1){
        return n * ans;
    }
    else{
        return ans ;
    }

}

int main(){
    int n , x;
    cin >> n >> x;
    cout << solve(n, x) << endl ;
    return  0 ;
}
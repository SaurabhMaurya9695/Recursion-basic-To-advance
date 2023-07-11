#include<bits/stdc++.h>
using namespace std ;
#define ll long long

int solve(int n){
    //base case ;
    if(n == 0 || n == 1){
        return 1;
    }

    // postorder for call 
    int coming_val = solve(n - 1) ;
    int val = n ;
    // postorder work ;
    return n * coming_val ;
}

int main(){
    int n ;
    cin >> n ;
    cout << solve(n) << endl ;
    return  0 ;
}
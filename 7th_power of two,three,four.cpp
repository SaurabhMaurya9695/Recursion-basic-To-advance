#include<bits/stdc++.h>
using namespace std ;
#define ll long long

// we are cheking is n is a power of x or not ?
bool solve(int n , int x){
    if(n == 1){
        return true ;
    }

    if(n % x == 0){
        return solve(n / x , x ) ;
    }
    else{
        return false;
    }

    
}

int main(){
    int n , x ;
    cin >> n >> x;
    cout << ((solve(n , x) == true) ? "true" : "false"  )<< endl ;
    return  0 ;
}
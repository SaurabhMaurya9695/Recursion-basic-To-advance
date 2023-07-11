#include<bits/stdc++.h>
using namespace std ;
#define ll long long

void solve(int n){
    if(n == 0){
        return   ;
    }
    // postorder call ;
    solve(n - 1) ;
    //postorder work ;
    cout<< n << endl;
}

int main(){
    int n ;
    cin >> n ;
    solve(n) ;
    return  0 ;
}
#include<bits/stdc++.h>
using namespace std ;
#define ll long long

void solve(int n){
    if(n == 0){
        return ;
    }
    cout<< n << endl;
    solve(n - 1) ;
}

int main(){
    int n ;
    cin >> n ;
    solve(n) ;
    return  0 ;
}
#include<bits/stdc++.h>
using namespace std ;
#define ll long long

// we are cheking is n is a power of x or not ?
void solve(vector<int> &arr , int idx){
    //basecase ;
    if(idx == arr.size() ){
        return ;
    }

    //  call for postorder 
    solve(arr , idx + 1) ;
    //printing all values in postorder ;
    cout<< arr[idx] << " ";
    
}

int main(){
    vector<int> arr = {1,2,3,4,5,6} ;
    solve(arr , 0) ;
    return  0 ;
}
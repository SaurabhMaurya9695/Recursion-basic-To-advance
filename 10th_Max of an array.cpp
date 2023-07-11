// ``````````````````````BY preorder calls`````````````````````````
#include<bits/stdc++.h>
using namespace std ;
#define ll long long

// we are cheking is n is a power of x or not ?
int ans = INT_MIN;
void solve(vector<int> &arr , int idx){
    //basecase ;
    if(idx == arr.size()){
        cout<< ans << endl;
        return ;
    }

    //checking in preorder who is the max;
    ans = max(ans , arr[idx]);

    // preorder call 
    solve(arr , idx + 1) ;
    
}

int main(){
    vector<int> arr = {11,12,33,42,152,6} ;
    solve(arr , 0) ;
    return  0 ;
}

// ``````````````````````BY PostOrder calls`````````````````````````

#include<bits/stdc++.h>
using namespace std ;
#define ll long long

// we are cheking is n is a power of x or not ?
int ans = INT_MIN;
int solve(vector<int> &arr , int idx){

    // expectation :  solve(arr , idx) -> return us the max ele from idx to n ; X
    // faith       :  solve(arr , idx + 1) -> return us the max ele from idx + 1 to n ; Y


    //basecase ;
    if(idx == arr.size()){
        return arr[idx - 1 ]; 
    }

    int selfVal = arr[idx] ;
    //postOrder call .. it works on faith ;
    int faithValue = solve(arr , idx + 1) ;

    //meeting the expectation -> we returned that value which is greator ;

    // if(faithValue > selfVal){
    //     return faithValue ;
    // }
    // else{
    //     return selfVal;
    // }

    return max(faithValue , selfVal);


}

int main(){
    vector<int> arr = {1166,12,33,421,152,6} ;
    cout << solve(arr , 0)  << endl;
    return  0 ;
}
// ``````````````````````BY PostOrder calls`````````````````````````
#include<bits/stdc++.h>
using namespace std ;
#define ll long long


int solve(vector<int> &arr , int idx , int val , int n)
{
    if(idx == n ){
        if(arr[idx] == val){
            return idx + 1 ; 
        }
        else{
            return -1; // return after all calls;
        }
    }

    // postOrder calls;
    int last_val = solve(arr , idx + 1 , val , n);

    //if last_val == -1 .. it means no val found behind this ;
    if(last_val == -1){
        if(arr[idx] == val){
            return idx + 1 ;
        }
        else{
            return last_val;
        }
    }
    else{
        return last_val;
    }
    
}

int main(){
    vector<int> arr = {1, 2 , 3, 2, 3, 4, 5, 5, 7} ;
    int n = arr.size() - 1;
    int x;
    cin >> x;
    cout <<"VALUE PRESENT AT : " << solve(arr , 0 , x , n)  << endl;
    return  0 ;
}

// ``````````````````````````PreOrder Calls`````````````````````
#include<bits/stdc++.h>
using namespace std ;
#define ll long long


int ans = INT_MIN;
int solve(vector<int> &arr , int idx , int val , int n)
{
    if(idx == n ){
        if(ans == INT_MIN){
            return -1;
        }
        else{
            return ans + 1;
        }
    }

    //preOrder Work;
    if(arr[idx] == val)
    {
        ans = max(ans , arr[idx]);
    }

    //preorder calls;
    return solve(arr , idx + 1 , val , n) ;
}

int main(){
    vector<int> arr = {1, 2 , 3, 2, 3, 4, 5, 5, 7} ;
    int n = arr.size() - 1;
    int x;
    cin >> x;
    cout <<"VALUE PRESENT AT : " << solve(arr , 0 , x , n)  << endl;
    return  0 ;
}
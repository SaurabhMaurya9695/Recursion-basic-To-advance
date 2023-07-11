// ``````````````````````BY preorder calls`````````````````````````

#include<bits/stdc++.h>
using namespace std ;
#define ll long long


int solve(vector<int> &arr , int idx , int val)
{
    if(idx == arr.size()){
        return -1;
    }
    //checking in preorder
    if(arr[idx] == val){
        cout <<"we found at : ";
        return idx + 1;
    }
    return  solve(arr , idx + 1 , val);
}

int main(){
    vector<int> arr = {1, 2 , 3, 2, 3, 4, 5, 5} ;
    int x;
    cin >> x;
    cout << solve(arr , 0 , x)  << endl;
    return  0 ;
}


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
    
    // make postOrder Calls;
    int returned_val = solve(arr , idx + 1 , val , n) ;
    if(returned_val == -1) // behind this no other val found;
    {
        if(arr[idx] == val){
            return idx  + 1;
        }
        else{
            return returned_val;
        }
    }
    else{
        if(arr[idx] == val){
            return idx + 1;
        }
        else{
            return returned_val;
        }
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


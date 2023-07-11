#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> get_stair_paths(int n){
    
    // expectation solve(n) -> retuns all the path from n  to 1 with all jumps ;
    // faith solve(n-1) -> return all the path from n - 1 to 1;
    // meet : if i add 1 in the path of solve(n-1) it will give me the path of 1 

    // base case ;
    //positive baseCase ;
    if(n == 0){
        return {""} ; // we just has a choice of stay at base pos
    }
    else if(n < 0){
        return {} ; // we just return {} ;
    }


    //call for 1 in postOrder , It has to return all the path by taking 1 jump only;
    vector<string> Path1 = get_stair_paths(n - 1);
    // we get all the path1 then add 1 in this path ;
    vector<string> res ;
    for(auto x : Path1){
        res.push_back('1' + x);
    }
    // we can't enter in the postOrder of 2 until we finish 1st call ;

    //call for 2 in postOrder , It has to return all the path by taking 2 jump only;
    vector<string> Path2 = get_stair_paths(n - 2);
    // we get all the path1 then add 2 in this path ;
    for(auto x : Path2){
        res.push_back('2' + x);
    }

    //call for 3 in postOrder , It has to return all the path by taking 3 jump only;
    vector<string> Path3 = get_stair_paths(n - 3);
    // we get all the path3 then add 3 in this path ;
    for(auto x : Path3){
        res.push_back('3' + x);
    }

    return res;
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = get_stair_paths(n);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}
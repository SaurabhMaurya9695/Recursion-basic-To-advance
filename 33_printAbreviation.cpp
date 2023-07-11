#include<iostream>
using namespace std;


void solve(string s , string ans , int idx , int cnt){
    // write your code here
    // if you observe the pattern of ans it is nothing but a binary represntation
    // make two calls for it one for add in ans , and one to not add 
    // if 11 string is there then make ans as 2 ;

    // for every idx we have a choice to be added or not to be added 

    if(idx == s.size()){
        if(cnt == 0){
            cout << ans << endl;
            return;
        }
        else{
            cout << ans + to_string(cnt) << endl;
            return ;
        }
    }
    if(cnt > 0){
        solve(s , ans + to_string(cnt) + s[idx] , idx + 1 , 0) ;
    }
    else{
        solve(s , ans + s[idx] , idx + 1 , 0) ;
    }
    solve(s , ans , idx + 1, cnt + 1) ; 
}



int main(){
    string s;
    cin >> s;
    solve(s,"" , 0 , 0);
}

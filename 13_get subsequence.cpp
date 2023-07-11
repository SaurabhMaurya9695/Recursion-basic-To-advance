#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<string> gss(string s ){
   // expec -> gss(abc) -> this fun returns us all the subsequence of string s;
   // faith -> gss(bc)  -> this fun returns us all subsequence of string bc ;
   // subsequence of c  -> [" " , c] ;
   // subsequence of bc -> [b , bc , " " , c];
   // subsequence of bc is we add once b in subsequence of c or once not ;
    if(s.size() == 0){
        return {""};
    }

    char firstChar = s[0] ;
    string left = s.substr(1);
    
    // get all subsequence of in postorder ;
    vector<string> getSubsequence = gss(left ) ;

    //postOrder Work;
    vector<string> ans ;

    // we have to add once with getSubsequence and not
    for(auto x : getSubsequence){
        ans.push_back("" + x);
    } 
    for(auto x : getSubsequence){
        ans.push_back(firstChar + x);
    } 
    
    return ans ;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s );
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
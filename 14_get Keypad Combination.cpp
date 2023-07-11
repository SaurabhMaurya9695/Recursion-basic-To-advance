#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<string> keypad = {".;" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tu" , "vwx" , "yz"} ;
vector<string> solve(string s){
    //expectation : solve(78) -> gives the all combination of 78 keypad ;
    // faith : solve(8) -> gives all the kaypad combination of 8 ;

    if(s.size() == 0){
        return {""};
    }

    char ch = s[0] ; // it has 7
    string left = s.substr(1);  // it has 8 ;
    // find all the keypad combination for 8 in postorder;
    vector<string> getKeypad = solve(left); // our faith on this ;

    //getKeypad has the all keypad combination of 8 then we have to add 7th key corrosponding
    //keypad alphabets ;

    string KeypadString = keypad[ch - '0'] ; // gives 8 in number and take 8th string of the keypad

    vector<string> res ;

    for(int i = 0 ; i< KeypadString.size() ; i ++){
        char ch = KeypadString[i];
        // we have to add all these ch with the inner of geykeypad ;
        for(auto x : getKeypad){
            res.push_back(ch + x); // adding all char to the postOrder result ;
        }
    }
    return res ;

}

int main(){
    string s;
    cin >> s;
    vector<string> ans = solve(s);
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
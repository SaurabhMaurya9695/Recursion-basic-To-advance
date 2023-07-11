#include <bits/stdc++.h>
using namespace std;

void printSS(string ques, string ans){
    
    // we have to gave our s[0] to choice whether it's pick or unpick 
    // s[0] has choice to add or not add ;

    if(ques.size() == 0){
        cout<<ans << endl;
        return;
    }

    char ch = ques[0]; //  ek baar add kro ans me or ek baar na add kro
    string left = ques.substr(1);
    printSS(left ,  ans + ch ) ;  // add in ans 
    printSS(left , ans + "" );   //  not add in ans ;
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}
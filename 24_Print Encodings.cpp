#include <bits/stdc++.h>
using namespace std;

void solve(string s, string ans){
    // write your code here

    // we have to go in  preorder and make call for 
    // single digit and double digit ;
    if (s.length()==0)
    {
        cout<<ans<<endl;
        return;
	}

	int code1 = s[0]-'0';
	char atcode1 = char('a'+code1-1);
	int code2 = stoi(s.substr(0,2));
	char atcode2 = char('a'+code2-1);

	if(code1 >0 && code1 < 10)
		solve(s.substr(1),ans + atcode1);
	if(code2 >=10 && code2 <=26)
		solve(s.substr(2),ans + atcode2);

    
}

int main(){
    string str;
    cin>>str;
    solve(str,"");
    
}
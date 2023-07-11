#include <bits/stdc++.h>
using namespace std;

void printPermutations(string s, string asf ){
	
	if(s.size() == 0){
		cout<< asf << endl;
		return ;
	}
	for(int i = 0 ; i < s.size() ; i ++){
		// i denote the char we choose;
		char ch = s[i]; 
		// and make call on left part ;
		string beforeCh = s.substr(0 , i) ;
		string afterch = s.substr(i + 1) ;
		string NewStr = beforeCh  + afterch ;
		printPermutations(NewStr, asf + ch) ;
	}

}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"" );
    
}
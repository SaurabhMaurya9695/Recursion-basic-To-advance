#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    // we know we have to print our ans when ques == " ";
    if(ques.size() == 0){
    	cout << asf << "\n";
    	return ;
    }

    // get the keypad of s[0] ;
    char ch = ques[0]  ;
    string KeypadCode = codes[ch - '0'];
    string left = ques.substr(1);
    for(int i = 0 ;i < KeypadCode.size() ; i++) // you have to add the all keypadCode char in all the calls;
    {
    	printKPC(left , asf + KeypadCode[i]) ;
    }
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}
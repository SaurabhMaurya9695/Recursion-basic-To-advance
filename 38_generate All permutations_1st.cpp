https://cses.fi/paste/392c0f6ede31cb8558acc9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
/*
 *    coder :: Saurabh Maurya
 *        >>> INDIA <<<
 */
set<string> st ;
 
void solve( string s , string ans)
{
	if(s.size() == 0){
		st.insert(ans);
		return ;
	}
 
	for(int i = 0;  i< s.size() ; i ++){
		char ch = s[i] ;
		string left = s.substr(0 , i) + s.substr(i + 1);
		solve(left , ans + ch) ;
	}
 
}
int main()
{
    string s;
    cin >> s;
    
    string ans ;
    solve( s , ans) ;
 
cout << st.size() << endl;
    for(auto x : st){
    	cout << x << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    
    return 0;
}
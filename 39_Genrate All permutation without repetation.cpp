#include <bits/stdc++.h>
using namespace std;
#define ll long long 
/*
 *    coder :: Saurabh Maurya
 *        >>> INDIA <<<
 */
 
vector<string> temp ;
void solve(ll idx , ll n , map<char , ll> & mp , string ans , string s)
{
	// every place has two choice to be select or not ;
	if(idx >  n){
		temp.push_back(ans);
		return ;
	}
 
	for(auto &[x , r] : mp){
		if(mp[x] > 0){
			mp[x] --;
			solve(idx + 1, n , mp , ans + x , s) ;
			mp[x] ++ ;
		}
	}
 
 
}
int main()
{
    string s;
    cin >> s;
    map<char , ll > mp;
    for(auto x : s){
    	mp[x]++;
    }
 
    string ans ;
    solve(0 , s.size() - 1 , mp , ans , s) ;
    cout<< temp.size() << endl;
    for(auto x : temp){
    	cout << x << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    
    return 0;
}
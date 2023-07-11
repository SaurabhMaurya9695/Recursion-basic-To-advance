#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string ans){

	// when we reached destination
    if(sr == dr  && sc == dc){
    	cout << ans << endl;
    	return ;
    }
    //negative baseCase
    if(sr < 0 || sc < 0){
    	return ;
    }


    if(sr < dr){
    	printMazePaths(sr + 1 , sc , dr , dc , ans + "h") ;// jb tak ye condition true rhegi tb tak 1 bahta rhega
    }

    if(sc < dc){
    	printMazePaths(sr , sc + 1 , dr , dc , ans + "v") ; // jb tak ye condition true rhegi tb tak 1 bahta rhega
    }
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}
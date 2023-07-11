#include<iostream>
using namespace std;


void printMazePaths(int sr, int sc, int dr, int dc, string ans) {
    // when we reached destination
    if(sr == dr  && sc == dc){
    	cout << ans << endl;
    	return ;
    }
    //negative baseCase
    if(sr < 0 || sc < 0){
    	return ;
    }

    // if we at index i then we can make the calls of h1 , h2 , h3 ;
    for(int i = 1; i<= 3 ; i++){
    	if(sr < dr){
    		printMazePaths(sr + i , sc, dr , dc , ans + "h" + to_string(i));
    	}
    }

    for(int i = 1; i<= 3 ; i++){
    	if(sc < dc){
    		printMazePaths(sr , sc + i , dr , dc , ans + "v" + to_string(i));
    	}
    }
    for(int i = 1; i<= 3 ; i++){
    	if(sr < dr || sc < dc){
    		printMazePaths(sr + i , sc + i , dr , dc , ans + "d" + to_string(i));
    	}
    }
}

int main() {
        int n ;
        int m ;cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }
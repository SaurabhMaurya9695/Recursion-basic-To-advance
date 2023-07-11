#include <iostream>
using namespace std;

void printStairPaths(int n, string psf){
    
    if( n < 0 ){
    	return ;
    }
    if(n == 0){
        cout << psf << "\n";
        return ;
    }

    for(int i = 1 ; i <= n ; i++){
    	printStairPaths(n - i , psf + to_string(i)); // all calls of 1 , 2, 3 only 
        // whatever the call made and added in psf
    }
}

int main(){

    int n;
    cin >> n;
    printStairPaths(n, "");
}
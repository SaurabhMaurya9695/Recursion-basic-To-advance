#include<iostream>
using namespace std;


void printZigZag(int n){
    // write your code here
    if(n == 0){
        return;
    }

    cout << n << " ";
    printZigZag(n - 1) ; //calling in preorder 
    cout << n << " ";  // printing in Inorder
    printZigZag(n - 1) ; // calling for postorder ;
    cout << n << " " ;  // printing in PostOrder

    
}



int main(){
    int n; cin>>n;
    printZigZag(n);
}

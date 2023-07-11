#include<bits/stdc++.h>
using namespace std ;
void display(vector<int> arr){
	for(int i = 0 ;i < arr.size() ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void solve(vector<int> arr , int opt , int size ){
	if(opt >  size){
		display(arr);
		return ;
	}

	for(int idx =0 ; idx < arr.size() ; idx ++) // we have to fill all boxes
	{
		if(arr[idx] == 0){ // box is empty then we can place the 
			arr[idx] = opt ; // place at ith place 
			solve(arr , opt + 1 , size ); // make choice for next place
			arr[idx] = 0; // now backtrack when came 
		}
	}
}

int main(){
	int n ;
	cin >> n ;
	vector<int> arr(n, 0);
	solve(arr , 1 , n );
}
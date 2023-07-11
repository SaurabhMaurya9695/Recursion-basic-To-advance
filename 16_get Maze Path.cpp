#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    // expectation : GMP(source , destination ) -> we have to find all the path from src to dst
    // if we are taking the H right call from (x , y) then its value be (x , y + 1) ;
    // if we are taking the V dowm call from (x , y) then its value be (x + 1 , y)  ;

    // whatever the ans is received by (x + 1 , y) -> we have to just add V behind this
    // and H behind (x , y + 1) calls ;

    // baseCase ;
    // we have to stop when we reached our destination ;
    if(sr == dr && sc == dc){
        return {""}; // just stay there ;
    }


    // making call for H & V and receiving the all values in postOrder ;
    vector<string> HPath ;
    vector<string> VPath;
    if(sc < dc){ // if this condition always hold then you can move in H drxn
         HPath = getMazePaths(sr , sc + 1 , dr , dc) ;
    }
    if(sr < dr){
         VPath = getMazePaths(sr + 1, sc , dr , dc) ;
    }

    // to store all the path ;
    vector<string> AllPaths ;

    //Adding H behind H path ;
    for(auto x : HPath){
        AllPaths.push_back("H" + x);
    }

    //Adding V behind V path ;
    for(auto x : VPath){
        AllPaths.push_back("V" + x);
    }

    return AllPaths;

}


void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}
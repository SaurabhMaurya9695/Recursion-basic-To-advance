#include<bits/stdc++.h>
using namespace std;

vector<string> getMazePaths(int srcRow, int srcCol, int destRow, int destCol) {
   // faith : whatever the path coming from horizontal we add H behind this it will gave 
   // all the path 
        if(srcRow == destRow && srcCol == destCol)
        {
            // Positive Base Case
            return {""};
        }
        else if(srcRow > destRow || srcCol > destCol)
        {
            // Negative Base Case
            return {};             
        }
        vector<string> res ;
        // Horizontal
        for(int i=1; srcCol + i <= destCol; i++)
        {
            vector<string> hpaths = getMazePaths(srcRow, srcCol + i, destRow, destCol);
            for(string s: hpaths)
                res.push_back("h" + to_string(i) + s);
        }
        
        // Vertical
        for(int i=1; srcRow + i <= destRow; i++)
        {
            vector<string> vpaths = getMazePaths(srcRow + i, srcCol, destRow, destCol);
            for(string s: vpaths)
                res.push_back("v" + to_string(i) + s);
        }
        
        // Diagonal
        for(int i=1; srcCol + i <= destCol && srcRow + i <= destRow; i++)
        {
            vector<string> dpaths = getMazePaths(srcRow + i, srcCol + i, destRow, destCol);
            for(string s: dpaths)
                res.push_back("d" + to_string(i) + s);
        }
        return res;
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
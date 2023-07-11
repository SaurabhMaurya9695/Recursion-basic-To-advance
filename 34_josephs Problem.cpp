#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:  
    int solve(int n , int k)
    {
        if(n == 1)
        {
            return 0;
        }
        int x = solve(n - 1, k);
        int y = (x + k) % n ;
        return y;
    }

    int josephus(int n, int k)
    {
        return solve(n , k) + 1;
    }
};

int main(){
    Solution sol  ;
    int x = sol.josephus(7,3) ;
    std::cout << x << "\n";
    return 0;

}


// Method 2 ;

class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int> q;
        for(int i = 1 ; i <= n ; i++)
        {
            q.push(i);    // 1 2 3 4 5 
        }
        while(q.size() != 1)
        {
            int del = k - 1;
            while(del --)
            {
                int x = q.front();
                q.pop();
                q.push(x);
            }
             q.pop();
            
        }
        return q.front();
    }
};
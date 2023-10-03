/*
number of good pairs -> 
Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

*/

#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end() 
#define pb push_back 
#define nn '\n' 

// brute force approach... T_C -> O(N*N)  S_C -> O(1)

void f1(int n, vector<int>&v)
{
    int ans=0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(v[i]==v[j]) ans++;
        }
    }
    
    cout << ans << nn;
}

// optimized approach. T_C -> O(N) , S_C -> O(1) 

void f2(int n, vector<int>&v)
{
    int ans=0;
    map<int,int>mp;
    
    for(int i=0; i<n; i++)
    {
        ans+=mp[v[i]];
        
       // cout << ans << nn;
        
        mp[v[i]]++;
    }
    
    cout << ans << nn;
}

void solve()
{
    int n;
    cin >> n;
    
    vector<int>v(n);
    
    for0(i, n)
    cin >> v[i];
    
    f1(n, v);
    
    f2(n, v);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    solve();
    
    return 0;
}

/*
input 
2
6
1 2 3 1 1 3
4
1 1 1 1

output 
4
6 
*/
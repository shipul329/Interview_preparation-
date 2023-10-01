/*  Problem statement -> 

Given an array of n integers nums, a 132 pattern is a subsequence of three integers
nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.
*/

#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back 
#define nn '\n'

// brute force approach T_C -> O(N*N*N) S_C -> O(1);

bool f1(int n, vector<int>&v)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(v[j] > v[k] && v[k] > v[i])
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

// here comes the hero "The Stack"! T_C -> O(N) & S_P -> O(N).. since we are maintaining a stak 

bool f2(int n, vector<int>&v)
{
    stack<int>st;
    
    int tmp=INT_MIN; /// which is c, where we gonna deal b>c && c>a 
    
    for(int i=n-1; i>=0; i--)
    {
        if(v[i] < tmp) return true;
        
        while(!st.empty() && st.top() < v[i])
        {
            tmp=st.top();
            st.pop();
        }
        
        st.push(v[i]);
    }
    
    return false;
}

void solve()
{
    int n;
    cin >> n;
    
    vector<int>v(n);
    
    for0(i, n)
    cin >> v[i];
    
    bool flag=f2(n, v);
    
    if(flag) cout << "Yes" << nn;
    
    else cout << "No" << nn;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}

/*
input 
4
4
1 2 3 4
4
3 1 4 2
6
4 7 11 5 13 2
4
11 11 12 9

output 
No
Yes
Yes
No
*/ 
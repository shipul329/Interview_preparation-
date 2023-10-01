/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that 
you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

TC-> O(V+E) & SC-> O(N)+O(N) ~ O(2N)= O(N) 
*/

#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back 
#define nn '\n'

bool canFinish(int n, vector<int>adj[])
{
    vector<int>indegree(n, 0);
    
    for0(i, n)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    
    queue<int>q;
    vector<int>ans;
    
    for(int i=0; i<n; i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        ans.pb(node);
        
        for(auto it:adj[node])
        {
            indegree[it]--;
            
            if(indegree[it]==0)
            q.push(it);
        }
    }
    
    if(ans.size()!=n)
    return false;
    
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector<int>adj[n];
    
    for0(i, m)
    {
        int u, v;
        cin >> u >> v;
        
        adj[v].pb(u);
    }
    
    bool flag=canFinish(n, adj);
    
    if(flag) cout << "YES" << nn;
    
    else cout << "NO" << nn;
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
2 
4 4
1 0
2 0
3 1 
3 2
2 2 
0 1 
1 0 

output 
YES
NO 
*/
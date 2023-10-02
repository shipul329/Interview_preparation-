/*
Given a sorted dictionary of an alien language having N words and k starting alphabets
of standard dictionary. Find the order of characters in the alien language.
*/


/*
  **Note that: interviewr might ask, when the order will not be possible ?? 
    two cases are there when the order will not be possible 
    1) if all the characters are same and large one is before smaller 
         abdc, abd in that case this is not possible 
    2) and when we will get a DAG like a->b and b->a so a<b<a there is a DAG 
*/


#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back 
#define nn '\n'

vector<int>topoSort(int n, vector<int>adj[])
{
    vector<int>indegree(n, 0);
    
    for(int i=0; i<n; i++)
    {
        for(auto it:adj[i])
        indegree[it]++;
    }
    
    queue<int>q; 
    
    for(int i=0; i<n; i++)
    if(indegree[i]==0) q.push(i);
    
    vector<int>tmp;
    
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        tmp.pb(node);
        
        for(auto it:adj[node])
        {
            indegree[it]--;
            
            if(indegree[it]==0)
            q.push(it);
        }
    }
    
    return tmp;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    
    vector<string>v(n);
    
    for0(i, n)
    {
        cin >> v[i];
    }
    
    vector<int>adj[k];
    
    for(int i=0; i<n-1; i++)
    {
        string fs=v[i];
        string sn=v[i+1];
        
        int mn=min((int)fs.size(), (int)sn.size());
        
        for(int j=0; j<mn; j++)
        {
            if(fs[j]!=sn[j])
            {
                adj[fs[j]-'a'].push_back(sn[j]-'a');
                break; 
            }
        }
    }
    
    vector<int>ans=topoSort(k, adj);
    
    string str="";
    
    for(auto it:ans)
    {
        str+=(char)it+'a';
    }
    
    cout << str << nn; 
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
5 4
baa abcd abca cab cad 
3 3 
caa aaa aab 

output 
bdac 
cab 
*/
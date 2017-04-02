#include <bits/stdc++.h>

using namespace std; // }}}
vector <int> adj[100005];
bool visited[100005];
int c=0;
void dfs(int s)
    {
    visited[s]=true;
    c++;
    for(int i=0;i<adj[s].size();i++)
        {
        int temp=adj[s][i];
        if(!visited[temp])
            dfs(temp);
    }
}
int main()
{ 
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    long long result =(long long) n*(n-1)/2;
     for(int i=0;i<n;i++)
         {
         visited[i]=false;
     }
    for(int i=0;i<n;i++)
        {
        if(!visited[i])
            {
            c=0;
            dfs(i);
            result-=(long long)(c*(c-1)/2);         
        }
    }

    
    /** Write code to compute the result using N,I,pairs **/
    
    
    cout << result << endl;
    return 0;
}

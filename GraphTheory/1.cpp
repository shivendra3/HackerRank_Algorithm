#include<bits/stdc++.h>
using namespace std;
vector <int> v[100006];
bool visited[100006];
int c=0,n,m,lib,cit;
void dfs(int s)
    {
    visited[s]=true;
    c++;
    for(int i=0;i<v[s].size();i++)
        {
        int temp=v[s][i];
        if(!visited[temp])
        dfs(temp);
        }
}
int main()
    {
    int t,x,y;
    cin>>t;
    while(t--)
        {
        cin>>n>>m>>lib>>cit;
        for(int i=0;i<=n;i++)
            {
            visited[i]=false;
            v[i].clear();
        }
        for(int i=0;i<m;i++)
            {
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        long long cost=0;
        for(int i=1;i<=n;i++)
            {
            if(!visited[i])
                {
                c=0;
                dfs(i);
                //cout<<c;
                cost+=lib;
                cost+=(c-1)*cit;
            }
        }
        cout<<min(cost,(long long)n*lib)<<endl;
    }
    return 0;
}

void DFS(vector<int> adj[],int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<pair<int,int>>& bridge)
{
    static int time = 0;
    disc[u] = low[u] = time;
    time+=1;

    for(int v: adj[u])
    {
        if(disc[v]==-1) //If v is not visited
        {
            parent[v] = u;
            DFS(adj,v,disc,low,parent,bridge);
            low[u] = min(low[u],low[v]);

            if(low[v] > disc[u])  // Bridge detected..
                bridge.pb({u,v});
        }
        else if(v!=parent[u])   //Ignore child to parent edge and get minimum discovery time for node which means that we can reach here via another path
            low[u] = min(low[u],disc[v]);
    }
}


int main()
{

    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();

    vector<int> adj[3];
    adj[0].push_back(1);
    adj[1].push_back(2);

    int V = 3;

    vector<int> disc(V,-1),low(V,-1),parent(V,-1);
    vector<pair<int,int>> bridge;


    for(int i=0;i<3;++i)
        if(disc[i]==-1)
            DFS(adj,i,disc,low,parent,bridge);




    d(disc);
    d(low);
    d(parent);
    for(auto it: bridge)
        cout<<it.first<<"-->"<<it.second<<"\n";


    return 0;
}

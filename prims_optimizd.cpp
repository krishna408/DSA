class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<bool> mst(V,0);
        vector<int> parent(V,-1);
        vector<int> key(V,INT_MAX);
        key[0]=0;
        
        pq.push({0,0});
        while(!pq.empty()){
            int v=pq.top().second;
            //int weight=pq.top().first;
            mst[v]=1;
            pq.pop();
            
            for(int i=0;i<adj[v].size();i++){
                int a=adj[v][i][0];
                int b=adj[v][i][1];
                
                if(!mst[a]&&key[a]>b){
                    key[a]=b;
                    //mst[it.first]=1;
                    
                    pq.push({b,a});
                    parent[a]=v;
                }
            }
            
        }
        int sum=0;
        for(int x:key)
        sum+=x;
        return sum;
    }
};


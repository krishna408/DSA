class Solution {
public:
    void dfs(int parent,int node,vector<int> adj[],vector<int>&low,vector<int>&tin,vector<int>&vis,vector<vector<int>>&res,int &time){
        low[node]=tin[node]=time++;
        vis[node]=1;
        for(auto it:adj[node]){
            if(it==parent)
                continue;
            if(vis[it]==0){
             dfs(node,it,adj,low,tin,vis,res,time);
             
                low[node]=min(low[node],low[it]);
                
             if(low[it]>tin[node]){
                 res.push_back({node,it});
             }
                
            }else{
                low[node]=min(low[node],tin[it]);
            }
        }        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);
        
        int time=1;
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            
        }
        
        vector<vector<int>>res;
        for(int i=0;i<n;i++){    
            if(vis[i]==0)
            dfs(-1,i,adj,low,tin,vis,res,time);
        
        }
        
        return res;
    }
};

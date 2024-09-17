class Solution {
private:
    void DFS(int node,vector<int> &visited ,vector<int> adj[]){
        visited[node]=1;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                DFS(neighbour, visited, adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        /*unordered_map<int, list<int>>adj;
        //creating adjacency list
        for(int i=0; i<v; i++){
            int u=isConnected[i][0];
            int v=isConnected[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }*/
        vector<int> adj[v];

        for(int i = 0;i<v;i++){
            for(int j = 0;j<v;j++){
                if(isConnected[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        //unordered_map<int,bool>visited;
        vector<int> visited (v, 0);
        int cnt=0;
        for(int i=0; i<v; i++){
            if(!visited[i]){
                DFS(i,visited,adj);
                cnt++;
            }
        }
        return cnt;
    }
};

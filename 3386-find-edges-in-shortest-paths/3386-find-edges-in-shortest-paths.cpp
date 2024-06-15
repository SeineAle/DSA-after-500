class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int N = edges.size();
        map<vector<int>, int> mp;
        for(int i = 0; i < N; i ++){
            mp[{min(edges[i][0], edges[i][1]), max(edges[i][0], edges[i][1]), edges[i][2]}] = i;
        }
        vector<vector<pair<int, int>>> graph(n);
        for(auto edge : edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> dist(n, INT_MAX); dist[0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0});
        while(pq.size()){
            int s = pq.top()[0];
            int u = pq.top()[1];
            pq.pop();
            for(auto el : graph[u]){
                int v = el.first;
                int w = el.second;

                if(dist[v] >= s + w){
                    dist[v] = s + w;
                    pq.push({s+w, v});
                }
            }
        }
        vector<bool> ans(N, false);
        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(n-1);
        while(q.size()){
            int u = q.front();
            q.pop();
            for(auto el : graph[u]){
                int v = el.first;
                int w = el.second;
                if(dist[u] - w == dist[v]){
                    ans[mp[{min(u, v), max(u,v), w}]] = true;
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
        return ans;
    }
};

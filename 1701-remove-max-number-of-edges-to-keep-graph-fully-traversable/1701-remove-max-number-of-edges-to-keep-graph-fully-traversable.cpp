class dissjoint_set{
    private:
        vector<int> size, parant;
    public:
        dissjoint_set(int n){
            size.resize(n + 1, 1);
            parant.resize(n + 1);
            for(int i = 0; i <= n; i ++) parant[i] = i;
        }

        int find_parant(int X){
            if(parant[X] == X) return X;
            parant[X] = find_parant(parant[X]);
            return parant[X];
        }
        void union_by_size(int X, int Y){
            int UpX = find_parant(X);
            int UpY = find_parant(Y);

            if(UpX == UpY) return;

            if(size[UpX] <= size[UpY]){
                parant[UpX] = UpY;
                size[UpY] += size[UpX];
            }

            else{
                parant[UpY] = UpX;
                size[UpX] += size[UpY];
            }
        }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dissjoint_set DS1(n);
        dissjoint_set DS2(n);
        vector<bool> toBeRemoved(edges.size(), false);
        for(int i = 0; i < edges.size(); i ++){
            if(edges[i][0] == 3){
                int u = edges[i][1];
                int v = edges[i][2];
                if(DS1.find_parant(u) == DS1.find_parant(v)){
                    toBeRemoved[i] = true;
                }else{
                    DS1.union_by_size(u, v);
                    DS2.union_by_size(u, v);
                }
            }
        }
        for(int i = 0; i < edges.size(); i ++){
            if(edges[i][0] == 1){
                int u = edges[i][1];
                int v = edges[i][2];
                if(DS1.find_parant(u) == DS1.find_parant(v)){
                    toBeRemoved[i] = true;
                }else{
                    DS1.union_by_size(u, v);
                }
            }
        }
        for(int i = 0; i < edges.size(); i ++){
            if(edges[i][0] == 2){
                int u = edges[i][1];
                int v = edges[i][2];
                if(DS2.find_parant(u) == DS2.find_parant(v)){
                    toBeRemoved[i] = true;
                }else{
                    DS2.union_by_size(u, v);
                }
            }
        }
        set<int> st1, st2;
        for(int i = 1; i <= n; i ++){
            st1.insert(DS1.find_parant(i));
        }
        for(int i = 1; i <= n; i ++){
            st2.insert(DS2.find_parant(i));
        }
        if(st1.size() != 1 || st2.size() != 1) return -1;
        int sum = 0;
        for(auto el : toBeRemoved){
            sum += el;
        }
        return sum;
    }
};
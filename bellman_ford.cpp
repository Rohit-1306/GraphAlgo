vector<int> bellman_ford(int v, int src, vector<vector<int>>& edges) { //O(V * E)
    vector<int> dis(v + 1, INT_MAX);
    dis[src] = 0;

    //relax all edges v-1 times
    for (int i = 0; i < v - 1; i++) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dis[u] != INT_MAX and (dis[u] + w < dis[v]))
                dis[v] = dis[u] + w;
        }
    }

    //for negative weight cycle
//    for(auto edge : edges){
//        int u = edge[0];
//        int v = edge[1];
//        int w = edge[2];

//        if(dis[0] != INT_MAX and (dis[u]+w < dis[v])){
//            cout<<"Negative wt cycle found";
//            exit(0);
//        }
//    }

    return dis;
}

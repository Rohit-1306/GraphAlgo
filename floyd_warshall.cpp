vector<vector<int>> floyd_warshall(vector<vector<int>> adj_matrix) { // O(V^3)
    vector<vector<int>> dis(adj_matrix);
    int v = adj_matrix.size();

    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dis[i][j] > dis[i][k] + dis[k][j] and dis[i][k] != INT_MAX and dis[k][j] != INT_MAX)
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
    return dis;
}

vector<int> dijsktra(vector<pair<int,int>>& graph[], int src) { // O((N + M) log N)
    vector<int> d(n + 1, INT_MAX);
    set<pair<int, int>> s; //{weight,node}

    s.insert({0, src});
    d[src] = 0;

    while (s.size() != 0) {
        auto it = s.begin();
        int i = it -> second;

        s.erase(it);

        for (auto e : graph[i]) {
            int nbr = e.first;
            int w = e.second;

            if (d[i] + w < d[nbr]) {
                s.erase({d[nbr], nbr});
                d[nbr] = d[i] + w;
                s.insert({d[nbr], nbr});
            }
        }
    }
    return d;
}

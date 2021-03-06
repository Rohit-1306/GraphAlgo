int findSet(int i, int parent[]) {
    if (parent[i] == -1)
        return i;

    return parent[i] = findSet(parent[i], parent);
}

void unionSet(int x, int y, int parent[], int rank[]) {
    int s1 = findSet(x, parent);
    int s2 = findSet(y, parent);

    if (s1 != s2) {
        if (rank[s1] < rank[s2]) {
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }
        else {
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
    }
}

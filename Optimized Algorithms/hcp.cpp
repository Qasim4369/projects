#include <iostream>
#include <cstring>
using namespace std;
//pseudocode :
//
//1. Read the input parameters.
//2. For every subset S of{ 1, 2, ..., n } that contains the starting vertex :
//a.If | S | = 1, set the cost of the subset to 0 and continue.
//b.For every vertex v in S that is not the starting vertex :
//i.If v has not been visited before, mark it as visited.
//ii.Calculate the cost of the path that starts at the starting vertex, goes through all vertices in S, and ends at v.
//iii.Recursively find the minimum cost of visiting all remaining vertices in S, starting from v.
//iv.Add the cost of the path from v back to the starting vertex to the total cost of visiting all vertices in S, and update the minimum cost if necessary.
//c.If all vertices in S have been visitedand the total cost of visiting all vertices in S is less than T, update the minimum cost if necessary.
//3. If the minimum cost is less than or equal to T, output the minimum costand the corresponding path.Otherwise, output "NO FEASIBLE CIRCUIT".
//
//time complexity:
//
//-Step 1 takes constant time.
//- Step 2 loops over all subsets of{ 1, 2, ..., n } that contain the starting vertex.There are 2 ^ (n - 1) such subsets, so this step has a time complexity of O(2 ^ n).
//- Step 2b loops over at most n vertices in each subset, and performs a constant amount of work for each vertex.Therefore, the time complexity of this step is O(n * 2 ^ n).
//- Step 2c checks whether all vertices in S have been visited, which takes O(n) time, and adds the cost of the path back to the starting vertex, which takes constant time.Therefore, the time complexity of this step is O(n * 2 ^ n).
//- Step 3 takes constant time.
//- Therefore, the overall time complexity of the algorithm is O(n * 2 ^ n).
const int MAXN = 20;

int n, T, g[MAXN][MAXN], t[MAXN], path[MAXN], best_path[MAXN], best_cost = 1e9;
bool vis[MAXN];

void dfs(int u, int cost, int depth) {
    if (depth == n) { // found a complete path
        if (g[u][0] != -1 && cost + g[u][0] <= T && cost + g[u][0] < best_cost) {
            best_cost = cost + g[u][0];
            memcpy(best_path, path, sizeof(path));
        }
        return;
    }
    for (int v = 0; v < n; ++v) {
        if (g[u][v] != -1 && !vis[v] && cost + g[u][v] + t[v] <= T && cost + g[u][v] + t[v] < best_cost) {
            vis[v] = true;
            path[depth] = v;
            dfs(v, cost + g[u][v] + t[v], depth + 1);
            vis[v] = false;
        }
    }
}

int main() {
    // input graph
    cout<<"Input Graph size n"<<endl;
    cin >> n;
    memset(g, -1, sizeof(g));
    for (int i = 0; i < n; ++i) g[i][i] = 0;
    cout<<"Input m"<<endl;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    // input delivery times and time limit
    for (int i = 1; i < n; ++i) cin >> t[i];
    cout<< "Input T"<< endl;
    cin >> T;
    // start from vertex 0 (home location)
    vis[0] = true;
    path[0] = 0;
    dfs(0, 0, 1);
    if (best_cost == 1e9) cout << "NO FEASIBLE CIRCUIT\n";
    else {
        for (int i = 0; i < n; ++i) cout << best_path[i] << " ";
        cout << 0 << endl;
    }
    return 0;
}

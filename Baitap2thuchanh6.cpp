#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, dist;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

int main() {
    int N, M, XI, YI, XJ, YJ;
    cin >> N >> M >> XI >> YI >> XJ >> YJ;
    XI--; YI--; XJ--; YJ--;

    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    const int INF = 1e9;
    vector<vector<int>> dist(N, vector<int>(M, INF));
    vector<vector<pair<int,int>>> parent(N, vector<pair<int,int>>(M, {-1,-1}));

    // 4 hướng di chuyển
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    if (A[XI][YI] == 0 || A[XJ][YJ] == 0) {
        cout << 0; // không đi được
        return 0;
    }

    dist[XI][YI] = 0;
    pq.push({XI, YI, 0});

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        if (cur.dist > dist[cur.x][cur.y]) continue;

        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (A[nx][ny] == 0) continue;

            int nd = cur.dist + A[nx][ny];
            if (nd < dist[nx][ny]) {
                dist[nx][ny] = nd;
                parent[nx][ny] = {cur.x, cur.y};
                pq.push({nx, ny, nd});
            }
        }
    }

    if (dist[XJ][YJ] == INF) {
        cout << 0; // không có đường
        return 0;
    }

    cout << 1 << "\n" << dist[XJ][YJ] - A[XJ][YJ] << "\n";

    // Truy vết đường đi
    vector<pair<int,int>> path;
    for (int x = XJ, y = YJ; x != -1 && y != -1; ) {
        path.push_back({x, y});
        auto p = parent[x][y];
        x = p.first; y = p.second;
    }
    reverse(path.begin(), path.end());

    for (auto [x, y] : path)
        cout << x+1 << " " << y+1 << "\n";
}
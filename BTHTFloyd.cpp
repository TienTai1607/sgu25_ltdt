#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9; //Khai báo hằng số vô cực (INF = 10^9), biểu thị rằng không có đường đi giữa hai đỉnh (ban đầu)
long long dist[1005][1005]; //Ma trận lưu khoảng cách ngắn nhất giữa các cặp đỉnh i → j
int n, m;

int main() {
    cin >> n >> m;

    // Khởi tạo ma trận khoảng cách
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0; //đường đi từ một đỉnh đến chính nó là 0,
            else dist[i][j] = INF; //và nếu chưa có thông tin thì gán bằng INF
        }
    }

    // Nhập các cạnh
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], 1LL * w); /*có thể có nhiều cạnh trùng giữa cùng hai đỉnh u → v,
        nhưng với trọng số khác nhau, nếu có nhiều cạnh, lấy cạnh ngắn nhất, 1LL * w để ép kiểu sang long long, tránh tràn số
        */ 
    }

    // Thuật toán Floyd
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) //Nếu đường đi i→k→j ngắn hơn đường i→j hiện tại, thì cập nhật lại
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // In kết quả
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << "0 ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
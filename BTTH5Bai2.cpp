//tìm đường đi ngắn nhất qua đỉnh trung gian

#include <bits/stdc++.h>
using namespace std;

//ta tạo cấu trúc của 1 cạnh đó là to: đỉnh mà cạnh đi tới, w: là trọng số của cạnh
struct Edge {
    int to;
    int w;
};

const long INF = 1e9; //dùng để biểu diễn vô cùng (tức là chưa có đường đi)
int n, m, s, t, x;
vector<vector<Edge>> adj; //tạo danh sách các cạnh đi ra từ u

vector<long> dijkstra(int start, vector<int>& trace) {
    vector<long> dist(n + 1, INF);//Tạo một mảng dist (kích thước n + 1 ), dist[i] sẽ lưu khoảng cách ngắn nhất từ đỉnh start đến đỉnh i,gán tất cả bằng INF (1e18)
    trace.assign(n + 1, -1);// là một mảng dùng để ghi nhớ đỉnh trước đó trên đường đi ngắn nhất, gán cho tất cả phần tử giá trị -1 (nghĩa là chưa có “đỉnh cha”)
    priority_queue<pair<long,int>, vector<pair<long,int>>, greater<>> pq;/*
    Đây là hàng đợi ưu tiên (priority queue) — hay còn gọi là heap — để giúp thuật toán Dijkstra chọn đỉnh có khoảng cách nhỏ nhất một cách nhanh nhất*/

    dist[start] = 0;//Khoảng cách từ start đến chính nó = 0
    pq.push({0, start});//Đưa {khoảng_cách, đỉnh} vào hàng đợi ưu tiên

    while (!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop(); //lấy đỉh u có khoảng cách nhỏ nhất du lên đầu hàng đợi
        if (du != dist[u]) continue; // nếu giá trị hàng đợi đã cũ (nếu không bằng với giá trị cũ ) thì bỏ qua 

        for (auto [v, w] : adj[u]) { //tách v và w và gắn vào adj[]= [{to: , weight: }]
            if (dist[v] > dist[u] + w) { // điều kiện để xem có thể cải thiện đường đi đến v không
                dist[v] = dist[u] + w;
                trace[v] = u; // lưu lại đỉnh trước của v trong đườg đi ngắn nhất
                pq.push({dist[v], v}); // đưa đỉh v vào hàng đợi ưu tiên với khoảng cách mới cập nhật
            }
        }
    }
    return dist; /*Sau khi vòng lặp của thuật toán Dijkstra chạy xong,
                hàm sẽ trả về mảng dist — tức là khoảng cách ngắn nhất từ start đến mọi đỉnh*/
}

//hàm để lấy đường đi
vector<int> getPath(int s, int t, vector<int>& trace) { //Dùng trace để lần ngược từ t → s
    vector<int> path;
    for (int v = t; v != -1; v = trace[v])
        path.push_back(v);
    reverse(path.begin(), path.end()); //Đảo ngược lại path để có thứ tự đúng
    return path;
}

int main() {

    //nhập dữ liệu vào đồ thị
    cin >> n >> m >> s >> t >> x;
    adj.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }


    //chạy dijkstra 2 lần   
    vector<int> trace1, trace2;
    vector<long> dist1 = dijkstra(s, trace1); //chạy từ s để lấy dist1
    vector<long> dist2 = dijkstra(x, trace2); //chạy từ x để lấy dist2 

    if (dist1[x] == INF || dist2[t] == INF) {
        cout << "Khong co duong di qua " << x << "\n";
        return 0;
    }
    
    // cộng 2 thuật toán đã tìm được lại với nhau để cho ra một chu trình dijkstra hoàn chỉnh mà vẫn qua x
    long kq = dist1[x] + dist2[t];
    cout << kq << "\n";

    // Ghép đường đi: s → x và x → t
    vector<int> path1 = getPath(s, x, trace1);
    vector<int> path2 = getPath(x, t, trace2);
    path2.erase(path2.begin()); // bỏ trùng đỉnh x

    //Nối 2 đường lại thành một đường hoàn chỉnh s → x → t
    vector<int> fullPath = path1;
    fullPath.insert(fullPath.end(), path2.begin(), path2.end());

    //In ra toàn bộ đường đi
    for (int v : fullPath) cout << v << " ";
    cout << "\n";
}
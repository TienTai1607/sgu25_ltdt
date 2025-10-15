//Tìm đường đi ngắn nhât (Dijkstra)

#include <bits/stdc++.h>

using namespace std;

// Tạo một Struct Edge để biểu diễn 1 cạnh
struct Edge{
    int to; //đỉnh mà cạnh đó đi đến
    int weight; //trọng số của cạnh
};

const long INF=1e9; // có thể hiểu là khoảng cách vô cùng
//tạo các biến để lưu thông tin của 1 đồ thị
int n, m, s, t;
vector<vector<Edge>> adj; //danh sách các cạnh đi ra từ u
vector<long> dist; //để lưu khoảng cách ngắn nhất từ đỉnh xuất phát s đến mỗi đỉnh khác
vector<int> trace; //dùng để coi lại đường đi giữa các đỉnh rồi đi ngược lại từ đích về chỗ bắt đầu 
 
// thuật toán Dijkstra
void dijkstra(int s){
    dist.assign(n+1, INF); //ta khởi tạo 1 mảng với giá trị ban đầu là vô cùng ( chưa biết đường đi)
    trace.assign(n+1, -1); //khởi tạo mảng trace ban đầu là -1 vì chưa có đỉnh trước
    dist[s]=0; //ban đầu đỉnh s nối với chính nó thì có độ dài là 0


    // priority_queue lưu (khoảng cách, đỉnh)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; /*
    Đây là cách khai báo một hàng đợi ưu tiên (priority queue) mà phần tử nhỏ nhất nằm ở trên cùng*/
    pq.push({0, s}); //ban đầu ở đây đỉnh s có khoảng cách là 0

    while(!pq.empty()){
        auto [du,u] = pq.top(); // tách pair ra làm hai biến (du:khoảng cách, u:đỉnh) và lấy đỉnh đầu tiên có khoảng cách nhỏ nhất
        pq.pop();

        if(du !=dist[u]) continue; /*Nếu giá trị du (khoảng cách lấy từ hàng đợi) không khớp với khoảng cách ngắn nhất hiện tại dist[u],
                                    thì bỏ qua (vì nó là bản cũ, không còn đúng nữa)*/
        
        for(auto [v,w] : adj[u]){ //tách v và w và gắn vào adj[]= [{to: , weight: }]
            if(dist[v] > dist[u] + w){ // điều kiện để xem có thể cải thiện đường đi đến v không
                dist[v] = dist[u] + w;  //dist[u] + w là độ dài đường đi mới qua u
                trace[v]=u; // lưu lại đỉnh trước của v trong đườg đi ngắn nhất
                pq.push({dist[v],v}); // đưa đỉh v vào hàng đợi ưu tiên với khoảng cách mới cập nhật
            }
        }
    }
}


//truy vết đường đi dùng để lấy danh sách các đỉnh trên đường đi ngắn nhất
vector<int> getPath(int s, int t) { //Khai báo một hàm trả về, nó sẽ trả về danh sách các đỉnh trong đường đi ngắn nhất từ s → t
    vector<int> path; //Tạo một vector rỗng có tên là path để lưu các đỉnh trên đường đi
    if (dist[t] == INF) return path;
    for (int v = t; v != -1; v = trace[v]) //Đây là vòng lặp truy ngược từ t về s,dựa vào mảng trace[] (đỉnh cha)
        path.push_back(v);
    reverse(path.begin(), path.end()); //Đảo ngược lại path để có thứ tự đúng
    return path;
}


int main(){
    //nhập dữ liệu của đồ thị
    cin >> n >> m >> s >> t;
    adj.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    //chạy thuật toán Dijkstra và in kq
    dijkstra(s);
    vector<int> path = getPath(s, t);

    if (path.empty()) {
        cout << "Khong co duong di\n";
        return 0;
    }

    cout << path.size() << " " << dist[t] << "\n";
    for (int v : path) cout << v << " ";
    cout << "\n";
}
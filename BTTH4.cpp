//chu trình euler

#include<iostream> 
#include<vector> 
#include<cstring> 
#include<set> 
#include<stack> 
#include<algorithm>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> duongdi; // đây là đường đi của euler, chứa thứ tự các đỉnh thi theo chiều ngược của euler

// dùng hàm dfs để kiểm tra đồ thị có liên thông không
void dfs(int u, vector<bool>& visited){
    visited[u]=true;
    for(int v=1;v<=n;v++){
        if(adj[u][v] > 0 && !visited[v]){
            dfs(v,visited);
        }
    }
}

// hàm euler
void euler(int u){
    for(int v=1;v<=n;v++){ //duyệt qua các đỉnh v kề với đỉnh u
        while(adj[u][v]>0){ // nếu còn cạnh thì tức là vẫn còn đường đi từ u sang v
            adj[u][v]--; //xóa cạnh vừa mới đi qua xog
            adj[v][u]--;
            euler(v);
        }
    }
    duongdi.push_back(u);
}

int main(){
    // nhập số đỉnh và ma trận kề vào
    cin>>n;
    adj.assign(n + 1, vector<int>(n + 1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>adj[i][j];
        }
    }

    //ở vòng lặp này sẽ tính bậc của từng đỉnh, đỉnh nào có bậc >0 thi sẽ được chọn làm đỉnh bắt đầu
    int batdau=-1;
    for(int i=1;i<=n;i++){
        int dinh=0;
        for(int j=1;j<=n;j++){
            dinh+=adj[i][j];
        }
        if(dinh>0){
            batdau=i;
            break;
        }
    }
    
    // nếu đồ thị rỗng (không có cạnh nào) thì vẫn coi là có chu trình Euler
    if(batdau == -1){
        cout << 1 << "\n";
        cout << 1;
        return 0;
    }

    //kiểm tra tính liên thông của đồ thị
    vector<bool> visited(n+1,false);
    dfs(batdau,visited);

    /*kiểm tra nếu đỉnh có cạnh nhưng chưa được thăm thì đồ thị sẽ không liên thông,
    vì cạnh của nó nằm ở 1 thành phần khác*/
    for(int i=1;i<=n;i++){
        int dinh=0;
        for(int j=1;j<=n;j++){
            dinh+=adj[i][j];
        }
        if(dinh>0 && !visited[i]){
            cout<<0;
            return 0;
        }
    }

    //kiểm tra các đỉnh của đồ thị có phải là bậc chẵn hay không
    for(int i=1;i<=n;i++){
        int dinh=0;
        for(int j=1;j<=n;j++){
            dinh+=adj[i][j];
        }
        if(dinh % 2 !=0){
            cout<<0;
            return 0;
        }
    }

    euler(batdau); // nếu thỏa điều kiện thì sễ bắt đầu đi tìm chu trình euler

    cout<<1<<"\n";
    for(int i=duongdi.size()-1;i>=0;i--){
        cout<<duongdi[i]<<" ";
    }

    return 0;

}

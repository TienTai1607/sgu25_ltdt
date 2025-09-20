#include <iostream>
#include <vector>
using namespace std;

//Hàm dùng để kiểm tra ma trận hợp lệ 
bool hopLe(const vector<vector<int>>& mang, int n) {
    for (int i=0; i<n ; i++) {
        if (mang[i].size() !=n) return false; //Nếu ko đủ phần tử trong mảng sẽ trả về giá trị false
        for( int j=0; i<n ; j++){
            if (mang[i][j] !=0 && mang [i][j] !=1 ) return false; //Chỉ được trả về giá trị 0 hoặc 1 nếu ko thì sai
        }
    }
    return true;
}

//Hàm để kiểm tra xem đồ thì Vô hướng hay Có hướng
bool Huong(const vector<vector<int>>& mang, int n) {
    for (int i=0; i<n ;i++){
        for(int j=0; j<n; i++){
            if(mang[i][j] != mang[j][i]) return false;//Sẽ trả về vô hướng nếu không có cặp nào bằng nhau 
        }
    }
    return true;
}

int main() {
    int n;
    cout<<"Mời nhập vào số đỉnh của đồ thị : ";
    cin>>n;
    /*Tạo 1 mảng gồm n dòng , mỗi dòng gồm có k phần tử,
    và mặc định có phần tử trong mảng đều được gán giá trị bằng 0*/
    vector<vector<int>> mang(n, vector<int>(n));
    
    cout<<"Mời nhập vào ma trận kề (" << n <<"x"<< n <<"):"<<endl;
    for (int i=0; i<n ; i ++){
        for(int j=0; j<n ;j++){
            cin>>mang[i][j];
        }
    }
    cout<<endl;
    //In ra thông tin vừa nhập
    cout<<"Số đỉnh của đồ thị : "<<n<<endl;
    cout<<"Ma trận kề : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mang[i][j]<<" ";
        }
        cout<<endl;
    }

    //In ra kết quả
      //kiểm tra có hợp lệ hay không
    if(!hopLe(mang,n)){
        cout<<"Thông tin của đồ thị không hợp lệ!"<<endl;
        return 0;
    }else {
        cout<<"Thông tin của đồ thị hợp lệ!"<<endl;
    }

      //Kiểm tra xe đồ thị có hướng hay vô hướng
    if(Huong(mang,n)){
        cout<<"Đây là đồ thị vô hướng!"<<endl;
    } else {
        cout<<"Đây là đồ thị có hướng!"<<endl;
    }

    return 0;
}
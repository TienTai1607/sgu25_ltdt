#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Hàm dùng để kiểm tra có phải số nguyên tố hay không
bool SNT(int n) {
    if (n < 2) return false;
    for (int i=2 ; i*i <=n ; i++){
        if(n % i == 0 ) return false;
    }
    return true;
}

// Hàm tính số mũ của số nguyên tố trong N giai thừa
int Somu(int N, int p){
    int count = 0;
    while (N>0){
        count += N/p;
        N/=p;
    }
    return count;
}

int main() {
    int N;
    while (cin>>N) { // Dùng để đọc N nhiều lần cho đến khi hết input
        vector<int> kq;

        // duyệt các số từ 2 đến N nếu là số NT thì tính số mũ
        for (int p = 2; p <= N ; p++ ){
            if(SNT(p)){
                kq.push_back(Somu(N,p));
            }
        }

        // In ra kết quả
        for (int i=0 ; i < kq.size() ; i++){
            cout<<kq[i];
            if (i !=kq.size() - 1 ) cout <<" ";
        }
        cout<<endl;

    }
    return 0;

}

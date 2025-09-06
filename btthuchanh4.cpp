#include <iostream>
using namespace std;

// Hàm dùng để tính số lượng số 0 của N!
long long Zero(long long N) {
    long long kq=0; // lưu lại tổng số lượng số 0 tận cùng
    while (N > 0) {
        kq += N/5;
        N/=5;
    }
    return kq;
}

int main() {
    long long N;
    while (cin>>N) {
        cout<<Zero(N)<<endl;
    }
    return 0;
}
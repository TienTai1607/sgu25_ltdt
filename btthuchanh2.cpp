#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    int a[N];
    for(int i=0 ; i < N ; i++){
        cin>>a[i];
    }  // Khởi tạo mạng và nhập số phần tử N từ bàn phím


    int check[1001]={0};  /*N<=1000 với mục đích là đánh dấu xem số nào đã xuất hiện trong dãy
                            và khởi tạp 1 mảng với check={0,0,0,...}
                            */ 
    
    for(int i=0 ; i < N ; i++){
        if(a[i]<1 || a[i]>N){
            cout<<"NO";
            return 0;
        }
        if(check[a[i]] == 1){  // nếu số bị lặp hoặc đã xuất hiện trước đó thì cho ra kq NO
            cout<<"NO";
            return 0;
        }
        check[a[i]] == 1;  //dùng để đánh dấu phần tử a[i] đã xuất hiện trong dãy

    }
    cout<<"YES";
    return 0;

}

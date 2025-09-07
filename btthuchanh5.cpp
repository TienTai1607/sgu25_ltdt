#include <iostream>
using namespace std;

int main() {
    int nx,ny,nz;
    int x[100],y[100],z[100];
    int Save[100]; //mảng dùng để lưu các phần tử chung
    int Dem=0; //đếm số lượng phần tử chung tìm được

    //Nhập dãy x
    cin >> nx;
    for (int i=0 ; i<nx ; i++) {
        cin>>x[i];
    }

    //nhập dãy y
    cin>> ny;
    for (int i=0 ; i<ny ; i++) {
        cin>>y[i];
    }

    //nhập dãy z
    cin>> nz;
    for (int i=0 ; i<nz ; i++) {
        cin>>z[i];
    }

    //tìm phần tử chung của 3 mảng
    for (int i=0 ; i<nx ; i++) {
        bool iny=false,inz=false; // cờ để kiểm tra xem có trong y và z không

        //ta kiểm tra xe x[i] có trong y không 
        for(int j=0; i < ny ; j++) {
            if(x[i]==y[j]){
                iny=true;
                break;
            }
        }

        //kiểm tra x[i] có trong z không
        for(int k=0 ; k < nz ; k++) {
           if (x[i]==z[k]) {
                inz=true;
                break; 
           }
        }

        //kiểm tra nếu có cả trong y và z
        if (iny && inz) {
            //kiểm tra x[i] đã có trong Save chưa 
            bool kt=false;
            for (int l =0; l<Dem ; l++) {
                if (Save[l]==x[i]){
                    kt=true;
                    break; 
                }
            }

            //nếu chưa có thì thêm vào mảng Save
            if(!kt) {
                Save[Dem++]=x[i]; //lưu x[i] và đếm số lượng phần tử có cả trong 3 mảng
            }
        }
    }

    // sắp xếp lại mảng Save theo thứ tự tăng dần ( ta sẽ dùng bubble sort)
    for (int i=0 ; i<Dem - 1 ; i++) {
        for (int j=i+1 ; j< Dem ; j++) {
            if (Save[i] > Save[j]) {
                int Bien=Save[i];
                Save[i]=Save[j];
                Save[j]=Bien;
            }
        }
    }

    // in ra kểt quả
    cout << Dem << "\n";
    //in ra các phân tử chung
    for (int i=0; i<Dem ; i++){
        cout<< Save[i]<<" ";
    }
    cout<<"\n";

    return 0 ;
}
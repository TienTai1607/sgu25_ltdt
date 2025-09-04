#include <vector>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int T;
    cin>>T;

    while(T--) {
        string s;
        cin >> s;
        int n=s.size();

        vector<int> freq(26*26*26, 0);
        for(int i=0 ; i+2 < n ; i++){
            int idx=(s[i] - 'A')*26*26
                    + (s[i+1] - 'A')*26
                    + (s[i+2] - 'A');
            
            freq[idx]++;
        }

        int ans=0;
        for( int x : freq) ans=max(ans,x);
        cout<<ans<<"\n";

    }
    return 0;

}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1,1,2};
    for(int i   = 0;i<v.size();i++){
        int num = v[i];
        for(int j = i+1;j<v.size();j++){
            
            if(num == v[j]){
                v.erase(v.begin() + j);
            }
        }
        

    }
      // removes element at index 2 (30)
    cout << "{";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
        if(i != v.size() - 1)
            cout << ",";
    }
    cout << "}";

    return 0;
    
}
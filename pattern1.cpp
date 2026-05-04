#include <iostream>
using namespace std;

int main(){
    int n = 4;
    int num = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if( j == 0||j==2){
                cout<<"0 ";
            }else{
                cout<<"1 ";
            }        }
        cout << endl;
    }
}
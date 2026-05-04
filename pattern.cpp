#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    for(int i = 0; i <= 6; i++){
        for(int j = 0; j <= 5; j++){
            
            if(i == 0){
                cout << "* ";
            }
            else if(i == 6){
                cout << "* ";
            }
            else if(j == 0){
                cout << "* ";
            }
            else if(j == 5){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
    cout << endl;
}
}
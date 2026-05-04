#include <bits/stdc++.h>

using namespace std;

class student{
public:
    int id;
    student(){
        id = 100;
        cout<<" ";
    }
    student(int x){
        id = x;
    }

};
int main(){
    student s;
    cout<<s.id;
}
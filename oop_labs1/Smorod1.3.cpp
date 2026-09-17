 #include <iostream>
 using namespace std;

 struct safeArray{
    int* data;
    int size;
 };

 safeArray createArray(int size){
    safeArray arr;
    arr.size = size;
    arr.data = new int[size]{};
    return arr;
 }

 int main (){
    int N;
    cout << "N: "; cin >> N;
    
 }
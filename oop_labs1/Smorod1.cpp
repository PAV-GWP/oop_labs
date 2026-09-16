 #include <iostream>
 using namespace std;
 
 void fillArray(int (&arr)[10]){
    for (int i=0; i<10; i++){
        cin >> arr[i];
    }
 }
 void printArray(const int(&arr)[10]){
    for (auto x: arr){
        cout << x<< " ";
    }
    cout << "\n";
 }

 int main(){
    int arr[10];
    fillArray(arr);
    printArray(arr);
    return 0;
 }
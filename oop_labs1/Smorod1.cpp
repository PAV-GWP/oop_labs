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
 void swapElements(int (&arr)[10], int &idx1, int &idx2){
    int musor = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = musor;
 }
 void multiplyByTwo(int (&arr)[10]){
    for (int& x :arr){
        x*=2;
    }
 }

 int main(){
    int arr[10];
    fillArray(arr);
    cout<< "Array: ";
    printArray(arr);
    int i1=0, i2=1;
    swapElements(arr, i1, i2);
    cout << "swap: ";
    printArray(arr);
    multiplyByTwo(arr);
    cout << "multiplyByTwo: \n";
    printArray(arr);
    return 0;
 }
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
 int& getElement(safeArray& arr, int index){
    static int dummy = -999;
    if (index <0 || index>=arr.size){
        cout << "Error";
        return dummy;
    }
    return arr.data[index];
 }
 void printSafe(const safeArray& arr){
    for (int i=0; i<arr.size; i++){
        cout << arr.data[i]<<" ";
    }
 }
 void reSizeArray(safeArray& arr, int newSize){
    if (newSize == arr.size) return;
    int* newData = new int[newSize]{};
    if (newSize<arr.size){
        cout << "Deleted el: ";
        for (int i=newSize; i<arr.size; i++){
            cout<<arr.data[i] << " ";
        }
        cout << "\n";
        for (int i=0; i < newSize; i++){
            newData[i] = arr.data[i];
        }
    }
    else{
        for (int i=0; i<arr.size; i++){
            newData[i] = arr.data[i];
        }
    }
    delete[] arr.data;
    arr.data = newData;
    arr.size = newSize;
 }
 int main (){
    int N=5;
    // cout << "N: "; cin >> N;
    safeArray myArr = createArray(N);
    cout<< "array: ";
    for (int i=0; i<N; i++){
        getElement(myArr, i) = (i+1)*10;
    }
    printSafe(myArr);
    cout<< "\n";
    cout<< "2 index: ";
    getElement(myArr, 2) = 999;
    printSafe(myArr);
    cout<< "\n";
    cout<< "Error: ";
    getElement(myArr, 10) = 100;
    cout<< "\n";
    cout<< "Down aize: ";
    reSizeArray(myArr, 3);
    printSafe(myArr);
    cout<< "\n";
    cout<< "Up size: ";
    reSizeArray(myArr, 5);
    printSafe(myArr);

    delete[] myArr.data;
    myArr.data = nullptr;
 }
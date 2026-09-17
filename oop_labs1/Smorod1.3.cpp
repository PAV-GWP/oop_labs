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
 int main (){
    int N;
    cout << "N: "; cin >> N;
    safeArray myArr = createArray(N);
    getElement(myArr, 2) = 999; // 999 на втором индексе
    cout << getElement(myArr,2);
    delete[] myArr.data;
    myArr.data = nullptr;
 }
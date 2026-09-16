 #include <iostream>
 using namespace std;
 
 /// @brief Заполняет статический массив числами, введенными с клавиатуры
 /// @param arr Ссылка на массив из 10 целых чисел, который нужно заполнить
 void fillArray(int (&arr)[10]){
    for (int i=0; i<10; i++){
        cin >> arr[i];
    }
 }
 /// @brief Выводит все элементы массива через пробел
 /// @param arr Константная ссылка на массив (только для чтения)
 void printArray(const int(&arr)[10]){
    for (auto x: arr){
        cout << x<< " ";
    }
    cout << "\n";
 }
 /// @brief Меняет местами два элемента массива по индексам
 /// @param arr Ссылка на массив (будем менять)
 /// @param idx1 Ссылка на индекс первого элемента
 /// @param idx2 Ссылка на индекс второго элемента
 void swapElements(int (&arr)[10], int &idx1, int &idx2){
    int musor = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = musor;
 }
 /// @brief Умножает каждый элемент массива на 2
 /// @param arr Ссылка на массив (будем менять)
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
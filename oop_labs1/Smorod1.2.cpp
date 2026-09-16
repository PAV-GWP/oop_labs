 #include <iostream>
 using namespace std;

 /// @brief Находит первый отрицательный элемент, уменьшает динамический массив до него и пересоздает память
 /// @param arr Ссылка на указатель на динамический массив (int*&)
 /// @param size Ссылка на размер массива (int&)
 void process(int*& arr, int& size){
    int negative = -1;
    for (int i = 0; i<size; i++){
        if (arr[i]<0){
            negative = i;
            break;
        }
    }
    if (negative != -1){
        int newSize = negative;
            if (newSize == 0){
                delete [] arr;
                arr = nullptr;
                size = 0;
                return;}
            int* newarr = new int [newSize]{};
            for (int i=0; i<newSize; i++){
                newarr[i]= arr[i];
            }
            delete[] arr;
            arr = newarr;
            size = newSize;
    }
 }
 int main(){
    int N;
    cout << "N: ";
    cin >> N;
    int * arr = new int[N]{};
    cout << "Elements: ";
    for (int i =0; i< N; i++){
        cin >> arr[i];
    }
    process(arr, N);
    for (int i=0; i<N; i++){
        cout << arr[i]<< " ";
    }
    cout << "\n";
    delete[]arr;
    arr = nullptr;
 }
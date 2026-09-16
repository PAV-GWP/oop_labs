 #include <iostream>
 using namespace std;

 int main(){
    int N;
    cout << "N: ";
    cin >> N;
    int * arr = new int[N]{};
    cout << "Elements: ";
    for (int i =0; i< N; i++){
        cin >> arr[i];
    }
 }
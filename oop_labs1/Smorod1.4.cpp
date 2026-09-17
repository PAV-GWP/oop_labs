 #include <iostream>
 using namespace std;

 int** allocateMatrix(int rows, int cols){
    int** matrix = new int*[rows];
    for (int i=0; i<rows; i++){
        matrix[i]=new int[cols]{};
    }
    return matrix;
 }
 void fillMatrix(int** matrix, int rows, int cols){
    for (int i =0; i<rows; i++){
        for (int j=0; j<cols; j++){
            matrix[i][j]=(i+1)*(j+1);
        }
    }
 }
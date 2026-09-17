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
 void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, std::string title = "Matrix"){
    cout << "=== " << title << " ===\n";
    int width = cols * 6;
    if (showBorders){
        for (int w=0; w< width; w++){
            cout << "-";
        }
        cout << "\n";
    }
    for (int i=0; i<rows;i++){
        if (showBorders) cout << "| ";
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        if (showBorders) cout << "|";
        cout << "\n";
    }
 }
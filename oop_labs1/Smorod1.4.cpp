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
    cout << "Enter grades for " << rows << " students and " << cols << " subjects:\n";
    for (int i = 0; i < rows; i++){
        cout << "Student " << (i + 1) << ":\n";
        for (int j = 0; j < cols; j++){
            cout << "  Subject " << (j + 1) << ": ";
            cin >> matrix[i][j];
        }
    }
    cout << "\n";
 }
 void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, std::string title = "Matrix"){
    cout << "===" << title << " ===\n";
    int width = cols * 4;
    if (showBorders){
        for (int w=0; w< width; w++){
            cout << "-";
        }
        cout << "\n";
    }
    for (int i=0; i<rows;i++){
        if (showBorders) cout << "| ";
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "  ";
        }
        if (showBorders) cout << "|";
        cout << "\n";
    }
 }
 void freeMatrix(int**matrix, int rows){
    for ( int i =0; i<rows; i++){
        delete[] matrix[i];
    }
    delete[]matrix;
 }

 int main(){
    int rows =3; int cols = 3;
    int** myMatrix= allocateMatrix(rows, cols);
    fillMatrix(myMatrix, rows, cols);

    printMatrix(myMatrix, rows, cols); // без доп параметров

    printMatrix(myMatrix, rows, cols, true, "With Title"); // Только заголовки

    printMatrix(myMatrix, rows, cols, false, "Without Borders"); // без рамок
    freeMatrix(myMatrix, rows);
    myMatrix = nullptr;
 }
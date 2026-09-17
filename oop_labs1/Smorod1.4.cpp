 #include <iostream>
 using namespace std;
 /// @brief Выделяет динамическую память под двумерный массив (матрицу)
 /// @param rows Количество строк (студентов)
 /// @param cols Количество столбцов (предметов)
 /// @return Указатель на выделенный двумерный массив (int**)
 int** allocateMatrix(int rows, int cols){
    int** matrix = new int*[rows];
    for (int i=0; i<rows; i++){
        matrix[i]=new int[cols]{};
    }
    return matrix;
 }
 /// @brief Заполняет матрицу значениями (оценками студентов) с клавиатуры
 /// @param matrix Указатель на матрицу
 /// @param rows Количество строк
 /// @param cols Количество строк
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
 /// @brief Выводит матрицу на экран с заголовком и опциональной рамкой
 /// @param matrix Указатель на матрицу
 /// @param rows Количество строк
 /// @param cols Количество столбцов
 /// @param showBorders Флаг отображения рамки (по умолчанию true)
 /// @param title Заголовок матрицы (по умолчанию "Matrix")
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
 /// @brief Корректно очищает динамическую память двумерного массива
 /// @param matrix Указатель на матрицу
 /// @param rows Количество строк
 void freeMatrix(int**matrix, int rows){
    for ( int i =0; i<rows; i++){
        delete[] matrix[i];
    }
    delete[]matrix;
 }
 /// @brief Главная функция программы: тестирование выделения памяти, ввода, вывода и очистки
 /// @return
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
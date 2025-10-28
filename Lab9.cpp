#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Task 1 Function
vector<vector<vector<int>>> get_matrices() {
    string filename;
    cout << "Enter a file name: ";
    cin >> filename;
    ifstream myfile(filename);
    if (!myfile) {
        cout << "Invalid file name." << endl;
        exit(1);
    }
    string mystr;
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;
    string nstring;
    getline(myfile, nstring);
    int n = stoi(nstring);
    getline(myfile, nstring);

    int myint;
    while (getline(myfile, mystr)) {
        if (matrix1.size() < n) {
            vector<int> line;
            stringstream ss(mystr);
            string token;
            while (ss >> token) {
                line.push_back(stoi(token));
            }
            matrix1.push_back(line); 
        }
        else {
            vector<int> line;
            stringstream ss(mystr);
            string token;
            while (ss >> token) {
                line.push_back(stoi(token));
            }
            matrix2.push_back(line); 
        }
    };
    vector<vector<vector<int>>> matrices;
    matrices.push_back(matrix1);
    matrices.push_back(matrix2);
    return matrices;
}

// Task 1 Function
void print_matrix(vector<vector<int>> matrix) {
    int biggest = 0; 
    for (vector line : matrix) {
        for (int num : line) {
            if (num > biggest) {
                biggest = num;
            }
        }
    }
    int maxdigits = to_string(biggest).length();
    for (vector line : matrix) {
        for (int num : line) {
            int numdigits = maxdigits - to_string(num).length();
            string zerostring = "";
            if (numdigits > 0) {
                for (int i = 0; i < numdigits; i++) {
                    zerostring += "0";
                }
            }
            cout << zerostring << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Task 2 Function
vector<vector<int>> add_matrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
    vector<vector<int>> matrix3(matrix1.size(), vector<int>(matrix1.size())); 
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1.size(); j++) {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return matrix3;
}

// Task 3 Function
vector<vector<int>> multiply_matrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
    vector<vector<int>> matrix3;
    int length = matrix1.size();
    for (int i = 0; i < length; i++) {
        vector<int> myline;
        for (int j = 0; j < length; j++) {
            int result = 0;
            for (int k = 0; k < length; k++){
                if (matrix1[i][k] && matrix2[k][j]) {
                    result += matrix1[i][k] * matrix2[k][j];
                }
            }
            myline.push_back(result);
        }
        matrix3.push_back(myline);
    } 
    return matrix3;
}

// Task 4 Function
int diagnonal_sum(vector<vector<int>> matrix) {
    int n = matrix.size();
    int sum = 0;
    if (n % 2 == 1) { // Checks if matrix size is odd
        sum = 0 - (matrix[n / 2][n / 2]); // Subtracts center element
    }
    int lastrow = -1;
    int lastcol = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == lastrow + 1 && j == lastcol + 1) {
                sum += matrix[i][j];
                lastrow++;
                lastcol++;
            }
        }
    }
    lastrow = -1;
    lastcol = 5;
    for (int i = 0; i < n; i++) {
        for (int j = n; j >= 0; j--) {
            // cout << "i: " << i << endl << "j: " << j << endl << endl;
            if (i == lastrow + 1 && j == lastcol - 1) {
                sum += matrix[i][j];
                lastrow++;
                lastcol--;
            }
        }
    }
    return sum;
}

// Task 5 Function
vector<vector<int>> row_swap(vector<vector<int>> matrix, int row1, int row2) {
    int n = matrix.size();
    if (row1 >= n || row2 >= n) {
        return matrix;
    }
    vector<vector<int>> retmatrix(matrix.size(), vector<int>(matrix.size()));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            retmatrix[i][j] = matrix[i][j];
        }
    }
    vector<int> temprow = retmatrix[row1];
    retmatrix[row1] = retmatrix[row2];
    retmatrix[row2] = temprow;
    return retmatrix;
}

// Task 6 Function
vector<vector<int>> rotate_matrix(vector<vector<int>> matrix) {
    vector<vector<int>> retmatrix(matrix.size(), vector<int>(matrix.size()));
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            retmatrix[j][i] = matrix[i][j];
        }
    }
    return retmatrix;
}

// Task 6 Function
vector<vector<int>> col_swap(vector<vector<int>> matrix, int col1, int col2) {
    int n = matrix.size();
    if (col1 >= n || col2 >= n) {
        return matrix;
    }
    vector<vector<int>> retmatrix(matrix.size(), vector<int>(matrix.size()));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            retmatrix[i][j] = matrix[i][j];
        }
    }
    retmatrix = rotate_matrix(retmatrix);
    vector<int> temprow = retmatrix[col1];
    retmatrix[col1] = retmatrix[col2];
    retmatrix[col2] = temprow;
    retmatrix = rotate_matrix(retmatrix);
    retmatrix = rotate_matrix(retmatrix);
    retmatrix = rotate_matrix(retmatrix);
    return retmatrix;
}

// Task 7 Function
vector<vector<int>> replace_val(vector<vector<int>> matrix, int row, int col, int val) {
    int n = matrix.size();
    vector<vector<int>> retmatrix(matrix.size(), vector<int>(matrix.size()));
    if (row >= n || col >= n) {
        return matrix;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            retmatrix[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i == row && j == col) {
                retmatrix[i][j] = val;
            }
        }
    }
    return retmatrix;
}

int main() {
    // Question 1
    cout << "-----------------------------------------" << endl << endl;
    cout << "Task 1: Read values from file and print as matrices: " << endl;
    vector<vector<vector<int>>> matrices = get_matrices();
    vector<vector<int>> matrix1 = matrices[0];
    vector<vector<int>> matrix2 = matrices[1];
    cout << "Matrix 1:" << endl;
    print_matrix(matrix1);
    cout << "Matrix 2:" << endl;
    print_matrix(matrix2);
    cout << "-----------------------------------------" << endl << endl;
    
    // Question 2
    cout << "Task 2: Addition Matrix:" << endl;
    print_matrix(add_matrix(matrix1, matrix2));
    cout << "-----------------------------------------" << endl << endl;

    // Question 3
    cout << "Task 3: Multiplication Matrix:" << endl;
    print_matrix(multiply_matrix(matrix1, matrix2));
    cout << "-----------------------------------------" << endl << endl;


    // Question 4
    cout << "Task 4: Diagonal Sum of Matrix " << endl << endl;
    cout << "Diagonal Sum of Matrix 1: " << endl;
    cout << diagnonal_sum(matrix1) << endl << endl;
    cout << "-----------------------------------------" << endl << endl;

    // Question 5
    cout << "Task 5: Matrix with swapped rows: " << endl;
    cout << "Matrix 1 with rows 1 and 3 swapped: " << endl;
    cout << "Initial: " << endl;
    print_matrix(matrix1);
    cout << "Swapped: " << endl;
    print_matrix(row_swap(matrix1, 1, 3));
    cout << "-----------------------------------------" << endl << endl;

    // Question 6
    cout << "Task 6: Matrix with swapped columns: " << endl << endl;
    cout << "Matrix 1 with columns 1 and 3 swapped: " << endl;
    cout << "Initial: " << endl;
    print_matrix(matrix1);
    cout << "Swapped: " << endl;
    print_matrix(col_swap(matrix1, 1, 3));
    cout << "-----------------------------------------" << endl << endl;

    // Question 7
    cout << "Task 7: Function to replace matrix value from given row, column, and new value" << endl << endl;
    cout << "Matrix 1 with row 0, column 2 set to 500: " << endl;
    print_matrix(replace_val(matrix1, 0, 2, 500));

    cout << "In the case of invalid bounds, initial matrix is returned." << endl << endl;
}
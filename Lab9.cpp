#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void print_matrix(vector<vector<int>> matrix) {
    for (vector line : matrix) {
        for (int num : line) {
            cout << num << " ";
        }
        cout << endl;
    }
}

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
                cout << "Added " << matrix[i][j] << ". New sum is: " << sum << endl;
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
                cout << "Added " << matrix[i][j] << ". New sum is: " << sum << endl;
                lastrow++;
                lastcol--;
            }
        }
    }
    return sum;
}

vector<vector<int>> row_swap(vector<vector<int>> matrix, int row1, int row2) {
    int n = matrix.size();
    row1--;
    row2--;
    vector<vector<int>> retmatrix(matrix.size(), vector<int>(matrix.size()));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            retmatrix[i][j] = matrix[i][j];
        }
    }
    if (row1 >= n || row2 >= n) {
        return matrix;
    }
    vector<int> temprow = retmatrix[row1];
    retmatrix[row1] = retmatrix[row2];
    retmatrix[row2] = temprow;
    return retmatrix;
}

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

vector<vector<int>> col_swap(vector<vector<int>> matrix, int col1, int col2) {
    int n = matrix.size();
    col1--;
    col2--;
    vector<vector<int>> retmatrix(matrix.size(), vector<int>(matrix.size()));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            retmatrix[i][j] = matrix[i][j];
        }
    }
    retmatrix = rotate_matrix(retmatrix);
    if (col1 >= n || col2 >= n) {
        return matrix;
    }
    vector<int> temprow = retmatrix[col1];
    retmatrix[col1] = retmatrix[col2];
    retmatrix[col2] = temprow;
    retmatrix = rotate_matrix(retmatrix);
    retmatrix = rotate_matrix(retmatrix);
    retmatrix = rotate_matrix(retmatrix);
    return retmatrix;
}

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
int main() {
    ifstream myfile("file.txt");
    if (!myfile) {
        cerr << "Failed to open file.txt\n";
        return 1;
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
    cout << "Matrix 1:" << endl;
    print_matrix(matrix1);
    cout << "Matrix 2:" << endl;
    print_matrix(matrix2);
    
    // Matrix Addition
    vector<vector<int>> matrix3(matrix1.size(), vector<int>(matrix1.size())); 
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1.size(); j++) {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    cout << "Addition Matrix:" << endl;
    print_matrix(matrix3);

    cout << "Multiplication Matrix:" << endl;
    print_matrix(multiply_matrix(matrix1, matrix2));

    cout << "Diagonal Sum of Matrix 1: " << endl;
    cout << diagnonal_sum(matrix1) << endl;

    cout << "Matrix 1 with rows 1 and 3 swapped: " << endl;
    print_matrix(row_swap(matrix1, 1, 3));

    cout << "Matrix 1 with cols 1 and 3 swapped: " << endl;
    cout << "Initial: " << endl;
    print_matrix(matrix1);
    cout << "Swapped: " << endl;
    print_matrix(col_swap(matrix1, 1, 3));
}
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
        if (matrix1.size() < 4) {
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
}
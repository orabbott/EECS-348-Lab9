#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

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
    for (vector line : matrix1) {
        for (int num : line) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << "Matrix 2:" << endl;
    for (vector line : matrix2) {
        for (int num : line) {
            cout << num << " ";
        }
        cout << endl;
    }

}
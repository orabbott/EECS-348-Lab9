#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    ifstream myfile("file.txt");
    if (!myfile) {
        cerr << "Failed to open file.txt\n";
        return 1;
    }

    string mystr;
    vector<vector<int>> matrix;
    int myint;
    while (getline(myfile, mystr)) {
        vector<int> line;
        stringstream ss(mystr);
        string token;
        while (ss >> token) {       // splits by whitespace
            line.push_back(stoi(token));
        }
        matrix.push_back(line); 
    }
    for (vector line : matrix) {
        for (int num : line) {
            cout << num << " ";
        }
        cout << endl;
    }

}
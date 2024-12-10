#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream file("q1.csv");
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    string line, word;
    string data[600];
    int index = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        while (getline(ss, word, ',')) {
            if (index < 600) {
                data[index++] = word;
            } else {
                cerr << "Array size exceeded" << endl;
                return 1;
            }
        }
        if (index < 600) {
            data[index++] = "END"; // Add the "END" marker at the end of each line
        } else {
            cerr << "Array size exceeded" << endl;
            return 1;
        }
    }
    file.close();
    for (int i = 0; i < index; )
    {
        cout << "Name: " << data[i++] << endl;
        int hop = 1;
        while (i < index && data[i] != "END")
        {
            cout << "Friend " << hop << " (" << hop << " hop): " << data[i++] << endl;
            hop++;
        }

        i++; // Move past the "END" marker
        cout << endl; // Print a blank line between each person's data for readability
    }

    
return 0;
}


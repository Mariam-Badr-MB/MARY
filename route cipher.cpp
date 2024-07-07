#include <iostream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

int main() {
    string message ,  message_t;
    int row, column, top, bottom, right, left;
    
    cout << "Please enter your message: ";
    getline(cin, message);

    cout << "Please enter your secret key: ";
    cin >> column;

    while (true) {
        if (cin.fail() || column <= 0 || column > (message.size() / 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n Please enter a valid positive integer: ";
            cin >> column;
        } else {
            break;
        }
    }
    
    // Convert characters to uppercase
    for (char &i : message) {
        if (isalpha(i)) {
            message_t += toupper(i);
        }
       
    }

    // Calculate the number of rows
    if (message_t.length() % column == 0) {
        row = message_t.length() / column;
    } 
    else {
        row = (message_t.length() / column) + 1;
     }
    // Allocate the array dynamically
    char** messages = new char*[row];
    for (int i = 0; i < row; ++i) {
        messages[i] = new char[column];
    }

    // Fill in matrix
    int index = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (index < message_t.length()) {
                messages[i][j] = message_t[index++];
            } else {
                messages[i][j] = 'X'; // Padding with 'X' if the message doesn't fill the entire array
            }
        }
    }
    
    // Initialize indices
    top = 0;
    bottom = row - 1;
    right = column - 1;
    left = 0;

    // Printing the encrypted message
    cout << "Encrypted message is :  ";
      while (true) {
        if (left > right || top > bottom) {
            break;
        }

        // Print from top to bottom
        for (int i = top; i <= bottom; i++) {
            cout << messages[i][right];
        }
        right--;

        // Check if left is greater than right before proceeding
        if (left > right) {
            break;
        }

        // Print from right to left
        for (int i = right; i >= left; i--) {
            cout << messages[bottom][i];
        }
        bottom--;

        // Check if bottom is greater than top before proceeding
        if (bottom < top) {
            break;
        }

        // Print from bottom to top
        for (int i = bottom; i >= top; i--) {
            cout << messages[i][left];
        }
        left ++;

        // Check if right is less than left before proceeding
        if (right < left) {
            break;
        }

        // Print from right to left
        for (int i = left; i <= right; i++) {
            cout << messages[top][i];
        }
        top ++;
    }

  

    return 0;
}
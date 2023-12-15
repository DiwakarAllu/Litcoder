#include <iostream>
#include <string>
using namespace std;

// Function to perform Caesar cipher encryption
string caesarCipherEncrypt(string input, int rotation)
{
    string result = "";

    for (char &c : input)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + rotation) % 26 + base;
        }
        result += c;
    }

    return result;
}

int main()
{
    string message;

    // Taking user input
    cout << "Enter the message to encrypt: ";
    getline(cin, message);

    int rotation = 4; // Rotation for the Caesar cipher

    // Calling the caesarCipherEncrypt function and printing the result
    string encryptedMessage = caesarCipherEncrypt(message, rotation);
    cout << "Encrypted Message: " << encryptedMessage << endl;

    return 0;
}

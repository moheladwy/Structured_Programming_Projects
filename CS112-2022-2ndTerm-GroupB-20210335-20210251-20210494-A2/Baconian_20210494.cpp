// FCAI - Programing 1 - 2022 - Assignment 2
// Program Name:Banconian_20210494.cpp
// problem Description:This program is gonna take a massage from the user & cipher each letter to 5 letters from ("a") , ("b")
// Last Modification Date: 25/3/2022
// Author and ID and Group: Youssef Hamed Mohamed Hamed ,20210494,Group B
// Teaching Assistant :Eng.
// Purpose: To get the
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string encrypt(string pt) // Encrypt function
{
    char key[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; // string array
    string value[26] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb", "abaaa", "abaab", "ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb", "baaaa", "baaab", "baaba", "baabb", "babaa", "babab", "babba", "babbb", "bbaaa", "bbaab"};

    int i, j; // Incripting the val
    string encpt1 = "";
    for (i = 0; i < pt.length(); i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (pt[i] == key[j])
            {
                encpt1 = encpt1 + value[j];
            }
        }
    }
    return encpt1;
}
string decrypt(string encpt)
{
    string value[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    string key[26] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb", "abaaa", "abaab", "ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb", "baaaa", "baaab", "baaba", "baabb", "babaa", "babab", "babba", "babbb", "bbaaa", "bbaab"};

    int i, j; // get the val decripted
    string decpt1 = "";
    for (i = 0; i < encpt.length(); i = i + 5)
    {
        for (j = 0; j < 26; j++)
        {
            if (key[j] == encpt.substr(i, 5))
            {
                decpt1 = decpt1 + value[j];
            }
        }
    }
    return decpt1;
}
int main() // Taking the text and output it once and it's baconian
{
    string pt, encpt, decpt;
    cout << "Enter plaintext: ";
    cin >> pt;                                   // taking the input in plan text
    encpt = encrypt(pt);                         // calling the encrypt function
    cout << "Encrypted text: " << encpt << "\n"; // output the encrypted text
    decpt = decrypt(encpt);
    cout << "decrypted text:" << decpt; // output the decrypted text
    return 0;
}
/*
Author: Mohamed Hussein Hassan.
ID: 20210335.
Section: S17, S18.
Task Number: 3.
Cipher Number: 5.
Cipher Name: Simple Substitution Cipher.
Cipher Description: In this cipher, a replacement alphabet is used to replace each letter by another one,
With Creating a general version that builds the cipher alphabet using a given key of 5 unique letters.
The user enters the key to cipher a message and the same key to decipher the message.
The cipher alphabet is built by adding the remaining 21 letters in order after the key letters.
*/
#include <iostream>
#include <string>
using namespace std;

char my_alphabet_letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char my_key[5];
char my_cipher_letters[26];

string get_key();
bool check_unique_key(string key);
string make_lowerCase(string message);
string get_message();
bool check_valid_message(string message);
string choose_method();
bool try_again();
bool check_array(char letter);
void general_Encryption(string key);
int get_number_of_letter(char letter, string choose);
string Decryption(string message);
string Encryption(string message);
void program();

int main()
{
    program();
    return 0;
}

bool check_unique_key(string key)
{
    if (key.length() == 5)
    {
        bool checker = true;
        for (int i = 0; i < key.length(); i++)
        {
            for (int j = i + 1; j < key.length(); j++)
            {
                if (key[i] == key[j] || int(key[i]) < 97 || int(key[i]) > 122)
                {
                    checker = false;
                    break;
                }
            }
        }
        return checker;
    }
    else
    {
        return false;
    }
}

string make_lowerCase(string message)
{
    string lowerCase_message = "";
    for (auto letter : message)
    {
        lowerCase_message += tolower(letter);
    }
    return lowerCase_message;
}

string get_key()
{
    string key;
    cout << "Enter unique Key from 5 letters only: ";
    while (true)
    {
        key = "";
        while (key.empty())
        {
            getline(cin, key);
        }
        key = make_lowerCase(key);
        if (check_unique_key(key))
        {
            return key;
        }
        else
        {
            cout << "Enter unique Key from 5 letters [A:Z] and the letters must not be equal: ";
        }
    }
}

string get_message()
{
    string message;
    bool bool_of_message;
    cout << "Plain text: ";
    while (true)
    {
        message = "";
        while (message.empty())
        {
            getline(cin, message);
        }
        if (message != "")
        {
            message = make_lowerCase(message);
            bool_of_message = check_valid_message(message);
            if (bool_of_message == true)
            {
                break;
            }
            else
            {
                cout << "Enter Message that contain only letters and space: ";
            }
        }
        else
        {
            cout << "\nEnter a Plain text please: ";
        }
    }
    return message;
}

bool check_valid_message(string message)
{
    int counter = 0, ascii_of_letter;
    for (int i = 0; i < message.length(); i++)
    {
        ascii_of_letter = int(message[i]);
        if ((ascii_of_letter >= 97 && ascii_of_letter <= 122) || ascii_of_letter == 32)
        {
            counter += 1;
        }
    }
    if (counter == message.length())
    {
        return true;
    }
    else
    {
        return false;
    }
}

string choose_method()
{
    string choose;
    cout << "Encryption [1]\n"
         << "Decryption [2]\n"
         << "Both [3]\n"
         << "Exit [4]\n"
         << "Choose Method from the apove: ";
    while (true)
    {
        cin >> choose;
        if (choose == "1" || choose == "2" || choose == "3" || choose == "4")
        {
            break;
        }
        else
        {
            cout << "Enter a valid option plz: ";
        }
    }
    return choose;
}

bool try_again()
{
    string again;
    cout << "use the program again [y] or [n]: ";
    while (true)
    {
        cin >> again;
        if (again == "y" || again == "Y")
        {
            return true;
        }
        else if (again == "n" || again == "N")
        {
            return false;
        }
        else
        {
            cout << "Enter valid option from [y] or [n] please: ";
        }
    }
}

bool check_array(char letter)
{
    bool checker = true;
    for (int i = 0; i < 5; i++)
    {
        if (letter == my_key[i])
        {
            checker = false;
            break;
        }
    }
    return checker;
}

int get_number_of_letter(char letter, string choose)
{
    int number_of_letter;
    if (choose == "1")
    {
        for (number_of_letter = 0; number_of_letter < 26; number_of_letter++)
        {
            if (letter == my_alphabet_letters[number_of_letter])
            {
                break;
            }
        }
    }
    else if (choose == "2")
    {
        for (number_of_letter = 0; number_of_letter < 26; number_of_letter++)
        {
            if (letter == my_cipher_letters[number_of_letter])
            {
                break;
            }
        }
    }
    return number_of_letter;
}

void general_Encryption(string key)
{
    int num = 0;
    for (int i = 0; i < 5; i++)
    {
        my_key[i] = key[i];
        my_cipher_letters[i] = my_key[i];
    }
    for (int i = 0; i < 26; i++)
    {
        if (check_array(my_alphabet_letters[i]))
        {
            my_cipher_letters[num + 5] = my_alphabet_letters[i];
            num++;
        }
    }
}

string Encryption(string message)
{
    string encrypt_message = "";
    int number_of_element;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == ' ')
        {
            encrypt_message += ' ';
        }
        else
        {
            number_of_element = get_number_of_letter(message[i], "1");
            encrypt_message += my_cipher_letters[number_of_element];
        }
    }
    return encrypt_message;
}

string Decryption(string message)
{
    string decrypt_message = "";
    int number_of_element;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == ' ')
        {
            decrypt_message += ' ';
        }
        else
        {
            number_of_element = get_number_of_letter(message[i], "2");
            decrypt_message += my_alphabet_letters[number_of_element];
        }
    }
    return decrypt_message;
}

void program()
{
    int counter = 0;
    string message, choose, key;
    choose = choose_method();
    if (choose != "4")
    {
        key = get_key();
        key = make_lowerCase(key);
        general_Encryption(key);
        message = get_message();
        message = make_lowerCase(message);
        if (choose == "1")
        {
            message = Encryption(message);
            cout << "Cipher text: " << message << endl;
        }
        else if (choose == "2")
        {
            message = Decryption(message);
            cout << "Decipher text: " << message << endl;
        }
        else if (choose == "3")
        {
            message = Encryption(message);
            cout << "Cipher text: " << message << endl;
            message = Decryption(message);
            cout << "Decipher text: " << message << endl;
        }
        bool again = try_again();
        if (again)
        {
            program();
            counter += 1;
        }
    }
    if (counter == 0)
    {
        cout << endl
             << "Thanks for using my decoder programm.\n";
    }
}
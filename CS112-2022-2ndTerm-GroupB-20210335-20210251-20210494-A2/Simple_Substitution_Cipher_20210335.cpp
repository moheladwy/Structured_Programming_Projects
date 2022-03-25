// Cipher Number: 5 ,Cipher Name: Simple Substitution Cipher, Author: Mohamed Hussein Hassan, ID: 20210335.
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

char my_letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char my_key[5];
char my_cipher[26];

string get_key();                                     // Done.
bool check_unique_key(string key);                    // Done.
string make_lowerCase(string message);                // Done.
string get_message();                                 // Done.
bool check_valid_message(string message);             // Done.
string choose_method();                               // Done.
bool try_again();                                     // Done.
void clear_screen();                                  // Done.
bool check_arr(char letter);                          // Done.
void general_Encryption(string key);                  // Done.
int get_number_of_letter(char letter, string choose); // Done.
string Decryption(string message);                    // Done.
string Encryption(string message);                    // Done.
void program();                                       // Done.

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

void clear_screen()
{
    HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hndl, &csbi);
    DWORD written;
    DWORD n = csbi.dwSize.X * csbi.dwCursorPosition.Y + csbi.dwCursorPosition.X + 1;
    COORD curhome = {0, 0};
    FillConsoleOutputCharacter(hndl, ' ', n, curhome, &written);
    csbi.srWindow.Bottom -= csbi.srWindow.Top;
    csbi.srWindow.Top = 0;
    SetConsoleWindowInfo(hndl, TRUE, &csbi.srWindow);
    SetConsoleCursorPosition(hndl, curhome);
}

bool check_arr(char letter)
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
            if (letter == my_letters[number_of_letter])
            {
                break;
            }
        }
    }
    else if (choose == "2")
    {
        for (number_of_letter = 0; number_of_letter < 26; number_of_letter++)
        {
            if (letter == my_cipher[number_of_letter])
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
        my_cipher[i] = my_key[i];
    }
    for (int i = 0; i < 26; i++)
    {
        if (check_arr(my_letters[i]))
        {
            my_cipher[num + 5] = my_letters[i];
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
            encrypt_message += my_cipher[number_of_element];
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
            decrypt_message += my_letters[number_of_element];
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
            clear_screen();
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
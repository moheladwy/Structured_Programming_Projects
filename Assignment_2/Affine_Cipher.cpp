#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
char my_letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int a2, b2, c2;

void get_numbers();                       // Done.
bool check_letter(string input);          // Done.
bool check_equation();                    // Done.
bool check_valid_message(string message); // Done.
string get_message();                     // Done.
string make_lowerCase(string message);    // Done.
int get_number_of_letter(char letter);    // Done.
string Encrypt_message(string message);   // Done.
string Decrypt_message(string message);   // Done.
string choose_method();                   // Done.
bool try_again();                         // Done.
void clear_screen();                      // Done.
void program();                           // Done.

int main()
{
    program();
    return 0;
}
void get_numbers()
{
    string a1, b1, c1;
    cout << "Enter the a, b and c Numbers with respeact that The Numbers [a] and [c] must follow the equation {(a*c) % 26 = 1}: ";
    while (true)
    {
        cin >> a1 >> b1 >> c1;
        if (check_letter(a1) && check_letter(b1) && check_letter(c1))
        {
            a2 = stoi(a1);
            b2 = stoi(b1);
            c2 = stoi(c1);
            if (check_equation())
            {
                break;
            }
            else
            {
                cout << "Please enter numbers a and c that following the equation {(a * c) % 26 = 1}: ";
            }
        }
        else
        {
            cout << "Please Enter only numbers: ";
        }
    }
}

bool check_letter(string input)
{
    bool checker = true;
    for (auto letter : input)
    {
        if (isdigit(letter) == false)
        {
            checker = false;
            break;
        }
    }
    return checker;
}

bool check_equation()
{
    if ((a2 * c2) % 26 == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
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

string make_lowerCase(string message)
{
    string lowerCase_message = "";
    for (int i = 0; i < message.length(); i++)
    {
        lowerCase_message += tolower(message[i]);
    }
    return lowerCase_message;
}

int get_number_of_letter(char letter)
{
    int number_of_letter;
    for (number_of_letter = 0; number_of_letter < 26; number_of_letter++)
    {
        if (my_letters[number_of_letter] == letter)
        {
            break;
        }
    }
    return number_of_letter;
}

string Encrypt_message(string message)
{
    string message_after_encryption = "";
    int number_of_letter, Encryption_Equation;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == ' ')
        {
            message_after_encryption += message[i];
        }
        else
        {
            number_of_letter = get_number_of_letter(message[i]);
            Encryption_Equation = ((a2 * number_of_letter) + 26 + b2) % 26;
            message_after_encryption += my_letters[Encryption_Equation];
        }
    }
    return message_after_encryption;
}

string Decrypt_message(string message)
{
    string message_after_encryption = "";
    int number_of_letter, Decryption_Equation;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == ' ')
        {
            message_after_encryption += message[i];
        }
        else
        {
            number_of_letter = get_number_of_letter(message[i]);
            Decryption_Equation = (c2 * (number_of_letter - b2 + 26)) % 26;
            message_after_encryption += my_letters[Decryption_Equation];
        }
    }
    return message_after_encryption;
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

void program()
{
    int counter = 0;
    string message, choose;
    choose = choose_method();
    if (choose != "4")
    {
        get_numbers();
        message = get_message();
        message = make_lowerCase(message);

        if (choose == "1")
        {
            message = Encrypt_message(message);
            cout << "Cipher text: " << message << endl;
        }
        else if (choose == "2")
        {
            message = Decrypt_message(message);
            cout << "Decipher text: " << message << endl;
        }
        else if (choose == "3")
        {
            message = Encrypt_message(message);
            cout << "Cipher text: " << message << endl;
            message = Decrypt_message(message);
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
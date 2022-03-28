//FCAI - Programming 1 - 2022 - Assignment 2
//Program name : caesar cipher
//last modification date : 3/26/2022
//Alialdin muhammed mostafa | 20210251 | Group B
// Teaching assistant :Hagar Ahmed
//purpose :taking the whole mark in the assignment


#include <iostream>
#include<cstring>
#include<string>
using namespace std;
bool checkShifts(string input) {
    bool checker = true; 
    for (auto digit : input) {
        if (input[0] == '-') {
            continue;
        }
        if (isdigit(digit) == false) {//if the input is not digit return false
            checker = false;
            break;
        }
    }
    return checker;
}

string enter() {
    string shifts;
    while (true) {//ask for input and checking weather the inp
        cout << "\n" << "enter your number of shifts\nenter positive number to shift right or negative number to shift left: " << endl;
        cin >> shifts;
        if (checkShifts(shifts)) {
            return shifts;
        }
        else {
            cout << "invalid input" << endl;
        }
    }
}
void ciphering() {
    string text;
    string shifts;
    int direction;
    
   
    cout << "enter your text: " << endl;
    text = "";
    while (text.empty()) {
        getline(cin, text);
    }
    
    int inputLength = text.length();
    string moves = enter();
    int move = stoi(moves);  
    if (move > 26) {
        move = move % 26;
    }
    if (move < -26) {
        move = move % 26;
    }
    cout << "your ciphered text is: " ;

    for (int i = 0; i < inputLength; i++) {
        char x = text[i];
        if (x == 32) {
            cout << " ";
            continue;
        }
        if (x > 90) { //if x is small
            x -= 32;//make it capital
        }

        if (x + move < 65) { //if  ascii character is out of capital alphapet index
            x += 26;
            x += move;
            cout << x;
            continue;
        }
        if (x + move > 90) { //if  ascii character is out of capital alphapet index
            x -= 26;
            x += move;
            cout << x;
            continue;
        }
        else {
            x += move;
            cout << x;
            continue;
        }


        
       


    }
}

void deciphering() {
    string text;
    int shifts;
    cout << "enter the ciphered text : " << endl;
    text = "";
    while (text.empty()) {
        getline(cin, text);
    }
    
    int inputLength = text.length();
    string moves = enter();
    int move = stoi(moves);
    if (move > 26) {
        move = move % 26;
    }
    cout << "your deciphered text is: " ;
    for (int i = 0; i < inputLength; i++) {
        char x = text[i];
        if (x == 32) {
            cout << " ";
        }
        else if (x > 90) {// if character is small
            x -= 32;//make it capital
            if (x - move < 65) {
                x += 26;
                x -= move;//cipher it
                cout << x;
            }else{ 
                x -= move;
                cout << x;
            }
        }
        else
        {
            if (x - move < 65) {
                x += 26;
                x -= move;//cipher it
                cout << x;
            }
            else {
                x -= move;
                cout << x;
            }
        }
       
            
    }
}
int main()
{
   
    while (true) {
        string choice;
        cout << "hello, what do you want to do?" << '\n' << "1:cipher a message" << '\n' << "2: decipher a message" << '\n' << "pick 1 or 2: ";
        cin >> choice;
        cin.clear();
        if (choice == "1") {
            ciphering();
            return false;
        }
        else if (choice=="2") {
            deciphering();
            return false;
        }
        else {
            cout << "please only input 1 or 2";
        }
    }
    
    
    
    
      
}



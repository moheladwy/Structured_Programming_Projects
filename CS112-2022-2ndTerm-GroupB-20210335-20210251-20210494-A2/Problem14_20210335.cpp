/*
Author Name: Mohamed Hussein Hassan Mohamed
ID: 20210335
Section: S17,S18
Task Number: 4
Problem Number: 14
Program Description: I Suppose to Write a program to input the current time in the format hh:mm:ss and reject invalid
inputs. Then calculate the seconds passed since the last midnight.
*/
#include <iostream>
#include <string>
using namespace std;

string h, m, s;
int hour, minute, second;

string get_time();
bool check_time(string time2);
void split_time(string time2);
bool check_valid_time();
void calc_total_seconds();
void program();

int main()
{
    program();
    return 0;
}

string get_time()
{
    string time2;
    char time1[9];
    cout << "Please enter a valid time in (hh:mm:ss) format (hours between 00 and 23): ";
    cin.getline(time1, 9, '\n');
    for (char letter : time1)
    {
        if (letter != ':')
        {
            time2 += letter;
        }
    }
    return time2;
}

bool check_time(string time2)
{
    bool checker = true;
    for (char letter : time2)
    {
        if (isalpha(letter))
        {
            checker = false;
            break;
        }
    }
    return checker;
}

void split_time(string time2)
{
    for (int i = 0; i < 8; i++)
    {
        if (i < 2)
        {
            h += time2[i];
        }
        else if (i < 4)
        {
            m += time2[i];
        }
        else if (i < 8)
        {
            s += time2[i];
        }
    }
}

bool check_valid_time()
{
    bool checker = true;
    hour = stoi(h);
    minute = stoi(m);
    second = stoi(s);
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
    {
        checker = false;
    }
    return checker;
}

void calc_total_seconds()
{
    int total_seconds;
    total_seconds = second + (hour * 60 * 60) + (minute * 60);
    cout << "The time in seconds since midnight is: " << total_seconds << "\n";
}

void program()
{
    string time;
    while (true)
    {
        time = "";
        time = get_time();
        if (check_time(time))
        {
            split_time(time);
            if (check_valid_time())
            {
                break;
            }
            else
            {
                cout << "The Hours must be between [0:23].\n"
                     << "The Minutes and Seconds must be between [0:59].\n";
            }
        }
        else
        {
            cout << "The Time should be numbers only, try again.\n";
        }
    }
    calc_total_seconds();
}
// FCAI - Programing 1 - 2022 - Assignment 2
// Program Name:problem 13.20210494.cpp
// problem Description:This program is gonna take from the user
//  two points and calculate the slop and output the linear equation
// Last Modification Date:25/3/2022
// Author and ID and Group: Youssef Hamed Mohamed Hamed ,20210494,Group B
// Teaching Assistant :Eng.
// Purpose: To get the liniear equation
#include <iostream>
using namespace std;

int main()

{
    int x1, y1, x2, y2, m, c;

    cout << "enter first point x1,y1 \n"; // geting the first 2 points
    cin >> x1 >> y1;

    cout << "enter secend point x2,y2 \n "; // geting the second 2 points
    cin >> x2 >> y2;

    m = (y2 - y1) / (x2 - x1); // calculating the slop
    c = y1 - (m * x1);         // calculating the linear equation
    cout << "The equation of the line is ";
    cout << "Y = " << m << "X "
         << "+ " << c;

    return 0;
}
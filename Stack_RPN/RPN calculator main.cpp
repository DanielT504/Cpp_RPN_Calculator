/*****************************************************************************
 *	Name: Daniel Thero                                                       *
 *	Course: ICS4U                                                            *
 *	Date: April 11th, 2018                                                   *
 *	                                                                         *
 *	Purpose: Program creates a keyboard-based, functional RPN calculator     *
 *           using a stack class.                                            *
 *	                                                                         *
 *	Usage: Follow instructions given in-console.                             *
 *	                                                                         *
 *	Revision History: n/a                                                    *
 *	                                                                         *
 *	Known Issues: None                                                       *
 *	                                                                         *
 *****************************************************************************/

#include "apstring.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <string>
#include "rpn.h"

#define ASCII_TL 218
#define ASCII_TR 191
#define ASCII_BL 192
#define ASCII_BR 217
#define ASCII_V 179
#define ASCII_H 196

using namespace std;

//class
Rpn calc;

//declaring handles
HANDLE hWnd;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//initializing box colors globally to avoid passing them through many functions
int boxColor[7][4] = {
    {13,13,13,13},
    {13,13,13,13},
    {15,15,15,15},
    {2,3,3,3},
    {2,3,3,3},
    {2,3,3,3},
    {2,3,3,3},
    };

//function prototypes
void screenSize();
void prompt();
void drawRect(int x1, int y1, int x2, int y2);
void printChar(int x, int y, char c);
void makeBoxes();
void makeLabels(int a, int b, int x, int y, int x2, int y2);
void command();
void number(apstring enter);

int main(){
    //function to resize windows
    screenSize();

    //function to set up console and receive input
    command();

    return 0;
}

//function to resize windows
void screenSize(){
    //stuff to enable console resizing
    SMALL_RECT rect;
    hWnd = GetStdHandle(STD_OUTPUT_HANDLE);

    //resizing console
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = 78;
    rect.Bottom = 28;
    SetConsoleWindowInfo(hWnd, TRUE, &rect);
}

//function to determine box layout
void drawRect(int x1, int y1, int x2, int y2) {

    //determining location of box corners
    printChar(x1, y1, ASCII_TL);
    printChar(x2, y1, ASCII_TR);
    printChar(x1, y2, ASCII_BL);
    printChar(x2, y2, ASCII_BR);

    //determining location of horizontal lines
    for (int i = x1 + 1; i < x2; i++) {
        printChar(i, y1, ASCII_H);
        printChar(i, y2, ASCII_H);
    }

    //determining location of vertical lines
    for (int i = y1 + 1; i < y2; i++) {
        printChar(x1, i, ASCII_V);
        printChar(x2, i, ASCII_V);
    }
}

//function to draw to boxes
void printChar(int x, int y, char c) {
    //initializing coordinates
    COORD coord;
    coord.X = x;
    coord.Y = y;

    //printing appropriate line symbol at the determined coordinates
    SetConsoleCursorPosition(hWnd, coord);
    cout << c;

}

//function to determine location of boxes
void makeBoxes(){

    //initializing coordinates of input/output box
    int x = 0;
    int y = 5;
    int x2 = 78;
    int y2 = 7;

    //calling a function to draw input/output box in the appropriate color
    SetConsoleTextAttribute(hConsole, 8);
    drawRect(x, y, x2, y2);

    //dealing with each column of boxes
    for (int a = 0; a < 4; a++) {
        //dealing with each successive box in the current column
        for (int b = 0; b < 7; b++){
            //setting the size and starting position of each box
            x = 20 * a;
            y = 8 + 3 * b;
            x2 = x + 18;
            y2 = y + 2;

            //setting each box and label to its respective predetermined color
            SetConsoleTextAttribute(hConsole, boxColor[b][a]);
            //calling a function to draw boxes
            drawRect(x, y, x2, y2);
            //labeling each box with its respective title
            makeLabels(a, b, x, y, x2, y2);
        }
    }
}

//function to give user instructions
void prompt(){
    //initializing coordinates of text
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(hWnd, coord);

    //outputting instructions in the appropriate color
    SetConsoleTextAttribute(hConsole, 14);
    cout << "\nTo enter a value or operator, type the short form of the ";
    cout << "desired box as\nindicated, then press enter. Negative numbers ";
    cout << "are preceded by the '-' symbol,\nand decimals are permitted to ";
    cout << "five decimal places. Exit by entering off ('o').\nValues must be";
    cout << " containable in a float. Use RPN format (post fix notation).\n";
}

//function to print the labels of each box
void makeLabels(int a, int b, int x, int y, int x2, int y2){
    //initializing each label
    string label[7][4] = {
    {"sin-enter deg.(s)","cos-enter deg.(c)",
    "tan-enter deg.(t)","    modulus(m)"},
    {"   logarithm(l)","absolute value(a)",
    "   exponent(^)","  square root(r)"},
    {"      OFF(o)","     delete(z)","  clear stack(x)","      enter"},
    {"   addition(+)","        7","        8","        9"},
    {"  subtraction(-)","        4","        5","        6"},
    {"multiplication(*)","        1","        2","        3"},
    {"   division(/)","        -","        0","        ."},
    };

    //initializing the coordinates of each label
    //to fit within its respective box
    COORD coord;
    coord.X = x + 1;
    coord.Y = y + 1;
    SetConsoleCursorPosition(hWnd, coord);
    //printing label
    cout << label[b][a];
}

//function to set up console and receive input
void command(){
    //declaring input variable
    apstring enter = " ";

    //continue to receive user input until they turn the calculator off
    while(enter != "o"){
        //function to give user instructions on how to use the calculator
        prompt();
        //function to determine location of boxes
        makeBoxes();
        cout << endl;

        //setting the coordinates of the stack display title
        COORD coord;
        coord.X = 19;
        coord.Y = 6;
        SetConsoleCursorPosition(hWnd, coord);

        //setting the stack display and the user input to the appropriate color
        SetConsoleTextAttribute(hConsole, 15);
        cout << "Stack:";

        //setting the coordinates of the user input cursor
        coord.X = 1;
        coord.Y = 6;
        SetConsoleCursorPosition(hWnd, coord);

        //receiving user input
        cin >> enter;

        //clearing input box
        system("CLS");

        //determining how to proceed, depending on the input of the user
        if (enter == "s"){
            calc.sine();
        }
        else if (enter == "c"){
            calc.cosine();
        }
        else if (enter == "t"){
            calc.tangent();
        }
        else if (enter == "m"){
            calc.mod();
        }
        else if (enter == "l"){
            calc.log();
        }
        else if (enter == "a"){
            calc.absoluteValue();
        }
        else if (enter == "^"){
            calc.exponent();
        }
        else if (enter == "r"){
            calc.squareRoot();
        }
        else if (enter == "o"){
        }
        else if (enter == "x"){
            calc.clearAll();
        }
        else if (enter == "+"){
            calc.add();
        }
        else if (enter == "-"){
            calc.subtract();
        }
        else if (enter == "*"){
            calc.multiply();
        }
        else if (enter == "/"){
            calc.divide();
        }
        else if (enter == "z"){
            calc.del();
        }
        else{
            number(enter);
        }

        //setting coordinates of the stack display
        coord.X = 27;
        coord.Y = 6;
        SetConsoleCursorPosition(hWnd, coord);

        //displaying updated stack
        for (int d = 0; d <= calc.Top(); d++){
            cout << calc.request(d) << " ";
        }

    }

    //clearing input box before exiting
    system("CLS");
}

//function to handle entered numbers
void number(apstring enter){
    //declaring variable that will receive the entered number
    float val = 0;

    //determining whether or not number entered is negative
    if (enter.find('-') != npos){
        //if number is negative then remove minus sign
        //from the apstring before converting to a float
        enter = enter.substr(1, enter.length() - 1);
        //converting apstring number to a float negative value
        val = -(atof(enter.c_str()));
    } else {
        //converting apstring number to a float positive value
        val = atof(enter.c_str());
    }

    //pushing entered number onto the stack
    calc.oprt(val);
}

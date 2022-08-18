#include "HelperFunction.h"
void HelperFunction::failInput()
{
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    if (cin.fail())
        cin.clear();
    cin.ignore(1, '\n');
    SetConsoleTextAttribute(colors, 4);
    cout << endl;
    cout.width(90); cout << "*-----------------------------------------------*\n";
    cout.width(90); cout << "|       ---------------------------------       |\n";
    cout.width(90); cout << "|       |       \"Invalid Option\"        |       |\n";
    cout.width(90); cout << "|       ---------------------------------       |\n";
    cout.width(90); cout << "|                                               |\n";
    cout.width(90); cout << "|         Please Select right choice.           |\n";
    cout.width(90); cout << "*-----------------------------------------------*\n";
    SetConsoleTextAttribute(colors, 7);
}
void HelperFunction::selectedBox(int& val)
{
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 2);
    cout << endl;
    cout.width(90); cout << "*-----------------------------------------------*\n";
    cout.width(65); cout << "|\t  You seletecd option #" << val << ".        \t|\n";
    cout.width(90); cout << "*-----------------------------------------------*\n";
    cout << endl;
    SetConsoleTextAttribute(colors, 7);
}
void HelperFunction::sucessBox(char operation[25])
{
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 2);
    cout << endl;
    cout.width(95); cout << "*----------------------------------------------------------*\n";
    cout.width(40); cout << "  \""<<operation<<",  Operation has been done successfully\"      \n";
    cout.width(95); cout << "*----------------------------------------------------------*\n";
    cout << endl;
    SetConsoleTextAttribute(colors, 7);
}
void HelperFunction::failBox(char operation[25])
{
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 4);
    cout << endl;
    cout.width(95); cout << "*----------------------------------------------------------*\n";
    cout.width(40); cout << "  \""<<operation<<",  Operation could not done completed\"      \n";
    cout.width(95); cout << "*----------------------------------------------------------*\n";
    cout << endl;
    SetConsoleTextAttribute(colors, 7);
}
void HelperFunction::mainMenu()
{
    cout << endl;
    cout.width(100); cout << " ____________________________________________________________________ \n";
    cout.width(100); cout << "|                 _____________________________                      |\n";
    cout.width(100); cout << "|                |                             |                     |\n";
    cout.width(100); cout << "|                |      \"RED - BLACK Tree\"     |                     |\n";
    cout.width(100); cout << "|                |_____________________________|                     |\n";
    cout.width(100); cout << "|____________________________________________________________________|\n";
    cout.width(100); cout << "|                                                                    |\n";
    cout.width(100); cout << "|         Choose any option to perform following operations.         |\n";
    cout.width(100); cout << "|____________________________________________________________________|\n";
    cout.width(100); cout << "|  Press 1 to insert values one by one in the tree.                  |\n";
    cout.width(100);  cout << "|  Press 2 to delete a value from the tree.                          |\n";
    cout.width(100);  cout << "|  Press 3 to searching a value from the tree.                       |\n";
    cout.width(100);    cout << "|  Press 4 to in-order traversal LNR.                                |\n";
    cout.width(100);    cout << "|  Press 5 to pre-order traversal NLR.                               |\n";
    cout.width(100);   cout << "|  Press 6 to post-order traversal LRN.                              |\n";
    cout.width(100);    cout << "|  Press 7 to in-order traversal 2 RNL.                              |\n";
    cout.width(100);   cout << "|  Press 8 to pre-order traversal 2 NRL.                             |\n";
    cout.width(100);   cout << "|  Press 9 to post-order traversal 2 RLN.                            |\n";
    cout.width(100);    cout << "|  Press 10 to destroy the tree.                                     |\n";
    cout.width(100);    cout << "|  Press 11 to delete all values in the tree greater than X.         |\n";
    cout.width(100);    cout << "|  Press 12 to displaying parent of a node present in Tree.          |\n";
    cout.width(100);   cout << "|  Press 13 to read integer values from the file \"input.txt\".        |\n";
    cout.width(100);    cout << "|  Press 14 Exit.                                                    |\n";
    cout.width(100); cout << "|____________________________________________________________________|\n";
    cout.width(100);    cout << "|  Press 15 to Display Red - Black in form of Binary Tree. (Extra)   |\n";
    cout.width(100);   cout << "*____________________________________________________________________*\n";
}
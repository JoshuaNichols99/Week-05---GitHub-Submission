// Week 05 - Programming Assignment.cpp created by Joshua Nichols.
#include <iostream>
#include <iomanip> 
#include <string>
#include <stdlib.h>

using namespace std;
// Declares prototype functions.
void ShowUsage();
void MakePurchase(int& iTotalXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);
void DisplayPurchase(const int iTotalXSmallconst, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);
void DisplayTotal(const int iTotalXSmallconst, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);

int main() {
    char select;
    // Local variables, not mistake as parameter references.
    int iTotalXSmall = 0;
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;
    // Allows the program to excute and display at least once.
    ShowUsage();
    do {
        cout << "Please enter selection: "; cin >> select;
        switch (select) {
        case 'S':
        case 's':
            ShowUsage();
            break;
        case 'P':
        case 'p':
            MakePurchase(iTotalXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            cout << endl;
            break;
        case 'C':
        case 'c':
            DisplayPurchase(iTotalXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            cout << endl;
            break;
        case 'T':
        case 't':
            DisplayTotal(iTotalXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            cout << endl;
            break;
        default:
            break;
        }  
    } while (select != 'Q' && select != 'q');
    cout << "Thank you" << endl;
    cout << "Press any key to continue . . ." << endl;
}
// Displays program's menu and clears pervious outputs; Used keyword: 'S' or 's'
void ShowUsage() {
    system("CLS");
    cout << setw(60) << setfill('*') << "" << left << endl;
    cout << setw(5) << setfill('*') << "" << " Welcome to my Johnny Utah's PointBreak Surf Shop " << setw(5) << setfill('*') << "" << left << endl;
    cout << setw(60) << setfill('*') << "" << left << endl; cout << endl; cout << endl;
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl; cout << endl;
}
// Inputs user's quantity and size of surfboard; Used keyword: 'P' or 'p'
void MakePurchase(int& iTotalXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge) {
    int quantity = 0;
    string size;
    cout << "Please enter the quantity and type (XXXS=squirrel small,S=small, M=medium, L=large) of surfboard you would like to purchase:"; cin >> quantity >> size;
    switch (size[0]) {
    case 'S':
    case 's':
        iTotalSmall = quantity;
        break;
    case 'M':
    case 'm':
        iTotalMedium = quantity;
        break;
    case 'L':
    case 'l':
        iTotalLarge = quantity;
        break;
    default:
        break;
    }
    if (size == "XXXS" || size == "xxxs") {
        iTotalXSmall = quantity;
    }
    cout << endl;
}
// Displays the number of surfboards sold by size; Used keyword: 'C' or 'c'
void DisplayPurchase(const int iTotalXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge) {
    if (iTotalXSmall > 0) {
        cout << "The total number of squirrel small surfboards is " << iTotalXSmall << endl;
    }
    if (iTotalSmall > 0) {
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    }
    if (iTotalMedium > 0) {
        cout << "The total number of medium surfboards is " << iTotalMedium << endl;
    }
    if (iTotalLarge > 0) {
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    }
    if (iTotalXSmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0) {
        cout << "No purchases made yet." << endl;
    }
}
// Displays the total amount of money earned per purchase size; Used keyword: 'T' or 't'
void DisplayTotal(const int iTotalXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge) {
    const double pXS = 100.00, pS = 175.00, pM = 190.00, pL = 200.00;
    double totalAmount = 0.00;
    double pTotalXSmall = iTotalXSmall * pXS;
    double pTotalSmall = iTotalSmall * pS;
    double pTotalMedium = iTotalMedium * pM;
    double pTotalLarge = iTotalLarge * pL;
    totalAmount = pTotalXSmall + pTotalSmall + pTotalMedium + pTotalLarge;
    if (iTotalXSmall > 0) {
        cout << "The total number of squirrel small surfboards is " << iTotalXSmall << " at a total of $" << fixed << setprecision(2) << pTotalXSmall << endl;
    }
    if (iTotalSmall > 0) {
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << fixed << setprecision(2) << pTotalSmall << endl;
    }
    if (iTotalMedium > 0) {
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << fixed << setprecision(2) << pTotalMedium << endl;
    }
    if (iTotalLarge > 0) {
        cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << fixed << setprecision(2) << pTotalLarge << endl;
    }
    if (iTotalXSmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0) {
        cout << "No purchases made yet." << endl;
    }
    else {
        cout << "Amount due: $" << fixed << setprecision(2) << totalAmount << endl;
    }
}
/*
A do-while loop seems necessary in order for the program to excute at least once.
Even though local variables names are the same as parameter reference names in void functions; They both are separate and contribute to the program as a whole.
*/
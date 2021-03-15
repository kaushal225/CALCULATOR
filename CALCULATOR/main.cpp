#include <iostream>
#include <limits>
#include <Windows.h>
using namespace std;
bool gameover=true;

void ignoreLine()
{
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getDouble()
{
    while (true) // Loop until user enters a valid input
    {
        cout << " ENTER THE NUMBER: \n\t"<< endl;
        double x{};
        cout<<"\t";
        cin >> x;

        // Check for failed extraction
        if (cin.fail()) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // and remove the bad input
            cout << "\n\n\tOOPS ! THAT IS AN INVALID VALUE PLEASE TRY AGAIN\n";
        }
        else
        {
            ignoreLine(); // remove any extraneous input

            // the user can't enter a meaningless double value, so we don't need to worry about validating that
            return x;
        }
    }
}

char getOperator()
{
    while (true) // Loop until user enters a valid input
    {
        cout << "ENTER ANY OPERATOR OF THE FOLLOWING : +, -, *, or / : \n\t";
        char operation{};
        cout<<"\t";
        cin >> operation;

        // Check whether the user entered meaningful input
        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
          return operation; // return it to the caller
        default: // otherwise tell the user what went wrong
        	ignoreLine();
            cout << "\n\n\tOOPS THAT IS A INVALID OPERATOR PLEASE TRY AGAIN.\n";
        }
    } // and try again
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        cout <<"\n\t"<< x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        cout <<"\n\t"<< x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        cout <<"\n\t"<< x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        cout <<"\n\t"<< x << " / " << y << " is " << x / y << '\n';
        break;
    default: // Being robust means handling unexpected parameters as well, even though getOperator() guarantees op is valid in this particular program
        cerr << "\n\n\t SOMETHING WENT WRONG CALCULATOR GOT AN INVALID OPERATOR PLEASE TRY AGAIN.\n";
    }
}

int main()
{
    while(gameover==true)
    {
        system("cls");
       double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);
    string gh;
    cout << "\n\n\tPRESS X TO CLOSE APPLICATION\n\n\t ANY OTHER KEY TO USE CALCULATOR AGAIN: \n\t";
    cin >> gh;
    cin.ignore(100,'\n');
    if(gh=="x"||gh=="X")
    {
        gameover=false;
    }

    }


    return 0;
}

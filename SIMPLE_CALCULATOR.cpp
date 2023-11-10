#include <iostream>
using namespace std;

int main()
{
    cout << "Enter First Number\n ";
    double first_no, second_no;
    cin >> first_no;
    cout << "Enter Second Number\n ";
    cin >> second_no;
    cout << "Enter An Operator (+,-,*,/) To Perform An OPeration\n";
    char op;
    cin >> op;
    switch (op)
    {
    case '+':
    {

        double sum = first_no + second_no;
        cout << "Addition Of Two Numbers Is: " << sum;
        break;
    }
    case '-':
    {
        double sub = first_no - second_no;
        cout << "Subtraction Of Two Numbers Is: " << sub;
        break;
    }
    case '*':
    {
        double multiply = first_no * second_no;
        cout << "Multiplication Of Two Numbers is: " << multiply;
        break;
    }
    case '/':
    {
        double divide = first_no / second_no;
        cout << "Division Of Two Numbers Is: " << divide;
        break;
    }

    default:
    {
        cout << "You Enter An Invalid Operator";
    }

    break;
    }
}
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int guess_no = 0;
    int random_no;
    cout << "\t\t\t\t\t\t-------------- YOUR WELCOME - NUMBER GUESSING GAME -------------- \n";
    cout << "\n\t\t\t\t\t\t\t\t       GUESS A NUMBER \n";
    srand(time(NULL));
    random_no = rand() % 100;

    do
    {

        cout << "Enter an integer number \n";
        cin >> guess_no;

        if (guess_no <= (random_no - 10))
        {
            cout << " Your guess Is Too Low , Try again\n ";
        }
        else if (guess_no >= (random_no + 10))
        {
            cout << " Your Guess Is Too High ,Try Again\n";
        }
        else if (guess_no > random_no)
        {
            cout << " Your Guess Is High  ,Try Again\n";
        }
        else if (guess_no < random_no)
        {
            cout << " Your Guess Is Low ,Try Again\n";
        }
        if (guess_no == random_no)
        {

            cout << " Congratulations!!! You Guess The Number, You Won The Game\n";
            break;
        }
    } while (guess_no != random_no);
}

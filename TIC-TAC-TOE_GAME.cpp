#include <iostream>
using namespace std;

int row, coloumn;
char turn = 'x';
string player1, player2;
int input;
bool draw = false;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void display()
{
    system("CLS");
    cout << "\n\n\t\tTIC-TAC-TOE GAME\n\n\n";
    cout << "    |    |    \n";
    cout << " " << board[0][0] << "  | " << board[0][1] << "  | " << board[0][2] << "  \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << " " << board[1][0] << "  | " << board[1][1] << "  | " << board[1][2] << "  \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << " " << board[2][0] << "  | " << board[2][1] << "  | " << board[2][2] << "  \n";
    cout << "    |    |    \n";
}

void location()
{
    cout << "Enter a digit from 1-9\n";
    if (turn == 'x')
    {
        cout << player1 << "'s turn: ";
    }
    if (turn == 'o')
    {
        cout << player2 << "'s turn: ";
    }
    cin >> input;
    if (input == 1)
    {
        row = 0;
        coloumn = 0;
    }
    if (input == 2)
    {
        row = 0;
        coloumn = 1;
    }
    if (input == 3)
    {
        row = 0;
        coloumn = 2;
    }
    if (input == 4)
    {
        row = 1;
        coloumn = 0;
    }
    if (input == 5)
    {
        row = 1;
        coloumn = 1;
    }
    if (input == 6)
    {
        row = 1;
        coloumn = 2;
    }
    if (input == 7)
    {
        row = 2;
        coloumn = 0;
    }
    if (input == 8)
    {
        row = 2;
        coloumn = 1;
    }
    if (input == 9)
    {
        row = 2;
        coloumn = 2;
    }
    else
    {
        cout << "Invalid Move!!\n";
    }
    if (turn == 'x' && board[row][coloumn] != 'x' && board[row][coloumn] != 'o')
    {
        board[row][coloumn] = 'x';
        turn = 'o';
    }
    else if (turn == 'o' && board[row][coloumn] != 'x' && board[row][coloumn] != 'o')
    {
        board[row][coloumn] = 'o';
        turn = 'x';
    }
    else
    {
        cout << "Box Already Filled!!\nPlease Choose Another\n";
        location();
    }
    display();
}

bool checkwin()
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) || (board[0][i] == board[1][i] && board[0][i] == board[2][i]))
        {
            return true;
        }
    }
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
    {
        return true;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'x' && board[i][j] != 'o')
                return false;
        }
    }
    draw = true;
    return true;
}

int main()
{
    cout << "Enter the name of First player: ";
    cin >> player1;
    cout << "\nEnter the name of Second player: ";
    cin >> player2;
    while (!checkwin())
    {
        display();
        location();
    }
    if (turn == 'o' && draw == false)
    {
        cout << "Congratulations!! " << player1 << " has won the Game";
    }
    else if (turn == 'x' && draw == false)
    {
        cout << "Congratulations!! " << player2 << " has won the Game";
    }
    else
    {
        cout << "Game Draw";
    }
    return 0;
}

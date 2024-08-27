// Tic-Tac-Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <time.h>

using namespace std;

// A simple program to demonstrate 
// Tic-Tac-Toe Game. (hell on earth edition)

class GFG // Great *** Game
{
private:
    static GFG* instance;

    char board[3][3];
    int turns;

    GFG()
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = '1' + (i*3 + j); // 49 + (i*3 + j) works as well

        turns = 9;
        srand(time(NULL)); // Randomize the random seed generator ... to create random numbers during each program start for rand
    }

    char getTurn() { return (turns % 2) ? 'X' : 'O'; }

    int NumOfCharsInString(const char* str, char ch, int length)
    {
        int CharNum = 0;
        for (int i = 0; i < length; i++)
            if (str[i] == ch)
                CharNum++;

        return CharNum;
    }

    // CheckWinner method will 
    // decide the combination 
    // of three box given below.
    char checkWinner()
    {
        char line[3] = {};
        for (int a = 0; a < 8; a++) {

            switch (a) {
            case 0:
                line[0] = board[0][0];
                line[1] = board[0][1];
                line[2] = board[0][2];
                break;
            case 1:
                line[0] = board[1][0];
                line[1] = board[1][1];
                line[2] = board[1][2];
                break;
            case 2:
                line[0] = board[2][0];
                line[1] = board[2][1];
                line[2] = board[2][2];
                break;
            case 3:
                line[0] = board[0][0];
                line[1] = board[1][0];
                line[2] = board[2][0];
                break;
            case 4:
                line[0] = board[0][1];
                line[1] = board[1][1];
                line[2] = board[2][1];
                break;
            case 5:
                line[0] = board[0][2];
                line[1] = board[1][2];
                line[2] = board[2][2];
                break;
            case 6:
                line[0] = board[0][0];
                line[1] = board[1][1];
                line[2] = board[2][2];
                break;
            case 7:
                line[0] = board[0][2];
                line[1] = board[1][1];
                line[2] = board[2][0];
                break;
            }

            //For X winner
            if (memcmp(line, "XXX", 3) == 0)
            {
                // For winner -to display Congratulations! message.
                cout << "Congratulations! " << 'X' << "'s have won! Thanks for playing." << endl;
                return 'X';
            }
            // For O winner
            else if (memcmp(line, "OOO", 3) == 0)
            {
                // For winner -to display Congratulations! message.
                cout << "Congratulations! " << 'O' << "'s have won! Thanks for playing." << endl;
                return 'O';
            }
        }
        //delete[]& line;

        /*
        for (int a = 0; a < 9; a++) { // WTF IS THIS?????
            if (Arrays.asList(board).contains(
                String.valueOf(a + 1))) {
                break;
            }
            else if (a == 8){
                return 'd';
                }
        }
        */

        if (turns == 0)
        {
            // If no one win or lose from both player x and O.
            // then here is the logic to print "draw".
            cout << "It's a draw! Thanks for playing." << endl;
            return 'd';
        }

        // To enter the X Or O at the exact place on board.
        char turn = getTurn();
        cout << turn << "'s turn" << endl << "enter a slot number to place " << turn << " in:" << endl;
        return 'n';
    }

    int CheckToWin()
    {
        cout << "win selected" << endl;
        char line[3] = {};
        for (int a = 0; a < 8; a++)
        {
            switch (a) {
            case 0:
                line[0] = board[0][0];
                line[1] = board[0][1];
                line[2] = board[0][2];
                break;
            case 1:
                line[0] = board[1][0];
                line[1] = board[1][1];
                line[2] = board[1][2];
                break;
            case 2:
                line[0] = board[2][0];
                line[1] = board[2][1];
                line[2] = board[2][2];
                break;
            case 3:
                line[0] = board[0][0];
                line[1] = board[1][0];
                line[2] = board[2][0];
                break;
            case 4:
                line[0] = board[0][1];
                line[1] = board[1][1];
                line[2] = board[2][1];
                break;
            case 5:
                line[0] = board[0][2];
                line[1] = board[1][2];
                line[2] = board[2][2];
                break;
            case 6:
                line[0] = board[0][0];
                line[1] = board[1][1];
                line[2] = board[2][2];
                break;
            case 7:
                line[0] = board[0][2];
                line[1] = board[1][1];
                line[2] = board[2][0];
                break;
            }

            if (NumOfCharsInString(line, 'X', 3) == 0 && NumOfCharsInString(line, 'O', 3) == 2)
            {
                for (int i = 0; i < 3; i++)
                    if (line[i] != 'O')
                        return line[i] - '0'; // line[i]-48 works as well
            }
        }

        return CheckToBlockPlayerFromWinning();
    }

    int CheckToBlockPlayerFromWinning()
    {
        cout << "block selected" << endl;
        char line[3] = {};
        for (int a = 0; a < 8; a++)
        {
            switch (a) {
            case 0:
                line[0] = board[0][0];
                line[1] = board[0][1];
                line[2] = board[0][2];
                break;
            case 1:
                line[0] = board[1][0];
                line[1] = board[1][1];
                line[2] = board[1][2];
                break;
            case 2:
                line[0] = board[2][0];
                line[1] = board[2][1];
                line[2] = board[2][2];
                break;
            case 3:
                line[0] = board[0][0];
                line[1] = board[1][0];
                line[2] = board[2][0];
                break;
            case 4:
                line[0] = board[0][1];
                line[1] = board[1][1];
                line[2] = board[2][1];
                break;
            case 5:
                line[0] = board[0][2];
                line[1] = board[1][2];
                line[2] = board[2][2];
                break;
            case 6:
                line[0] = board[0][0];
                line[1] = board[1][1];
                line[2] = board[2][2];
                break;
            case 7:
                line[0] = board[0][2];
                line[1] = board[1][1];
                line[2] = board[2][0];
                break;
            }

            if (NumOfCharsInString(line, 'X', 3) == 2 && NumOfCharsInString(line, 'O', 3) == 0)
            {
                for (int i = 0; i < 3; i++)
                    if (line[i] != 'X')
                        return line[i] - '0'; // line[i]-48 works as well
            }
        }

        int counter;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == '1' + (i*3 + j))
                {
                    counter = 0;
                    switch (board[i][j])
                    {
                    case '1':
                        if ((board[0][1] == '2' && board[0][2] == 'X') || (board[0][1] == 'X' && board[0][2] == '3'))
                            counter++;
                        if ((board[1][0] == '4' && board[2][0] == 'X') || (board[1][0] == 'X' && board[2][0] == '7'))
                            counter++;
                        if ((board[1][1] == '5' && board[2][2] == 'X') || (board[1][1] == 'X' && board[2][2] == '9'))
                            counter++;
                        break;
                    case '2':
                        if ((board[0][0] == '1' && board[0][2] == 'X') || (board[0][0] == 'X' && board[0][2] == '3'))
                            counter++;
                        if ((board[1][1] == '5' && board[2][1] == 'X') || (board[1][1] == 'X' && board[2][1] == '8'))
                            counter++;
                        break;
                    case '3':
                        if ((board[0][0] == '1' && board[0][1] == 'X') || (board[0][0] == 'X' && board[0][1] == '2'))
                            counter++;
                        if ((board[1][2] == '6' && board[2][2] == 'X') || (board[1][2] == 'X' && board[2][2] == '9'))
                            counter++;
                        if ((board[1][1] == '5' && board[2][0] == 'X') || (board[1][1] == 'X' && board[2][0] == '7'))
                            counter++;
                        break;
                    case '4':
                        if ((board[0][0] == '1' && board[2][0] == 'X') || (board[0][0] == 'X' && board[2][0] == '7'))
                            counter++;
                        if ((board[1][1] == '5' && board[1][2] == 'X') || (board[1][1] == 'X' && board[1][2] == '6'))
                            counter++;
                        break;
                    case '5':
                        if ((board[0][1] == '2' && board[2][1] == 'X') || (board[0][1] == 'X' && board[2][1] == '8'))
                            counter++;
                        if ((board[1][0] == '4' && board[1][2] == 'X') || (board[1][0] == 'X' && board[1][2] == '6'))
                            counter++;
                        break;
                    case '6':
                        if ((board[1][0] == '4' && board[1][1] == 'X') || (board[1][0] == 'X' && board[1][1] == '5'))
                            counter++;
                        if ((board[0][2] == '3' && board[2][2] == 'X') || (board[0][2] == 'X' && board[2][2] == '9'))
                            counter++;
                        break;
                    case '7':
                        if ((board[0][0] == '1' && board[1][0] == 'X') || (board[0][0] == 'X' && board[1][0] == '4'))
                            counter++;
                        if ((board[1][1] == '5' && board[0][2] == 'X') || (board[1][1] == 'X' && board[0][2] == '3'))
                            counter++;
                        if ((board[2][1] == '8' && board[2][2] == 'X') || (board[2][1] == 'X' && board[2][2] == '9'))
                            counter++;
                        break;
                    case '8':
                        if ((board[0][1] == '2' && board[1][1] == 'X') || (board[0][1] == 'X' && board[1][1] == '5'))
                            counter++;
                        if ((board[2][0] == '7' && board[2][2] == 'X') || (board[2][0] == 'X' && board[2][2] == '9'))
                            counter++;
                        break;
                    case '9':
                        if ((board[0][0] == '1' && board[1][1] == 'X') || (board[0][0] == 'X' && board[1][1] == '5'))
                            counter++;
                        if ((board[0][2] == '3' && board[1][2] == 'X') || (board[0][2] == 'X' && board[1][2] == '6'))
                            counter++;
                        if ((board[2][0] == '7' && board[2][1] == 'X') || (board[2][0] == 'X' && board[2][1] == '8'))
                            counter++;
                        break;
                    default:
                        break;
                    }

                    if (counter > 1)
                        return board[i][j] - '0';
                }

        return CheckToCreateStrategy();
    }
    
    int CheckToCreateStrategy()
    {
        int counter;
        cout << "strategy selected" << endl;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == '1' + (i*3 + j))
                {
                    counter = 0;
                    switch (board[i][j])
                    {
                    case '1':
                        if ((board[0][1] == '2' && board[0][2] == 'O') || (board[0][1] == 'O' && board[0][2] == '3'))
                            counter++;
                        if ((board[1][0] == '4' && board[2][0] == 'O') || (board[1][0] == 'O' && board[2][0] == '7'))
                            counter++;
                        if ((board[1][1] == '5' && board[2][2] == 'O') || (board[1][1] == 'O' && board[2][2] == '9'))
                            counter++;
                        break;
                    case '2':
                        if ((board[0][0] == '1' && board[0][2] == 'O') || (board[0][0] == 'O' && board[0][2] == '3'))
                            counter++;
                        if ((board[1][1] == '5' && board[2][1] == 'O') || (board[1][1] == 'O' && board[2][1] == '8'))
                            counter++;
                        break;
                    case '3':
                        if ((board[0][0] == '1' && board[0][1] == 'O') || (board[0][0] == 'O' && board[0][1] == '2'))
                            counter++;
                        if ((board[1][2] == '6' && board[2][2] == 'O') || (board[1][2] == 'O' && board[2][2] == '9'))
                            counter++;
                        if ((board[1][1] == '5' && board[2][0] == 'O') || (board[1][1] == 'O' && board[2][0] == '7'))
                            counter++;
                        break;
                    case '4':
                        if ((board[0][0] == '1' && board[2][0] == 'O') || (board[0][0] == 'O' && board[2][0] == '7'))
                            counter++;
                        if ((board[1][1] == '5' && board[1][2] == 'O') || (board[1][1] == 'O' && board[1][2] == '6'))
                            counter++;
                        break;
                    case '5':
                        if ((board[0][1] == '2' && board[2][1] == 'O') || (board[0][1] == 'O' && board[2][1] == '8'))
                            counter++;
                        if ((board[1][0] == '4' && board[1][2] == 'O') || (board[1][0] == 'O' && board[1][2] == '6'))
                            counter++;
                        break;
                    case '6':
                        if ((board[1][0] == '4' && board[1][1] == 'O') || (board[1][0] == 'O' && board[1][1] == '5'))
                            counter++;
                        if ((board[0][2] == '3' && board[2][2] == 'O') || (board[0][2] == 'O' && board[2][2] == '9'))
                            counter++;
                        break;
                    case '7':
                        if ((board[0][0] == '1' && board[1][0] == 'O') || (board[0][0] == 'O' && board[1][0] == '4'))
                            counter++;
                        if ((board[1][1] == '5' && board[0][2] == 'O') || (board[1][1] == 'O' && board[0][2] == '3'))
                            counter++;
                        if ((board[2][1] == '8' && board[2][2] == 'O') || (board[2][1] == 'O' && board[2][2] == '9'))
                            counter++;
                        break;
                    case '8':
                        if ((board[0][1] == '2' && board[1][1] == 'O') || (board[0][1] == 'O' && board[1][1] == '5'))
                            counter++;
                        if ((board[2][0] == '7' && board[2][2] == 'O') || (board[2][0] == 'O' && board[2][2] == '9'))
                            counter++;
                        break;
                    case '9':
                        if ((board[0][0] == '1' && board[1][1] == 'O') || (board[0][0] == 'O' && board[1][1] == '5'))
                            counter++;
                        if ((board[0][2] == '3' && board[1][2] == 'O') || (board[0][2] == 'O' && board[1][2] == '6'))
                            counter++;
                        if ((board[2][0] == '7' && board[2][1] == 'O') || (board[2][0] == 'O' && board[2][1] == '8'))
                            counter++;
                        break;
                    default:
                        break;
                    }

                    if (counter > 1)
                        return board[i][j] - '0';
                }

        return CheckToProgress();
    }

    int CheckToProgress()
    {
        cout << "progress selected" << endl;
        char line[3] = {};
        for (int a = 0; a < 8; a++)
        {
            switch (a) {
            case 0:
                line[0] = board[0][0];
                line[1] = board[0][1];
                line[2] = board[0][2];
                break;
            case 1:
                line[0] = board[1][0];
                line[1] = board[1][1];
                line[2] = board[1][2];
                break;
            case 2:
                line[0] = board[2][0];
                line[1] = board[2][1];
                line[2] = board[2][2];
                break;
            case 3:
                line[0] = board[0][0];
                line[1] = board[1][0];
                line[2] = board[2][0];
                break;
            case 4:
                line[0] = board[0][1];
                line[1] = board[1][1];
                line[2] = board[2][1];
                break;
            case 5:
                line[0] = board[0][2];
                line[1] = board[1][2];
                line[2] = board[2][2];
                break;
            case 6:
                line[0] = board[0][0];
                line[1] = board[1][1];
                line[2] = board[2][2];
                break;
            case 7:
                line[0] = board[0][2];
                line[1] = board[1][1];
                line[2] = board[2][0];
                break;
            }

            if (NumOfCharsInString(line, 'X', 3) == 0 && NumOfCharsInString(line, 'O', 3) > 0)
            {
                for (int i = 0; i < 3; i++)
                    if (line[i] != 'O')
                        return line[i] - '0'; // line[i] - 48
            }
        }

        return ChooseFreeSpace();
    }

    int ChooseFreeSpace() // No strategy is usable .... just place figure in a free space
    {
        cout << "random selected" << endl;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == '1' + (i*3 + j))
                    return 1 + (i*3 + j);

        return 0; // ERROR (this never returns, it's here to calm down the compiler)
    }

    // To print out the board.
    /* |---|---|---|
       | 1 | 2 | 3 |
       |-----------|
       | 4 | 5 | 6 |
       |-----------|
       | 7 | 8 | 9 |
       |---|---|---|*/

    void printBoard()
    {
        cout << "|---|---|---|" << endl;
        cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << endl;
        cout << "|-----------|" << endl;
        cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << endl;
        cout << "|-----------|" << endl;
        cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << endl;
        cout << "|---|---|---|" << endl;
    }

    char updateBoard(const int& pos)
    {
        int x = pos / 3;
        int y = pos % 3;

        //char value = 48+pos;
        if (board[x][y] == '1' + pos) // same as 49+pos
        {
            board[x][y] = getTurn();
            turns--;
            printBoard();
            return checkWinner();
        }
        else
        {
            cout << "Slot " << pos << " already taken; re-enter slot number:" << endl;
            return 'n';
        }
    }

public:
    static GFG* get_instance()
    {
        if (instance == nullptr)
            instance = new GFG();

        return instance;
    }
    ~GFG() { delete instance; }
    GFG(const GFG& other) = delete;
    void operator=(const GFG&) = delete;

    void play()
    {
        cout << "Welcome to 3x3 Tic-Tac-Toe." << endl;
        printBoard();

        char turn = getTurn();
        cout << turn << " will play first. Enter a slot number to place " << turn << " in:" << endl;

        int numInput = 0;
        do
        {
            if (getTurn() == 'X') // Player is playing
            {
                // Exception handling.
                // numInput will take input from user like from 1 to 9.
                // If it is not in range from 1 to 9.
                // then it will show you an error "Invalid input."
                try
                {
                    cin >> numInput;
                    if (!(numInput > 0 && numInput <= 9))
                    {
                        cout << "Invalid input; re-enter slot number:" << endl;
                        continue;
                    }
                }
                catch (exception e)
                {
                    cout << e.what() << " caught; re-enter slot number:" << endl;
                    continue;
                }
            }
            else // BOT is playing
            {
                this_thread::sleep_for(3000ms); // Make a bot 'thinking' sequence by waiting a bit, heh
                if (turns == 8) // first round -- important to define strategy and to make sure the bot doest lose the game
                {
                    if (board[1][1] == 'X') // the bot will play either in the center or in some of the corners --- so it wouldnt lose (otherwise a lose is possible no matter how well the bot thinks ... tic-tak-toe is just like that, cant help it)
                        switch (rand() % 4)
                        {
                        case 0:
                            numInput = 1;
                            break;
                        case 1:
                            numInput = 3;
                            break;
                        case 2:
                            numInput = 7;
                            break;
                        case 3:
                            numInput = 9;
                            break;
                        default:
                            break;
                        }
                    else
                        numInput = 5;
                }
                else if (turns == 6) // second round -- important to block some pre-defined winning strategies (again, it's just the way tic-tac-toe works, pre-win is possible)
                {
                    if (board[0][0] != '1' && board[1][1] != 'O' && board[2][2] != '9') // block winning strategy
                    {
                        switch (rand() % 2)
                        {
                        case 0:
                            numInput = 3;
                            break;
                        case 1:
                            numInput = 7;
                            break;
                        default:
                            break;
                        }
                    }
                    else if (board[0][2] != '3' && board[1][1] != 'O' && board[2][0] != '7') // block another winning strategy
                        switch (rand() % 2)
                        {
                        case 0:
                            numInput = 1;
                            break;
                        case 1:
                            numInput = 9;
                            break;
                        default:
                            break;
                        }
                    else if (board[0][0] != '1' && board[1][1] == 'O' && board[2][2] != '9' || board[0][2] != '3' && board[1][1] == 'O' && board[2][0] != '7') // block yet another winning strategy
                        switch (rand() % 4)
                        {
                        case 0:
                            numInput = 2;
                            break;
                        case 1:
                            numInput = 4;
                            break;
                        case 2:
                            numInput = 6;
                            break;
                        case 3:
                            numInput = 8;
                            break;
                        default:
                            break;
                        }
                    /*else if (board[0][1] == 'X' && board[1][0] == 'X' || board[0][1] == 'X' && board[1][2] == 'X') // block strategy yeeet
                        switch (rand() % 3)
                        {
                        case 0:
                            numInput = 1;
                            break;
                        case 1:
                            numInput = 3;
                            break;
                        default:
                            break;
                        }
                    else if (board[1][2] == 'X' && board[2][1] == 'X' || board[1][0] == 'X' && board[2][1] == 'X') // againe
                        switch (rand() % 2)
                        {
                        case 0:
                            numInput = 7;
                            break;
                        case 1:
                            numInput = 9;
                            break;
                        default:
                            break;
                        }*/
                    else // no player winning strategies detected ---- place figure based on bot strategies
                        numInput = CheckToBlockPlayerFromWinning();
                }
                else
                    numInput = CheckToWin(); // BOT strategies
            }

            // This game has two player x and O.
            // Here is the logic to decide the turn.
        } while (updateBoard(numInput - 1) == 'n');
    }
};
GFG* GFG::instance = nullptr;

int main()
{
    GFG* game = GFG::get_instance();
    game->play();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

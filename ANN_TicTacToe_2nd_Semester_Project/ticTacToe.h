#include <iostream>
#include <vector>
#include <iomanip>
#define X 1.0
#define O 0.5
#define _blank 0.01
class TicTac
{
private:
    std::vector<double> board;

public:
    TicTac()
    { // filling vecotr with _blank
        for (int i = 0; i < 9; i++)
        {
            board.push_back(_blank);
        }
    }
    void displayBoard()
    { // fucntion to display overall updated gameboard each time
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout<<" ";
                if (this->at(i, j) == X)
                    std::cout << " X ";
                else if (this->at(i, j) == O)
                    std::cout << " O ";
                else
                    std::cout <<"<"<<(i*3)+j+1<<">";
                if (j != 2)
                    std::cout << std::setw(6) << "|" << std::setw(6);
            }

            if (i != 2)
                std::cout << "\n\n+----------------------------------+\n";
            std::cout << std::endl;
        }
    }
    double evaluate()
    {
        /*funciton to check accross horizontal, vertical and diagonal cells
        whether the player has won or not*/

        // checking diagonal cells
        if ((at(0, 0) == this->at(1, 1) && this->at(0, 0) == this->at(2, 2)) || (at(0, 2) == this->at(1, 1) && this->at(0, 2) == this->at(2, 0)) && this->at(1, 1) != _blank)
            return this->at(1, 1);
        for (int i = 0; i < 3; i++)
        {
            // checking horizontaly
            if (at(i, 0) == this->at(i, 1) && at(i, 1) == this->at(i, 2) && this->at(i, 0) != _blank)
            {
                return this->at(i, 1);
            }
            // checking vertically
            else if (at(0, i) == this->at(1, i) && this->at(0, i) == this->at(2, i) && this->at(1, i) != _blank)
                return this->at(0, i);
        }
        return -101;
    }
    double &setBoard(int index)
    { /*funciton that returns refernce of board
     at a particular index in 1D*/
        return board.at(index);
    }
    double at(int row, int col)
    {
        // As 1D vector is used instead of 2D so, 2D index are
        // converted in 1D by formula [row*rowSize+column]
        return board.at((row * 3) + col);
    }
    double at(int index)
    {
        // As 1D vector is used instead of 2D so, 2D index are
        // converted in 1D by formula [row*rowSize+column]
        return board.at(index);
    }
    bool draw()
    { 
        /*funciton that returns true if game is draw
        else returns false*/
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                if (this->at(i, j) == _blank)
                    return false;
        }
        return true;
    }
    bool isEmpty(int x)
    {
        /*function to check is the cell
        at provided index is blank or not*/
        if (this->board.at(x) != _blank)
            return true;
        else
            return false;
    }
    void clearBoard(){
        for(int i=0;i<9;i++)
        this->board.at(i)=_blank;
    }
};
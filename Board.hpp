#include <iostream>

enum Player { UNPLAYED=0, PlayerA, PlayerB };

class Board
{
    public:
      Board()
      {
          board = new int[7*6]();

          this->width = 7;
          this->height = 6;
      }

      Board(int width, int height)
      {
          board = new int[width*height]();
          this->width = width;
          this->height = height;
      }

      ~Board()
      {
          delete board;
      }

      /*
        Plays a game piece and determines if that piece won the game
        Input: 
          Player p (enum) - the player playing the game piece
          Column c (int) - next column to play a game piece
        Output: 
          bool - whether this game piece is a win
       */
      bool playPiece( Player p, int col)
      {
          // Check if play is inbounds or if the column is full
          if (col >= width || col < 0 || checkLocation(height - 1, col) != UNPLAYED)
            return false;

          // Find the next row a piece can be played
          int y = -1;
          while (checkLocation(++y, col) != UNPLAYED);
          setPiece(p, y, col);

          // Check directions for a win condition

          // No need to check up because there are no pieces above
          // if (checkWin(p, y+1, col, 0, 1) == 3) return true;

          // Check down
          if (checkWin(p, y-1, col, -1, 0) == 3) return true;

          // Check sum of horizontal
          if ((checkWin(p, y, col+1, 0, 1) + checkWin(p, y, col-1, 0, -1)) >= 3) return true;

          // Check sum of Diagonal
          if (checkWin(p, y-1, col+1, -1, 1) + checkWin(p, y+1, col-1, 1, -1) >= 3) return true;
          if (checkWin(p, y-1, col-1, -1, -1) + checkWin(p, y+1, col+1, 1, 1) >= 3) return true;

          return false;
      }

      /*
        Prints the game board to the output stream provided
       */
      void printBoard(std::ostream& stream)
      {
          for (int x = height - 1; x >= 0; x--)
          {
              for (int y = 0; y < width; y++)
              {
                  stream << "|";
                  if (checkLocation(x, y) == PlayerA)
                      stream << "A";
                  else if (checkLocation(x, y) == PlayerB)
                      stream << "B";
                  else
                      stream << " ";
              }
              stream << "|" << std::endl;
          }
          stream << std::endl;
      }

    protected:
      Player checkLocation(int row, int col) { return static_cast<Player>(board[width * col + row]); }

      void setPiece(Player p, int row, int col) {  board[width * col + row] = p; }

      /*
        Recursive check for win
        Input: 
          Player p (enum) - the player playing the game piece
          int x,y - the current location to check
          int dirX,dirY - the direction to continue checking for a win
        Output: 
          int - how many pieces have been found
       */
      int checkWin( Player p, int x, int y, int dirX, int dirY)
      {
          if (x >= width || x < 0 || y >= height || y < 0)
              return 0;
          else if (checkLocation(x, y) == p)
              return checkWin(p, x+dirX, y+dirY, dirX, dirY) + 1;
          else
              return 0;
      }

    private:
      int height;
      int width;

      // 2D array stored as a 1D arrary
      int* board;
};
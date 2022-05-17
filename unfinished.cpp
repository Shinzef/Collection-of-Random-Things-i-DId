#include <iostream>
#include <vector>

char chessboard[8][8];


int turns = 0;
int black_score = 0;
int white_score = 0;


void createBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0) // white
			{
				chessboard[i][j] = static_cast<char>(254u);
			}
			else // black
			{
				chessboard[i][j] = static_cast<char>(255u);
			}

			// put all the pawns

			if (i == 1)
			{
				chessboard[i][j] = 'P';
			}
			else if (i == 6)
			{
				chessboard[i][j] = 'p';
			}
			
		}
	}
}

void turn()
{
	if ( turns % 2 == 0)
	{
		std::cout << "its white turns\n";
		turns++;
	}
	else
	{
		std::cout << "its black turns\n";
		turns++;
	}
}

bool validateMove(int x, int y, int x_new, int y_new)
{
	// check what kind of piece is there
	char piece = chessboard[x-1][y];
	std::cout << "Piece: " << piece << std::endl;

	x = x - 1;
	x_new = x_new - 1;

	char topright = chessboard[x_new - 1][y_new + 1];
	char topleft = chessboard[x_new - 1][y_new - 1];
	char bottomright = chessboard[x_new + 1][y_new + 1];
	char bottomleft = chessboard[x_new + 1][y_new - 1];

	std::cout << "Bottom left: " << bottomleft << std::endl;
	std::cout << "Bottom right: " << bottomright << std::endl;
	std::cout << "Top left: " << topleft << std::endl;
	std::cout << "Top right: " << topright << std::endl;

	std::cout << piece;

	switch (piece)
	{
		case 'P': // pawn
		{
			if (x == 1)
			{
				std::cout << "This is a starting piece\n";
				if (abs(x - x_new) > 2)
				{
					std::cout << "This move is sus\n";
					chessboard[x][y] = chessboard[x_new][y_new];
					return false;
				}

				if (y_new != y)
				{
					std::cout << "This move is sus\n";
					chessboard[x][y] = chessboard[x_new][y_new];
					return false;
				}
			}
			else
			{
				if (abs(x - x_new) > 1)
				{
					std::cout << "This move is sus\n";
					chessboard[x][y] = chessboard[x_new][y_new];
					return false;
				}

			
				if (chessboard[x_new][y_new] != static_cast<char>(255u) || chessboard[x_new][y_new] != static_cast<char>(254u))
				{
					std::cout << "This move is sus\n";
					chessboard[x][y] = chessboard[x_new][y_new];
					return false;
				}

				if (topleft == 'P')
				{
					std::cout << "This move is sus\n";
				}
			} 
		} break;
		case 'p': // black pawn
		{
			if (x == 6)
			{
				std::cout << "This is a starting piece\n";
				if (abs(x - x_new) > 2)
				{
					std::cout << "This move is sus\n";
					chessboard[x][y] = chessboard[x_new][y_new];
					return false;
				}

				if (y_new != y)
				{
					std::cout << "This move is sus\n";
					chessboard[x][y] = chessboard[x_new][y_new];
					return false;
				}
			}
			else
			{
				if (abs(x - x_new) > 1)
				{
					std::cout << "This move is sus\n";
					chessboard[x][y] = chessboard[x_new][y_new];
					return false;
				}





				if (y_new != y)
				{
					std::cout << "This move is sus\n";
					chessboard[x][y] = chessboard[x_new][y_new];
					return false;
				}
				
				
			}
		} break;
		
	}



	
	

	return true;
}

void movePiece()
{
	turn();


	std::cout << "Enter the piece you want to move: ";
	char x;
	int y;
	std::cin >> x >> y;

	int x_pos;
	// convert char into int
	switch (x)
	{
		case 'A':
			x_pos = 0;
			break;
		case 'B':
			x_pos = 1;
			break;
		case 'C':
			x_pos = 2;
			break;
		case 'D':
			x_pos = 3;
			break;
		case 'E':
			x_pos = 4;
			break;
		case 'F':
			x_pos = 5;
			break;
		case 'G':
			x_pos = 6;
			break;
		case 'H':
			x_pos = 7;
			break;
		default:
			std::cout << "Invalid input" << std::endl;
			return;
	}

	std::cout << y-1 << x_pos << std::endl;

	std::cout << "Enter the new position: ";
	char x_new;
	int y_new;
	std::cin >> x_new >> y_new;

	int x_pos_new;
	switch ( x_new )
	{
		case 'A':
			x_pos_new = 0;
			break;
		case 'B':
			x_pos_new = 1;
			break;
		case 'C':
			x_pos_new = 2;
			break;
		case 'D':
			x_pos_new = 3;
			break;
		case 'E':
			x_pos_new = 4;
			break;
		case 'F':
			x_pos_new = 5;
			break;
		case 'G':
			x_pos_new = 6;
			break;
		case 'H':
			x_pos_new = 7;
			break;
	}
	

	std::cout << y_new - 1 << x_pos_new << std::endl;
	char last = chessboard[y_new - 1][x_pos_new];

	// change the position
	chessboard[y_new - 1][x_pos_new] = chessboard[y - 1][x_pos];
	bool valid = validateMove(y, x_pos, y_new, x_pos_new);

	// remove the old position

	char replacement;
	
	if (valid == true)
	{
		if ((y - 1 + x_pos) % 2 == 0)
		{
			replacement = static_cast<char>(254u);
		}
		else
		{
			replacement = static_cast<char>(255u);
		}
		chessboard[y - 1][x_pos] = replacement;
	}
	else
	{
		chessboard[y_new - 1][x_pos_new] = last;
	}

	std::cout << "Black score: " << black_score << " White score: " << white_score << std::endl;
}

void printBoard()
{
	std::cout << "A B C D E F G H" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			std::cout << chessboard[i][j] << " ";

		}
		std::cout << i + 1 << std::endl;
	}
}



int main()
{
	createBoard();
	printBoard();

	while (true)
	{
		movePiece();
		printBoard();

		

	}
}

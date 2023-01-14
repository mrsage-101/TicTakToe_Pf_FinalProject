#include<iostream>
#include<iomanip>
using namespace std;
void draw_board(int&, int&, char[][20]);
void enter_board(char&, char[][20]);
bool have_won(char[][20], int&, int&, char&);
int empty_spaces(int&, int&, char[][20]);
int main()
{
	cout << setw(68) << "=============" << endl;
	cout << setw(67) << "TIC TAC TOE" << endl;
	cout << setw(68) << "=============" << endl;

	system("color f0");

	int rows = 0;
	int columns = 0;
	char arr_board[20][20] = {};
	char player_turn = 'X'; int ch = 0;

	bool won = have_won(arr_board, rows, columns, player_turn);
	bool gameFinished = won || empty_spaces == 0;
	bool is_draw = empty_spaces == 0 && won == false;
	//bool gameFinished = false;

	// entry of rows and columns
	cout << "Enter the number of rows:    ";
	cin >> rows;
	cout << "Enter the number of columns: ";
	cin >> columns;

	// initializing array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			arr_board[i][j] = '1';
		}
	}

	if (rows == columns)
	{
		while (!gameFinished)
		{
			system("cls");
			draw_board(rows, columns, arr_board);
			enter_board(player_turn, arr_board);
			gameFinished = have_won(arr_board, rows, columns, player_turn) || empty_spaces(rows, columns, arr_board) == 0;
			//is_draw = won == false || empty_spaces(rows, columns, arr_board) == 0;
		}
	}
	else
	{
		cout << "Fail! Enter equal number of rows and columns" << endl;
		cout << "Enter the number of rows:    ";
		cin >> rows;
		cout << "Enter the number of columns: ";
		cin >> columns;

		while (!gameFinished)
		{
			system("cls");
			draw_board(rows, columns, arr_board);
			enter_board(player_turn, arr_board);
			gameFinished = have_won(arr_board, rows, columns, player_turn) || empty_spaces(rows, columns, arr_board) == 0;
			//is_draw = won == false || empty_spaces(rows, columns, arr_board) == 0;
		}
	}

	if (player_turn == 'X' && empty_spaces != 0)
	{
		cout << "PLAYER 1 WINS" << endl;
	}
	else if (player_turn == 'O' && empty_spaces != 0)
	{
		cout << "PLAYER 2 WINS" << endl;
	}
	/*else if(is_draw = won == false && empty_spaces == 0)
	{
		cout << "DRAW" << endl;
	}*/

	system("PAUSE");
	return 0;
}
void draw_board(int& ros, int& cols, char a_b[][20])
{
	for (int i = 0; i < ros; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << " | " << a_b[i][j] << " | ";
		}
		cout << endl;
	}
}
void enter_board(char& turn, char arre[][20])
{
	int r = 0; int c = 0;

	if (turn == 'X')
	{
		cout << "Player 1 turn: " << endl;
	}
	else if (turn == 'O')
	{
		cout << "Player 2 turn: " << endl;
	}

	cout << "Enter the row : ";
	cin >> r;
	cout << "Enter the column: ";
	cin >> c;

	if (turn == 'X' && arre[r][c] != 'X' && arre[r][c] != 'O')
	{
		arre[r][c] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && arre[r][c] != 'X' && arre[r][c] != 'O')
	{
		arre[r][c] = 'O';
		turn = 'X';
	}
	else
	{
		cout << "Box at this index is filled !" << endl;
		enter_board(turn, arre);
	}
}
bool have_won(char ar[][20], int& rows, int& columns, char& turn)
{
	// for diagonal up left and down right

	for (int i = 0; i < rows; i++)
	{
		if (ar[i][i] == turn)
		{
			if (i == rows - 1)
			{
				return true;
			}
		}
		else
		{
			break;
		}
	}

	// for diagonal up right and down left

	int j = 0;
	for (int i = rows - 1; i >= 0; i--)
	{
		if (ar[j][i] == turn)
		{
			if (i == 0)
			{
				return true;
			}
		}
		else
		{
			break;
		}
		j++;
	}

	// horizontal

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (ar[i][j] == turn)
			{
				if (j == rows - 1)
				{
					return true;
				}
			}
			else
			{
				break;
			}
		}
	}

	// vertical

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (ar[j][i] == turn)
			{
				if (j == rows - 1)
				{
					return true;
				}
			}
			else
			{
				break;
			}
		}
	}

	return false;
}
int empty_spaces(int& rows, int& columns, char a[][20])
{
	int count = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (a[i][j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}
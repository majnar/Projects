#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

enum direction { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class pBall
{
private:
	// Coordinates for ball, og is for original coordinates
	int xCoord;
	int ogX;
	int yCoord;
	int ogY;
	direction ballDirection;

public:
	pBall(int posX, int posY) // Constructor used to save original position of ball so we can reset
	{
		ogX = posX;
		xCoord = posX;
		ogY = posY;
		yCoord = posY;
		ballDirection = STOP;
	}

	void reset() // Used to reset position of ball
	{
		xCoord = ogX;
		yCoord = ogY;
		ballDirection = STOP;
	}

	void changeBallDirection(direction newDirection) // Changes ball direction
	{
		ballDirection = newDirection;
	}

	void randomDirection() // Makes game more interesting
	{
		ballDirection = (direction)((rand() % 6) + 1); // Generates a random direction based on enum
	}


	inline int getX()
	{
		return xCoord;
	}

	inline int getY()
	{
		return yCoord;
	}

	inline direction getDirection()
	{
		return ballDirection;
	}

	void move()
	{
		// Left & up are - and right & down is + because coordinates start in top left (reversed)
		switch (ballDirection)
		{
		case STOP:
			break;

		case LEFT:
			xCoord--;
			break;

		case RIGHT:
			xCoord++;
			break;

		case UPLEFT:
			xCoord--;
			yCoord--;
			break;

		case DOWNLEFT:
			xCoord--;
			yCoord++;
			break;

		case UPRIGHT:
			xCoord++;
			yCoord--;
			break;

		case DOWNRIGHT:
			xCoord++;
			yCoord--;
			break;

		default:
			break;
		}
	}

	friend ostream& operator << (ostream& obj, pBall p)
	{
		obj << "Ball [" << p.xCoord << "," << p.yCoord << "][" << p.ballDirection << "]";

		return obj;
	}
};

class pPaddle
{
private:
	int xCoord;
	int ogX;
	int yCoord;
	int ogY;

public:
	pPaddle()
	{
		xCoord = 0;
		yCoord = 0;
	}

	pPaddle(int posX, int posY) :pPaddle()
	{
		ogX = posX;
		ogY = posY;
		xCoord = posX;
		yCoord = posY;
	}

	inline void reset()
	{
		xCoord = ogX;
		yCoord = ogY;
	}

	inline int getX()
	{
		return xCoord;
	}

	inline int getY()
	{
		return yCoord;
	}

	inline void moveUp()
	{
		yCoord--;
	}

	inline void moveDown()
	{
		yCoord++;
	}

	friend ostream& operator << (ostream& obj, pPaddle p)
	{
		obj << "Paddle [" << p.xCoord << "," << p.yCoord << "]";

		return obj;
	}
};

class pGameManager
{
private:
	int width;
	int height;
	int p1Score;
	int p2Score;
	char p1Up;
	char p1Down;
	char p2Up;
	char p2Down;
	bool quitGame;
	pBall* ball;
	pPaddle* p1;
	pPaddle* p2;

public:
	pGameManager(int w, int h) // Constructor 
	{
		srand(time(NULL));

		quitGame = false;

		p1Up = 'w';
		p1Down = 's';

		p2Up = 'i';
		p2Down = 'k';

		p1Score = 0;
		p2Score = 0;
		
		width = w;
		height = h;

		ball = new pBall(w / 2, h / 2);

		p1 = new pPaddle(1, h / 2 - 3);
		p2 = new pPaddle(w - 2, h / 2 - 3);
	}

	~pGameManager() // Destructor to free memory of pointers to prevent memory leak
	{
		delete ball;
		delete p1;
		delete p2;
	}

	void scoreInc(pPaddle* player)
	{
		if (player == p1)
		{
			p1Score++;
		}

		else if (player == p2)
		{
			p2Score++;
		}

		ball->reset();
		p1->reset();
		p2->reset();
	}

	void draw()
	{
		/*system("cls");*/
		for (int i = 0; i < width + 2; i++)
		{
			cout << "\xB2";
		}
		cout << endl;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int ballX = ball->getX();
				int ballY = ball->getY();

				int player1X = p1->getX();
				int player1Y = p1->getY();

				int player2X = p2->getX();
				int player2Y = p2->getY();
				
				if (j == 0)
				{
					cout << "\xB2";
				}

				if (ballX == j && ballY == i)
				{
					cout << "O"; // Ball
				}

				else if (player1X == j && player1Y == i)
				{
					cout << "|"; // Player 1 paddle
				}

				else if (player1X == j && player1Y + 1 == i)
				{
					cout << "|"; // Player 1 paddle
				}

				else if (player1X == j && player1Y + 2 == i)
				{
					cout << "|"; // Player 1 paddle
				}

				else if (player1X == j && player1Y + 3 == i)
				{
					cout << "|"; // Player 1 paddle
				}

				else if (player2X == j && player2Y == i)
				{
					cout << "|"; // Player 2 paddle
				}

				else if (player2X == j && player2Y + 1 == i)
				{
					cout << "|"; // Player 2 paddle
				}

				else if (player2X == j && player2Y + 2 == i)
				{
					cout << "|"; // Player 2 paddle
				}

				else if (player2X == j && player2Y + 3 == i)
				{
					cout << "|"; // Player 2 paddle
				}

				else
				{
					cout << " ";
				}

				if (j == width - 1)
				{
					cout << "\xB2";
				}
			}
			cout << endl;
		}

		for (int i = 0; i < width + 2; i++)
		{
			cout << "\xB2";
		}
		cout << endl;

		cout << "Score 1: " << p1Score << endl << "Score 2: " << p2Score << endl;
	}

	void input()
	{
		ball->move();

		int ballX = ball->getX();
		int ballY = ball->getY();

		int player1X = p1->getX();
		int player1Y = p1->getY();

		int player2X = p2->getX();
		int player2Y = p2->getY();

		if (_kbhit()) // If keyboard is pressed
		{
			char current = _getch();

			if (current == p1Up)
			{
				if (player1Y > 0)
				{
					p1->moveUp();
				}
			}

			if (current == p2Up)
			{
				if (player2Y > 0)
				{
					p2->moveUp();
				}
			}

			if (current == p1Down)
			{
				if (player1Y + 4 < height)
				{
					p1->moveDown();
				}
			}

			if (current == p2Down)
			{
				if (player2Y + 4 < height)
				{
					p2->moveDown();
				}
			}

			if (ball->getDirection() == STOP)
			{
				ball->randomDirection();
			}

			if (current == 'q')
			{
				quitGame = true;
			}
		}
	}

	void moveLogic()
	{
		int ballX = ball->getX();
		int ballY = ball->getY();

		int player1X = p1->getX();
		int player1Y = p1->getY();

		int player2X = p2->getX();
		int player2Y = p2->getY();

		// Left player
		for (int i = 0; i < 4; i++)
		{
			if (ballX == player1X + 1)
			{
				if (ballY == player1Y + i)
				{
					ball->changeBallDirection((direction)((rand() % 3) + 4));
				}
			}
		}

		// Right player
		for (int i = 0; i < 4; i++)
		{
			if (ballX == player2X - 1)
			{
				if (ballY == player2Y + i)
				{
					ball->changeBallDirection((direction)((rand() % 3) + 1));
				}
			}
		}

		// Bottom wall
		if (ballY == height - 1)
		{
			ball->changeBallDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
		}

		// Top wall
		if (ballY == 0)
		{
			ball->changeBallDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
		}

		// Right wall
		if (ballX == width - 1)
		{
			scoreInc(p1);
		}

		// Left wall
		if (ballX == 0)
		{
			scoreInc(p2);
		}
	}

	void run()
	{
		while (!quitGame)
		{
			draw();
			input();
			moveLogic();
			Sleep(100);
		}
	}
};

int main()
{
	pGameManager g(40, 20);

	g.run();

	return 0;
}
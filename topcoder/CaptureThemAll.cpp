/*
	https://community.topcoder.com/stat?c=problem_statement&pm=2915&rd=5853
	987.86/1000!!!
*/
#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class CaptureThemAll {
public:
	int fastKnight(string knight, string rook, string queen) {
		int minimumMoves = INT_MAX;
		vector< vector<int> > distances(3, vector<int>(64, INT_MAX));
		vector<int> piecesX(3); // 0 = knight, 1 = rook, 2 = queen
		vector<int> piecesY(3);
		piecesX[0] = knight[0] - 'a';
		piecesX[1] = rook[0] - 'a';
		piecesX[2] = queen[0] - 'a';
		piecesY[0] = knight[1] - '1';
		piecesY[1] = rook[1] - '1';
		piecesY[2] = queen[1] - '1';
		distances[0][8*piecesX[0] + piecesY[0]] = 0;
		// begin BFS
		queue<int> squareQueue;
		vector<int> knightMoves = {2, 2, -2, -2, 1, -1, 1, -1}; // used for iterations
		for (int board = 0; board < 3; board++) {
			if (board == 0) {
				squareQueue.push(8*piecesX[0] + piecesY[0]);
			}
			else {
				distances[board][8*piecesX[board] + piecesY[board]] = distances[0][8*piecesX[board] + piecesY[board]];
				squareQueue.push(8*piecesX[board] + piecesY[board]);
			}
			while (!squareQueue.empty()) {
				int popped = squareQueue.front();
				squareQueue.pop();
				int currentY = popped%8;
				int currentX = popped/8;
				int x_it = 0;
				int y_it = 4;
				for (int i = 0; i < 8; i++) {
					int newX = currentX + knightMoves[x_it];
					int newY = currentY + knightMoves[y_it];
					if (newX >= 0 && newY >= 0 && newX < 8 && newY < 8 &&
						distances[board][newX*8 + newY] > distances[board][currentX*8 + currentY] + 1) {
						distances[board][newX*8 + newY] = distances[board][currentX*8 + currentY] + 1;
						squareQueue.push(newX*8 + newY);
						if (((board == 1 && newX == piecesX[2] && newY == piecesY[2]) || (board == 2 && newX == piecesX[1] && newY == piecesY[1])) &&
							distances[board][newX*8 + newY] < minimumMoves) {
							minimumMoves = distances[board][newX*8 + newY];
						}
					}
					x_it++; y_it++;
					if (y_it == 8) y_it = 0;
				}
			}
		}
		return minimumMoves;
	}
};
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  int num_lines, width;
  cin >> num_lines >> width;
  vector<string> piece(num_lines);
  for (int i = 0; i < num_lines; i++) {
    string input;
    cin >> input;
    piece[i] = input;
  }
  // scan from top left for corner of rectangle, then assert that block is a rectangle
  int left_x, left_y, right_x, right_y;
  bool found = false;
  for (int i = 0; i < num_lines && !found; i++) {
    for (int j = 0; j < width && !found; j++) {
      if (piece[i][j] == 'X') {
	left_x = i; right_x = i;
	left_y = j; right_y = j;
	while (right_x + 1 < num_lines && piece[right_x + 1][j] == 'X') {
	  right_x++;
	}
	while (right_y + 1 < width && piece[i][right_y + 1] == 'X') {
	  right_y++;
	}
	found = true;
      }
    }
  }
  // then go through and assert all squares are within that rectangle
  bool go = true;
  for (int i = 0; i < num_lines && go; i++) {
    for (int j = 0; j < width && go; j++) {
      if (piece[i][j] == 'X' && (i < left_x || i > right_x || j < left_y || j > right_y)) {
	cout << "NO" << endl;
	go = false;
      }
    }
  }
  if (go) cout << "YES" << endl;
}

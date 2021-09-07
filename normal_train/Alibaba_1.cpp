#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;



int main() {
	int row, col;
	int num;
	cin >> row >> col >> num;
	vector<string> _map;
	vector<string> s;
	int startx = 0;
	int starty = 0;

	for (int i = 0; i < row; i++) {
		string str;
		cin >> str;
		_map.push_back(str);
		for (int j = 0; j < col; j++) {
			if (str[j] == '@') {
				startx = i;
				starty = j;
				_map[i][j] = '.';
				break;
			}
		}
	}

	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;
		s.push_back(str);
	}
	

	int x = startx;
	int y = starty;

	

	for (int i = 0; i < num; i++) {
		string cur = s[i];
		if (cur == "WEST") {//上j--
			while (y >= 0) {
				if (y == 0 || _map[x][y - 1] == '#') {
					starty = y;
					break;
				}
				y--;
			}
		}
		else if (cur == "EAST") {//右
			while (y < col) {
				if (y == col - 1 || _map[x][y + 1] == '#') {
					starty = y;
					break;
				}
				y++;
			}
		}
		else if (cur == "NORTH") {//上i--
			while (x >= 0) {
				if (x == 0 || _map[x - 1][y] == '#') {
					startx = x;
					break;
				}
				x--;
			}
		}
		else if (cur == "SOUTH") {//下i++
			while (x < col) {
				if (x == row - 1 || _map[x + 1][y] == '#') {
					startx = x;
					break;
				}
				x++;
			}
		}
	}
	cout << x+1 << " " << y+1;
    cin.get();
    cin.get();
	return 0;
}
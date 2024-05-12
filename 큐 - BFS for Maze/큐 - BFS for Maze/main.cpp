#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

// BFS

int a = 0, b = 0, sa = 0, sb = 0, ta = 0, tb = 0;
int s = 1, q = 0;
int map[100][100];


struct Location2D {
	int row;
	int col;
	Location2D(int r = 0, int c = 0) { row = r; col = c; }
	bool isNeighbor(Location2D& p) {
		return (row == p.row && (col == p.col - 1 || col == p.col + 1)) || (col == p.col && (row == p.row - 1 || row == p.row + 1));
	}
	bool operator==(Location2D& p) { return row == p.row && col == p.col; }
};


bool isValidloc(int r, int c) {
	if (r < 0 || c < 0 || r >= a || c >= b) {
		return false;
	}
	else {
		return map[r][c] == '0' || map[r][c] == 'T';
	}
}



int main() {
	queue<Location2D>locQueue;
	scanf_s("%d %d", &a, &b);
	getchar();
	char input[100];

	for (int i = 0; i < a; i++) {
		cin.getline(input,sizeof(input));
		for (int j = 0; j < b; j++) {
			map[i][j] = input[j];
			if (map[i][j] == 'S') {
				sa = i, sb = j;
			}
			if (map[i][j] == 'T') {
				ta = i, tb = j;
			}
		}
	}

	map[sa][sb] = s;
	locQueue.push(Location2D(sa, sb));
	//printf("%d %d///", sa, sb);

	while (locQueue.empty() == false) {
		Location2D here = locQueue.front();
		locQueue.pop();

		int r = here.row;
		int c = here.col;
		//printf("(%d, %d) ", r, c);
		if (map[r][c] != s) {
			s--;
		}

		if (r == ta && c == tb) {
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					printf("%2d ", map[i][j]);
				}
				printf("\n");
			}
			printf("%d", map[r][c]);
			return 0;
		}
		else {
			if (isValidloc(r - 1, c)) {
				locQueue.push(Location2D(r - 1, c));
					map[r - 1][c] = ++s;
					s--;
			}
			if (isValidloc(r + 1, c)) {
				locQueue.push(Location2D(r + 1, c));
					map[r + 1][c] = ++s;
					s--;
				
			}
			if (isValidloc(r, c - 1)) {
				locQueue.push(Location2D(r, c - 1));
					map[r][c - 1] = ++s;
					s--;
			}
			if (isValidloc(r, c + 1)) {
				locQueue.push(Location2D(r, c + 1));
					map[r][c + 1] = ++s;
					s--;
			}
				s++;
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("%2d ", map[i][j]);
		}
		printf("\n");
	}
	printf("0");
	return 0;
}
/**************************************************************************


*************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print(int[][5]);
void moving(int&, int&);
bool check(int[][5]);
bool preventX_outsider(int, int);
bool preventY_outsider(int, int);

const int SIZE = 5;

int main() {
	int arr[SIZE][SIZE] = { 0 };
	int loc_x = 2, loc_y = 2;
	int dir_x = 0, dir_y = 0;

	srand(time(NULL));
	arr[loc_x][loc_y] = 1;

	while (true) {

		cout << '(' << loc_x << ',' << loc_y << ')' << endl;
		print(arr);
		if (check(arr)) {
			break;
		}
		moving(dir_x, dir_y);

 		if (!preventX_outsider(loc_x, dir_x))
			dir_x = 0;
		if (!preventY_outsider(loc_y, dir_y))
			dir_y = 0;

		loc_x += dir_x;
		loc_y += dir_y;

		arr[loc_y][loc_x] = 1;
	}

	return 0;
}

void print(int arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void moving(int& dir_x, int& dir_y)
{
	int direct;
	direct = rand()%8;

	switch(direct){
	case 0:
		dir_y =-1;
		break;

	case 1:
		dir_x = 1;
		dir_y = -1;
		break;

	case 2:
		dir_x = 1;
		break;
	
	case 3:
		dir_x = 1;
		dir_y = 1;
		break;
	
	case 4:
		dir_y = 1;
		break;
	
	case 5:
		dir_x = -1;
		dir_y = 1;
		break;
	
	case 6:
		dir_x = -1;
		break;
	
	case 7:
		dir_x = -1;
		dir_y = -1;
		break;
	}
}
bool check(int arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (!arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}
bool preventX_outsider(int loc_x, int dir_x)
{
	if ((loc_x >= SIZE-1 && dir_x >=1) || (loc_x <=0 && dir_x <=-1)) {
		return false;
	}
	else
		return true;
}
bool preventY_outsider(int loc_y, int dir_y)
{
	if ((loc_y >= SIZE-1 && dir_y >= 1) || (loc_y <= 0 && dir_y <= -1)) {
		return false;
	}
	else
		return true;
}

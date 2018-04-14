#include<iostream>
using namespace std;
#include"Vector.h"
#include"List.h"
/*Global variables*/
List Result,Solution;
Vector *Action = NULL;
Vector max;
int Count = 0;
//Result is used to store results
//Action is store decision variables
//count is used to record the number of moves

void CreateAction(int n) {
	int i, j;
	int loop = 0;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n - i; j++) {
			if ((i == 0) && (j == 0))
				continue;
			Action[loop++].Set(i, j);
		}
	}
}

bool Run(Vector, int);

int main()
{
	int x, y, n;
	/***********
	x Number of Merchants
	y as servant number
	n for the maximum capacity of the ship
	***********/
	Vector start;
	cout << "Input Number of Merchants  ";
	cin >> x;
	cout << "Input Number of servant  ";
	cin >> y;
	cout << "Input Number of maximum capacity of the ship  ";
	cin >> n;
	start.Set(x, y);
	max.Set(x, y);
	Result.Insert(start, 0);
	Count = (n + 1)*(n + 2) / 2 - 1;
	Action = new Vector[Count];
	CreateAction(n);
	if (Run(start, 1))
		Result.Show(Solution);
	else
		puts("No Plan!");
	delete[] Action;
	return 0;
}



bool Run(Vector now, int n) {
	Vector temp;
	int i;
	if (now == temp)
		return true;
	for (i = 0; i<Count; i++) {
		temp = Action[i];
		if (n % 2)
			temp = now - Action[i];
		else
			temp = now + Action[i];
		if (temp.IsSafe(max) == true) {
			//if the action is feasible
			if (Result.IsLoop(temp, n)) {
				//if it's not a dead loop
				Result.Insert(temp, n);
				Solution.Insert(Action[i],n);
				if (Run(temp, n + 1))
					return true;
				else {
					Result.Delete();
					Solution.Delete();
				}
			}
		}
	}
	return false;
}

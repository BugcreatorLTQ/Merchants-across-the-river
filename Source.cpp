#include<iostream>
using namespace std;
#include"Vector.h"
#include"List.h"
/*全局变量*/
List Result;
Vector *Action = NULL;
Vector max;
int Count = 0;
//Result用来储存决策结果
//Action为决策集合
//count为决策集合大小

void CreateAction(int n, Vector *Action) {
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
	//x为商人数,y为仆人数,n为船中最大容量
	Vector start;
	cout << "输入商人数  ";
	cin >> x;
	cout << "输入仆人数  ";
	cin >> y;
	cout << "输入船的最大容量  ";
	cin >> n;
	start.Set(x, y);
	max.Set(x, y);
	Result.Insert(start, 0);
	Count = (n + 1)*(n + 2) / 2 - 1;
	Action = new Vector[Count];
	CreateAction(n, Action);
	if (Run(start, 1))
		Result.Show();
	else
		puts("No Plan!");
	delete[] Action;
	return 0;
}



bool Run(Vector now, int n) {
	//now为当前状态
	//n为当前渡河次数
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
			//判断now+(-1)n*temp是否为安全状态
			if (Result.IsLoop(temp, n)) {
				//判断是否产生回路
				Result.Insert(temp, n);
				if (Run(temp, n + 1))
					return true;
				else
					Result.Delete();
			}
		}
	}
	return false;
}

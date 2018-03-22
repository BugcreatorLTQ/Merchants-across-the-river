#include<iostream>
using namespace std;
#include"Vector.h"
#include"List.h"
/*ȫ�ֱ���*/
List Result;
Vector *Action = NULL;
Vector max;
int Count = 0;
//Result����������߽��
//ActionΪ���߼���
//countΪ���߼��ϴ�С

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
	//xΪ������,yΪ������,nΪ�����������
	Vector start;
	cout << "����������  ";
	cin >> x;
	cout << "����������  ";
	cin >> y;
	cout << "���봬���������  ";
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
	//nowΪ��ǰ״̬
	//nΪ��ǰ�ɺӴ���
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
			//�ж�now+(-1)n*temp�Ƿ�Ϊ��ȫ״̬
			if (Result.IsLoop(temp, n)) {
				//�ж��Ƿ������·
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


class Vector {
private:
	int x;
	int y;
public:
	Vector(int x = 0, int y = 0) { this->x = x; this->y = y; };
	Vector operator+(Vector &action);	//Add
	Vector operator-(Vector &action);	//Sub
	bool operator==(Vector &action) { if ((x == action.x) && (y == action.y))return true; else return false; };
	bool IsSafe(Vector &max);
	void Set(int a, int b) { x = a; y = b; };
	void ShowSolution();
	void ShowResult();
};

void Vector::ShowResult()
{
	printf("River: %d %d\n", x, y);
}

void Vector::ShowSolution()
{
	printf("Ship : %d %d\n", x, y);
}

Vector Vector::operator+(Vector &action) {
	Vector temp = *this;
	temp.x += action.x;
	temp.y += action.y;
	return temp;
}

Vector Vector::operator-(Vector &action) {
	Vector temp = *this;
	temp.x -= action.x;
	temp.y -= action.y;
	return temp;
}

bool Vector::IsSafe(Vector &max) {
	//determine whether the current dexision is feasible
	if (x > max.x || y > max.y)
		return false;
	if (x < 0 || y < 0)
		return false;
	if (x == max.x || x == 0)
		return true;
	if ((x >= y) && ((max.x - x) >= (max.y - y)))
		return true;
	return false;
}




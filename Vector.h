
class Vector {
private:
	int x;
	int y;
public:
	Vector(int x = 0, int y = 0) { this->x = x; this->y = y; };
	Vector operator+(Vector &action);	//向量加法
	Vector operator-(Vector &action);	//向量减法
	bool operator==(Vector &action) { if ((x == action.x) && (y == action.y))return true; else return false; };
	bool IsSafe(Vector &max);
	void Set(int a, int b) { x = a; y = b; };
	friend ostream& operator<<(ostream& o,const Vector& action);
};

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

ostream& operator<<(ostream& o,const Vector& action) {
	o << "( " << action.x << " , " << action.y << " )";
	return o;
}




typedef struct node {
	Vector data;
	int flag;
	node *next;
}*Node;

class List {
private:
	Node head;
	Node rear;
	int count;
public:
	List() { head = new node; rear = head; head->next = NULL; count=0; };
	~List();//destructor
	List(const List &other);
	void Insert(Vector &action,int n);
	void Show(const List &other);//Show this List other is actions
	void Delete();//Delete last node
	bool IsLoop(Vector &action, int n);//judging dead Loops
};

List::~List() {
	Node now = head, next;
	cout << count << endl;
	while (now != NULL) {
		next = now->next;
		delete now;
		now = next;
	}
}

void List::Insert(Vector &action,int n) {
	Node now = new node;
	now->data = action;
	if (n % 2 == 1)
		now->flag = 0;
	else
		now->flag = 1;
	rear->next = now;
	rear = now;
	now->next = NULL;
	count++;
}

void List::Show(const List &solution) {
	Node now = head->next;
	Node action = solution.head->next;
	while (action != NULL) {
		now->data.ShowResult();
		action->data.ShowSolution();
		now = now->next;
		action = action->next;
	}
	now->data.ShowResult();
}

void List::Delete(){
	Node now = head;
	while (now->next != rear) {
		now = now->next;
	}
	delete rear;
	now->next = NULL;
	rear = now;
	count--;
}

bool List::IsLoop(Vector &action,int n) {
	Node now = head->next;
	while (now != NULL) {
		if (now->data == action)
			if (n % 2 != now->flag)
				return false;
		now = now->next;
	}
	return true;
}
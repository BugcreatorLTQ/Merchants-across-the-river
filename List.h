
typedef struct node {
	Vector data;
	int flag;
	node *next;
}*Node;

class List {
private:
	Node head;
	Node rear;
public:
	List() { head = new node; rear = head; head->next = NULL; };
	~List();//析构
	void Insert(Vector &action,int n);
	void Show();//输出链表
	void Delete();//删除最后一个节点
	bool IsLoop(Vector &action, int n);//判断是否为死循环
};

List::~List() {
	Node now = head, next;
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
}

void List::Show() {
	Node now = head->next;
	while (now != NULL) {
		cout << now->data << endl;
		now = now->next;
	}
}

void List::Delete(){
	Node now = head;
	while (now->next != rear) {
		now = now->next;
	}
	delete rear;
	now->next = NULL;
	rear = now;
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
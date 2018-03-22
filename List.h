
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
	~List();//����
	void Insert(Vector &action,int n);
	void Show();//�������
	void Delete();//ɾ�����һ���ڵ�
	bool IsLoop(Vector &action, int n);//�ж��Ƿ�Ϊ��ѭ��
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
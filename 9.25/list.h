template<class Type> class List;
template<class Type> class ListNode {
	friend class List<Type>;
public:
	ListNode() { next == NULL; }
	ListNode(const Type &item);
	ListNode<Type> *NextNode() { return next; }
	void InsertAfter(ListNode<Type> *p);
	ListNode<Type> *GetNode(const Type &item, ListNode<Type> *next);
	ListNode<Type> *RemoveAfter();
private:
	Type data;
	ListNode<Type> *next;
};
template<class Type>class List {
public:
	List() { tail = head = new ListNode<Type>(); }
	~List();
	void Create_List();
	void MakeEmpty();
	int Length() const;
	ListNode<Type> *Find(Type value);
	int Insert(Type value, int i);
	void Output_List();
	int Delete(int i);
private:
	ListNode<Type> *head, *tail;
};
template<class Type>
void List<Type>::Create_List() {
	ListNode<Type> *p, *q;
	head = new ListNode<Type>(NULL);
	p = head;
	while(std::cin>>p->data){
		q = new ListNode<Type>(NULL);
		p->next = q;
		p = q;
	}
	std::cin >> p->data;
	p->next = NULL;

}
template<class Type>int List<Type>::Insert(Type x, int i) {
	ListNode<Type> *p,*q;
	int j = 0;
	p = head;
	q = new ListNode<Type>(x,NULL);
	while (p != NULL&&j<i-1) {
		p = p->next;
		j++;
	}
	if (p == NULL&head != NULL) {
		std::cout << "Invaid position for Insertion!\n";
			return 0;
	}
	if (head == NULL || i == 0) {
		q->next = head;
		if (head == NULL) tail = q;
		head = q;
	}
	else {
		q->next = p->next;
		if (p->next == NULL)
			tail = q;
		p->next = q;
	}
	return 1;

}
template <class Type> int List<Type>::Delete(int i)
{  //删除链表中的第i个结点并将其返回
   //其中i是结点编号，从0开始计数
	ListNode<Type> *p, *q;
	int j = 0;
	p = head;
	while (p != NULL && j<i - 1)
	{  //循链找第i-1个结点
		p = p->link;
		j++;
	}
	if (p == NULL && head != NULL)
	{  //非空表且链短，找不到第i-1个结点
		std::cout << "Invaid position for Insertion!\n";
		return 0;  //删除失败，返回0
	}
	if (i == 0) {  //删除表首结点
		q = head;
		p = head = head->next;
		//重置表首结点为被删结点的后继结点  
	}
	else {  //删除表中间或者表尾结点
		q = p->next;
		p->next = q->next;
	}
	if (q == tail)
		tail = p;  //如果删除表尾结点，修改表尾指针
	delete q;
	return 1;  //删除成功，返回1
}
template<class Type> void List<Type>::Output_List() {
	ListNode<Type> *p;
	p=head;
	while (p->next != NULL) {
		std::cout << p->data << " ";
	}
	std::cout <<std::endl;
	delete p;
}

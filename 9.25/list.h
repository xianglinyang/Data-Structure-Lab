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
{  //ɾ�������еĵ�i����㲢���䷵��
   //����i�ǽ���ţ���0��ʼ����
	ListNode<Type> *p, *q;
	int j = 0;
	p = head;
	while (p != NULL && j<i - 1)
	{  //ѭ���ҵ�i-1�����
		p = p->link;
		j++;
	}
	if (p == NULL && head != NULL)
	{  //�ǿձ������̣��Ҳ�����i-1�����
		std::cout << "Invaid position for Insertion!\n";
		return 0;  //ɾ��ʧ�ܣ�����0
	}
	if (i == 0) {  //ɾ�����׽��
		q = head;
		p = head = head->next;
		//���ñ��׽��Ϊ��ɾ���ĺ�̽��  
	}
	else {  //ɾ�����м���߱�β���
		q = p->next;
		p->next = q->next;
	}
	if (q == tail)
		tail = p;  //���ɾ����β��㣬�޸ı�βָ��
	delete q;
	return 1;  //ɾ���ɹ�������1
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

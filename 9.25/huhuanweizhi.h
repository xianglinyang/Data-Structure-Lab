template <class Type> class List;  //List���ǰ����������
    template <class Type> class LinkNode {  //�������ඨ��
      friend class List <Type>;  //��������Ϊ��Ԫ�ඨ��
      public:
	LinkNode( ) { link=NULL; }  //�����βεĹ��캯��
	LinkNode(const Type &item);  //���βεĹ��캯��
	LinkNode <Type> *NextNode( ) { return link; }
	//������ǰ���ĺ�̽���ַ
	void InsertAfter(LinkNode <Type> *p);  //��ǰ������
	LinkNode <Type> * GetNode(const Type &item, 
                   LinkNode <Type> *next);	//����һ���½��
	LinkNode <Type> * RemoveAfter( );
            //ɾ����ǰ�����һ���
	private:
		Type data;  //������
		LinkNode <Type> *link;  //���ָ����
    };
    template <class Type> class List {  //�������ඨ��
      public:
	List(const Type &value) 
	   { tail=head=new LinkNode <Type> (value); }
	~List( );  //��������
	LinkNode <Type> * Create_List(int n);  //����һ��������
	void PrintList(LinkNode<Type> *p);
	//void MakeEmpty( );  //��������Ϊ�ձ�
	//int Length( ) const;  //��������ĳ���
	//LinkNode <Type> * Find(Type value);
            //������������������value�Ľ��
	int Insert(Type value, int i); 
            //����Ԫ�ز��������е�i��λ��
	Type * Delete(int i);  //�������еĵ�i��Ԫ��ɾȥ
	//Type * Get(int i);  //ȡ�������е�i��Ԫ��
        private:
	LinkNode <Type> *head, *tail;
            //����ı�ͷָ�롢��βָ��
    };
    template <class Type> LinkNode <Type> * Create_List(int n)
    {
	LinkNode<int> *p, *q,*head;
	if (n==0)    return NULL;
	head=new LinkNode <Type> (NULL);
	p=head;
	for (int i=1; i<n; i++)
	{
		std::cin>>p->data;
		q=new LinkNode <Type> (NULL);
		p->link=q;
		p=q;
	}
	std::cin>>p->data;
	p->link=NULL;
	return head;
    };
    /*template <class Type>
    void List <Type> :: CreateListF(Type endTag)
    {
    Type val;  LinkNode <Type> *NewNode; 
    first=new LinkNode <Type>;  //��ͷ���
    cin>>val;
    while (val!=endTag) {
        NewNode=new LinkNode <Type> (val);
        NewNode->link=first->link;
        first->link=NewNode;  //���뵽��ǰ��
        cin>>val;
    }
    current=first;
    }
    template <class Type>  
    void List <Type> :: CreateListR(Type endTag) {
    Type val;  LinkNode <Type> *NewNode, *last; 
    first=new LinkNode <Type>;  //��ͷ���
    cin>>val;  current=last=first; 
    while (val!=endTag) {  //lastָ���β
         NewNode=new LinkNode <Type> (val);
         last->link=NewNode;  last=NewNode;       
         cin>>val;  //���뵽��ĩ��
    }
    last->link=NULL;  //����β     
    } */ 
	template <class Type> int List <Type> :: Insert(Type x, int i)
    {  //����Ԫ��x���뵽��i���֮ǰ
   //����i�ǽ���ţ���0��ʼ����
        LinkNode<Type> *p, *q,*head,*last;
        int j=0;
        p=head;
        q=new LinkNode <Type> (x, NULL);
        //����������Ϊx���½�㣬��qָʾ
        while (p!=NULL && j<i-1)
        {  //ѭ���ҵ�i-1�����
	   p=p->link;
	   j++;
         }
         if (p==NULL && head!=NULL)
         {  //�ǿձ������̣��Ҳ�����i-1�����
	   std::cout<<"Invalid position for Insertion!\n";
	   return 0;  //����ʧ�ܣ�����0
         }
         if (head==NULL||i==0)
        {  //���½��������ձ��ǿձ��һ�����֮ǰ
             q->link=head;  //ԭ���׽���Ϊ�½��ĺ�̽��
	 if (head==NULL)    tail=q;
                  //�ڿձ��в����½��ʱ����βָ��ָ��ý��
	 head=q;  //�½��q��Ϊ���׽��  
        }
        else {  //���½������������м���߱�β
	 q->link=p->link;
	 if (p->link==NULL)  last=q;  //��������½������β
                                   //���޸ı�βָ��ָ���½��
	 p->link=q;  
        }
        return 1;  //����ɹ�������1
    }
    /*template <class Type> int List <Type> :: Delete(int i)
   {  //ɾ�������еĵ�i����㲢���䷵��
   //����i�ǽ���ţ���0��ʼ����
        LinkNode *p, *q;
        int j=0;
        p=head;
        while (p!=NULL && j<i-1)
        {  //ѭ���ҵ�i-1�����
             p=p->link;
	 j++;
         }
         if (p==NULL && head!==NULL)
         {  //�ǿձ������̣��Ҳ�����i-1�����
	  cout<<"Invalid position for Deletion!\n";
	  return 0;  //ɾ��ʧ�ܣ�����0
         }
         if (i==0)   {  //ɾ�����׽��
	  q=head;
	  p=head=head->link;
              //���ñ��׽��Ϊ��ɾ���ĺ�̽��  
        }
        else {  //ɾ�����м���߱�β���
	  q=p->link;  
	  p->link=q->link;  
        }
        if (q==tail)
	  tail=p;  //���ɾ����β��㣬�޸ı�βָ��
        delete q;
        return 1;  //ɾ���ɹ�������1
    }*/
    template<class Type> 
    void List <Type> :: PrintList(LinkNode<Type> *p){
    	if(p==NULL) ;
    	else for(;p!=NULL;){
    		std::cout<<p->data<<" ";
    		p=p->link;	
		}
	}

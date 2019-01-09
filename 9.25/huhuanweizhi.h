template <class Type> class List;  //List类的前向引用声明
    template <class Type> class LinkNode {  //链表结点类定义
      friend class List <Type>;  //链表类作为友元类定义
      public:
	LinkNode( ) { link=NULL; }  //不带形参的构造函数
	LinkNode(const Type &item);  //带形参的构造函数
	LinkNode <Type> *NextNode( ) { return link; }
	//给出当前结点的后继结点地址
	void InsertAfter(LinkNode <Type> *p);  //当前结点插入
	LinkNode <Type> * GetNode(const Type &item, 
                   LinkNode <Type> *next);	//建立一个新结点
	LinkNode <Type> * RemoveAfter( );
            //删除当前结点下一结点
	private:
		Type data;  //数据域
		LinkNode <Type> *link;  //后继指针域
    };
    template <class Type> class List {  //单链表类定义
      public:
	List(const Type &value) 
	   { tail=head=new LinkNode <Type> (value); }
	~List( );  //析构函数
	LinkNode <Type> * Create_List(int n);  //建立一个单链表
	void PrintList(LinkNode<Type> *p);
	//void MakeEmpty( );  //将链表置为空表
	//int Length( ) const;  //计算链表的长度
	//LinkNode <Type> * Find(Type value);
            //在链表中搜索含数据value的结点
	int Insert(Type value, int i); 
            //将新元素插在链表中第i个位置
	Type * Delete(int i);  //将链表中的第i个元素删去
	//Type * Get(int i);  //取出链表中第i个元素
        private:
	LinkNode <Type> *head, *tail;
            //链表的表头指针、表尾指针
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
    first=new LinkNode <Type>;  //表头结点
    cin>>val;
    while (val!=endTag) {
        NewNode=new LinkNode <Type> (val);
        NewNode->link=first->link;
        first->link=NewNode;  //插入到表前端
        cin>>val;
    }
    current=first;
    }
    template <class Type>  
    void List <Type> :: CreateListR(Type endTag) {
    Type val;  LinkNode <Type> *NewNode, *last; 
    first=new LinkNode <Type>;  //表头结点
    cin>>val;  current=last=first; 
    while (val!=endTag) {  //last指向表尾
         NewNode=new LinkNode <Type> (val);
         last->link=NewNode;  last=NewNode;       
         cin>>val;  //插入到表末端
    }
    last->link=NULL;  //表收尾     
    } */ 
	template <class Type> int List <Type> :: Insert(Type x, int i)
    {  //将新元素x插入到第i结点之前
   //其中i是结点编号，从0开始计数
        LinkNode<Type> *p, *q,*head,*last;
        int j=0;
        p=head;
        q=new LinkNode <Type> (x, NULL);
        //建立数据域为x的新结点，由q指示
        while (p!=NULL && j<i-1)
        {  //循链找第i-1个结点
	   p=p->link;
	   j++;
         }
         if (p==NULL && head!=NULL)
         {  //非空表且链短，找不到第i-1个结点
	   std::cout<<"Invalid position for Insertion!\n";
	   return 0;  //插入失败，返回0
         }
         if (head==NULL||i==0)
        {  //将新结点插入至空表或非空表第一个结点之前
             q->link=head;  //原表首结点成为新结点的后继结点
	 if (head==NULL)    tail=q;
                  //在空表中插入新结点时，表尾指针指向该结点
	 head=q;  //新结点q成为表首结点  
        }
        else {  //将新结点插入至链表中间或者表尾
	 q->link=p->link;
	 if (p->link==NULL)  last=q;  //如果插入新结点至表尾
                                   //则修改表尾指针指向新结点
	 p->link=q;  
        }
        return 1;  //插入成功，返回1
    }
    /*template <class Type> int List <Type> :: Delete(int i)
   {  //删除链表中的第i个结点并将其返回
   //其中i是结点编号，从0开始计数
        LinkNode *p, *q;
        int j=0;
        p=head;
        while (p!=NULL && j<i-1)
        {  //循链找第i-1个结点
             p=p->link;
	 j++;
         }
         if (p==NULL && head!==NULL)
         {  //非空表且链短，找不到第i-1个结点
	  cout<<"Invalid position for Deletion!\n";
	  return 0;  //删除失败，返回0
         }
         if (i==0)   {  //删除表首结点
	  q=head;
	  p=head=head->link;
              //重置表首结点为被删结点的后继结点  
        }
        else {  //删除表中间或者表尾结点
	  q=p->link;  
	  p->link=q->link;  
        }
        if (q==tail)
	  tail=p;  //如果删除表尾结点，修改表尾指针
        delete q;
        return 1;  //删除成功，返回1
    }*/
    template<class Type> 
    void List <Type> :: PrintList(LinkNode<Type> *p){
    	if(p==NULL) ;
    	else for(;p!=NULL;){
    		std::cout<<p->data<<" ";
    		p=p->link;	
		}
	}

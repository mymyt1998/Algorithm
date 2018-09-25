#include <iostream>
using namespace std;
struct node
{
	int val;
	node *next;
};
class linklist{
private:
	node * head;
public:
	linklist();//默认构造函数
	void create();//创建链表
	int listlength();//计算链表长度
	void PushList();//在链表尾部插入
	void insert(int pos,int val);//在链表第pos位置插入val
	void display();//打印链表
	~linklist();//析构函数，删除链表
};

linklist::linklist()//构造函数
{
	head = new node;
	head->next = NULL;
}

//后插法建立链表
void linklist::create()
{
	node *p, *q;
	p = head;
	int temp=-1;
	while (cin>>temp,temp!=-1)
	{
		//新节点
		q = new node;
		q->val = temp;
		q->next = NULL;
		//拼接
		p->next = q;
		p = q;
	}
}

//返回链表的长度
int linklist::listlength()
{
	int len = 0;
	node *p = head;

	while (p->next)
	{
		len++;
		p = p->next;
	}
	return len;
}

//在最后插入一个值
void linklist::PushList()
{
	node *p, *q;
	int val;
	//输入要插入的值
	cin >> val;
	p = head;
	q = new node;
	q->val = val;
	q->next = NULL;
	while (p->next)
	{
		p = p->next;
	}
	p->next = q;
}
//在第pos位置插入一个val
void linklist::insert(int pos,int val)//在pos位置插入val值
{
	node *p, *q;
	int i;
	i = 0;
	p = head;
	while (p && i < pos)
	{
		p = p->next;
		++i;
	}
	q = new node;
	q->val = val;
	q->next = p->next;
	p->next = q;
}


//显示链表
void linklist::display()
{
	node *p = head;
	while (p->next)
	{
		cout << p->next->val;
		p = p->next;
		cout <<" ";
	}
	cout << endl;
	cout << "the length of list : " << listlength() << endl;
}

linklist::~linklist()
{
	node *p;
	while (head->next)
	{
		p = head;
		head = head->next;
		delete p;
		p = NULL;
	}
	delete head;
	head = NULL;
}

int main()
{

	linklist list;

	cout << "输入链表：" << endl;
	list.create();
	list.display();

	list.PushList();
	list.display();

	list.insert(0,7);//在1位置插入7，0开始
	list.display();

	system("pause");
	return 0;
}

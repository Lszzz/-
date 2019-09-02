
//Author:kgvito 
//Date: 2017.12.25


#include<iostream>
using namespace std;

typedef int DataType;
#define Node ElemType
#define ERROR NULL

//构建一个节点类
class Node
{
public:
	int data;     //数据域
	Node* next;  //指针域
};

//构建一个单链表类
class LinkList
{
public:
	LinkList();                      //构建一个单链表;
	~LinkList();                  //销毁一个单链表;
	void CreateLinkList(int n);   //创建一个单链表
	void TravalLinkList();        //遍历线性表
	int GetLength();              //获取线性表长度
	bool IsEmpty();               //判断单链表是否为空
	ElemType* Find(DataType data); //查找节点
	void InsertElemAtEnd(DataType data);            //在尾部插入指定的元素
	void InsertElemAtIndex(DataType data, int n);    //在指定位置插入指定元素
	void InsertElemAtHead(DataType data);           //在头部插入指定元素
	void DeleteElemAtEnd();       //在尾部删除元素
	void DeleteAll();             //删除所有数据
	void DeleteElemAtPoint(DataType data);     //删除指定的数据
	void DeleteElemAtHead();      //在头部删除节点
private:
	ElemType* head;              //头结点
};

//初始化单链表
LinkList::LinkList()
{
	head = new ElemType;
	head->data = 0;               //将头结点的数据域定义为0
	head->next = NULL;            //头结点的下一个定义为NULL
}

//销毁单链表
LinkList::~LinkList()
{
	delete head;                 //删除头结点
}

//创建一个单链表
void LinkList::CreateLinkList(int n)
{
	ElemType* pnew, * ptemp;
	ptemp = head;
	if (n < 0) {       //当输入的值有误时，处理异常
		cout << "输入的节点个数有误" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++) {        //将值一个一个插入单链表中
		pnew = new ElemType;
		cout << "请输入第" << i + 1 << "个值: ";
		cin >> pnew->data;
		pnew->next = NULL;          //新节点的下一个地址为NULL
		ptemp->next = pnew;//当前结点的下一个地址设为新节点
		
		ptemp = pnew;               //将当前结点设为新节点
	}
}

//遍历单链表
void LinkList::TravalLinkList()
{
	if (head == NULL || head->next == NULL) {
		cout << "链表为空表" << endl;
	}
	ElemType* p = head;                 //另指针指向头结点
	while (p->next != NULL)        //当指针的下一个地址不为空时，循环输出p的数据域
	{
		p = p->next;               //p指向p的下一个地址
		cout << p->data << " ";
	}
}

//获取单链表的长度
int LinkList::GetLength()
{
	int count = 0;                  //定义count计数
	ElemType* p = head->next;           //定义p指向头结点
	while (p != NULL)                //当指针的下一个地址不为空时，count+1
	{
		count++;
		p = p->next;                //p指向p的下一个地址
	}
	return count;                   //返回count的数据
}

//判断单链表是否为空
bool LinkList::IsEmpty()
{
	if (head->next == NULL) {
		return true;
	}
	return false;
}

//查找节点
ElemType* LinkList::Find(DataType data)
{
	ElemType* p = head;
	if (p == NULL) {                           //当为空表时，报异常
		cout << "此链表为空链表" << endl;
		return ERROR;
	}
	else
	{
		while (p->next != NULL)               //循环每一个节点
		{
			if (p->data == data) {
				return p;                     //返回指针域
			}
			p = p->next;
		}
		
		return NULL;                           //未查询到结果
	}
}

//在尾部插入指定的元素
void LinkList::InsertElemAtEnd(DataType data)
{
	ElemType* newNode = new ElemType;    //定义一个Node结点指针newNode
	newNode->next = NULL;         //定义newNode的数据域和指针域
	newNode->data = data;
	ElemType* p = head;              //定义指针p指向头结点
	if (head == NULL) {           //当头结点为空时，设置newNode为头结点
		head = newNode;
	}
	else                          //循环知道最后一个节点，将newNode放置在最后
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = newNode;
	}
}

//在指定位置插入指定元素
void LinkList::InsertElemAtIndex(DataType data, int n)
{
	if (n<1 || n>GetLength())                   //输入有误报异常
		cout << "输入的值错误" << endl;
	else
	{
		ElemType* ptemp = new ElemType;        //创建一个新的节点
		ptemp->data = data;                     //定义数据域
		ElemType* p = head;                    //创建一个指针指向头结点
		int i = 1;
		while (n > i)                           //遍历到指定的位置
		{
			p = p->next;
			i++;
		}
		ptemp->next = p->next;                 //将新节点插入到指定位置
		p->next = ptemp;
	}
}

//在头部插入指定元素
void LinkList::InsertElemAtHead(DataType data)
{
	ElemType* newNode = new ElemType;    //定义一个Node结点指针newNode
	newNode->data = data;
	ElemType* p = head;              //定义指针p指向头结点
	if (head == NULL) {           //当头结点为空时，设置newNode为头结点
		head = newNode;
	}
	newNode->next = p->next;          //将新节点插入到指定位置
	p->next = newNode;
}

//在尾部删除元素
void LinkList::DeleteElemAtEnd()
{
	ElemType* p = head;          //创建一个指针指向头结点
	ElemType* ptemp = NULL;      //创建一个占位节点
	if (p->next == NULL) {        //判断链表是否为空
		cout << "单链表空" << endl;
	}
	else
	{
		while (p->next != NULL)   //循环到尾部的前一个
		{
			ptemp = p;            //将ptemp指向尾部的前一个节点
			p = p->next;          //p指向最后一个节点
		}
		delete p;                //删除尾部节点
		p = NULL;
		ptemp->next = NULL;
	}
}

//删除所有数据
void LinkList::DeleteAll()
{
	ElemType* p = head->next;
	ElemType* ptemp = new ElemType;
	while (p != NULL)                    //在头结点的下一个节点逐个删除节点
	{
		ptemp = p;
		p = p->next;
		head->next = p;
		ptemp->next = NULL;
		delete ptemp;
	}
	head->next = NULL;                 //头结点的下一个节点指向NULL
}

//删除指定的数据
void LinkList::DeleteElemAtPoint(DataType data)
{
	ElemType* ptemp = Find(data);    //查找到指定数据的节点位置
	if (ptemp == head->next) {        //判断是不是头结点的下一个节点，如果是就从头部删了它
		DeleteElemAtHead();
	}
	else
	{
		ElemType* p = head;          //p指向头结点
		while (p->next != ptemp)      //p循环到指定位置的前一个节点
		{
			p = p->next;
		}
		p->next = ptemp->next;         //删除指定位置的节点
		delete ptemp;
		ptemp = NULL;
	}

}

//在头部删除节点
void LinkList::DeleteElemAtHead()
{
	ElemType* p = head;
	if (p == NULL || p->next == NULL) {   //判断是否为空表，报异常
		cout << "该链表为空表" << endl;
	}
	else
	{
		ElemType* ptemp = NULL;      //创建一个占位节点
		p = p->next;
		ptemp = p->next;              //将头结点的下下个节点指向占位节点
		delete p;                     //删除头结点的下一个节点
		p = NULL;
		head->next = ptemp;           //头结点的指针更换
	}
}
/***双向链表

#ifndef DOUBLE_LINK_HXX
#define DOUBLE_LINK_HXX

#include <iostream>
using namespace std;
//一个节点
template<class T>
struct DNode
{
public:
	T value;
	DNode *prev;
	DNode *next;
public:
	DNode() { }
	DNode(T t, DNode *prev, DNode *next) {
		this->value = t;
		this->prev  = prev;
		this->next  = next;
	}
};
//双向链表基本操作
template<class T>
class DoubleLink
{
public:
	DoubleLink();
	~DoubleLink();

	int size();//大小
	int is_empty();//判断是否为空

	T get(int index);//获取节点
	T get_first();//获取首节点
	T get_last();//获取尾节点

	int insert(int index, T t);
	int insert_first(T t);
	int append_last(T t);

	int del(int index);
	int delete_first();
	int delete_last();

private:
	int count;
	DNode<T> *phead;
private:
	DNode<T> *get_node(int index);
};

template<class T>
DoubleLink<T>::DoubleLink() : count(0)
{
	// 创建“表头”。注意：表头没有存储数据！
	phead = new DNode<T>();
	phead->prev = phead->next = phead;
	// 设置链表计数为0
	//count = 0;
}

// 析构函数
template<class T>
DoubleLink<T>::~DoubleLink()
{
	// 删除所有的节点
	DNode<T>* ptmp;
	DNode<T>* pnode = phead->next;
	while (pnode != phead)
	{
		ptmp = pnode;
		pnode=pnode->next;
		delete ptmp;
	}

	// 删除"表头"
	delete phead;
	phead = NULL;
}

// 返回节点数目
template<class T>
int DoubleLink<T>::size()
{
	return count;
}

// 返回链表是否为空
template<class T>
int DoubleLink<T>::is_empty()
{
	return count==0;
}

// 获取第index位置的节点
template<class T>
DNode<T>* DoubleLink<T>::get_node(int index)
{
	// 判断参数有效性
	if (index<0 || index>=count)
	{
		cout << "get node failed! the index in out of bound!" << endl;
		return NULL;
	}

	// 正向查找
	if (index <= count/2)
	{
		int i=0;
		DNode<T>* pindex = phead->next;
		while (i++ < index) {
			pindex = pindex->next;
		}

		return pindex;
	}

	// 反向查找
	int j=0;
	int rindex = count - index -1;
	DNode<T>* prindex = phead->prev;
	while (j++ < rindex) {
		prindex = prindex->prev;
	}

	return prindex;
}

// 获取第index位置的节点的值
template<class T>
T DoubleLink<T>::get(int index)
{
	return get_node(index)->value;
}
//构造一整个双链表
 DoubleLinkedList()
 {
  NODE<T>* q = new NODE<T>;
  if (q == NULL)
  {
   cout << "Fail to malloc the head node." << endl;
   return;
  }
  phead = q;
  phead->pre = NULL;
  phead->data = NULL;
  phead->next = NULL;

  T i;
  cout << "Please input several integer number, input ctrl+z to the end: " << endl;
  while (cin >> i)
  {
   NODE<T>* p = new NODE<T>;
   if (p == NULL)
   {
	cout << "Fail to malloc a new node." << endl;
	return;
   }
   p->data = i;
   q->next = p;
   p->pre = q;
   p->next = NULL;
   q = q->next;
  }
 }

 //容器大小方法
 int size()
 {
  NODE<T>* p = phead->next;
  int count(0);
  while (p != NULL)
  {
   count++;
   p = p->next;
  }
  return count;
 }

// 获取第1个节点的值
template<class T>
T DoubleLink<T>::get_first()
{
	return get_node(0)->value;
}

// 获取最后一个节点的值
template<class T>
T DoubleLink<T>::get_last()
{
	return get_node(count-1)->value;
}

// 将节点插入到第index位置之前
template<class T>
int DoubleLink<T>::insert(int index, T t)
{
	if (index == 0)
		return insert_first(t);

	DNode<T>* pindex = get_node(index);
	DNode<T>* pnode  = new DNode<T>(t, pindex->prev, pindex);
	pindex->prev->next = pnode;
	pindex->prev = pnode;
	count++;

	return 0;
}

// 将节点插入第一个节点处。
template<class T>
int DoubleLink<T>::insert_first(T t)
{
	DNode<T>* pnode  = new DNode<T>(t, phead, phead->next);
	phead->next->prev = pnode;
	phead->next = pnode;
	count++;

	return 0;
}

// 将节点追加到链表的末尾
template<class T>
int DoubleLink<T>::append_last(T t)
{
	DNode<T>* pnode = new DNode<T>(t, phead->prev, phead);
	phead->prev->next = pnode;
	phead->prev = pnode;
	count++;

	return 0;
}

// 删除index位置的节点
template<class T>
int DoubleLink<T>::del(int index)
{
	DNode<T>* pindex = get_node(index);
	pindex->next->prev = pindex->prev;
	pindex->prev->next = pindex->next;
	delete pindex;
	count--;

	return 0;
}

// 删除第一个节点
template<class T>
int DoubleLink<T>::delete_first()
{
	return del(0);
}

// 删除最后一个节点
template<class T>
int DoubleLink<T>::delete_last()
{
	return del(count-1);
}


/**/
//测试函数
int main()
{
	LinkList l;
	int i;
	cout << "1.创建单链表   2.遍历单链表   3.获取单链表的长度   4.判断单链表是否为空   5.获取节点\n";
	cout << "6.在尾部插入指定元素   7.在指定位置插入指定元素   8.在头部插入指定元素\n";
	cout << "9.在尾部删除元素   10.删除所有元素   11.删除指定元素   12.在头部删除元素   0.退出" << endl;
	do
	{
		cout << "请输入要执行的操作: ";
		cin >> i;
		switch (i)
		{
		case 1:
			int n;
			cout << "请输入单链表的长度: ";
			cin >> n;
			l.CreateLinkList(n);
			break;
		case 2:
			l.TravalLinkList();
			break;
		case 3:
			cout << "该单链表的长度为" << l.GetLength() << endl;
			break;
		case 4:
			if (l.IsEmpty() == 1)
				cout << "该单链表是空表" << endl;
			else
			{
				cout << "该单链表不是空表" << endl;
			}
			break;
		case 5:
			DataType data;
			cout << "请输入要获取节点的值: ";
			cin >> data;
			cout << "该节点的值为" << l.Find(data)->data << endl;
			break;
		case 6:
			DataType endData;
			cout << "请输入要在尾部插入的值: ";
			cin >> endData;
			l.InsertElemAtEnd(endData);
			break;
		case 7:
			DataType pointData;
			int index;
			cout << "请输入要插入的数据: ";
			cin >> pointData;
			cout << "请输入要插入数据的位置: ";
			cin >> index;
			l.InsertElemAtIndex(pointData, index);
			break;
		case 8:
			DataType headData;
			cout << "请输入要在头部插入的值: ";
			cin >> headData;
			l.InsertElemAtHead(headData);
			break;
		case 9:
			l.DeleteElemAtEnd();
			break;
		case 10:
			l.DeleteAll();
			break;
		case 11:
			DataType pointDeleteData;
			cout << "请输入要删除的数据: ";
			cin >> pointDeleteData;
			l.DeleteElemAtPoint(pointDeleteData);
			break;
		case 12:
			l.DeleteElemAtHead();
			break;
		default:
			break;
		}
	} while (i != 0);

	system("pause");
	return 0;
}

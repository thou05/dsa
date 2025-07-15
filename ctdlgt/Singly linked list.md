Created: 202409221838
Tags: 

Danh sách liên kết đơn (Single Linked List) là một cấu trúc dữ liệu động hay là một danh sách mà mỗi phần tử đều liên kết với phần tử đứng sau nó trong danh sách.

Mỗi nút (node) gồm 
- phần tử dữ liệu 
- con trỏ đến nút tiếp theo trong danh sách

###### Các thao tác:
- Thao tác thêm nút vào đầu
	![[Pasted image 20240923104205.png]]
- Thao tác thêm nút vào cuối
	![[Pasted image 20240923104230.png]]
- Thao tác thêm nút vào giữa
	![[Pasted image 20240923104302.png]]
- Thao tác xóa nút
	![[Pasted image 20240923104322.png]]

###### Xây dựng
![[Pasted image 20240923105415.png]]

```C++
template <typename T>
class Node{
	public:
		T elem;
		Node *next;
		
		Node(T e, Node *n = NULL) : elem(e), next(n) {}
};

template <typename T>
class Slist{
	private:
		Node<T> *head;
		Node<T> *trail;
		int n;
	public:
		Slist() : head(NULL), trail(NULL), n(0) {}
		void push_front(T x){
			Node<T> *newNode = new Node<T>(x, head); //Tạo node mới, next trỏ vào head
			head = newNode;
			if(n == 0){
				trail = newNode; // Nếu danh sách rỗng, trail cũng trỏ vào node mới
			}
			n++;
		}
		void erase(T x){
			if(!head){
				return;  // Nếu danh sách rỗng, thoát
			}
			// Nếu phần tử đầu tiên là x, xóa nó
			while( head && head->elem == x){
				Node<T> *temp = head;
				head = head->next;
				delete temp;
				n--;
			}
			// Duyệt các phần tử còn lại
			Node<T> *curr = head;
			Node<T> *prev = NULL;
			while(curr){
				if(curr->elem = x){
					prev->next = curr->next; // Bỏ qua node hiện tại
					if(curr == trail){
						trail = prev; // Cập nhật trail nếu cần
					}
					delete curr;
					n--;
					curr = prev->next // Cập nhật current sang node tiếp theo
				}else{
					preve = curr;
					curr = curr->next;
				}
			}
		}
}

```

Giải thích
`Node<T>* newNode = new Node<T>(x, head);`
- Khai báo con trỏ `newNode` trỏ đến đối tượng kiểu `Node<T>` chứa dữ liệu kiểu `T`
- `new` toán tử cấp phát động, trả về địa chỉ của đối tượng được cấp phát
- `Node<T>(x, head)` gọi constructor, `x`: giá trị kiểu `T`, `head` con trỏ đến node hiện tại đang đứng đầu danh sách, `next` của node mới trỏ đến node cũ đứng đầu


#### Cài đặt
Sử dụng con trỏ header trỏ vào node đầu danh sách, trỏ trailer trỏ vào node cuối danh sách

```C++
#include <bits/stdc++.h>
#ifndef __node__
#define __node__

using namespace std;

template<class T>
class node{
	private:
		T elem;
		node *next;
	public:
		node(){}
		node(T x, node<T> *N = NULL){
			elem = x;
			next = N;
		}
		void setElem(T x){
			elem = x;
		}
		void setNext(node<T> *N = NULL){
			next = N;
		}
		T &getElem(){
			return elem;
		}
		node<T> *&getNext(){
			return next;
		}
};
#endif
```
```C++
#include <bits/stdc++.h>
#include "node.cpp"
#ifndef __iterator__
#define __iterator__
using namespace std;

template <class T>
class Iterator{
	private:
		node<T> *curr; //con tro tro vao node hien tai
	public:
		Iterator(){
			curr = NULL;	
		}
		Iterator(node<T> *p){
			curr = p;
		}
		node<T> *getCurr(){
			return curr;
		}
		Iterator<T> &operator =(Iterator<T> p){
			this->curr = p.getCurr();
			return *this;
		}
		bool operator !=(Iterator<T> p){
			return curr != p.getCurr();
		}
		Iterator<T> operator++(){
			curr = curr->getNext();
			return curr; //tu dong ep kieu thanh iterator vi co ham tao co doi
		}
		Iterator<T> operator++(int){
			node<T> *temp = curr;
			curr = curr->getNext();
			return temp;
		}
		T &operator *(){
			return curr->getElem();
		}
};
#endif
```
```C++
#include <bits/stdc++.h>
#include "node.cpp"
#include "iterator.cpp"
#ifndef __slist__
#define __slist__
using namespace std;

template<class T>
class Slist{
	private:
		node<T> *head, *tail;
		unsigned int len; //so phan tu hien tai trong list
	public:
		typedef Iterator<T> iterator;
		Slist(): head(NUll), tail(NULL), len(0){}
		Slist(int k, T x){
			head = tail = NULL;
			len = 0;
			for(int i = 1; i <= k; i++){
				push_back(x);  //?what da co push back dou
			}
		}
		iterator begin(){
			return head;
		}
		iterator end(){
			return NULL;
		}
		unsigned size(){
			return len;
		}
		bool empty(){
			return len == 0;
		}
		T &front(){
			return head->getElem();
		}
		T &back(){
			return tail->getElem();
		}
		void push_front(T x){
			head = new node<T>(x, head);
			if(len == 0){
				tail = head;
			}
			len++;
		}
		void push_back(T x){
			if(len == 0){
				push_front(x);
			}else{
				tail->setNext(new node<T>(x, NULL));
				tail = tail->getNext();
				len++;
			}
		}
		void pop_front(){
			if(len == 0){
				return;
			}
			if(len == 1){
				head = tail = NULL;
			}else{
				head = head->getNext();
			}
			len--;
		}
		void pop_back(){
			if(len == 0){
				return;
			}
			if(len == 1){
				head = tail = Null;
				len--;
				return;
			}
			node<T> *p = head;
			while(p->getNext() != tail){
				p = p->getNext();
			}
			p->setNext(NULL);
			tail = p;
			len--;
		}
};
#endif
```
```C++
//Demo 
#include <bits/stdc++.h>
#include "slist.cpp"
using namespace std;
int main(){
	Slist<int> L(10, 1);
	for(auto x: L){
		cout << x << " ";
	}
	Slist<int>::iterator it;
	cout <<endl << "Duyet bo lap xuoi: ";
	for(it = L.begin(); it != L.end(); it++){
		cout << *it << " ";
	}
	cout << endl << "Duyet auto: ";
	for(auto x : L){
		cout << x << " ";
	}
}
```
###### Code sfit
```C++
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class node{
	private:
		T elem;
		node *next;
		node *pre;
	public:
		node(T e = T(), node *n = NULL){
			elem = e;
			next = n;
		}
		T &getElem(){
			return elem;
		}
		node<T> *&getNext(){
			return next;
		}
		void setElem(T val){
			elem = val;
		}
		void setNext(node<T> *n){
			next = n;
		}
};

template <typename T>
class slist{
	private:
		node<T> *head, *tail;
		int len;
	public:
		slist(): head(NULL), tail(NULL), len(0){}
		class iterator{
			private: 
				node<T> *curr;
			public:
				iterator(node<T> *p = NULL): curr(p) {}
				node<T> *getCurr(){
					return curr;
				}
				iterator &operator =(iterator &p){
					this->curr = p.getCurr();
					return *this;
				}
				bool operator !=(iterator p){
					return curr != p.getCurr();
				}
				iterator operator ++(){
					curr = curr->getMext();
					return curr;
				}
				iterator operator ++(int){
					node<T> *temp = curr;
					curr = curr->getNext();
					return temp;
				}
				T &operator *(){
					return curr->getElem();
				}
		};

		iterator begin(){
			return head;
		}
		iterator end(){
			return NULL;
		}
		int size(){
			return len;
		}
		bool empty(){
			return len == 0;
		}
		T &front(){
			return head->getElem();
		}
		T &back(){
			return tail->getElem();
		}
		void push_front(T val){
			head = new node<T>(val, head);
			len++;
			if(len == 1){
				tail = head;
			}
		}
		void push_back(T val){
			if(len == 0){
				push_front(val);
			}else{
				tail->setNext(new node<T>(val, NULL));
				tail = tail->getNext();
				++len;
			}
		}
		void pop_front(){
			if(len == 0){
				return;
			}
			if(len == 1){
				head = tail = NULL;
			}else{
				head = head->getNext();
			}
		}
		void pop_back(){
			if(len == 0){
				return;
			}
			if(len == 1){
				head = tail = NULL;
			}else{
				node<T> *p = head;
				while(p->getNext() != tail){
					p = p->getNext();
				}
				p->setNext(NULL);
				tail = p;
			}
			--len;
		}
};
int main(){
	slist<int> L;
	L.push_back(3);
	L.push_back(1);
	L.push_back(5);
	L.push_front(0);
	L.pop_front();
	for(slist<int>::iterator it = L.begin(); it != L.end(); it++){
		cout << *it << ' ';
	}
}
```

#### Phân tích
###### Hàm push_front
![[Pasted image 20240922222513.png]]
```C++
void push_front(T x){
	head = new node<T>(x, head);
	if(len == 0){
		tail = head;
	}
	len++;
}
```

```C++
void push_front(T val){
	head = new node<T>(val, head);
	len++;
	if(len == 1){
		tail = head;
	}
}
```
- gán head bằng node mới

###### Hàm push_back
![[Pasted image 20240922222748.png]]
```C++
void push_back(T x){
	if(len == 0){
		push_front(x);
	}else{
		tail->setNext(new node<T>(x, NULL));
		tail = tail->getNext();
		len++;
	}
}
```
```C++
void push_back(T val){
	if(len == 0){
		push_front(val);
	}else{
		tail->setNext(new node<T>(val, NULL));
		tail = tail->getNext();
		++len;
	}
}
```

###### Hàm insert
![[Pasted image 20240922223236.png]]
```C++
void insert(iterator pos, T val){
	if(pos.getCurr() == head){
		push_front(val);
	}else if(pos.getCurr() == NULL){
		push_back(val);
	}else{
		node<T> *pre = head;
		while(pre->getNext() != pos.getCurr()){
			pre = pre->getNext();
		}
		node<T> *newNode = new node<T>(val, pos.getCurr());
		pre->setNext(newNode);
		++len;
	}
}
```
- Kiểm tra xem `pos` có trỏ đến `head` không, nếu đúng thì dùng hàm `push_front`.
- Nếu `pos` là `NULL` (nghĩa là sau `tail`), dùng `push_back`.
- Nếu không, chèn một node mới vào giữa hai node, dùng con trỏ `prev` để tìm vị trí trước `pos`.

###### Hàm pop_front
![[Pasted image 20240922223305.png]]
```C++
void erase(iterator pos) { 
	if (pos.getCurr() == head) { 
		pop_front(); 
	} else if (pos.getCurr() == tail) { 
		pop_back(); 
	} else { 
		node<T> *prev = head; 
		while (prev->getNext() != pos.getCurr()) { 
			prev = prev->getNext(); 
		} 
		prev->setNext(pos.getCurr()->getNext()); 
		delete pos.getCurr(); 
		--len; 
	} 
}
```
- Kiểm tra xem `pos` có trỏ đến `head` không, nếu đúng thì dùng `pop_front`.
- Nếu `pos` trỏ đến `tail`, dùng `pop_back`.
- Nếu không, xóa node giữa hai node, tìm vị trí trước `pos` bằng con trỏ `prev`.

###### Hàm pop_back



-----
## References
1. [code node]( https://ideone.com/Udb9nc)
2. [code slist iterator](https://ideone.com/Cfied0?)
3. [code slist](https://ideone.com/3ajMD5?)
4. https://ideone.com/dgdlxb?
5. https://github.com/sfit-utc/Cau-Truc-Du-Lieu-va-Giai-Thuat/blob/main/2024-2025/Wednesday/List/List.cpp
6. https://topdev.vn/blog/danh-sach-lien-ket-don-trong-c/
7. 
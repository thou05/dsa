Created: 202409291908
Tags: 

#### cài đặt bằng mảng
```C++
#include <bits/stdc++.h>
#ifndef __STACK__
#define __STACK__

using namespace std;

template<typename T>
class Stack{
	private:
		int num, cap;
		T *elem;
	public:
		Stack(): num(0), cap(0), elem(NULL) {}
		int size(){
			return num;
		}
		bool empty(){
			return num == 0;
		}
		T &top(){
			return elem[num-1];
		}
		void pop(){
			num--;
		}
		void push(T x){
			if(cap == num){
				cap = cap ? cap * 2 : 1;
				T *temp = new T[cap];
				for(int i = 0; i < num; i++){
					temp[i] = elem[i];
				}
				if(elem){
					delete[] elem;
				}
				elem = temp;
			}
			elem[num++] = x;
		}
		void clear(){
			num = 0;
		}
};
#endif
```

SFIT
```C++
#include <bits/stdc++.h>
#ifndef __STACK__
#define __STACK__
using namespace std;

template<typename T>
class Stack{
	private:
		int Size, Space;
		T *elem;
	public:
		Stack(){
			Size = Space = 0;
			elem = NULL;
		}
		~Stack(){
			if(elem != NULL){
				delete[] elem;
			}
		}
		Stack<T> &operator=(Stack<T> &s){
			if(this == &s){
				return *this;
			}
			this->Size = s.Size;
			this->Space = s.Space;
			if(elem != NULL){
				delete[] elem;
			}
			elem = new T[Space];
			for(int i = 0; i < Size; i++){
				elem[i] = s.elem[i];
			}
			return *this;
		}
		Stack(Stack<T> &s){
			*this = s;
		}
		int size(){
			return Size;
		}
		bool empty(){
			return Size == 0;
		}
		T &top(){
			return elem[Size - 1];
		}
		void pop(){
			if(empty()){
				return;
			}
			Size--;
		}
		void clear(){
			Size = 0;
		}
		void push(T val){
			if(Size == Space){
				Space = Size == 0 ? 1 : Size * 2;
				T *temp = new T[Space];
				for(int i = 0; i < Size; i++){
					temp[i] = elem[i];
				}
				if(elem != NULL){
					delete[] elem;
				}
				elem = temp;
			}
			elem[Size] = val;
			++Size;
		}
};
#endif
```

#### Cai dat bang node
```cpp
#include <bits/stdc++.h>
#ifndef __nodeStack__
#define __nodeStack__

using namespace std;

template<class T>
class node{
	private:
		T elem;
		node<T> *next;
	public:
		node<T>(T x, node<T> *n = NULL){
			elem = x;
			next = n;
		}
		node<T> &getNext(){
			return next;
		}
		T &getElem(){
			return elem;
		}
};

template<class T>
class Stack{
	private:
		unsigned num;
		node<T> *head;
	public:
		Stack(): num(0), head(NULL){}
		unsigned size(){
			return num;
		}
		bool empty(){
			return num == 0;
		}
		T &top(){
			return head->elem;
		}
		void pop(){
			if(num < 1){
				num = 0;
				head = NULL;
				return;
			}
			head = head->getNext();
			num--;
		}
		void push(T x){
			head = new node<T>(x, H);
			num++;
		}
};
#endif
```

-----
## References
1. https://ideone.com/AuYDoZ
2. https://github.com/sfit-utc/Cau-Truc-Du-Lieu-va-Giai-Thuat/blob/main/2024-2025/Wednesday/Stack/Stack.cpp
3. https://ideone.com/s6RpaH

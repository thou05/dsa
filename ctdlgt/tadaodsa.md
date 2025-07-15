


## Vector
`Trình bày cấu trúc của 1 lớp vector`
- Các thuộc tính
	Sử dụng mảng V có kích thước N chứa các phần tử của vector
	Một biến n lưu trữ kích thước của vector (số phaàn tử được lưu trữ)
- Cấu trúc
	- Khai báo 
		`vector<T> vecName(n)`
		`vector<T> vecName(n, value)`
		`vector<T> vecName(arr, arr + n)`
	- Modifiers: `assign, pop_back, insert, erase, emplace, emplace_back, swap, clear`
	- Iterators: `begin, end, rbegin, rend`
	- Capacity: `size, max_size, capacity, resize, empty, shrink_to_fit, reserve`
	- Element access `at, data, front, back, []`

## List
- KN: Là một dãy các vị trí lưu trữ các đối tượng với số lượng tùy ý. Nó thiết lập một mối quan hệ trước sau giữa các vị trí
- Cấu trúc: `front, back, push_back, push_front, insert, pop_back, pop_front, erase, begin, end, rbegin, rend, size, empty`
#### lien ket don
- KN:
	- Các nút được cài đặt bao gồm
		- Phần tử lưu trữ trong nó
		- Một liên kết đến nút kế tiếp
	- Sử dụng một con trỏ header, trỏ vào node đầu danh sách và con trỏ trailer trỏ vào node cuối danh sách
- Hình ảnh minh họa
	![[minhhoalkdon.png]]

- tap tam gia
```
//Tichpx - tap tam giac
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,res=0;
	cin>>n;
	int a[n]; 
	for(auto &x:a) cin>>x;
	sort(a,a+n,greater<int>());
	list<int> L;
	for(auto x:a)
	{
		while(L.size()>1 && L.front()>=L.back()+x) L.pop_front();
		L.push_back(x);
		if(res<L.size()) res=L.size();
	}
	if(res<3) cout<<"Khong the tao ra day thoa man";
	else cout<<res;
}

```

- Giai thua so lon
```cpp
//Tichpx  - giai thua so lon
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,d=0;
	cin>>n;
//	list<long long> L(1,1);
	
	deque<long long> L(1,1);                    //deque -> hang doi hai dau
	while(n>1)
	{
		long long nho=0;
		for(auto it=L.rbegin();it!=L.rend();it++)
		{
			nho+=*it*n;
			*it=nho%10;
			nho/=10;
		}
		while(nho) {L.push_front(nho%10); nho/=10;}
		n--;
		while(L.back()==0) {d++; L.pop_back();}
	}
	for(auto x:L) cout<<x;
	cout<<string(d,'0');
}

```
#### lien ket kep
- KN
	- Các nút được cài đặt bao gồm
		- Phần tử lưu trữ trong nó
		- Một liên kết đến nút trước nó
		- Một liên kết đến nút kế tiếp
	- Có 2 nút đặc biệt là trailer và header
- Hình vẽ minh họa
	![[minhhoalkkep.png]]

- trinh thám
```cpp
//Tichpx - lai la trinh tham (list=deque, priority_queue, interval-tree)
#include<bits/stdc++.h>
using namespace std;
#define vt first
#define gt second

int main()
{
	//list <pair<int,int>> L;
	deque <pair<int,int>> L;
	int n,k,x;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		while(L.size() && L.back().gt<=x) L.pop_back();
		L.push_back({i,x});
		if(i>=k)
		{
			while(i-L.front().vt>=k) L.pop_front();
			cout<<L.front().gt<<" ";
		}
	}
}

```

## Stack
- Khái niệm: Stack là cách tổ chức lưu trữ các đối tượng dưới dạng một danh sách tuyến tính mà việc bổ sung đối tượng và lấy các đối tượng ra được thực hiện ở cùng một đầu của danh sách. Stack được gọi là danh sách kiểu LIFO (Last In First Out - vào sau ra trước)
- Cấu trúc 
	- Các phép toán chính
		push(Object o): bổ sung đối tượng o vào stack
		pop(): lấy ra và trả lại phần tử được bổ sung vào cuối cùng của stack
	- Các phép toán bổ trợ
		top(): tả lại tham chiếu đến phần tử được bổ sung vào cuối cùng của stack
		size(): trả lại số phần tử hiện lưu trữ trong stack
		empty(): trả lại giá trị kiểu boolean để xác định stack có lưu trữ phần tử nào hay không

- Hình ảnh minh họa
	![[minhhoastack.png]]
	- thực hiện bổ sung phần tử từ trái qua phải
	- sử dụng biến t lưu chỉ số của phần tử ở đỉnh stack

#### Ký pháp ba lan
- Thuật toán chuyển biểu thức biểu diễn theo ký pháp trung tố về dạng biểu diễn ký pháp hậu tố
	- Sử dụng 2 stack Opr (lưu các toán tử) và BLExp (lưu biểu thức dạng hậu tố)
	- Thuật toán:
		- Đọc lần lượt từ trái qua phải biểu thức dạng trung tố
		- Nếu gặp dấu "(" thì PUSH vào Opr
		- Nếu gặp toán hạng thfi PUSH vào BLExp
		- Nếu gặp dấu ")" thì POP các toán tử của Opr và PUSH vào BLExp cho đến khi gặp dấu "(" thì POP dấu "(" bỏ nó đi
		- Nếu gặp toán tử thì
			- Nếu Opr rỗng thì PUSH toán tử đó vào Opr
			- Nếu toán tử được PUSH vào Opr cuối cùng có mức ưu tiên cao hơn toán tử vừa đọc thì: lần lượt POP các toán tử ra khỏi Opr và PUSH vào BLExp, đến khi gặp toán tử có mức ưu tiên thấp hơn hoặc Opr rỗng thì dừng lại. PUSH toán tử vào Opr
			- Nếu toán tử được PUSH vào Opr cuối cùng có mức ưu tiên nhỏ hơn toán tử vừa đọc thì: PUSH toán tử vừa đọc vào Opr
			• Cuối cùng POP tất cả các toán tử còn lại trong Opr và PUSH vào BLExp
			• Đảo ngược thứ tự các phần tử trong BLExp ta được biểu thức dạng hậu tố
		Thứ tự ưu tiên các toán tử (giảm dần): /, \*, -, +, ), (
	
- Thuật toán tính giá trị của biểu thức dạng hậu tố
	- Biểu thức lưu trong Stack BLExp, sử dụng stack phụ T
	- Thực hiện POP lần lượt các phần tử trong BLExp
		-  Nếu gặp toán hạng thì PUSH nó vào T
		-  Nếu gặp toán tử thì: POP 2 phần tử đầu của T ra và thực hiện với toán tử đó, PUSH kết quả thu được vào T.
	- Quá trình thực hiện cho đên khi BLExp rỗng. Giá trị của biểu thức là phần tử còn lại trong T.
#### Bài tập
1. biểu thức hậu tố ba lan
```
Biểu thức số học mà các toán tử chỉ gồm các phép tính **+ , -, *, /** trên trường số nguyên và các toán hạng là các số tự nhiên nằm trong đoạn [0,9]. Bạn hãy lập trình chuyển đổi sang dạng hậu tố Ba Lan sau đó tính giá trị của biểu thức
```
```cpp
#include<bits/stdc++.h>
using namespace std;
map<char,int> ut={{'*',2},{'/',2},{'+',1},{'-',1},{'(',0}};
int f(int a,int b, char o) 
{
	if(o=='+') return a+b;
	if(o=='-') return a-b;
	if(o=='*') return a*b;
	if(o=='/') return a/b;
}
int main()
{
	string x,h;
	stack<char> S;
	getline(cin,x);
	for(char c:x)
	if('0'<=c && c<='9')  h+=c; 
	else if(c=='(') S.push(c); 
	else if(ut.find(c)!=ut.end()) 
	{
		while(S.size() && ut[S.top()]>=ut[c]) {h+=S.top();S.pop();}
		S.push(c);
	}
	else //c==')'
	{
		while(S.top()!='(') {h+=S.top();  S.pop();}	
		S.pop();
	}
	while(S.size()) {h+=S.top(); S.pop();}
	cout<<h<<"\n";
	stack<int> O;
	for(auto c:h)
	if('0'<=c && c<='9') O.push(c-'0'); 
	else
	{
		int k=O.top(); O.pop();
		O.top()=f(O.top(),k,c);
	}
	cout<<O.top();
}
```

2. Khối lượng hóa chất
```
Một chất hữu cơ chỉ gồm các nguyên tố hóa học C,H,O có khối lượng phân tử tương ứng C=12, H=1, O=16.

Ví dụ Axit capric có công thức CH3-CH2-CH2-CH2-CH2-CH2-CH2-CH2-CH2-COOH ở dạng rút gọn CH3(CH2)8COOH

Bài toán đặt ra là cho một công thức ở dạng rút gọn bạn hãy tính khối lượng hóa chất đó biết rằng số rút gọn chỉ nằm trong khoảng [2,9].
```
```cpp
#include<bits/stdc++.h>
using namespace std;
void sol()
{
	map<char,int> K={{'C',12},{'O',16},{'(',0},{'H',1}};
	string x;
	cin>>x;
	stack<int> S;
	for(auto c:x)
	if(K.find(c)!=K.end()) S.push(K[c]);
	else if(c==')')
	{
		int t=0; 
		while(S.top()!=0) t+=S.top(),S.pop();
		S.top()=t;	
	} 
	else S.top()*=c-'0';
	int t=0; 
	while(S.size()) t+=S.top(),S.pop();
	cout<<t<<"\n";
}
int main()
{
	int test;
	cin>>test;
	while(test--) sol();
}
```

4. Kiểm tra ngoặc
```cpp
//Tichpx
#include<bits/stdc++.h>
using namespace std;
map<char,int> A={{'(',1},{')',1},{'[',2},{']',2},{'{',3},{'}',3}};
map<char,char> B={{'(',')'},{'[',']'},{'{','}'}};

string sol()
{
	string x;
	cin>>x;
	stack<char> S;	
	for(char c:x)
	if(B.find(c)!=B.end())
	{
		if(S.size() && A[S.top()]<A[c]) return "Sai";
		S.push(B[c]);
	}
	else if(c==')' or c==']' or c=='}') 
	{
		if(S.empty() or S.top()!=c) return "Sai";
		S.pop();
	}
	return S.empty()?"Dung":"Sai";	
}

int main()
{
	int t;
	cin>>t;
	while(t--) cout<<sol()<<"\n";
}

```

5. Chuyển xâu thập phân sang nhị phân
```cpp
void cv(int x){
    stack<int> s;
    while(x!=0){
        s.push(x%2);
        x/=2;
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}
int main(){
	int n;
	cout << "nhap so thap phan";
	cin >> n;
	cout << "so nhi phan la:";
	cv(n);
}
```

## Queue
`Trình bày khái niệm, cấu trúc của 1 queue, cài đặt queue bằng mảng / dslk đơn`
- KN: Queue là một CTDL trừu trượng, tổ chức lưu trữ các đối tượng dưới dạng một danh sách tuyến tính mà việc bổ sung đối tượng được thực hiện ở đầu này danh sách và việc lấy đối tượng ra được thực hiện đầu kia của danh sách (FIFO - First In First Out)
- Cấu trúc
	- Các pháp toán chính
		push(Object o): bổ sung 1 phần tử o vào cuối của queue
		pop(): xóa đi phần tử đầu của queue
	- Các phép toán bổ trợ
		front(): trả lại phần tử đầu queue nhưng không xóa
		back(): trả lại phần tử cuối queue nhưng không xóa
		size(): trả lại số phần tử hiện đang được lưu trữ trong queue
		empty(): trả lại giá trị kiểu boolean để xác định có phần tử được lưu trữ trong queue không
- Hình ảnh minh họa
	![[minhhoaqueue.png]]

#### Bài tập
1. Búp bê nga
```cpp
#include<bits/stdc++.h>
using namespace std;
signed main()
{
    int n, k, res = 0;
    cin >> n >> k;
    int a[n];
    for(int &x:a)   cin >> x;
    sort(a, a + n, greater<int>());
    queue<int> Q;
    for(int x:a){
        Q.push(x);
        if(Q.front() >= k + x)  Q.pop();
        else res += x;
    }
    cout << Q.size() << " "<< res;
    return 0;
}
```


## Tree
#### Cây tổng quát
- KN: Cây là một tập các nút với quan hệ cha-con (parent-child) giữa các nút, có một nút được gọi là gốc và nó không có cha. Trong khoa học mt, cây là một hô hình trừu tượng của cấu trúc phân cấp
- Cấu trúc lớp cây tổng quát
	- Thuộc tính
		`Node *root`
	- Phương thức
		```
		int size()
		int isEmpty()
		int isInternal(Node8)
		int isExternal(Node*)
		int isRoot(Node*)
		void preOrder(Node*)
		void inOrder(Node*)
		void postOrder(Node*)
		void insert(Node *parent, Element e)
		void remove(Node*)
		Node *root()

		```

```
Khi xây dựng lớp mẫu Node của cây tổng quát gồm public: T elem, vector<Node<T>*> child, hãy lập trình các hàm sau:
	- Hàm void count(Node<T> *H, T x) đếm tất cả các Node của cây H chứa x
	- Hàm void high(Node<T> *H) xác định chiều cao của cây H
```
```cpp
void count(Node<T> *H, T x){
	int sum = 0;
	if(H == NULL){
		return;
	}
	if(H->elem == x){
		sum++;
	}
	for(auto childNode: H->child){
		count(childNode, x);
	}
	if(H->elem == x && H->child.empty()){
		cout << "Cac node cua cay H chua " << x << ": " << sum;
		sum = 0;
	}
}


int high(Node<T> *H) {
    if (!H) return 0; 
    int maxHeight = 0;

    for (Node<T>* childNode : H->child) {
        maxHeight = max(maxHeight, high(childNode));
    }

    return 1 + maxHeight;
}
```
#### Cây nhị phân
- ĐN: Cây nhị phân là một cây có các tính chất sau
	- Mỗi một nút trong có nhiều nhất 2 nút con
	- Các nút con của 1 nút là 1 cặp có thứ tự
- Cấu trúc 
	- Kế thừa phương thức của ADT cây (copy trên cây tổng quát)
	- Thêm các phương thức : `địa chỉ left(p), địa chỉ right(p), int hasLeft(p), int hasRight(p)`
	
	- thuộc tính `BTreeNode *root`
	- Phương thức
		```
		BTreeNode *getroot()
		int size()
		int isEmpty()
		int isInternal(BTreeNode*)
		int isEnternal(BTreeNode*)
		int isRoot(BTreeNode*)
		void preOrder(BTreeNode*, void (*visit)(BTreeNode*))
		void inOrder(BTreeNode*, void (*visit)(BTreeNode*))
		void postOrder(BTreeNode*, void (*visit)(BTreeNode*))
		BTreeNode* insert(BTreeNode *parent, element)
		void remove(BTreeNode*)
		
		```
	
```cpp
//implement binary tree

void inOrder(Node<T> *H){
	if(H == NULL){
		return;
	}
	inOrder(H->left);
	cout << H->elem << " ";
	inOrder(H->right);	
}
void preOrder(Node<T> *H){
	if(H == NULL){
		return;
	}
	cout << H->elem << " ";
	preOrder(H->left);
	preOrder(H->right);	
}

void postOrder(Node<T> *H){
	if(H == NULL){
		return;
	}
	postOrder(H->left);
	postOrder(H->right);
	cout << H->elem << " ";
}

int count_leaf(Node<T>* H) {
    if (H == nullptr) return 0;
    if (H->left == nullptr && H->right == nullptr) return 1;
    return count_leaf(H->left) + count_leaf(H->right);
}

T sum(Node<T> *H){
	if (H == nullptr) return T();
    return H->elem + sum(H->left) + sum(H->right);
}

int height(Node<T> *H){
	if(H == NULL){
		return 0;
	}
	int left = height(H->left)
	int right = height(H->right);
	return max(left, right) + 1;
}

void deleteNode(Node *root, int data){
    if(root == NULL){
        return root;
    }
    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }else{
        if(root->left == NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
 
void checkLeaf(Node *root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
    }
    checkLeaf(root->left);
    checkLeaf(root->right);
}
 
void addNode(Node *parent, int data){
    if(parent == NULL){
        return new Node(data);
    }
    if(data < parent->data){
        parent->left = addNode(parent->left, data);
    }else if(data > parent->data){
        parent->right = addNode(parent->right, data);
    }
    return parent;
}
```


#### Cây tìm kiếm nhị phân
- Khái niệm: cây tìm kiếm nhị phân là cây nhị phân thỏa mãn: 
	- Nút cha có khóa lớn hơn khóa của tất cả các nút của cây con bên trái và nhỏ hơn khóa của tất cả các nút của cây con bên phải. 
	- Các nút con trái và phải cũng là cây tìm kiếm nhị phân.
- Cấu trúc lớp của cây tìm kiếm nhị phân
	- Thuộc tính
		`Node<Keys, T> *root`
	- Phương thức
		```
		int size()
		int isEmpty()
		int isInternal(Node<Key,T>*)
		int isExternal(Node<Key,T>*)
		int isRoot(Node<Keys,T>*)
		void preOrder(Node<Keys,T>*)
		void inOrder(Node<Keys,T>*)
		void postOrder(Node<Keys,T>*)
		Node<Keys,T> *search(Keys, Node<Keys,T>*)
		Node<Keys,T> *insert(Keys, T)
		void remove(Keys)
		Node<Keys,T> *root()
		```

```
Khi xây dựng lớp mẫu Node của cây tìm kiếm nhị phân gồm public: T elem, Node<T> *left, *right; giả sử có sẵn các toán tử so sánh đối với kiểu dữ liệu T hãy lập trình các phương thức sau:
	- Hàm T *max(T x) tìm giá trị của phần tử lớn nhất trong cây (cây đã khác rỗng)
	- Hàm void erase(T x) xóa dữ liệu x ra khỏi cây nếu có
```
```cpp
T *max(T x){
	if(root == NULL) return NULL;
	Node<T> *p = root;
	while(p->right != NULL){
		p = p->right;
	}
	return &(p->elem);
}
void erase(T x){
	root = deleteNode(root, x);
}

T* max(T x) {
	Node<T>* current = this; 
	while (current->right != nullptr) {
		current = current->right;  
	}
	return &(current->elem);    
}

void erase(T x) {
	Node<T>** current = this;
	while (*current != nullptr) {
		if (x < (*current)->elem) {
			current = &((*current)->left); 
		} else if (x > (*current)->elem) {
			current = &((*current)->right); 
		} else {
			break; 
		}
	}
	if (*current == nullptr) return; 
	Node<T>* target = *current; 
	if (target->left == nullptr && target->right == nullptr) {
		delete target;
		*current = nullptr;
	}else if (target->left == nullptr) {
		*current = target->right;
		delete target;
	}else if (target->right == nullptr) {
		*current = target->left;
		delete target;
	}else {
		Node<T>* maxLeft = target->left;
		Node<T>** parentOfMaxLeft = &(target->left);
		while (maxLeft->right != nullptr) {
			parentOfMaxLeft = &(maxLeft->right);
			maxLeft = maxLeft->right;
		}
		target->elem = maxLeft->elem;
		*parentOfMaxLeft = maxLeft->left;
		delete maxLeft;
	}
}
```
## Sort
#### Bubble sort
- Ý tưởng: Thực hiện chuyển dần các phần tử có giá trị khóa nhỏ về đầu dãy, các phần tử có khóa lớn về cuối dãy
- Lập trình
	```cpp
	//cach 1
	void bubbleSort(int a[], int n){
	    for(int i = 0; i < n - 1; i++){
	        for(int j = 0; j < n - i - 1; i++){
	            if(a[j] > a[j + 1]){
	                swap(a[j], a[j+1]);
	            }
	        }
	    }
	}
	```

#### Selection sort
- Ý tưởng: Chọn phần tử có khóa nhỏ nhất trong các phần tử còn lại chuyển nó về đầu và loại bỏ nó khỏi dãy

- Lập trình
	```cpp
	void selectionSort(int a[], int n){
	    for(int i = 0; i < n - 1; i++){
	        int minPos = i;
	        for(int j = i + 1; j < n; j++){
	            if(a[j] < a[minPos]){
	                minPos = j;
	            }
	        } 
	        swap(a[i], a[minPos]);
	    }
	}
	```

#### Insert sort
- Ý tưởng: Lấy phần tử thứ A[j] chèn vào dãy gồm các phần tử từ A[1]...A[j-1] sao cho ta được dãy A[1]...A[j] được sắp. Trong đó dãy A[1]...A[j-1] là dãy đã được sắp

- Lập trình
	```cpp
	void insertionSort(int a[], int n){
	    for(int i = 1; i < n; i++){
	        int x = a[i], pos = i - 1;
	        while(pos >= 0 && x < a[pos]){
	            a[pos + 1] = a[pos];
	            --pos;
	        }
	        a[pos + 1] = x;
	    }
	}
	```
#### Quick sort
- Ý tưởng : sử dụng pp chia và trị
	- Thực hiện phân hoạch dãy S cần sắp thành 3 dãy S1, S2, S3. Trong đó
		- S2 chỉ có 1 phần tử
		- Tất cả các phần tử của dãy S3 đều > phần tử của dãy S2
		- Tất cả các phần tử cúa dãy S1 đều <= phần tử của dãy S2
		- Dãy S1, S3 có thể là rỗng
	- Tiếp tục phân hoạch dãy S1 và S3 độc lập theo nguyên tắc trên đến khi dãy cần thực hiện phân hoạch chỉ có 1 phần tử thì dừng lại. Khi đó ta được dãy các phần tử được sắp
	
- Lập trình
	```cpp
	int Partition(int a[], int low, int high){
	    int pivot = a[high];
	    int i = low - 1;
	    for(int j = low; j < high; j++){
	        if(a[j] <= pivot){
	            ++i;
	            swap(a[i], a[j]);
	        }
	    }
	    swap(a[i + 1], a[high]);
	    return i + 1;
	}
	
	void quickSort(int a[], int low, int high){
	    if(low < high){
	        int p = Partition(a, low, high);
	        quickSort(a, low, p - 1);
	        quickSort(a, p + 1, high);
	    }
	}
	```
#### Merge sort
- Ý tưởng
	- Chia mảng thành 2 mảng con bằng cách chia đôi mảng ban đầu
	- Áp dụng đệ quy để tiếp tục chia nhỏ mảng con cho đến khi mỗi mảng con chỉ còn một phần tử
	- Trộn hai mảng con đã đc sắp xếp thành 1 mảng lớn hơn đã được sắp xếp
- Lập trình
	```cpp
	void merge(int a[], int left, int mid, int right){
	    int n1 = mid - left + 1;
	    int n2 = right - mid;
	    int l[n1], r[n2];
	    for(int i = 0; i < n1; i++){
	        l[i] = a[left + i];
	    }
	    for(int i = 0; i < n2; i++){
	        r[i] = a[mid + 1 + i];
	    }
	
	    int i = 0, j = 0;
	    int k = left;
	    while(i < n1 && j < n2){
	        if(l[i] <= r[j]){
	            a[k] = l[i];
	            ++i;
	        }else{
	            a[k] = r[j];
	            ++j;
	        }
	        k++;
	    }
	    while(i < n1){
	        a[k] = l[i];
	        ++i;
	        ++k;
	    }
	    while(j < n2){
	        a[k] = r[j];
	        ++j;
	        ++k;
	    }
	}
	
	void mergeSort(int a[], int left, int right){
	    if(left < right){
	        int mid = (left + right) / 2;
	        mergeSort(a, left, mid);
	        mergeSort(a, mid + 1, right);
	        merge(a, left, mid, right);
	    }
	}
	```

#### Heap sort
- Ý tưởng
	- Tạo mảng A[1], ..., A[n] biểu diễn cây Heap
	- Tráo đổi phần tử A[1] với phần tử A[n]
	- Tạo mảng A[1],...,A[n-1] biểu diễn cây heap
	- Tráo đổi phần tử A[1] với phần tử A[n-1]
	- Lặp lại quá trình trên đến khi mảng chỉ còn 1 phần tử

- Lập trình
	```cpp
	void heapify(int a[], int n, int i){
	    int largest = i;
	    int left = 2 * i + 1;
	    int right = 2 * i + 2;
	    
	    if(left < n && a[left] > a[largest]){
	        largest = left;
	    }
	    if(right < n && a[right] > a[largest]){
	        largest = right;
	    }
	    if(largest != i){
	        swap(a[i], a[largest]);
	        heapify(a, n, largest);
	    }
	}
	
	void heapsort(int a[], int n){
	    for(int i = n / 2 - 1; i >= 0; i--){
	        heapify(a, n, i);
	    }
	    for(int i = n - 1; i >= 0; i--){
	        swap(a[i], a[0]);
	        heapify(a, i, 0);
	    }
	}

	```

## Search
#### Linear search
```cpp
bool linearSearch(int a[], int n, int x){
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            return true;
        }
    }
    return false;
}
```

#### Binary search
```cpp
int binarySearch(int a[], int n, int x){
    int l = 0, r = n - 1;
    while(l < r){
        int m = (l + r) / 2;
        if(a[m] == x){
            return m;
        }else if(a[m] < x){ 
            l = m + 1;
        }else{ 
            r = m - 1;
        }

    }
    return -1;
}
```

## Câu 3

```cpp
class Laptop{
    private:
        string ma;
        string hang;
        string ten;
        string cauHinh;
        double donGia;
        int soLuong;
    public:
        Laptop(): ma(""), hang(""), ten(""), cauHinh(""), donGia(0), soLuong(0) {}
        friend istream &operator >>(istream &is, Laptop &lap){
            cout << "Nhap ma: ";
            is.ignore();
            getline(is, lap.ma);
            cout << "Nhap ten: ";
            getline(is, lap.hang);
            cout << "Nhap cau hinh: ";
            getline(is, lap.cauHinh);
            cout << "Nhap don gia: ";
            is >> lap.donGia;
            cout << "Nhap so luong: ";
            is >> lap.soLuong;
        }
        friend ostream &operator <<(ostream &os, Laptop &lap){
            os << lap.ma << ", " << lap.ten << ", " << lap.cauHinh << ", " 
                << lap.donGia << ", " << lap.soLuong << endl;
        }
        string getMa(){
            return ma;
        }
        string getHang(){
            return hang;
        }
        double getGia(){
            return donGia;
        }
        int getSL(){
            return soLuong;
        }
};

class QuanLyLaptop{
    private:
        vector<Laptop> dsLap;
    public:
        void themLap(Laptop &lap){
            dsLap.push_back(lap);
        }
        double tongGiaTonKhoTheoHang(string hang){
            double sum = 0;
            for(auto lap : dsLap){
                if(lap.getHang() == hang){
                    sum += lap.getGia() * lap.getSL();
                }
            }
            return sum;
        }
        void inDS(){
            for(auto lap : dsLap){
                cout << lap << endl;
            }
        }
        int timLapTheoMa(string ma){
            int left = 0, right = dsLap.size() - 1;
            if(left <= right){
                int mid = (left + right) / 2;
                if(dsLap[mid].getMa() == ma){
                    return mid;
                }else if(dsLap[mid].getMa() < ma){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            return -1; 
        }
};
```

```cpp
class QLSV{
private:
	list<SinhVien> ds;
public:
	void them(SinhVien s){
		ds.push_back(s);
	}
	void xoaTheoMa(string ma){
		for(auto it = ds.begin(); it != ds.end(); it++){
			if(it->getMa() == ma){
				ds.erase(it);
				break;
			}
		}
	}
}
```

## Câu 5 - Mô tả quá trình sắp xếp

```
Mô tả quá trình sắp xếp dãy số sau đây bằng thuật toán sắp xếp chọn (SelectionSort).
	43, 12, 13, 76, 25, 76, 65, 21, 62, 26

Giải
n = 10          0   1   2   3   4   5   6   7   8   9  (chỉ số)
i  j  posmin    43  12  13  76  25  76  65  21  62  26
0  1    0       
0  2    1       
0  3    1       
0  4    1       
0  5    1       
0  6    1       
0  7    1       
0  8    1       
0  9    1       
0  10   1       12 `34 `13  76  25  76  65  21  62  26   
1  2    1       
1  3    2       
1  4    2       
1  5    2       
1  6    2       
1  7    2       
1  8    2       
1  9    2       
1  10   2       12  13 `34  76  25  76  65 `21  62  26   
2  3    2       
2  4    2       
2  5    4       
2  6    4       
2  7    4       
2  8    7       
2  9    7  
2  10   7       12  13  21 `76 `25  76  65  34  62  26     
3  4    3            
3  5    4       
3  6    4       
3  7    4       
3  8    4       
3  9    4       
3  10   4       12  13  21  25 `76  76  65  34  62 `26          
4  5    4            
4  6    4       
4  7    6       
4  8    7       
4  9    7       
4  10   9       12  13  21  25  26 `76  65 `34  62  76  
5  6    5       
5  7    6       
5  8    7       
5  9    7       
5  10   7       12  13  21  25  26  34 `65  76 `62  76             
6  7    6       
6  8    6       
6  9    8       
6  10   8       12  13  21  25  26  34  62 `76 `65  76               
7  8    7       
7  9    8       
7  10   8       12  13  21  25  26  34  62  65 `76` 76              
8  9    8       
8  10   8       12  13  21  25  26  34  62  65  76  76   
9 kết thúc     
```

```
Mô tả quá trình sắp xếp dãy số sau đây bằng thuật toán sắp xếp chọn (BubbleSort).
	43, 12, 13, 76, 25, 76, 65, 21, 62, 26

Note
- So sánh a[j] với a[j-1] => nếu swap đánh dấu đổi vị trí ở hàng trên
- j ở vị trí nào thì so sánh 2 bé trước nó, j và j - 1 được sắp lại rồi

Giải
n = 10  0   1   2   3   4   5   6   7   8   9  (chỉ số)
i  j    43  12  13  76  25  76  65  21 `62 `26
0  9    43  12  13  76  25  76  65  21  26  62
0  8    43  12  13  76  25  76 `65 `21  26  62
0  7    43  12  13  76  25 `76 `21  65  26  62
0  6    43  12  13  76 `25 `21  76  65  26  62
0  5    43  12  13 `76 `21  25  76  65  26  62
0  4    43  12  13  21  76  25  76  65  26  62
0  3    43  12  13  21  76  25  76  65  26  62
0  2   `43 `12  13  21  76  25  76  65  26  62
0  1    12  43  13  21  76  25  76  65  26  62
0  0
1  9    12  43  13  21  76  25  76 `65 `26  62
1  8    12  43  13  21  76  25 `76 `26  65  62
1  7    12  43  13  21  76  25  26  76  65  62
1  6    12  43  13  21 `76 `25  26  76  65  62
1  5    12  43  13  21  25  76  26  76  65  62
1  4    12  43  13  21  25  76  26  76  65  62
1  3    12 `43 `13  21  25  76  26  76  65  62
1  2    12  13  43  21  25  76  26  76 `65 `62
1  1
2  9    12  13  43  21  25  76  26 `76 `62  65
2  8    12  13  43  21  25  76  26  62  76  65
2  7    12  13  43  21  25 `76 `26  62  76  65
2  6    12  13  43  21  25  26  76  62  76  65
2  5    12  13  43  21  25  26  76  62  76  65
2  4    12  13 `43 `21  25  26  76  62  76  65
2  3    12  13  21  43  25  26  76  62 `76 `65
2  2
3  9    12  13  21  43  25  26  76  62  65  76
3  8    12  13  21  43  25  26 `76 `62  65  76
3  7    12  13  21  43  25  26  26  76  65  76
3  6    12  13  21  43  25  26  26  76  65  76
3  5    12  13  21 `43 `25  26  26  76  65  76
3  4    12  13  21  25  43  26  26  76  65  76
3  3
4  9    12  13  21  25  43  26  26 `76 `65  76
4  8    12  13  21  25  43  26  26  65  76  76
4  7    12  13  21  25  43  26  26  65  76  76
4  6    12  13  21  25 `43 `26  26  65  76  76
4  5    12  13  21  25  26  43  26  65  76  76
4  4
5  9    12  13  21  25  26  43  26  65  76  76
5  8    12  13  21  25  26  43  26  65  76  76
5  7    12  13  21  25  26 `43 `26  65  76  76
5  6    12  13  21  25  26  26  43  65  76  76
5  5
6  9    12  13  21  25  26  26  43  65  76  76
6  8    12  13  21  25  26  26  43  65  76  76
6  7    12  13  21  25  26  26  43  65  76  76
6  6
7  9    12  13  21  25  26  26  43  65  76  76
7  8    12  13  21  25  26  26  43  65  76  76
7  7
8  9    12  13  21  25  26  26  43  65  76  76
8  8
9ketthuc12  13  21  25  26  26  43  65  76  76
```

```
Mô tả quá trình sắp xếp dãy số sau đây bằng thuật toán sắp xếp chọn (InsertionSort).
	43, 12, 13, 76, 25, 76, 65, 21, 62, 26

Giải
n = 10     0   1   2   3   4   5   6   7   8   9  (chỉ số)
i  j  x    43  12  13  76  25  76  65  21  62  26
1  0  12   43  43  13  76  25  76  65  21  62  26       
1 -1  12   12  43  13  76  25  76  65  21  62  26
2  1  13   12  43  43  76  25  76  65  21  62  26
2  0  13   12  13  43  76  25  76  65  21  62  26
3  2  76   12  13  43  76  25  76  65  21  62  26
4  3  25   12  13  43  76  76  76  65  21  62  26
4  2  25   12  13  43  43  76  76  65  21  62  26
4  1  25   12  13  25  43  76  76  65  21  62  26
5  4  76   12  13  25  43  76  76  65  21  62  26
6  5  65   12  13  25  43  76  76  76  21  62  26
6  4  65   12  13  25  43  76  76  76  21  62  26
6  3  65   12  13  25  43  65  76  76  21  62  26
7  6  21   12  13  25  43  65  76  76  76  62  26
7  5  21   12  13  25  43  65  76  76  76  62  26
7  4  21   12  13  25  43  65  65  76  76  62  26
7  3  21   12  13  25  43  43  65  76  76  62  26
7  2  21   12  13  25  25  43  65  76  76  62  26
7  1  21   12  13  21  25  43  65  76  76  62  26
8  7  62   12  13  21  25  43  65  76  76  76  26
8  6  62   12  13  21  25  43  65  76  76  76  26
8  5  62   12  13  21  25  43  65  65  76  76  26
8  4  62   12  13  21  25  43  62  65  76  76  26
9  8  26   12  13  21  25  43  62  65  76  76  76
9  7  26   12  13  21  25  43  62  65  76  76  76
9  6  26   12  13  21  25  43  62  65  65  76  76
9  5  26   12  13  21  25  43  62  62  65  76  76
9  4  26   12  13  21  25  43  43  62  65  76  76
9  3  26   12  13  21  25  26  43  62  65  76  76
10 KT 
->   12  13  21  25  26  43  62  65  76  76
```

```
n/2-1

Heapsort
n = 7            30  50  `7 | 20  100  70  `100
i 
  pd(A,3,7)      30  `50  100 | 20  `100  70  7
  pd(A,2,7)     `30  100  `100 | 20  50  70  7
  pd(A,1,7)      100  100  `30 | 20  50  `70  7
                `100  100  70 | 20  50  30  `7
7 sw(A[1], A[7]) `7  `100  70 | 20  50  30  100
  pd(A,1,6)      100  `7  70 | 20  `50  30  100
		         `100  50  70 | 20   7  `30  100
6 sw(A[1],A[6])  `30  50 | `70 20  7  100  100
  pd(A,1,5)      `70  50 | 30 20  `7  100  100
5 sw(A[1],A[5])   `7  `50 | 30 20  70  100  100
  pd(A,1,4)       50  `7 | 30 `20  70  100  100
                  `50  20 | 30  `7  70  100  100
4 sw(A[1],A[4])   `7 | 20 `30  50  70  100  100
  pd(A,1,3)       `30 | 20  `7  50  70  100  100
3 sw(A[1],A[3])   `7 | `20  30  50  70  100  100
  pd(A,1,2)       `20 | `7  30  50  70  100  100
2 sw(A[1],A[2])    7 20  30  50  70  100  100
  pd(A,1,1)        7 20  30  50  70  100  100
1 KT

```

```
Mô tả quá trình trộn 2 nửa dãy số sau đây để được dãy được sắp bằng thuật toán trộn trong thuật toán MergeSort
	20, 54, 87, 134, 154, 200 | 10, 55, 70, 80, 92, 160, 300

A 20, 54, 87, 134, 154, 200 | 10, 55, 70, 80, 92, 160, 300
B 10
A 20, 54, 87, 134, 154, 200 | 10, 55, 70, 80, 92, 160, 300
B 10 20 

```

#### mô tả trộn
![[motatron1.png]]
![[motatron2.png]]
![[motatron3.png]]




#### mô tả sắp xếp trộn
![[motasapxeptron1.png]]
![[motasapxeptron2.png]]





#### mô tả phân hoạch partition
![[phanhoachpartition.png]]





#### mô tả sắp xếp quicksort
![[motaquick1.png]]
![[motaquick2.png]]
![[motaquick3.png]]



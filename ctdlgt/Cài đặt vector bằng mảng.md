Created: 202409201706
Tags: 

- Sử dụng mảng V có kích thước cap (capacity)
- Một biến num (number) lưu trữ kích thước của vector (số phần tử được lưu trữ)
- Phép toán reference `operator[]` được thực hiện trong thời gian O(1) bằng việc trả lại `V[r]`
	![[Pasted image 20240904215239.png]]
- Cài đặt Vector bằng mảng:
	- **Không gian** sử cho cấu trúc dữ liệu là **O(n)**
	- Các phép toán **size, empty, at và replace** chạy trong thời gian **O(1)**
	-  **insert và erase** chạy trong thời gian **O(n)**
-  Với phép toán **insert**, khi mảng đầy sẽ dẫn đến ngoại lệ, để tránh trường hợp này chúng ta thay mạng hiện tại bằng mảng lớn hơn

----
#### Khởi tạo mảng
- Một con trỏ để trỏ đến mảng động v - lưu trữ phần tử vector
- Một biến để lưu kích thước hiện tại của mảng (size), và một biến để lưu sức chứa tối đa của mảng (capacity)

#### Cung cấp phương thức cơ bản
- `push_back` Thêm phần tử: Kiểm tra mảng hiện tại đủ sức chứa thêm phần tử mới hay không , nếu không => tăng kích thước theo chiến lược gấp đôi => thêm phần tử vào mảng và cập nhật kích thước
- `operator[]` Truy cập phần tử: Cung cấp phương thức để truy cập phần tử tại chỉ số nhất định, kiểm tra lỗi nếu chỉ số nằm ngoài phạm vi mảng
- `front, back` Truy cập phần tử đầu tiên và cuối cùng: đảm bảo kiểm tra nếu vector rỗng
- `size` Lấy số phần tử: trả về số lượng phần tử hiện tại trong vector
- `empty` Kiểm tra rỗng: để ktra xem vector có chứa bất kì phần tử nào không
- `clear` Xóa tất cả phần tử: thường bằng cách đặt kích thước về 0

#### Code mẫu
```C++
#include<iostream>
#ifndef __vector__
#define __vector__
using namespace std;

template<class T>
class vector_reverse_iterator{  //? class này để làm gì
	private: //có thể ko có dòng này vì C++ tự mặc định private
		T *curr;  
	public:
		vector_reverse_iterator(T *c = 0){
			curr = c;
		}
		vector_reverse_iterator<T> &operator=(vector_reverse_iterator<T> it){ // ? chua hieu 
			this->curr = it.curr;
			return *this;
		}
		vector_reverse_iterator<T> operator++(){ //++curr
			curr--; // ? la sao
			return curr;
		}
		vector_reverse_iterator<T> operator++(int){
			vector_reverse_iterator<T> tmp = curr;
			curr--;
			return tmp;
		}
		T &operator*(){ //? ham nay lam gi
			return *curr;
		}
		bool operator!=(vector_reverse_iterator<T> t){
			return curr != t.curr;
		}
};

template<class T>
class Vector{
	private:
		int cap, num;
		T *buff;
	public:
		//constructor
		Vetor(){
			cap = num = 0;
			buff = 0;
		}
		Vector(int k, T x){
			cap = num = k;
			buff = new T[k];
			for(int i = 0; i < k; i++){
				buff[i] = x;
			}
		}
		//destructor
		~Vector(){
			if(buff){
				delete[] buff;
			}
		}
		int capacity(){
			return cap;
		}
		int size(){
			return num;
		}
		bool empty(){
			return num == 0;
		}
		void pop_back(){
			if(num > 0){
				num--;
			}
		}
		void extend(int newcap){
			if(newcap < cap){
				return;
			}
			cap = newcap;
			T *temp = new T[cap];
			for(int i = 0; i < num; i++){
				temp[i] = buff[i];
			}
			if(buff){
				delete[] buff; //xoa buff cũ
			}
			buff = temp; //gán buff mới nhiều cap hơn
		}
		T &back(){
			return buff[num-1];
		}
		void push_back(T x){
			if(num == cap){
				extend(cap * 2 + 5); //tai sao + 5 ?
			}
			buff[num++] = x;
		}
		T &operator[](int k){ //? khong hieu
			return buff[k];
		}
		void insert(int k, T x){
			if(cap == num){
				extend(cap * 2 + 5);
			}
			for(int i = num - 1; i >= k; i--){ //chua hieu nay lam
				buff[i+1] = buff[i];
			}
			buff[k] = x;
			num++;
		}
		Vector &operator =(Vector<T> V){ //ham nap chong toan tu gan
			this->num = V.num;
			this->cap = V.cap;
			if(cap){
				this->buff = new T[cap];
				for(int i = 0; i < num; i++){
					this->buff[i] = V.buff[i];
				}
			}else{
				this->buff = 0;
			}
			return *this;
		}
		typedef T *iterator;
		iterator begin(){
			return buff;
		}
		iterator end(){
			return buff+num;
		}
		typedef vector_reverse_iterator<T> reverse_iterator;
		reverse_iterator rbegin(){
			return reverse_iterator(buff+num-1);
		}
		reverse_iterator rend(){
			return reverse_iterator(buff-1);
		}
};
#endif


```

#### code sfit
```C++
#ifndef __VECTOR__
#define __VECTOR__
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Vector{
	private: 
		T *elem;
		int Size, space;
	public:
		class iterator{
			private:
				T *curr;
			public:
				iterator(T *p = NULL){
					curr = p;
				}
				iterator &operator ++(int){
					curr++; //chuyen con tro toi o nho tiep
					return *this;
				}
				iterator &operator ++(){
					curr++;
					return *this;
				}
				iterator &operator --(int){
					curr--;
					return *this;
				}
				iterator &operator --(){
					curr--;
					return *this;
				}
				iterator operator +(int i){
					return curr + i; 
				}
				int operator -(iterator it){
					return this->curr - it.curr;
				}
				bool operator ==(const iterator &it) const{
					return curr = it.curr;
				}
				bool operator !=(const iterator &it) const{
					return !(it == (*this));
				}
				T &operator*(){
					//*it - giatri tại vi tri it đang trỏ đến
					return *curr;
				}
				friend ostream &operator <<(ostream &os, const iterator &it){
					os << it.curr;
					return os;
				}
		};

		iterator begin() const{
			return iterator(&elem[0]);
		}
		iterator end() const{
			return iterator(elem + Size);
		}
		iterator rbegin() const{ //đảo đến phần tử cuối cùng
			return elem + Size - 1;
		}
		iterator rend() const{
			return elem - 1;
		}

		Vector(){
			Size = 0;
			space = 0;
		}
		Vector(int n){
			Size = n;
			space = n;
			elem = new T[n];
			for(int i = 0; i < n; i++){
				elem[i] = T();
			}
		}
		Vector(int n, T value){
			Size = n;
			space = n;
			elem = new T[n];
			for(int i = 0; i < n; i++){
				elem[i] = value; 
			}
		}
		void reserve(int newMalloc){
			if(space >= newMalloc){
				return;
			}
			space = newMalloc;
			T *temp = new T[newMalloc];
			for(int i = 0; i < Size; i++){
				temp[i] = elem[i];
			}
			if(elem){
				delete[] elem;
			}
			elem = temp;
		}
		void push_back(T &val){
			if(space == 0){
				reverse(8); //tại sao
			}
			if(space == Size){
				resever(space * 2);
			}
			Size++;
			elem[Size - 1] = val;
		}
		void pop_back(){
			if(Size == 0){
				return;
			}
			Size--;
		}
		T &operator[](int i){ //ham nap chong toan tu truy cap chi so vector
			return elem[i]
		}
		int size() const{
			return Size;
		}
		void insert(iterator it, T val){
			int pos = it - begin();
			if(Size == space){
				reserve(Size * 2);
			}
			Size++;
			for(int i = Size; i > pos; i--){
				elem[i] = elem[i-1];
			}
			elem[pos] = val;
		}
};
#endif

```


#### Phân tích
###### Hàm [[extend]]

###### Hàm tạo

###### Hàm hủy

###### Hàm nạp chồng toán tử gán 1 ngôi
- class Vector do ta định nghĩa nên không thể sử dụng phép gán thuông thường để gán các biến với nhau => muốn gán 2 vector cần nạp chồng toán tử gán

```C++
ector &operator =(Vector<T> V){ //ham nap chong toan tu gan
			this->num = V.num;
			this->cap = V.cap;
			if(cap){
				this->buff = new T[cap];
				for(int i = 0; i < num; i++){
					this->buff[i] = V.buff[i];
				}
			}else{
				this->buff = 0;
			}
			return *this;
		}
```

>[!FAQ] chưa hiểu rõ lắm code này

```C++
Vector & operator=(Vector & rhs) 
	{
	    if (this != &rhs) // ngan can tu sao chep
		{
	        delete[] array;          // xoa mang hien tai
	        size = rhs.size;         // dat kich thuoc moi
	        capacity = rhs.capacity; // dat dung luong moi
	        array = new T[capacity]; // tao mang moi
	        
			// Sao chep cac phan tu tu phai sang trai
	        for (int i = 0; i < size; i++)
	            array[i] = rhs.array[i];
	    }
	    
	    return *this; // tra ve vector ve trai sau khi gan xong
	}​
```
Giả sử có 2 vector a và b, gán a = b
- `Vector &operator` dấu `&` cho biết vector a có thể bị sửa đổi thông tin, 1 tham chiếu `Vector &rhs` tượng trưng cho b
- Đầu tiên, so sánh địa chỉ 2 vector, `this` - địa chỉ vector a, `&rhs` - địa chỉ vector b, nếu khác nhau (ngăn cản tự sao chép):
	- Giải phóng bộ nhớ của mảng hiện tại
	- Cập nhật độ dài và dung lượng mới
	- Cấp phát bộ nhớ động mới cho mảng a
	- Dùng vòng lặp để sao chép các phần tử của b sang a
	- Trả về vector a, `this` đia chỉ => `*this`  giá trị của địa chỉ

###### Hàm nạp chồng toán tử truy cập chỉ số của vector
```C++
T &operator[](int k){ //? khong hieu
	return buff[k];
}
```
```C++
T &operator[](int i){ //ham nap chong toan tu truy cap chi so vector
	return elem[i]
}
```
Do C++ cung cấp sẵn truy cập trực tiếp chỉ số của mảng, vector là mảng động
=> return được luôn

###### Hàm [[push_back]]
###### Hàm `insert`
```C++
void insert(int k, T x){
			if(cap == num){
				extend(cap * 2 + 5);
			}
			for(int i = num - 1; i >= k; i--){ //chua hieu nay lam
				buff[i+1] = buff[i];
			}
			buff[k] = x;
			num++;
		}
```
```C++
void insert(iterator it, T val){
			int pos = it - begin();
			if(Size == space){
				reserve(Size * 2);
			}
			Size++;
			for(int i = Size; i > pos; i--){
				elem[i] = elem[i-1];
			}
			elem[pos] = val;
		}
```
```cpp
void insert(int pos, T newElement)
	{
	    // Gap doi dung luong neu vector day
	    if (size == capacity)
	        expand(2 * size);
	    
		// Dich cac phan tu sang phai de tao cho trong cho viec chen
	    for (int i = size; i > pos; i--)
	        array[i] = array[i - 1];
	        
	    // Dat phan tu moi vao vi tri chen
	    array[pos] = newElement;
	    
	    // Tang kich thuoc
	    size++;
	}
```

- Đầu tiên, kiểm tra dung lượng như [[push_back]]
- Dịch chuyển các phần tử để tạo chỗ trống cho việc chèn
- Đặt phần tử mới vào vị trí chèn
- Tăng kích thước

> [!FAQ]- Chưa hiểu code iterator ở sfit, khi có iterator thì khác gì truyền trực tiếp pos như 2 cái kia ?
> Tại vì sao
###### Hàm `erase`
```C++
void erase(int pos)
	{
	    // Dich cac phan tu sang trai de lap day cho trong de lai do viec xoa
	    for (int i = pos; i < size - 1; i++)
	        array[i] = array[i + 1];
	
	    // Giam kich thuoc
	    size--;
	}​
```

###### Hàm `clear`
```
void clear(){
	size = 0;
}
```


-----
## References
1. https://codelearn.io/sharing/cach-tao-vector-trong-cpp
2. https://ideone.com/LyeviE
3. [[DSA]]

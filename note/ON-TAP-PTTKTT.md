Created: 202505212154
Tags: 

## Câu 1
```
Giari các pt đệ quy sau
1. T(n) = 2T(n/2) + n
2. T(n) = 2T(n/2) + n^2
```

## Câu 2
```
1. Trình bày pp thiết kế thuật toán chia để trị
2. Mô phỏng các bước thực hiện thuật toán chia để trị tìm kiếm phần tử lớn nhất trong mảng nguyên 33, 85, 10, 90, 82, 40, 78
3. Cài đặt tt chia để trị tìm kiếm phần tử lớn nhất trong mảng số nguyên bằng ngôn ngữ C/C++
```
```
1. Trình bày pp thiết kế thuật toán giảm để trị
2. Mô phỏng các bước thực hiện thuật toán sắp xếp chèn với mảng số nguyên sau: 3,8,10,9,82,4,78
3. Cài đặt thuật toán sắp xếp chèn bằng ngôn ngữ C/C++
```
```
3. Cài đặt thuật toán tìm kiếm nhị phân bằng c/c++
```

- Phương pháp chia để trị
	- Chia nhỏ bài toán thành các bài toán con
	- Giải quyết các bài toán con
	- Tổng hợp lời giải các bài toán con thành lời giải của bài toán ban đầu

- pp giảm để trị
	- quy về đúng 1 bài toán nhỏ hơn
	- có 3 chiến lược
		- giảm bởi 1 hằng số
		- giảm bởi 1 hệ số
		- giảm kích thước của biến / chia cắt
			- tìm điểm chia cắt
			- xử lý tùy theo điều kiện

- Tìm phần tử lớn nhất trong mảng số nguyên
- mô phỏng
	![[findmaxa.png]]
```cpp
int findMax(int a[], int low, int high){
	if(low == high){
		int max = a[low];
		return max;
	}else{
		int mid = (low + high) / 2;
		int x = findMax(a, low, mid);
		int y = findMax(a, mid + 1, high);
		if(x>y) return x;
		else return y;
	}
}
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


```cpp
//sap xep chen
void insertionSort(int a[], int n){
	for(int i = 1; i < n; i++){
		int v = a[i];
		int j = i - 1;
		while(a[j] > v && j >= 0){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v
	}
}
```

```cpp
//tìm kiếm nhị phân
int binarySearch(int a[], int l, int r, int x){
	if(l <= r){
		int mid = (l+r)/2;
		if(a[mid] == x){
			return mid;
		}else if(a[mid] > x){
			return binarySearch(a, l, mid - 1, x);
		}else{
			return binarySearch(a, mid + 1, r, x);
		}
	}
	return -1;
}
```
```cpp
//sap xep tron
void mergeSort(int a[], int l, int r){
	if(l > r){
		int m = (l+r)/2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void merge(int a[], int l, int m, int r){
	int i = l, j = m + 1, n = r - l + 1;
	int b[n];
	for(int k = 0; k < n; k++){
		if(j > r){
			b[k] = a[i];
			i++;
		}else if(i > m){
			b[k] = a[j];
			j++;
		}else if(a[i] < a[j]){
			b[k] = a[i];
			i++
		}else{
			b[k] = a[j]; 
			j++;
		}
	}
	for(int k = 0; k < n; k++){
		a[l + k] = b[k];
	}
}
```

## Câu 3
### Tham lam

- Mục đích: tìm 1 lời giải tốt nhất trong thời gian chấp nhận được (độ phức tạp đa thức)
- Ý tưởng: Dựa vào sự đánh giá tối ưu cục bộ địa phương (local optimum) để đưa ra quyết định tức thì tại mỗi bước lựa chọn, với hy vọng cuối cùng sẽ tìm ra được phương án tối ưu toàn cục (global optimum)
- Kĩ thuật
	- Sắp xếp các lựa chọn cho bước đó theo thứ tự nào đó “có lợi” (tăng dần hoặc giảm dần)
	- Chọn lựa chọn tốt nhất rồi đi tiếp bước kế (không quay lui)
	-> Có thể áp dụng hàng đợi ưu tiên
- Đặc điểm
	- Có trường hợp luôn tìm ra phương án tối ưu
	- Trường hợp không tìm ra phương án tối ưu thì thu được một phương án khả dĩ chấp nhận được
	- Thường có tốc độ tốt hơn hẳn so với các thuật toán tối ưu toàn cục.

```
1. Nêu mục đích, ý tưởng, kĩ thuật và đặc điểm của phương pháp tham lam
2. Giả sử có 1 máy ATM có các loại tiền 100.000 vnđ, 50.000 vnđ, 40.000 vnđ và 10.000 vnđ và mỗi loại tiền đều có số lượng không hạn chế. Khách hàng cần rút một số tiền n vnđ (tính chẵn đến 10.000 vnđ, hay n chia hết cho 10.000). Hãy tìm phương án trả tiền sao cho trả đủ n vnđ và số tờ tiền phải trả là ít nhất
	a. Nêu ý tưởng giải bài toán bằng pp tham lam
	b. Minh họa các bước thực hiện với số tiền rút là 480.000vnd
	c. Viết chương trình giải bài toán theo pp đã nêu ở câu a
```
- Ý tưởng
	- Gọi X1 , X2 , X3 , X4 lần lượt là mệnh giá các đồng tiền 100.000 vnđ, 50.000 vnđ, 40.000 vnđ và 10.000 vnđ
	- Ta phải tìm bộ X1 , X2 , X3 , X4 sao cho: 100.000 * X1 + 50.000 * X2 + 40.000 * X3 + 10.000 * X4 = n và X1 + X2 + X3 + X4 → min
	- Trả ra các tờ tiền có mệnh giá 100.000 nhiều nhất có thể sao cho tổng giá trị không vượt quá n (tổng số tiền cần phải trả ra). Số tờ tiền mệnh giá 100.000 cần trả ra là: X1 = n / 100.000. Số tiền còn lại cần phải trả ra là n = n - 100.000 * X1
	- Tiếp theo, trả ra các tờ tiền có mệnh giá 50.000 nhiều nhất có thể sao cho tổng giá trị không vượt quá số tiền còn lại phải trả ra là n Số tờ tiền mệnh giá 50.000 cân trả ra là: X2 = n / 50.000. Số tiền còn lại cần phải trả ra là n = n - 50.000 * X2.
	- Tương tự ta có: Số tờ tiền mệnh giá 40.000 cần trả ra là: X3 = n / 40.000; n = n - 40.000 * X3 . Số tờ tiền mệnh giá 10.000 cần trả ra là: X4 = n / 10.000.
- Ví dụ minh họa
	### **Ví dụ minh họa với n = 480000:**
	- `c[0] = 100000` → `a[0] = 480000 / 100000 = 4` → còn `n = 80000`
	- `c[1] = 50000` → `a[1] = 80000 / 50000 = 1` → còn `n = 30000`
	- `c[2] = 40000` → `a[2] = 30000 / 40000 = 0` → còn `n = 30000`
	- `c[3] = 10000` → `a[3] = 30000 / 10000 = 3` → còn `n = 0`
	Kết quả: **4 tờ 100.000, 1 tờ 50.000, 0 tờ 40.000, 3 tờ 10.000**
- code
```cpp
//atm - bt
#include <bits/stdc++.h>
using namespace std;

const int MAX = 4;
int c[MAX] = {100000, 50000, 40000, 10000};
int n, a[MAX];

int main(){
    cout <<"N = ";
    cin >> n;
    for(int i = 0; i < MAX; i++){
        a[i] = n / c[i];
        cout << "So to " << c[i] << " VND: " << a[i] << endl;
        n = n - c[i] * a[i];
    }
}
```

```
1. Nêu mục đích, ý tưởng, kĩ thuật và đặc điểm của phương pháp tham lam
2. Có n cuộc họp, cuộc họp thứ i bắt đầu vào thời điểm Si và kết thúc ở thời điểm Fi. Do chỉ có một phòng hội thảo nên hai cuộc họp bất kì sẽ được cùng bố trí phục vụ nếu khoảng thời gian làm việc của chúng chỉ giao nhau tại đầu mút. Hãy bố trí phòng họp để phục vụ được nhiều cuộc họp nhất.
```


```cpp
//lập lich họp - bt
#include <bits/stdc++.h>
using namespace std;

const int MAX = 8;
int s[MAX] = {0, 1, 3, 3, 4, 5, 6, 8};   //start 
int f[MAX] = {6, 4, 5, 7, 8, 9, 10, 11};  //finish
int a[MAX];   //mang chua thu tu sap xep tang dan theo thoi diem ket thuc

bool cmp(int i, int j) {
    return f[i] < f[j];
}

int main(){
    for(int i = 0; i < MAX; i++){
        a[i] = i;
    }
    sort(a, a + MAX, cmp);
    cout << "Cuoc hop duoc chon: " << a[0];
    int e = f[a[0]];  //end
    for(int i = 1; i < MAX; i++){
        if(s[a[i]] >= e){
            cout << " " << a[i];
            e = f[a[i]];
        }
    }
}
```
```
cái ba lô - slide
Cho một cái ba lô có thể đựng một trọng lượng W và n loại đồ vật, mỗi đồ vật i có một trọng lượng g[i] và một giá trị v[i]. Tất cả các loại đồ vật đều có số lượng không hạn chế. Tìm một cách lựa chọn các đồ vật đựng vào ba lô, chọn các loại đồ vật nào, mỗi loại lấy bao nhiêu sao cho tổng trọng lượng không vượt quá W và tổng giá trị là lớn nhất
```
```cpp
//cai ba lo tham lam
struct vat{
	float tl, gt, dg;
	int pa;
}

void tinhDonGia(vat sp[], int n){
	for(int i = 1; i <= n; i++){
		sp[i].dg = sp[i].gt / sp[i].tl;
	}
}
void sort(vat sp[], int n){
	for(int i = 1; i <= n - 1; i++){
		for(int i = j + 1; j <= n; j++){
			if(sp[i].dg < sp[j].dg){
				swap(sp[i], sp[j]);
			}
		}
	}
}
void greedy(vat sp[], int n, float W){
	for(int i = 1; i <= n; i++){
		sp[i].pa = W / sp[i].tl;
		W -= sp[i].pa * sp[i].tl;
	}
}
//=============
#include<bits/stdc++.h>
using namespace std;
struct vat{
	int tl;
	int gt;
	float tile(){
		return (float)gt/tl;
	}
};
bool ss(vat a, vat b){
	return a.tile()>b.tile();
}
void caibalo(int w, vector<vat>& dovat){
	sort(dovat.begin(), dovat.end(), ss);
	int tongtl=0, tonggt=0;
	for(auto dv : dovat){
		int sl= w/dv.tl;
		if(sl>0){
			tongtl=tongtl+sl*dv.tl;
			tonggt=tonggt+sl*dv.gt;
			w=w-sl*dv.tl;
		}
	}
	cout<<"Tong trong luong la "<<tongtl<<endl;
	cout<<"Tong gia tri la "<<tonggt;
}
int main(){
	vector<vat>dovat={{10,25},{15,30},{4,6},{2,2}};
	int w=37;
	caibalo(w,dovat);
}
```
- Ý tưởng
	- Gọi X = (X1, X2, …., Xn) với Xi là số nguyên không âm là một phương án. Xi là số đồ vật thứ i 
	- Cần tìm X sao cho:  X1  g[1] + X2  g[2] +…+ Xn  g[n] ≤ W  F(X) = X1  v[1] + X2  v[2] +…+ Xn  v[n] --> Max
	-  C1: Tư tưởng tham lam theo vật có giá trị lớn nhất
		- Xét các loại đồ vật theo thứ tự giá trị từ lớn đến nhỏ
		- Với mỗi đồ vật được xét sẽ lấy một số lượng tối đa mà trọng lượng còn lại của ba lô cho phép
		- Xác định trọng lượng còn lại của ba lô và quay lại bước 2 cho đến khi không còn có thể chọn được đồ vật nào nữa
	- Tư tưởng tham lam theo đơn giá 
		- Tính đơn giá (giá cho một đơn vị trọng lượng) cho các loại đồ vật 
		- Xét các loại đồ vật theo thứ tự đơn giá từ lớn đến nhỏ 
		- Với mỗi đồ vật được xét sẽ lấy một số lượng tối đa mà trọng lượng còn lại của ba lô cho phép 
		- Xác định trọng lượng còn lại của ba lô và quay lại bước 3 cho đến khi không còn có thể chọn được đồ vật nào nữa

```
Trồng cây - slide
Một nông dân đang muốn trồng hoa vào khu vườn của mình. Để cho khu vườn trở nên thật màu sắc ông quyết định trồng nhiều loài hoa khác nhau vào khu vườn. Mỗi loài hoa có 1 cách trồng khác nhau do đó ông sẽ trồng từng loài hoa vào các ngày liên tiếp nhau. Cháu của ông rất mong chờ được thấy tất cả loài hoa trong khu vườn đều nở hoa trông sẽ tuyệt vời như thế nào. Tuy nhiên mỗi loài hoa lại có thời gian phát triển từ lúc trồng tới lúc nở hoa khác nhau. Nhiệm vụ của bạn là giúp ông nông dân tìm ra ngày sớm nhất mà tất cả loài hoa đều nở hoa
```

```
Lưu file trên đĩa từ - slide
```

```
Chọn môn học - slide
Trong kì này bạn muốn học n môn học, trong đó tiết học của môn học thứ i bắt đầu tại thời điểm S[i] và kết thúc tại thời điểm F[i]. Bạn không được phép chọn hai môn học mà khoảng thời gian của hai môn học gối lên nhau. Làm thế nào để bạn có thể tìm được một tập lớn nhất các môn học không gối lên nhau.
```

```
Lập lịch - slide
Bạn được ông chủ giao cho n tác vụ và một chiếc máy tính để thực hiện các tác vụ đó. Tác vụ thứ i có thời hạn D[i] và nếu bạn hoành thành tác vụ đó trước thời hạn D[i], bạn sẽ được thưởng P[i] đồng, còn nếu hoành thành sau thời hạn D[i] thì bạn sẽ không nhận được đồng tiền thưởng nào cả. Biết rằng mỗi tác vụ mất thời gian đúng 1 đơn vị để hoành thành. Tìm một cách thực thi các tác vụ sao cho bạn nhận được nhiều tiền thưởng nhất. Giả sử thời hạn của các tác vụ là trong khoảng [1, n].
```

```
Cho thuê máy  - bt 
Trung tâm tính toán hiệu năng cao nhận được đơn đặt hàng của n khách hàng. Khách hàng i muốn sử dụng máy trong khoảng thời gian từ ai đến bi và trả tiền thuê là ci. Hãy bố trí lịch cho thuê máy để tổng số tiền thu được là lớn nhất mà thời gian sử dụng máy của hai khách hàng bất kì được phục vụ đều không giao nhau (cả trung tâm chỉ có một máy cho thuê).
```

```
Bài toán đóng thùng - bt
```

```
Bài toán người du lịch - bt
Có n thành phố được đánh số từ 1 đến n. Một người du lịch, xuất phát từ thành thành phố s, muốn đi thăm tất cả các thành phố khác, mỗi thành phố đúng một lần, rồi lại quay về nơi xuất phát. Giả thiết biết chi phí đi từ thành phố i đến thành phố j là c(i, j), 1 ≤ i, j ≤ n. Hãy tìm một hành trình cho người du lịch sao cho chi phí của hành trình này là nhỏ nhất
```
### Quy hoạch động
```
1. Trình bày các khái niệm trong quy hoạch động: cơ sở của quy hoạch động, bảng phương án (bảng quy hoạch) và công thức truy hồi
2. Ở đất nước Omega người ta chỉ tiêu tiền xu. Có N loại tiền xu, loại thứ i có mệnh giá là Ai đồng. Một người khách du lịch đến Omega du lịch với số tiền M đồng. Ông ta muốn đổi số tiền đó ra tiền xu Omega để tiện tiêu dùng. Ông ta cũng muốn số đồng tiền đổi được là ít nhất (cho túi tiền đỡ nặng khi đi đây đi đó). Bạn hãy giúp ông ta tìm cách đổi tiền.
	- Nêu ý tưởng giải bài toán bằng pp quy hoạch động
	- Trình bày các bước thực hiện của thuật toán với N-5, các đồng có mệnh giá là 1,2,3,5,10 và số tiền cần đổi M-27 đồng
	- Viết ctrinh giải bài toán theo ý tưởng đã nêu ở câu a

3. Cho một cái ba lô có thể đựng một trọng lượng W và n loại đồ vật, mỗi đồ vật i có một trọng lượng g[i] và một giá trị v[i]. Tất cả các loại đồ vật đều có số lượng không hạn chế. Tìm một cách lựa chọn các đồ vật đựng vào ba lô, chọn các loại đồ vật nào, mỗi loại lấy bao nhiêu sao cho tổng trọng lượng không vượt quá W và tổng giá trị là lớn nhất
	a. Nêu ý tưởng giải bài toán bằng pp quy hoạch động
	b. Trình bày các bước thực hiện của tt với trọng lượng cho phép của ba lô W = 15kg và bảng dữ liệu sau 
	Đồ vật          | A | B | C | D | E
	Trọng lượng(kg) | 4   3   2   1   6 
	Gía trị (tr đ)  | 8   9   5   2   9
	c. Viết ctrinh giải bài toán theo ý tưởng đã nêu ở câu a
```

Khái niệm trong quy hoạch động
- Cở sở của quy hoạch động: tập các bài toán nhỏ nhất có ngay lời giải để từ đó giải quyết các bài tóan lớn hơn
- Bảng quy hoạch (bảng phương án) là không gian lưu trữ lời giải các bài toán con để tìm cách phối hợp chúng
- Công thức truy hồi là công thức phối hợp nghiệm của các bài toán con để có nghiệm của bài toán lơn

- Bảng phương án (bảng quy hoạch)
	- Quy hoạch động = chia để trị + cơ chế lưu trữ nghiệm để sử dụng lại
	- Số chiều = số biến trong công thức truy hồi
	- Xuất phát từ cơ sở của quy hoạch động => thiết lập quy tắc điền kết quả vào bảng quy hoạch theo công thức truy hồi
	- Tra bảng tìm kết quả
	- Lần vết trên bảng để tìm lời giải tối ưu

- Đổi tiền -bt
	- Ý tưởng
		-  Gọi L[i, t] là số đồng xu ít nhất nếu đổi t đồng ra i loại tiền xu (từ 1 đến i). 
		- Với giới hạn số tiền cần đổi là t, việc chọn trong số các tiền xu từ 1 đến i để có số đồng xu là ít nhất sẽ là một trong hai khả năng:
		 - Nếu không chọn tiền xu thứ i thì L[i, t] là giá trị nhỏ nhất có thể có bằng cách chọn  trong số các tiền xu {1, 2, …, i-1} với giới hạn số tiền t. Tức là L[i, t] = L[i - 1, t].
		 - Nếu chọn tiền xu thứ i thì L[i, t] bằng với mệnh giá tiền xu thứ i (= A[i]) cộng với giá  trị nhỏ nhất có thể có được bằng cách chọn trong số các tiền xu từ 1 đến i (có thể được chọn nhiều lần) với giới hạn số tiền là t−A[i] (= L[i, t−A[i]]).
		 - Vì theo cách xây dựng L[i, t] là nhỏ nhất có thể nên L[i, t] là min của hai trường hợp trên
- Cái ba lô 
	- Thuật toán
		- Gọi L(i, t) là tổng giá trị lớn nhất khi chọn được i vật từ 1 đến i cho vào ba lô với tổng khối lượng không vượt quá t. Kết quả của bài toán là tổng giá trị lớn nhất chọn được trong n vật giới hạn trọng lượng là W tức L(n,W)
		- Xét đồ vật thứ i, và giới hạn trọng lượng hiện tại là j, ta có hai phương án để lựa chọn
			- Nếu vật thứ i không được chọn vào phương án tối ưu, thì kết quả tối ưu sẽ được chọn trong (i−1) đồ vật trước đó với giới hạn trọng lượng là j.
			- Nếu vật thứ i được chọn vào phương án tối ưu, thì tải trọng còn lại có thể sử dụng là (j−w[i]) cho (i−1) đồ vật phía trước, và ta được thêm giá trị v[i] của vật thứ i. Trường hợp này chỉ xét đến khi j≥w[i]​.
		- Nếu j < w[i] thì chỉ có duy nhất cách chọn đầu tiên, còn  j≥w[i] thì có thể chọn theo cả 2 cách để lấy cách tốt hơn. Ta có công thức quy hoạch động
			![[qhdcaibalo.png]]

```cpp
//DOI TIEN
#include <bits/stdc++.h>
using namespace std;

int n = 5, M = 27;
int a[] = {0,1,2,3,5,10};
int L[6][28];

int doiTien(){
    for(int i = 1; i <= n; i++){
        for(int t = 1; t <= M; t++){
            if(t < a[i]) L[i][t] = L[i-1][t];
            else L[i][t] = min(L[i-1][t], L[i][t-a[i]] + 1);
        }
    }
    return L[n][M];
}

int main(){
    for(int i = 0; i <= n; i++){
        L[i][0] = 0;
        for(int j = 1; j <= M; j++){
            L[i][j] = INT_MAX;
        }
    }
    int kq = doiTien();
    cout << "So dong tien it nhat: " << kq << endl;

    cout << "L[i][j] = {" << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= M; j++){
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    cout << "}" << endl;

}
```
```cpp
//cai ba lo
#include <bits/stdc++.h>
using namespace std;

int n = 4, W = 6;
int g[] = {0,2,1,4,3};
int v[] = {0,3,3,4,2};
int L[5][7];

int xepDoVat(){
    //int t = 0;
    for(int i = 1; i <= n; i++){
        for(int t = 1; t <= W; t++){
            if(t < g[i]) L[i][t] = L[i-1][t];
            else L[i][t] = max(L[i-1][t], L[i-1][t-g[i]] + v[i]);
        }
    }
    return L[n][W];
}

int main(){
    for(int i = 1; i <= n;i++){
        for(int t = 1; t <= W; t++){
            L[i][t] = 0;
        }
    }
    //memset(L, 0, sizeof(L));    
    int kq = xepDoVat();
    cout << "Cac do vat: " << endl;
    for(int i = 1; i <= n; i++){
        for(int t = 1; t <= W; t++){
            cout << L[i][t] << " ";
        }
        cout << endl;
    }
    cout << "Tong gia tri lon nhat: " << kq << endl;
}
```

```
Xâu con chung dài nhất - bt
Cho 2 xâu X, Y. Hãy tìm xâu con của X và của Y có độ dài lớn nhất. Biết xâu con của một xâu thu được khi xóa một số kí tự thuộc xâu đó (hoặc không xóa kí tự nào).
Ví dụ: X = “ALTRUISTIC” và Y = “ALGORITHMS” có xâu con chung dài nhất là “ALRIT” với độ dài là 5.
```
```cpp
#include <bits/stdc++.h>
using namespace std;

int nx, ny;
string X, Y;
int L[100][100];

int xauConChung(){
    for(int i = 1; i <= nx; i++){
        for(int j = 1; j <= ny; j++){
            if(X[i-1] == Y[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
            }
            else{
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    return L[nx][ny];
}
int main(){
    X = "Conghoa";
    Y = "Congtru";
    nx = X.length();
    ny = Y.length();
    for(int i = 0; i <= nx; i++){
        L[i][0] = 0;
    }
    for(int j = 0; j <= ny; j++){
        L[0][j] = 0;
    }
    int kq = xauConChung();
    cout << "Do dai xau con chung dai nhat: " << kq << endl;
    cout <<"L[i,j] = {" << endl;
    for(int i = 0; i <= nx; i++){
        for(int j = 0; j <= ny; j++){
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    cout << "}" << endl;
}
```

```
bt
Hai nước Alpha và Beta nằm ở hai bên bờ sông Omega, Alpha nằm ở bờ bắc và có M thành phố được đánh số từ 1 đến M, Beta nằm ở bờ nam và có N thành phố được đánh số từ 1 đến N (theo vị trí từ đông sang tây). Mỗi thành phố của nước này thường có quan hệ kết nghĩa với một số thành phố của nước kia. Để tăng cường tình hữu nghị, hai nước muốn xây các cây cầu bắc qua sông, mỗi cây cầu sẽ là nhịp cầu nối 2 thành phố kết nghĩa. Với yêu cầu là các cây cầu không được cắt nhau và mỗi thành phố chỉ là đầu cầu cho nhiều nhất là một cây cầu, hãy chỉ ra cách bắc cầu được nhiều cầu nhất.
```
### Quay lui

- Ý tưởng
	- Kỹ thuật thiết kế thuật toán dựa trên đệ quy
	- Tìm lời giải từng bước, tại mỗi bước
		- Nếu có một lựa chọn chấp nhận được  ghi nhận và tiến hành thử bước tiếp theo
		- Nếu không có lựa chọn nào khả thi 
			- Quay lại bước trước 
			- Xóa bỏ ghi nhận 
			- Thử các lựa chọn còn lại tại bước này
	- Phù hợp với bài toán liệt kê cấu hình dạng X[1, ..., n]
- Ưu điểm
	- Thử tất cả các tổ hợp để tìm được một lời giải
	- Nhiều cài đặt tránh được việc phải thử nhiều trường hợp chưa hoàn chỉnh, nhờ đó giảm thời gian chạy
- Nhược điểm
	- Quátrìnhtìmkiếmcứ gặpphải bế tắc với cùng một nguyên nhân
	- Thực hiện các công việc dư thừa (mỗi lần quay lui lại phải đánh giá lại lời giải)
	- Không sớm phát hiện được các khả năng bị bế tắc trong tương lai

```
Biểu thức zero - bt
Cho một số tự nhiên N ≤ 9. Giữa các số từ 1 đến N hãy thêm vào các dấu + và - sao cho kết quả thu được bằng 0. Hãy viết chương trình tìm tất cả các khả năng có thể.
```

```
bt
Cho một tự nhiên N ≤ 30. Tìm tất cả các cách phân tích số N thành tổng của các số nguyên dương. Các cách phân tích là hoán vị của nhau thì chỉ tính là một cách.
```
```
cái ba lô - bt
Cho một cái ba lô có thể đựng một trọng lượng W và n loại đồ vật, mỗi đồ vật i có một trọng lượng g[i] và một giá trị v[i]. Tất cả các loại đồ vật đều có số lượng không hạn chế. Tìm một cách lựa chọn các đồ vật đựng vào ba lô, chọn các loại đồ vật nào, mỗi loại lấy bao nhiêu sao cho tổng trọng lượng không vượt quá W và tổng giá trị là lớn nhất
```
```cpp
//cai ba lô
void try (int x[], int i){
	for(int j = 0; j <= n; j++){
		x[i] = j;
		if(i == n){
			
		}
	}
}

///=====
#include <bits/stdc++.h>
using namespace std;

struct DoVat{
    string ten;
    int tl;
    int gt;
    int pa; // phuong an
};

void printResult(DoVat x[], int n){
    cout << "Phuong an: ";
    for(int i = 0; i < n; i++){
        if (x[i].pa == 1)
            cout << x[i].ten << " ";
    }
    cout << endl;
}

void attempt(DoVat x[], int i, int n, int w){
    for(int j = 0; j < n; j++){
        x[i].pa = j;
        if(i == n){
            int kl = 0;
            for(int k = 0; k < n; k++){
                kl += x[k].tl * x[k].pa;
            }
            if(kl <= w) printResult(x, n);
        }else{
            attempt(x, i + 1, n, w);
        }
    }
}

int main(){
    int n = 4, w = 37;
    DoVat sp[n];
    sp[0] = {"A", 15, 30, 0};
    sp[1] = {"B", 10, 20, 0};
    sp[2] = {"C", 12, 25, 0};
    sp[3] = {"D", 5, 10, 0};
    
    attempt(sp, 0, n, w);
    cout << "Tong so phuong an: " << (1 << n) << endl;

}
```
```
dãy con tăng dài nhất - bt
```
## Câu 4
```
Giả sử có 3 loại tiền ệnh giá: 3000d, 5000d, và 8000d. Hãy chỉ ra rằng nếu giải bằng pp tham lam sẽ cho kết quả là vô nghiệm trong trường hợp cần đổi 10000d với số tờ tiền là ít nhất
```
-----
## References
1.

Created: 202505202353
Tags: 

```
Thời gian thi: 90p
Cấu trúc đề: 4 câu
	- 1b đánh giá độ phức tạp: 1đ
	- 3 bài bất kì trong "Nội dung" : 3đ mỗi bài
Nội dung
	- BFS DFS
		- Liệt kê những số đi được trong bài mọi con đường về 0
		- Robot
		- Đong nước
	- Chia để trị và quay lui
		- Lai ghép
		- Chia của
		- Đổi tiền
	- Tham lam
		- Buôn dưa lê
		- Lập lịch
	- Hàng đợi ưu tiên
		- Nối thanh kim loại
		- Trinh thám
		- Phần tử trung vị
		- Giao hàng
	- Quy hoạch động
		- Đổi tiền
		- Xâu con chung dài nhất
		- Sắp xếp ba lô
	(yc: làm đúng thuật toán, nêu từng bước tt, minh họa bằng tay tính toán vd cụ thể, code)
```

## Quy hoạch động
### Đổi tiền
THUẬT TOÁN

MINH HỌA

CODE
```cpp
#include<bits/stdc++.h>

using namespace std;

int C[105][10005], a[105], n, M;

void TRACE(int n, int M){
	if(C[n][M] == 0) return;
	while(C[n][M] == C[n-1][M]) n--;
	TRACE(n, M-a[n]);
	cout << a[n] <<" ";
}

main(){
	cin >> n >> M;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 0; i <=n; i++) C[i][0] = 0;
	for(int j = 0; j <=M; j++) C[0][j] = 1e9;
// 	fill(C[0]+1,C[0]+M+1,1e9);
	
	for(int i = 1; i <=n; i++){
		for(int j = 1; j <= M; j++){
			if(a[i] > j) C[i][j] = C[i-1][j];
			else C[i][j] = min(C[i-1][j], 1+C[i][j-a[i]]);
		}
	}
	
	if(C[n][M] == 1e9) cout <<"Khong doi duoc";
	else{
		cout << C[n][M] <<"\n";
		TRACE(n,M);
	} 
}
```

### Xâu con chung dài nhất LCS
- Bài toán: Cho xâu x và xâu y một xâu con chung của x và y thu được bằng cách xóa đi 1 số ký tự nào đó trong x và trong y phần còn lại giữ nguyên thứ tự. Cần tìm tất cả các xâu con chung dài nhất của x và y. 
- Input Nhập vào hai xâu kí tự trên hai dòng mỗi xâu không có độ dài từ 1 đến 100 
- Output Tất cả các xâu con chung dài nhất của hai xâu trên được viết trên từng dòng theo thứ tự từ điển Trong trường hợp không có xâu con chung xuất ra "khong co xau con chung"

```cpp
//tuando
#include<bits/stdc++.h>
using namespace std;
int C[105][105] = {},n,m;
string x,y;
void TRACE(int n,int m){
 if(C[n][m] == 0) return;
 while(C[n][m] == C[n-1][m]) n--;
 while(C[n][m] == C[n][m-1]) m--;
 TRACE(n-1,m-1);
 cout << x[n];
}
int main(){
 cin >> x; n= x.size(); x = "$" + x;
 cin >> y; m = y.size(); y = "$" + y;
 for(int i=1;i<=n;i++)
 for(int j=1;j<=m;j++) C[i][j] = x[i] == y[j] ? 1+C[i-1][j-1] : max(C[i-1][j],C[i][j-1]);
 cout << C[n][m] << "\n";
 TRACE(n,m);
}
```

```cpp
//ngothithanh
#include<bits/stdc++.h>

using namespace std;

string x, y;
int n,m, C[105][105];

void TRACE(int n, int m){
	if(C[n][m]==0) return;
	while(C[n][m] == C[n-1][m]) n--;
	while(C[n][m] == C[n][m-1]) m--;
	TRACE(n-1, m-1);
	cout << x[n];
}

main(){
	cin >> x; n = x.size(); x = "$"+x;
	cin >> y; m = y.size(); y = "$"+y;
	
	for(int i = 1; i <=n; i++) C[i][0] = 0;
	for(int j = 1; j <=m; j++) C[0][j] = 0;
	
	for(int i=1; i <=n; i++){
		for(int j = 1; j<=m; j++){
			if(x[i]==y[j]) C[i][j] = 1+C[i-1][j-1];
			else C[i][j] = max(C[i-1][j], C[i][j-1]);
		}
	}
	
	cout << C[n][m] <<"\n";
	TRACE(n,m);
}
```

```cpp
//Tichpx- tim tat ca cac xccdn
//LAPTRINHONLINE
#include<bits/stdc++.h>
using namespace std;
string x,y;
int C[105][105]={},n,m;
set<string> P[105][105];
int main()
{
 cin>>x; n=x.size(); x="$"+x;
 cin>>y; m=y.size(); y="$"+y;
 for(int i=1;i<=n;i++)
 for(int j=1;j<=m;j++)
 if(x[i]==y[j])
 {
 C[i][j]=C[i-1][j-1]+1;
 if(C[i][j]==1) P[i][j].insert(string(1,x[i]));
 else for(auto s:P[i-1][j-1]) P[i][j].insert(s+x[i]);
 }
 else
 {
 C[i][j]=max(C[i-1][j],C[i][j-1]);
 if(C[i-1][j]==C[i][j]) for(auto s:P[i-1][j]) P[i][j].insert(s);
 if(C[i][j-1]==C[i][j]) for(auto s:P[i][j-1]) P[i][j].insert(s);
 }
 for(auto s:P[n][m]) cout<<s<<"\n";
}

```
### Sắp xếp ba lô
THUẬT TOÁN

MINH HỌA

CODE
```cpp
#include<bits/stdc++.h>

using namespace std;

int n,m, a[105], b[105], C[105][1005];
void TRACE(int n, int m){
	while(n>0 && m>0){
		if(a[n] <= m && C[n][m] == C[n-1][m-a[n]]+b[n]){
			cout << "Chon: "<< n<< "kt: " << a[n] << "gt: " << b[n]<<"\n";
			m-=a[n]; 
		}
		n--;
	}
}
main(){
	cin >> n >> m;
	for(int i = 1; i <=n; i++) cin >> a[i] >> b[i];
	
	for(int i = 1; i <=n; i++) C[i][0] = 0;
	for(int j = 1; j <=m; j++) C[0][j] = 0;
	
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(a[i]>j) C[i][j] = C[i-1][j];
			else C[i][j] = max(C[i-1][j], b[i]+C[i-1][j-a[i]]);
		}
	}
	if(C[n][m] == 0) cout << -1 <<"\n";
	else{
		cout << C[n][m] <<"\n";
		TRACE(n,m);
	}
	
}
```
## BFS DFS
### Liệt kê những số đi được trong bài mọi con đường về 0
THUẬT TOÁN

MINH HỌA

CODE
```cpp
#include<bits/stdc++.h>

using namespace std;
main(){
	int n; cin >> n;
	stack<int> S; S.push(n);
	set<int> Out; Out.insert(n);
	
	while(!S.empty()){
		int u = S.top();
		S.pop();
		for(int a = 1; a*a <= u; a++){
			if(u%a==0){
				int v = (a-1)*(u/a + 1);
				if(Out.find(v)==Out.end()){
					S.push(v);
					Out.insert(v);
				}
			}
		}
		
	}
	
	for(auto v:Out){
		cout << v<<" ";
			
	}
	
}
```
### Robot
THUẬT TOÁN

MINH HỌA

CODE
```cpp
#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
main(){
	pair<int,int> n;
	cin >> n.x >> n.y;
	stack<pair<int,int>> s; s.push(n);
	set<pair<int,int>> out; out.insert(n);
	
	while(!s.empty()){
		pair<int, int> u = s.top();
		s.pop();
		if(u.x%2==0){
			pair<int,int> z = make_pair(u.y,u.x/2);
			if(out.find(z)==out.end()){
				out.insert(z);
				s.push(z);
			}
		}
		
		if(u.y%2!=0){
			pair<int,int> z = make_pair((u.y+1) / 2,u.x);
			if(out.find(z)==out.end()){
				out.insert(z);
				s.push(z);
			}
		}
	}
	
	for(pair<int,int> z:out){
		cout << "(" <<z.x<<","<<z.y<<") ";
	}
}
```
### Đong nước
THUẬT TOÁN
- B1: Nhập `n,m,k`
	- `n,m`: dung tích 2 bình
	- `k`: số lít nước cần đong
- B2: Kiểm tra điều kiện không thể đong
	- Nếu `k > max(n,m)` hoặc `k` không chia hết cho `gcd(n,m)` => In `"Khong dong duoc nuoc` và kết thúc
- B3: Khai báo hàng đợi `Q` và đưa trạng thái ban đầu `(0,0)` vào `Q`
- B4: Khai báo `map`để lưu số bước di chuyển đến mỗi trạng thái `(x,y)`. Ban đầu `Map[(0,0)] = 0`
- B5: Lặp lại khi hàng đợi còn phần tử 
	- Lấy `(x,y)` từ đầu hàng đợi ra
	- Nếu `x==k` hoặc `y==k` => In `Map[(x,y)]` là số bước và kết thúc
	- Sinh 6 trạng thái kế tiếp
		
		| Hành động                 | Trạng thái mới `(nx,ny)`           |
		| ------------------------- | ---------------------------------- |
		| Đổ cạn bình 1             | (0, y)                             |
		| Đổ đầy bình 1             | (n, y)                             |
		| Đổ cạn bình 2             | (x, 0)                             |
		| Đổ đầy bình 2             | (x, m)                             |
		| Rót từ bình 1 sang bình 2 | (max(0, x + y − m), min(x + y, m)) |
		| Rót từ bình 2 sang bình 1 | (min(x + y, n), max(0, x + y − n)) |
	- Với mỗi trạng thái `(nx,ny)` nếu chưa được xét: Thêm vào hàng đợi, gán `Map[(nx,ny)] = Map[(x,y)] + 1`
- B6: Nếu duyệt hết mà không gặp trạng thái có `k` lít nước => In "Khong dong duoc nuoc"

MINH HỌA
![[minhhoadongnuoc.png]]

CODE
```cpp
 #include <bits/stdc++.h>
 using namespace std;
 typedef pair<int,int> pii;
 k lít nước
 main() {
 int n,m,k;
 cin >> n>>m>>k;
 queue<pii> Q; Q.push({0,0});
 map<pii,int> M  0,0,0;
 while(Q.size()) {
 int x  Q.front().first, y  Q.front().second,t=x+y;
 Q.pop();
 pii Next[] = {{0,y},{n,y},{x,0},{x,m},{max(0,t-m),min(t,m)},{min(t,n),max(0,t-n)}};
 for (auto z: Next) {
 if M.count(z)==0) {
 Q.push(z);
 M[z]  M[{x, y}]  1;
 if (z.first==k || z.second==k) {
 cout  M[z];
 return 0;
 }
 }
 }
 }
 cout << "\nKhong dong duoc nuoc";
 }
```
```cpp
#include<bits/stdc++.h>

using namespace std;

//#define x first
//#define y second

typedef pair<int, int> pii;

main(){
	int n, m, k;
	cin >> n >> m >> k;
	queue<pii> Q;
	Q.push({0,0});
	map<pii,int> M;
	M[{0,0}] = 0;
	
	while(!Q.empty()){
		pii z = Q.front();
		Q.pop();
		int a = z.first, b = z.second;
		int t = a + b;
		vector<pii> vt = {
			{0, b},        // Do het thung a
			{n, b},        // Do day thung a
			{a, 0},        // Do het thung b
			{a, m},        // Do day thung b
			{max(0, t - m), min(t, m)}, // Do a -> b
			{min(t, n), max(0, t - n)}  // Do b -> a
		};
		for(auto u : vt){
			if(M.count(u) == 0){
				Q.push(u);
				M[u] = M[z] + 1;
				if(k == u.first || k == u.second){
					cout << M[u];
					return 0;
				}
			}
			
		}
	}
	cout << "Khong dong duoc\n";
	return 0;
	
}
```

## Chia để trị và quay lui
### Lai ghép
THUẬT TOÁN

MINH HỌA

CODE
```cpp
#include<bits/stdc++.h>

using namespace std;
string x, y;
int n;
void Try(string z, int k){
	if(k==n) cout << z <<"\n";
	else{
		Try(z+x[k],k+1);
		if(y[k]!=x[k]) Try(z+y[k],k+1);
	}
}
main(){
	cin >> x >> y;
	n = x.length();
	Try(" ",0);
}
```
### Chia của
THUẬT TOÁN
![[chiacua.png]]

MINH HỌA

CODE
```cpp
 #include <bits/stdc++.h>
 using namespace std;
 int n,a[100],T0,res=1e9;
 void TRY(int k,int A,int B 
 if (res<=1 return;
 if (k==n) res=min(res,BA;
 else {
 if (A+a[k+1]T/2 TRY(k+1,A+a[k+1],B;
 if (B+a[k+1]T+res)/2) TRY(k+1,A,B+a[k+1]);
 }
 }
 main() {
 cin>>n;
 for(int i  1;i<=n;i++) {cin >> a[i]; T+=a[i];}
 TRY0,0,0;
 cout<<res;
 }
```
```cpp
#include<bits/stdc++.h>

using namespace std;

int n, a[100], T = 0, res = 1e9;

void TRY(int k, int A, int B){
	if(k==n) res = min(res, B-A);
	else{
		if(A+a[k+1] <= T/2) TRY(k+1, A+a[k+1], B);
		if(B+a[k+1] < (T+res)/2) TRY(k+1, A, B+a[k+1]);
	}
	if(res <= 1) return;
}

main(){
	cin >> n;
	for(int i = 1; i <=n; i++){
		cin >> a[i];
		T+=a[i];
	}
	TRY(0,0,0);
	cout << res;
}
```
### Đổi tiền
THUẬT TOÁN
![[doitien.png]]

MINH HỌA

CODE
```cpp
 #include <bits/stdc++.h>
 #define zuno main
 #define ll long long
#define endl "\n"
 #define MOD 1000000007
 using namespace std;
 int a[101],L10001;
 int zuno() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    memset(L,0,sizeof(L));
    L0   1;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=10000;j++){
            if(L[j-a[i]]!0){
                if(L[j]==0) L[j]  L[j-a[i]]+1;
                else L[j] = min(L[j],L[j-a[i]]+1);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        if(L[x]!0) cout<<L[x]-1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
 }
```
```cpp
#include<bits/stdc++.h>
using namespace std;

int n, a[1000], M, res=1e9;

void TRY(int k, int t, int T){
	if(k==n){
		if((M-T)%a[n]==0) res = min(res, t+ (M-T)/a[n]);
		return;
	}
	for(int x=0; x+t<res && T+a[k]*x<=M; x++) TRY(k+1, t+x, T+a[k]*x);
}

int main(){
	cin>>n>>M;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	TRY(1,0,0);
	if(res==1e9) cout<<"\nKhong doi duoc"; else cout<<res;

}

```
## Tham lam
### Buôn dưa lê
THUẬT TOÁN

MINH HỌA

CODE
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n + k + 5, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long res = 0;
    queue<int> Q;

    for (int i = 1; i <= n + k - 1; i++) {
    	if(i<=n) Q.push(a[i]);
    	if (Q.empty()) continue;

        int x = Q.front(); Q.pop();

        if (x <= m) {
            res += x; 
        } else {
            res += m; 
            Q.push(x - m); 
        }

        if (Q.size() > k && !Q.empty()) {
            Q.pop();
        }
    }

    cout << res;
}
```
### Lập lịch
THUẬT TOÁN

MINH HỌA
![[minhhoalaplich.png]]

CODE
```cpp
#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}

main(){
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
	}
	
	sort(v.begin(), v.end(), cmp);
	
	int res = 0, t = -1e9;
	for(int i =0; i < n; i++){
		if(v[i].first > t){
			t = v[i].second;
			res++;
		}
	}
	cout << res;
}
```
## Hàng đợi ưu tiên
### Nối thanh kim loại
THUẬT TOÁN

MINH HỌA

CODE
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
	long n, x, res = 0;
	cin>>n;
	priority_queue<long, vector<long>, greater<long>> Q;
	for(int i=0, x; i<n; i++) {cin>>x; Q.push(x);}
	while(Q.size()>1){
		x = Q.top(); Q.pop();
		x += Q.top(); Q.pop();
		res += x;
		Q.push(x);
	}
	cout<<res;
}


```
### Trinh thám
THUẬT TOÁN
![[thuattoantrinhtham.png]]

MINH HỌA
![[minhhoatrinhtham.png]]

CODE
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
	priority_queue<pair<int,int>> Q;
	int n,k,x;
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>x;
		Q.push({x,i});
		while(i-Q.top().second >= k) Q.pop();
		if(i >= k) cout<<Q.top().first<<" ";
	}
}

```
### Phần tử trung vị
THUẬT TOÁN
![[thuattoanphantutrungvi.png]]

MINH HỌA
![[minhhoaphantutrungvi.png]]

CODE
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
	priority_queue<int,vector<int>,less<int>> L;
	priority_queue<int,vector<int>,greater<int>> R;
	int n,x;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>x;
		i%2?L.push(x):R.push(x);
		if(i>1 && L.top()>R.top()){
			L.push(R.top());
			R.push(L.top());
			L.pop();
			R.pop();
		}                         
		cout<<L.top()<<" "; 
	}
}
```
### Giao hàng
THUẬT TOÁN
![[thuattoangiaohang.png]]
MINH HỌA
![[minhhoagiaohang.png]]

CODE
```cpp
 #include <bits/stdc++.h>
 using namespace std;

int main() {
    list<int> A100005;
    long long n, res  0, a, b;
    priority_queue<int> pq;
    scanf("%lld", &n);
    while (n--) {
        scanf("%lld %lld", &a, &b);
        A[a].push_back(b);
    }
    for (int i  100000; i  0; i--) {
        for (auto x  A[i]) pq.push(x);
        if 
        }
    }
 !pq.empty()) {
            res += pq.top();
            pq.pop();
    printf("%lld", res);
    return 0;
 }
 Thuật toán Pris
```
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
	list<int> A[100005];
	priority_queue<int> Q;
	long n, res=0, a, b;
	cin>>n;
	while(n--){
		cin>>a>>b;
		A[a].push_back(b);
	}
	for(int i=1e5; i>0; i--){
		for(auto x : A[i]) Q.push(x);
		if(Q.size()){
			res += Q.top();
			Q.pop();
		}
	}
	cout<<res;
}


```


-----
## References
1.

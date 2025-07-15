const int MAX = 8;
int s[MAX], f[MAX], a[MAX];

bool cmp(int i, int j){
    return f[i] > f[j];
}

int main(){
    for(int i = 0; i < MAX; i++){
        a[i] =  i;
    }
    sort(a, a + MAX, cmp);
    cout << "cuoc hop dc chon: " << endl;
    int e = f[a[0]];
    for(int i = 1; i < MAX; i++){
        if(sơa[])
    }
}
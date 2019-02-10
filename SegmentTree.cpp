const int MAX_N = 131072;

int n;
int dat[MAX_N*2-1];

void init() {for(int i=0; i<2*n-1; i++) dat[i] = INT_MAX;}
//i番目の値をxに変更 (0-indexed)
void update(int i, int x){
  i += n-1;
  dat[i] = x;
  while(i>0){
    i = (i-1)/2;
    dat[i] = min(dat[i*2+1], dat[i*2+2]);
  }
}

//[a, b)の最小値, l, rにはノードkに対応づく区間を与える
int query(int a, int b, int k, int l, int r){
  //交差しない
  if(r <= a || b <= l) return INT_MAX;
  if(a <= l && r <= b) return dat[k];
  else{
    int mid = (l+r)/2;
    int vl = query(a, b, k*2+1, l, mid);
    int vr = query(a, b, k*2+2, mid, r);
    return min(vl, vr);
  }
}

int main(void){

  //usage
  init();
  update(0, 5);
  query(a, b, 0, 0, n);
}

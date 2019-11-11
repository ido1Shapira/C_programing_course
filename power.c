double Exp (int x){
  double e = 1; // initialize sum of series
  for (int i = 10; i > 0; --i ) {
    e = 1 + x * e / i;
  }
  double ans = 1;
  while (x > 0) {
    ans = e * ans;
    x--;
  }
  return ans;
}
double Pow (double x,int y){
  double ans = 1;
  while (y > 0){
    ans = x * ans;
    y--;
  }
  return ans;
}

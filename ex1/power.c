double Pow (double x,int y){
  double ans = 1;
  if(y<0){
    y= -1 * y;
  }
  while (y > 0){
    ans = x * ans;
    y--;
  }
  return (y<0)? 1/ans : ans;
}
double Exp (int x){
  double e = 1;
  for (int i = 10; i > 0; --i ) {
    e = 1 + e / i;
  }
  return Pow(e,x);
}

//补全下列两个函数即可
int lowbit(int n)
{
  return n&-n;
  //write your code here
  
}
int NumberOf1(int n) {
        int res = 0;
  		while(n)
        {
          n-=lowbit(n);
          res++;
        }
      //write your code here
        return res;
}
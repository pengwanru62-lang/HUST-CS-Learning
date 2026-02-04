
/**
  按任务要求补全该函数
  用递归实现辗转相除法
 **/
int gcd(int x, int  y)
{
	/**********  Begin  **********/ 
  printf("%d %d\n",x,y);
  if(y==0){
    return x;
  }else{
    int r=x%y;
    x=y;
    y=r;
    gcd(x,y);
  }
    
    
    /**********  End  **********/
}

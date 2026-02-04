# include<stdio.h>
int main(void)
{
   int M,N;
   scanf("%d %d",&M,&N);
   int c[M];
   int i, j=0, k=1;
   for (i=0; i<M;i++)
   	{
	   c[i]=1+i;
    }
   for (i=M;i>1; i--)
   {
   		while(k<=N)
   			{
                   if(c[j]!=0) 
                   {
                       j++;
                       if(j>M) 
					   {
					   	j=0;
					   	continue;
					   }
                       k++;
                   }
                   else 
				   {
                   	j++;
                    if(j>M) j=0;
				   }
            }
        c[j-1]=0;
        k=1;
   }    
   for(int l=0;l<M;l++)
   {
   	if(c[l]!=0) printf("%d\n",c[l]);
   }
   return 0;
}

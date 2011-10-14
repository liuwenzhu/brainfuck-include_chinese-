# include <iostream>
char f[5000],b,b1,b2,a[5000],o,*s=f,d[5];
int p,q,r,i;
void interpret(char *c)
{
   char *d;
   r++;
   while(*c)
   {
   switch (o=1,*c++)
   {
   case '<'  :p--;break;
   case '>'  :p++;break;
   case '+': a[p]++;break;
   case '-': a[p]--;break;
   case '.':  putchar(a[p]); fflush(stdout); break;
   case ',':  a[p]=getchar();fflush(stdout); break;
   case '[': 
             for (b=1,d=c;b&&*c;c++)
             {
				 if(*c=='[') b++;
				 if(*c==']') b--;
             }
			 if (!b)
			 {
				 c[-1]=0;
				 while(a[p])
				 interpret(d);
				 c[-1]=']';
				 break;
			 }

   case ']':         puts("UNBALANCED BRACKETS"), exit(0);
   case '#':
	            if(q>2)
		             printf("%2d %2d %2d %2d %2d %2d %2d %2d %2d %2d\n%*s\n",
		            *a,a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],3*p+2,"^");
	             break;
   default: o=0;
   }
   if( p<0 || p>10000)
            puts("RANGE ERROR"), exit(0);
      }
   r--;
}
int main(int argc,char *argv[])
{
FILE *t;
q=argc;
if (t=fopen("t.txt","r"))
{
	while (fscanf(t,"%c",&b)!=EOF)
	{

		if (b<0)
		{
			d[0]=b;
            if(fscanf(t,"%c",&b)!=EOF) d[1]=b;
			d[2]='\0';
			if(strcmp(d, "¼Ó")==0) { *s++='+'; continue; }
			if(strcmp(d, "¼õ")==0) { *s++='-'; continue; }
			if(strcmp(d, "×ó")==0) { *s++='<'; continue; }
			if(strcmp(d, "ÓÒ")==0) { *s++='>'; continue; }
			if(strcmp(d, "Í¹")==0) { *s++='['; continue; }
			if(strcmp(d, "°¼")==0) { *s++=']'; continue; }
			if(strcmp(d, "µã")==0) { *s++='.'; continue; }
			if(strcmp(d, "Ø¯")==0) { *s++=','; continue; }
		}
		*s++=b;
		i++;
	}
	*s=0;
   interpret(f);
}
}
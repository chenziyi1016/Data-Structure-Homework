#include <graphics.h>
#include<bits/stdc++.h>
using namespace std;
int z[20],res[10],z1[20],z2[20],z3[20],z4[20],z5[20],z6[20],n,x,num[10],cnt1,cnt2,cnt3,cnt4,cnt5,cnt6;
int tmp[20],start[20];
int ok=0; 
char c[30];
string xx;
struct re
{
	int id;
	int val;
 } ;re r[10];
bool cmp(re x,re y)
{
	return x.val<y.val;
}
void menu();

void drawCylinder1(double x, double y,int num,int z[]) {
    setcolor(WHITE);
    rectangle(x, y, x + 30, y+z[num]);  
	setfillstyle(SOLID_FILL, BLUE); 
    floodfill(x +1 , y + 1, WHITE); 
}

void drawCylinder2(double x, double y,int num) {
    setfillstyle(SOLID_FILL, RED);  // 设置填充颜色为蓝色
    floodfill(x +1 , y + 1, WHITE);  // 从中间位置开始填充
}
void drawCylinder3(double x, double y,int num,int z[]) {
    setcolor(WHITE);
    rectangle(x, y, x + 30, y+z[num]);  
	setfillstyle(SOLID_FILL, GREEN); 
    floodfill(x +1 , y + 1, WHITE); 
}
void drawCylinder4(double x, double y,int num) {
    setfillstyle(SOLID_FILL, YELLOW);  // 设置填充颜色为蓝色
    floodfill(x +1 , y + 1, WHITE);  // 从中间位置开始填充
}
void drawCylinder5(double x, double y,int num) {
    setfillstyle(SOLID_FILL, BLUE);  // 设置填充颜色为蓝色
    floodfill(x +1 , y + 1, WHITE);  // 从中间位置开始填充
}
void drawCylinder6(double x, double y,int num) {
    setfillstyle(SOLID_FILL, RED);  // 设置填充颜色为蓝色
    floodfill(x +1 , y + 1, WHITE);  // 从中间位置开始填充
}
void drawCylinder7(double x, double y,int num) {
    setfillstyle(SOLID_FILL, MAGENTA);  // 设置填充颜色为蓝色
    floodfill(x +1 , y + 1, WHITE);  // 从中间位置开始填充
}
void drawCylinder8(double x, double y,int num) {
    setfillstyle(SOLID_FILL, BROWN);  // 设置填充颜色为蓝色
    floodfill(x +1 , y + 1, WHITE);  // 从中间位置开始填充
}
void drawCylinder9(double x, double y,int num) {
    setfillstyle(SOLID_FILL, LIGHTGRAY);  // 设置填充颜色为蓝色
    floodfill(x +1 , y + 1, WHITE);  // 从中间位置开始填充
}
void drawCylinder10(double x, double y,int num) {
    setfillstyle(SOLID_FILL, DARKGRAY);  // 设置填充颜色为蓝色
    floodfill(x +1 , y + 1, WHITE);  // 从中间位置开始填充
}
void drawCylinder11(double x, double y,int num) {
    setfillstyle(SOLID_FILL, LIGHTBLUE);  // 设置填充颜色为蓝色
    floodfill(x +1 , y + 1, WHITE);  // 从中间位置开始填充
}
void drawCylinder12(double x, double y,int num) {
    setfillstyle(SOLID_FILL, LIGHTGREEN);  // 设置填充颜色为蓝色
    floodfill(x +1 , y + 1, WHITE);  // 从中间位置开始填充
}
void drawCylinder13(double x, double y,int num) {
    setfillstyle(SOLID_FILL, LIGHTCYAN);  // 设置填充颜色为蓝色
    floodfill(x +1 , y + 1, WHITE);  // 从中间位置开始填充
}
void drawCylinder14(double x, double y,int num) {
    setfillstyle(SOLID_FILL, LIGHTRED);  // 设置填充颜色为蓝色
    floodfill(x +1 , y + 1, WHITE);  // 从中间位置开始填充
}
void drawCylinder15(double x, double y,int num) {
    setfillstyle(SOLID_FILL, LIGHTMAGENTA);  // 设置填充颜色为蓝色
    floodfill(x +1 , y + 1, WHITE);  // 从中间位置开始填充
}
string get(int x)
{
	string s="";
	if(x==0)return "0";
	while(x)
	{
		s+=(x%10)+'0';
		x/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
void init(int z[])
{
	cleardevice();
	for(int i=1;i<=n;i++)
	{	
		drawCylinder1(i*50+50,400-z[i],i,z);
		Sleep(10);
	}
}
void final(int z[])
{
	cleardevice();
	for(int i=1;i<=n;i++)
	{	
		drawCylinder3(i*50+50,400-z[i],i,z);
		Sleep(10);
	}
}
void solve1()
{
	init(z);
	x=0;
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "冒泡排序");
	outtextxy(10, 40, "交换次数:");
	xx=get(x); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 40, c);
    for(int i=1;i<n;i++)
    {
    	for(int j=1;j<=n-i;j++)
    	{
    		cnt1++;
    		if(z1[j]>z1[j+1])
    		{
    			drawCylinder2(j*50+50,400-z1[j],j);
    			Sleep(10);
    			drawCylinder2(j*50+100,400-z1[j+1],1+j);
    			Sleep(1000);
    			swap(z1[j],z1[j+1]);
    			x++;
    			init(z1);
    			setfont(25, 0, "宋体");
				outtextxy(10, 10, "冒泡排序");
				outtextxy(10, 40, "交换次数:");
				xx=get(x); 	
				strcpy(c,xx.c_str());
				outtextxy(125, 40, c);
			}
		}
	}
	res[1]=x;
	final(z1); 
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "冒泡排序");
	outtextxy(10, 40, "最终次数:");
	xx=get(x); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 40, c);
	outtextxy(10, 70, "遍历次数:");
	xx=get(cnt1); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 70, c);
	Sleep(3000);
    menu();
}
int y[20];
void extrasolve(int p,int q)
{
	init(z2);
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "归并排序");
	outtextxy(10, 40, "区间:");
	xx=get(p); 	
	strcpy(c,xx.c_str());
	outtextxy(75, 40, c);
	outtextxy(115, 40, "--");
	xx=get(q); 	
	strcpy(c,xx.c_str());
	outtextxy(145, 40, c);
	int l1=p,l2=(p+q)/2+1,l3=p;
	int t=0;
	while(t<q-p+1)
	{
		while(l1<(p+q)/2+1&&z2[l1]<z2[l2]) 
		{
			drawCylinder2(l1*50+50,400-z2[l1],l1);
			y[l3++]=z2[l1++];t++;
			Sleep(500); 
			cnt2++;
		}
		while(l2<q+1&&z2[l1]>=z2[l2]) 
		{
			drawCylinder2(l2*50+50,400-z2[l2],l2);
			y[l3++]=z2[l2++];t++;
			Sleep(500); 
			cnt2++;
		}
		while(l1>(p+q)/2&&l2<q+1) 
		{
			drawCylinder2(l2*50+50,400-z2[l2],l2);
			y[l3++]=z2[l2++];t++;
			Sleep(500); 
			cnt2++;
		}
		while(l2>q&&l1<(p+q)/2+1) 
		{
			drawCylinder2(l1*50+50,400-z2[l1],l1);
			y[l3++]=z2[l1++];t++;
			Sleep(500); 
			cnt2++;
		}
	}
	for(int i=p;i<=q;i++)	z2[i]=y[i];
	init(z2);
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "归并排序");
	outtextxy(10, 40, "区间:");
	xx=get(p); 	
	strcpy(c,xx.c_str());
	outtextxy(75, 40, c);
	outtextxy(115, 40, "--");
	xx=get(q); 	
	strcpy(c,xx.c_str());
	outtextxy(145, 40, c);
	Sleep(1000); 
}
void guibing(int p,int q)
{
	int k=(p+q)/2;
	if(p!=k)
	{
		guibing(p,k);
		guibing(k+1,q);	
	}
	extrasolve(p,q);
}
void solve2()
{
	init(z);
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "归并排序");
	guibing(1,n);
	final(z2);
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "归并排序");
	setfont(25, 0, "宋体");
	outtextxy(10, 40, "遍历次数");
	xx=get(cnt2); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 40, c);
	Sleep(3000);
    menu();
}
void InsertSort(int l)
{
    int temp;
    int j;
    for(int i=1;i<=l;i++)
    {
        if(z3[i]<z3[i-1])
        {
            temp=z3[i];
            for(j=i-1;j>=0&&temp<z3[j];j--)
            {
            	cnt3++;
                drawCylinder2(j*50+50,400-z3[j],j);
    			Sleep(10);
    			drawCylinder2(j*50+100,400-z3[1+j],1+j);
    			Sleep(800);
    			swap(z3[j],z3[j+1]);
    			x++;
    			init(z3);
    			setfont(25, 0, "宋体");
				outtextxy(10, 10, "插入排序");
				outtextxy(10, 40, "交换次数:");
				xx=get(x); 	
				strcpy(c,xx.c_str());
				outtextxy(125, 40, c);
            }
         //   z2[j+1]=temp;

        }
    }
}
void solve3()
{
	x=0;
	init(z);
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "插入排序");
	outtextxy(10, 40, "交换次数:");
	xx=get(x); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 40, c);
	InsertSort(n);
	final(z3);
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "插入排序");
	outtextxy(10, 40, "最终次数:");
	xx=get(x); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 40, c);
	outtextxy(10, 70, "遍历次数:");
	xx=get(cnt3); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 70, c);
	Sleep(3000);
    menu();
}

void Select_Sort(int n)   
{
	for (int i = 1; i <= n-1; i++) 
	{
		int min = i;
		x++; 
		drawCylinder4(i*50+50,400-z4[i],i);
		Sleep(600);
		for (int j = i; j <= n; j++) 
		{
			cnt4++;
			if (z4[min] > z4[j]) 
			{
				drawCylinder4(j*50+50,400-z4[j],j);
				drawCylinder5(min*50+50,400-z4[min],min);
				min = j;
				x++; 
				Sleep(600);
			}
		}
		if (min != i) 
		{
			drawCylinder2(i*50+50,400-z4[i],i);
			drawCylinder2(min*50+50,400-z4[min],min);
			Sleep(800);
			swap(z4[i], z4[min]);
		}
		init(z4);
		setfont(25, 0, "宋体");
		outtextxy(10, 10, "选择排序");
		outtextxy(10, 40, "标记次数:");
		xx=get(x); 	
		strcpy(c,xx.c_str());
		outtextxy(125, 40, c);
		Sleep(1000);
	}
}

void solve4()
{
	x=0; 
	init(z);
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "选择排序");
	outtextxy(10, 40, "交换次数:");
	xx=get(x); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 40, c);
	outtextxy(10, 40, "标记次数:");
	xx=get(x); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 40, c);
	Select_Sort(n);
	final(z4); 
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "选择排序");
	outtextxy(10, 40, "总标记数:");
	xx=get(x); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 40, c);
	outtextxy(10, 70, "遍历次数:");
	xx=get(cnt4); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 70, c);
	Sleep(3000);
    menu();
}
void quicksort(int left, int right) {
	int i, j, t, temp;
	if(left > right)return;
    temp = z5[left]; //temp中存的就是基准数
    init(z5); 
    setfont(25, 0, "宋体");
	outtextxy(10, 10, "快速排序");
	outtextxy(10, 40, "交换次数:");
	xx=get(x); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 40, c);
	outtextxy(10, 70, "区间:");
	xx=get(left); 	
	strcpy(c,xx.c_str());
	outtextxy(75, 70, c);
	outtextxy(115, 70, "--");
	xx=get(right); 	
	strcpy(c,xx.c_str());
	outtextxy(145, 70, c);
    i = left;
    j = right;
    while(i != j) 
	{ 
    	while(z5[j] >= temp && i < j)j--,cnt5++;
    	while(z5[i] <= temp && i < j)i++,cnt5++;       
    	if(i < j)
    	{
    		drawCylinder2(i*50+50,400-z5[i],i);
    		Sleep(10);
    		drawCylinder2(j*50+50,400-z5[j],j);
    		Sleep(1500);
   			swap(z5[i],z5[j]);
    		x++;
    		init(z5);
    		setfont(25, 0, "宋体");
			outtextxy(10, 10, "快速排序");
			outtextxy(10, 40, "交换次数:");
			xx=get(x); 	
			strcpy(c,xx.c_str());
			outtextxy(125, 40, c);
			outtextxy(10, 70, "区间:");
			xx=get(left); 	
			strcpy(c,xx.c_str());
			outtextxy(75, 70, c);
			outtextxy(115, 70, "--");
			xx=get(right); 	
			strcpy(c,xx.c_str());
			outtextxy(145, 70, c);
			cnt5++;
    	}
    }
    j=left;
	if(i!=j)
	{
		drawCylinder2(i*50+50,400-z5[i],i);
	    Sleep(10);
	    drawCylinder2(j*50+50,400-z5[j],j);
	    Sleep(1500);
	   	swap(z5[i],z5[j]);
	    x++;
	    init(z5);
	    setfont(25, 0, "宋体");
		outtextxy(10, 10, "快速排序");
		outtextxy(10, 40, "交换次数:");
		xx=get(x); 	
		strcpy(c,xx.c_str());
		outtextxy(125, 40, c);
		outtextxy(10, 70, "区间:");
		xx=get(left); 	
		strcpy(c,xx.c_str());
		outtextxy(75, 70, c);
		outtextxy(115, 70, "--");
		xx=get(right); 	
		strcpy(c,xx.c_str());
		outtextxy(145, 70, c);
	}
	Sleep(1000);
    quicksort(left, i-1);
    quicksort(i+1, right);
}
void solve5()
{
	x=0;
	init(z);
	setfont(25, 0, "宋体");
	outtextxy(10, 40, "交换次数:");
	xx=get(x); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 40, c);
	outtextxy(10, 10, "快速排序");
	quicksort(1,n);
	res[5]=x;
	final(z5);
	setfont(25, 0, "宋体");
	outtextxy(10, 40, "最终次数:");
	xx=get(x); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 40, c);
	outtextxy(10, 10, "快速排序");
	outtextxy(10, 70, "遍历次数:");
	xx=get(cnt5); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 70, c);

	Sleep(3000);
    menu();
}
int GetMaxDigit(int n)
{
    int maxdata = *max_element(z6+1, z6+1 + n);
    int maxdigit = 0;                   
    while(maxdata)
	{
		maxdata /= 10;
		maxdigit++;
    }
    return maxdigit;
}


//基数排序
void RadixSort(int n)
{
    int base = 1, digit = GetMaxDigit(n);
    while(digit--)
	{
		outtextxy(10, 40, "当前基数");
		xx=get(base); 	
		strcpy(c,xx.c_str());
		outtextxy(125, 40, c);
		int count[20];
		for(int i=0;i<10;i++)count[i]=0;
        for(int i = 1; i <= n; i++)
		{
			cnt6++;
            int index = z6[i] / base % 10; 
            if(index==0)drawCylinder6(i*50+50,400-z6[i],i);
            if(index==1)drawCylinder7(i*50+50,400-z6[i],i);
            if(index==2)drawCylinder8(i*50+50,400-z6[i],i);
            if(index==3)drawCylinder9(i*50+50,400-z6[i],i);
            if(index==4)drawCylinder10(i*50+50,400-z6[i],i);
            if(index==5)drawCylinder11(i*50+50,400-z6[i],i);
            if(index==6)drawCylinder12(i*50+50,400-z6[i],i);
            if(index==7)drawCylinder13(i*50+50,400-z6[i],i);
            if(index==8)drawCylinder14(i*50+50,400-z6[i],i);
            if(index==9)drawCylinder15(i*50+50,400-z6[i],i);
            count[index]++;
            Sleep(500);
        }
         Sleep(1000);
        for(int i=0;i<10;i++)start[i]=0;
        for(int i = 1; i < 10; i++)start[i]=count[i-1]+start[i-1];

        for(int i=0;i<=n+1;i++)tmp[i]=0;
        for(int i = 1; i <=n; i++)
		{
            int index = z6[i] / base % 10;
            tmp[++start[index]] = z6[i];    //某一位相同的数字放到临时数组中合适的位置
        }

        for(int i=1;i<=n;i++)z6[i]=tmp[i];
        base *= 10;                        //比较下一位
        init(z6);
        setfont(25, 0, "宋体");
		outtextxy(10, 10, "基数排序");
        Sleep(2000);
    }      

                    
}
void solve6()
{
	init(z);
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "基数排序");
	Sleep(1000);
	RadixSort(n);
	final(z6);
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "基数排序");
	outtextxy(10, 40, "遍历次数:");
	xx=get(cnt6); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 40, c);
	Sleep(3000);
    menu();
}
void result()
{
	cleardevice();
	setfont(40, 0, "宋体");
  	outtextxy(130, 50, "排序算法比较最终结果");
  	setfont(25, 0, "宋体");
  	outtextxy(80, 130, "1.冒泡排序");
    outtextxy(80, 170, "2.归并排序");
    outtextxy(80, 210, "3.插入排序");
    outtextxy(80, 250, "4.选择排序");
    outtextxy(80, 290, "5.快速排序");
    outtextxy(80, 330, "6.基数排序");
  	outtextxy(220,130, "遍历次数:");
  	outtextxy(220,170, "遍历次数:");
  	outtextxy(220,210, "遍历次数:");
  	outtextxy(220,250, "遍历次数:");
  	outtextxy(220,290, "遍历次数:");
  	outtextxy(220,330, "遍历次数:");
	xx=get(cnt1); 	
	strcpy(c,xx.c_str());
	outtextxy(330, 130, c);
	xx=get(cnt2); 	
	strcpy(c,xx.c_str());
	outtextxy(330, 170, c);
	xx=get(cnt3); 	
	strcpy(c,xx.c_str());
	outtextxy(330, 210, c);
	xx=get(cnt4); 	
	strcpy(c,xx.c_str());
	outtextxy(330, 250, c);
	xx=get(cnt5); 	
	strcpy(c,xx.c_str());
	outtextxy(330, 290, c);
	xx=get(cnt6); 	
	strcpy(c,xx.c_str());
	outtextxy(330, 330, c);
	Sleep(10000);
	menu();
	return;
} 
void menu1();
void menu3()
{
	outtextxy(250, 130, "1.输入数据");
    outtextxy(250, 170, "2.随机生成");
    char nx;
    nx = getch();
    if (nx == '1') 
    {
    	cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>z[i];
		}
		cout<<"ok";
	}
    if (nx == '2')
    {
    	n=10;
		for(int i=1;i<=n;i++)
		{
			z[i]=rand()%250+50;
			while(i>1&&z[i]>=z[i+1])
			{
				int k=rand()%3+1;
				if(k%3)z[i]=rand()%200+50;
				else break;
			}
		}
	}
	ok=1;
	menu(); 
}
void menu() //选择菜单
{
	if(!ok)menu3(); 
	
	for(int i=1;i<=n;i++)z1[i]=z[i];
	for(int i=1;i<=n;i++)z2[i]=z[i];
	for(int i=1;i<=n;i++)z3[i]=z[i];
	for(int i=1;i<=n;i++)z4[i]=z[i];
	for(int i=1;i<=n;i++)z5[i]=z[i];
	for(int i=1;i<=n;i++)z6[i]=z[i];
    cleardevice();
   // SetBkColor(EGERGB(0x0,0x0,0xFF));
  	setfont(40, 0, "宋体");
  	outtextxy(200, 60, "排序算法演示");
    setfont(25, 0, "宋体");
    setcolor(EGERGB(0xAA, 0xCC, 0x77));
    outtextxy(250, 130, "1.冒泡排序");
    outtextxy(250, 170, "2.归并排序");
    outtextxy(250, 210, "3.插入排序");
    outtextxy(250, 250, "4.选择排序");
    outtextxy(250, 290, "5.快速排序");
    outtextxy(250, 330, "6.基数排序");
    outtextxy(250, 370, "7.最终结果");
    outtextxy(250, 410, "8.主页面");
    char nx;
    nx = getch();
    if (nx == '1') solve1();
    if (nx == '2') solve2();
    if (nx == '3') solve3();
	if (nx == '4') solve4();
    if (nx == '5') solve5();
    if (nx == '6') solve6();
    if (nx == '7') result();
    if (nx == '8') menu1();
}
void menu2()
{
	
	return; 
}
void menu1() //选择菜单
{
    cleardevice();
   // SetBkColor(EGERGB(0x0,0x0,0xFF));
  	setfont(40, 0, "宋体");
  	outtextxy(200, 60, "排序算法比较");
    setfont(25, 0, "宋体");
    setcolor(EGERGB(0xAA, 0xCC, 0x77));
    outtextxy(250, 130, "1.算法演示");
    outtextxy(250, 170, "2.时间比较");
    outtextxy(250, 210, "3.退出程序");
    char nx;
    nx = getch();
    if (nx == '1') menu();
    if (nx == '2') menu2();
	if (nx == '3') return;
}
int main() 
{
	srand(time(0));
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
	menu1();
    return 0;
}

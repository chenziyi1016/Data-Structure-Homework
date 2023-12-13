#include <graphics.h>
#include<bits/stdc++.h>
using namespace std;
int z[20],res[10],z1[20],z2[20],z3[20],z4[20],z5[20],z6[20],n,x;
char c[30];
string xx;
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
//void solve()
//{
//	
//    
//
//    int x1 = 100, y1 = 200;  // 圆柱体1的初始位置
//    int x2 = 300, y2 = 200;  // 圆柱体2的初始位置
//
//    for (int i = 0; i < 50000; i++) {
//        cleardevice();  // 清空屏幕
//        // 画第一个圆柱体
//        drawCylinder1(x1 + i * 0.4, y1);
//	//	delay(2); 
//        // 画第二个圆柱体
//        drawCylinder2(x2 - i *0.4, y2);
//
//        delay(30);  // 等待一段时间
//    }
//
//    delay(5000);
//    closegraph();
//}
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
    		if(z1[j]>z1[j+1])
    		{
    			drawCylinder2(j*50+50,400-z1[j],j);
    			Sleep(10);
    			drawCylinder2(j*50+100,400-z1[j+1],1+j);
    			Sleep(1500);
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
	Sleep(5000);
    menu();
}


void solve2()
{
	init(z);
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "归并排序");
	Sleep(10000);
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
                drawCylinder2(j*50+50,400-z3[j],j);
    			Sleep(10);
    			drawCylinder2(j*50+100,400-z3[1+j],1+j);
    			Sleep(1500);
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
	Sleep(5000);
    menu();
}
void solve4()
{
	init(z);
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "选择排序");
	outtextxy(10, 40, "交换次数:");
	xx=get(x); 	
	strcpy(c,xx.c_str());
	outtextxy(125, 40, c);
	final(z4); 
	Sleep(10000);
    menu();
}
void quicksort(int left, int right) {
	int i, j, t, temp;
//	cout<<left<<" "<<right<<'\n';
	if(left > right)
		return;
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
    	while(z5[j] >= temp && i < j)j--;
    	while(z5[i] <= temp && i < j)i++;       
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
	Sleep(5000);
    menu();
}
void solve6()
{
	init(z);
	setfont(25, 0, "宋体");
	outtextxy(10, 10, "堆排序");
	Sleep(10000);
    menu();
}
void result()
{
	return;
} 
void menu() //选择菜单
{
    cleardevice();
  //  SetBkColor(EGERGB(0x0,0x0,0xFF));
  	setfont(40, 0, "宋体");
  	outtextxy(200, 60, "排序算法比较");
    setfont(25, 0, "宋体");
    setcolor(EGERGB(0xFF, 0x0, 0x00));
    outtextxy(250, 130, "1.冒泡排序");
    outtextxy(250, 170, "2.归并排序");
    outtextxy(250, 210, "3.插入排序");
    outtextxy(250, 250, "4.选择排序");
    outtextxy(250, 290, "5.快速排序");
    outtextxy(250, 330, "6.堆排序");
    outtextxy(250, 370, "7.最终结果");
    char nx;
    nx = getch();
    if (nx == '1') solve1();
    if (nx == '2') solve2();
    if (nx == '3') solve3();
	if (nx == '4') solve4();
    if (nx == '5') solve5();
    if (nx == '6') solve6();
    if (nx == '7') result();
}
int main() 
{
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    n=10;
	for(int i=1;i<=n;i++)
	{
		z[i]=rand()%200+50;
		while(i>1&&z[i]>=z[i+1])
		{
			int k=rand()%2+1;
			if(k%2)z[i]=rand()%200+50;
			else break;
		}
	}
	for(int i=1;i<=n;i++)z1[i]=z[i];
	for(int i=1;i<=n;i++)z2[i]=z[i];
	for(int i=1;i<=n;i++)z3[i]=z[i];
	for(int i=1;i<=n;i++)z4[i]=z[i];
	for(int i=1;i<=n;i++)z5[i]=z[i];
	for(int i=1;i<=n;i++)z6[i]=z[i];
	menu();
    return 0;
}

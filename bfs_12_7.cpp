#include <bits/stdc++.h>
#include <graphics.h>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
//定义四个方向的行进增量
#define DIRECTION_NUM 4
int dx[DIRECTION_NUM] = { -1, 0, 1, 0 };
int dy[DIRECTION_NUM] = { 0, -1, 0, 1 };

//自定义颜色
const int COLOR_BLUE  = EGERGB(5, 224, 218);

//迷宫大小设置
const int MAZE_INC_SIZE = 8;						//迷宫大小变化增量
const int MAZE_MAX_SIZE = 5 * MAZE_INC_SIZE;		//迷宫大小最大值
const int MAZE_MIN_SIZE = MAZE_INC_SIZE;			//迷宫大小最小值
const int GRID_MAX_NUM = 2 * MAZE_MAX_SIZE + 1;		//迷宫格子数最大值(每行)

//迷宫
typedef struct Maze
{
	int size;			//迷宫大小
	int gridNum;		//格子数(每行)
	int gridWidth;		//格子宽度
	int grid[GRID_MAX_NUM][GRID_MAX_NUM];	//格子数据
	bool visited[GRID_MAX_NUM][GRID_MAX_NUM];		//判断这个格子是否到达过 
}Maze;

//迷宫数据
Maze maze;

int xCur, yCur;
int scrWidth = 600, scrHeight = 600;
int cnt=0; //bfs 层数
string xx;
char c[10];
int ok=0,op=1;

//方向定义
enum Direction {
	LEFT  = 0,
	UP    = 1,
	RIGHT = 2,
	DOWN  = 3
};

//块类型
enum BlockType {
	BLOCK_BLANK = 0,	//空格
	BLOCK_WALL,			//墙
	BLOCK_PATH,			//路径
};

void createMaze(int size);
void initMaze();
void drawMaze(bool enablePath);
bool findPath(int x, int y);

void drawHelpTip();

void shuffle(int a[], int length);

class fireball //烟花火球类
{
    private: double x;
    double y;
    double vx;
    double vy;
    int r;
    public: void setfireball(double a, double b, double c, double d) {
        x = a;
        y = b;
        vx = c;
        vy = d;
    }
    void setx(double a) {
        x = a;
    }
    double getx() {
        return x;
    }
    void sety(double a) {
        y = a;
    }
    double gety() {
        return y;
    }
    void setvx(double a) {
        vx = a;
    }
    double getvx() {
        return vx;
    }
    void setvy(double a) {
        vy = a;
    }
    double getvy() {
        return vy;
    }
    void explode() {}
    void setr(int a) {
        r = a;
    }
    int getr() {
        return r;
    }
    void show() {
        //模拟的是抛体运动
        setx(getx() + vx);
        sety(gety() + vy);
        vy += 0.3f;
        fillellipse(x, y, r, r);
    }
};
class firework //烟花类
{
    private: fireball f[80]; //用80个火球类作为烟花类的子对象
    int x0;
    int y0;
    public: int getx0() {
        return x0;
    }
    int gety0() {
        return y0;
    }
    int c = 255;
    void setfirework(int x, int y, int r) {
        double angle = 0;
        for (int i = 0; i < 80; i++) {
            f[i].setvx(8 * cos(angle));
            f[i].setvy(8 * sin(angle));
            f[i].setx(x);
            f[i].sety(y);
            f[i].setr(r);
            angle += 0.078539;
        }
        x0 = x;
        y0 = y;
    }
    void showfirework() {
        c--;
        setfillcolor(EGERGB(c, c, 0));
        fillellipse(x0, y0, 5, 5);
        for (int i = 0; i < 80; i++) {
            if (i % 2 == 0) setfillcolor(EGERGB(255, 0, 0));
            else setfillcolor(EGERGB(0, 255, 0));
            if (i % 3 == 0) setfillcolor(EGERGB(255, 255, 0));
            f[i].show();
        }
    }
};
void fireworkscene(int num) //用若干个烟花组成一个烟花景象
{
    while (num--) {
        setbkcolor(EGERGB(0x0, 0x0, 0x0));
        setbkmode(TRANSPARENT);
        //firework fw[15];
        //for(int i=0;i<15;i++)fw[i].setfirework(40+i*40,100);
        firework f;
        f.setfirework(320, 100, 3);
        firework f2;
        f2.setfirework(200, 78, 2);
        firework f3;
        f3.setfirework(480, 148, 1);
        int count = 0;
        int y2 = 480,
        y3 = 480;
        int y = 480;
        firework f4;
        f4.setfirework(150, 350 - 100, 3);
        firework f5;
        f5.setfirework(400, 380 - 100, 1);
        firework f6;
        f6.setfirework(500, 398 - 100, 2);
        int y4 = 480,
        y5 = 480,
        y6 = 480;
        firework f7;
        f7.setfirework(198, 230, 1);
        firework f9;
        f9.setfirework(322, 200, 1);
        firework f8;
        f8.setfirework(448, 269, 2);
        firework f10;
        f10.setfirework(336, 70, 3);
        int y7 = 480,
        y8 = 480,
        y9 = 480;
        int y10 = 480;
        for (; is_run() && count < 200; delay_fps(80)) {
            count++;
            imagefilter_blurring(NULL, 0x7e, 0xff);
            setcolor(EGERGB(255, 255, 255));
            if (y2 > f2.gety0()) circle(f2.getx0(), y2 = y2 - 4, 3);
            else f2.showfirework();
            if (y3 > f3.gety0()) circle(f3.getx0(), y3 = y3 - 4, 3);
            else f3.showfirework();
            if (y > f.gety0()) circle(f.getx0(), y = y - 4, 3);
            else f.showfirework();
            if (y4 > f4.gety0()) circle(f4.getx0(), y4 = y4 - 4, 3);
            else f4.showfirework();
            if (y5 > f5.gety0()) circle(f5.getx0(), y5 = y5 - 4, 3);
            else f5.showfirework();
            if (y6 > f6.gety0()) circle(f6.getx0(), y6 = y6 - 4, 3);
            else f6.showfirework();
            if (y7 > f7.gety0()) circle(f7.getx0(), y7 = y7 - 4, 3);
            else f7.showfirework();
            if (y8 > f8.gety0()) circle(f8.getx0(), y8 = y8 - 4, 3);
            else f8.showfirework();
            if (y9 > f9.gety0()) circle(f9.getx0(), y9 = y9 - 4, 3);
            else f9.showfirework();
            if (y10 > f10.gety0()) circle(f10.getx0(), y10 = y10 - 4, 3);
            else f10.showfirework();
 
            setfillcolor(EGERGB(255, 255, 0));
            fillellipse(500, 50, 20, 20); //金黄色的月亮
            for (int i = 0; i < 30; i++) {
                fillellipse((i * i * 34 + i * 8 * 8 * i * i - 3) % 640, (i * i * i * 28 + i * 8 + i * i - 232) % 240, 1, 1); //美丽的星星
            }
        }
    }
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

void bfs(Maze maze) {
    std::queue<std::pair<int, int>> q;
    q.push({yCur, xCur}); 
	if (maze.grid[yCur][xCur] == BLOCK_BLANK) {
				setfillcolor(YELLOW);
	            bar(xCur * maze.gridWidth + maze.gridWidth / 8, yCur * maze.gridWidth + maze.gridWidth / 8,
	                (xCur + 1) * maze.gridWidth - maze.gridWidth / 8, (yCur + 1) * maze.gridWidth - maze.gridWidth / 8);
	            Sleep(30);
	}
	xx=get(cnt); 	
	strcpy(c,xx.c_str());
	setfillcolor(BLACK); // 设置填充颜色为黑色
	ege_fillrect(100, 825, 300, 50); // 绘制矩形
	outtextxy(120, 845, c);
	ok=0;
    while (!q.empty()) {
        int si=q.size();
        cnt++;
        xx=get(cnt); 	
		strcpy(c,xx.c_str());
		setfillcolor(BLACK); // 设置填充颜色为黑色
		ege_fillrect(100, 825, 300, 50); // 绘制矩形
		outtextxy(120, 845, c);
        for(int i=0;i<si;++i)
        {
        	auto [x, y] = q.front();
			q.pop();
        	if (((maze.grid[x+1][y] == BLOCK_BLANK)) && !maze.visited[x+1][y]) {
            	q.push({x+1,y});
         	    maze.visited[x+1][y] = true;
         	    setfillcolor(YELLOW);
           	 	bar(y * maze.gridWidth + maze.gridWidth / 8, (x+1)* maze.gridWidth + maze.gridWidth / 8,
			            (y + 1) * maze.gridWidth - maze.gridWidth / 8, (x+2) * maze.gridWidth - maze.gridWidth / 8);
				if ((x+1 == maze.gridNum - 2) && (y == maze.gridNum - 2))
				{	
					ok=1;
					break;
				}
        	}
        	if (((maze.grid[x-1][y] == BLOCK_BLANK)) && !maze.visited[x-1][y]) {
		        q.push({x-1,y});
		       	maze.visited[x-1][y] = true;
		       	setfillcolor(YELLOW);
		        bar(y * maze.gridWidth + maze.gridWidth / 8, (x-1) * maze.gridWidth + maze.gridWidth / 8,
				                (y + 1) * maze.gridWidth - maze.gridWidth / 8, x * maze.gridWidth - maze.gridWidth / 8);
				if ((x-1 == maze.gridNum - 2) && (y == maze.gridNum - 2))
				{	
					ok=1;
					break;
				}
			}
			if (((maze.grid[x][y+1] == BLOCK_BLANK)) && !maze.visited[x][y+1]) {
		        	q.push({x,y+1});
		            maze.visited[x][y+1] = true;
		            setfillcolor(YELLOW);
		            bar((y + 1 ) * maze.gridWidth + maze.gridWidth / 8, x * maze.gridWidth + maze.gridWidth / 8,
					                (y + 2) * maze.gridWidth - maze.gridWidth / 8, (x + 1) * maze.gridWidth - maze.gridWidth / 8);
					if ((x == maze.gridNum - 2) && (y + 1 == maze.gridNum - 2))
					{	
						ok=1;
						break;
					}
			}
			if (((maze.grid[x][y-1] == BLOCK_BLANK)) && !maze.visited[x][y-1]) {
		            q.push({x,y-1});
		            maze.visited[x][y-1] = true;
		            setfillcolor(YELLOW);
		            bar((y-1) * maze.gridWidth + maze.gridWidth / 8, x * maze.gridWidth + maze.gridWidth / 8,
					                (y) * maze.gridWidth - maze.gridWidth / 8, (x + 1) * maze.gridWidth - maze.gridWidth / 8);
					if ((x == maze.gridNum - 2) && (y - 1 == maze.gridNum - 2))
					{	
						ok=1;
						break;
					}
			}
		}
		Sleep(30);
		if(ok==1) 
		{
			break;
		}
    }
    
	return ;
}

int main()
{
	setinitmode(INIT_RENDERMANUAL);
	createMaze(3 * MAZE_INC_SIZE);
	setcaption("迷宫");
	setbkmode(TRANSPARENT);

	bool flag_showPath = false;			//路径显示标志位
	bool redraw = false;					//重绘标志位

	srand((unsigned)time(0));

	drawMaze(false);				//绘制迷宫
	op=0;
	while (is_run()) {
		key_msg msg = getkey();

		int d = -1;
		if (msg.msg == key_msg_down) {
			//方向移动
			switch (msg.key) {
			case key_left:	d = LEFT;	break;
			case key_up:	d = UP;		break;
			case key_right:	d = RIGHT;	break;
			case key_down:	d = DOWN;	break;

			//功能键

			case key_enter:	//回车键，查找路径
				findPath(xCur, yCur);
				flag_showPath = true;	//同时设置显示路径
				redraw = true;
				break;

			case key_esc:	//ESC键，重新开始
				initMaze();
				redraw = true;
				break;
				
			case key_space: //空格键，进行bfs查找路径
				op=1;
				setfillcolor(BLACK); 
				ege_fillrect(0, 825, 300, 50); 
				setfont(20, 0, "宋体");
				outtextxy(10, 845, "bfs层数:");
				cnt = 0;
				bfs(maze);
				redraw = true;
				break;
			}
		}
		if(op==1)
		{
			    setfillcolor(BLACK); 
			    ege_fillrect(0, 825, 300, 50); 
			    setfont(20, 0, "宋体");
				outtextxy(10, 845, "最小步数:");
				xx=get(cnt); 	
				strcpy(c,xx.c_str());
				outtextxy(120, 845, c);
		}
		//按方向移动(单次移动两格) 
		if (d != -1) {
			//分别计算按指定方向行进一格和行进两格的位置
			int xNext1 = xCur + dx[d],     yNext1 = yCur + dy[d];
			int xNext2 = xCur + 2 * dx[d], yNext2 = yCur + 2 * dy[d];

			//判断是否可以按指定方向移动(目标方向上无墙格挡即可移动)
			if (0 <= xNext1 && xNext1 < maze.gridNum && 0 <= yNext1 && yNext1 < maze.gridNum
				&& (maze.grid[yNext1][xNext1] != BLOCK_WALL)) {

				//根据路线上的格子类型，修改路线样式
				switch (maze.grid[yNext1][xNext1]) {
				case BLOCK_PATH: //目标地点为路径，则消除路线上的路径标记，走过地方设置为空格
					maze.grid[yCur][xCur] = BLOCK_BLANK;
					maze.grid[yNext1][xNext1] = BLOCK_BLANK;
					break;

				case BLOCK_BLANK: //目标地点为空格，则路线上的格子设置为当前的值
					maze.grid[yNext1][xNext1] = maze.grid[yCur][xCur];
					maze.grid[yNext2][xNext2] = maze.grid[yCur][xCur];
					break;
				}

				//移动到目标位置
				xCur = xNext2;
				yCur = yNext2;

				//判断是否到终点(右下角)
				if ((xCur == maze.gridNum - 2) && (yCur == maze.gridNum - 2))
				{	
					Sleep(5);
				    fireworkscene(2);
				    Sleep(20);
					initMaze();
				}
				redraw = true;
			}
		}

		//重绘
		if (redraw) {
			redraw = false;
			drawMaze(flag_showPath);
		}
	}
	closegraph();
	return 0;
}

//创建迷宫
void createMaze(int size)
{
	if ((size > MAZE_MAX_SIZE) || (maze.size == size))
		return;

	maze.size = size;
	maze.gridNum = 2 * size + 1;

	//预设窗口宽高为800左右
	maze.gridWidth = (int)ceil(800.0f / maze.gridNum);	

	initMaze();

	//调整窗口大小
	scrWidth = maze.gridNum * maze.gridWidth;
	scrHeight = maze.gridNum * maze.gridWidth;
	initgraph(scrWidth, scrHeight+50);
}


//随机置乱
void shuffle(int a[], int length)
{
	for (int i = length - 1; i > 0; i--) {
		int r = rand() % i + 1;
		int temp = a[i];
		a[i] = a[r];
		a[r] = temp;
	}
}

//绘制带路径的迷宫
void drawMaze(bool enablePath)
{
	setbkcolor_f(BLACK);
	cleardevice();

	//格子内部边缘空隙宽度，取格子宽度1/8
	int padding = maze.gridWidth / 8;

	setcolor(WHITE);
	setlinewidth(2);
	//横围墙
	for (int i = 0; i < maze.gridNum; i += 2) {
		for (int j = 1; j < maze.gridNum; j += 2) {
			if (maze.grid[i][j] == BLOCK_WALL)
				line((j - 1) * maze.gridWidth + maze.gridWidth / 2, i * maze.gridWidth + maze.gridWidth / 2,
					(j + 1) * maze.gridWidth + maze.gridWidth / 2, i * maze.gridWidth + maze.gridWidth / 2);
		}
	}
	//竖围墙
	for (int i = 1; i < maze.gridNum; i += 2) {
		for (int j = 0; j < maze.gridNum; j += 2) {
			if (maze.grid[i][j] == BLOCK_WALL)
				line(j * maze.gridWidth + maze.gridWidth / 2, (i - 1) * maze.gridWidth + maze.gridWidth / 2,
					j * maze.gridWidth + maze.gridWidth / 2, (i + 1) * maze.gridWidth + maze.gridWidth / 2);
		}
	}

	//绘制到终点的路径
	if (enablePath) {
		setfillcolor(RED);
		for (int i = 1; i < maze.gridNum; i++) {
			for (int j = 1; j < maze.gridNum; j++) {
				if (maze.grid[i][j] == BLOCK_PATH)
					bar(j * maze.gridWidth + padding, i * maze.gridWidth + padding,
						(j + 1) * maze.gridWidth - padding, (i + 1) * maze.gridWidth - padding);
			}
		}
	}

	//绘制当前位置
	setfillcolor(RED);

	bar(xCur * maze.gridWidth + padding, yCur * maze.gridWidth + padding,
		(xCur + 1) * maze.gridWidth - padding, (yCur + 1) * maze.gridWidth - padding);

}

//带权的路径压缩并查集
class UnionFindSet
{
private:
	int* set;
	int* weight;
	int size;
	int count;
public:
	UnionFindSet(int size)
	{
		this->size = size;
		set = new int[size];
		weight = new int[size];

		init();
	}
	~UnionFindSet() {
		delete[] set;
		delete[] weight;
	}

	void init()
	{
		count = size;
		for (int i = 0; i < size; i++) {
			set[i] = i;
			weight[i] = 1;
		}
	}

	int find(int id)
	{
		while (set[id] != id)
			id = set[id];

		return id;
	}


	int quickFind(int id)
	{
		int root = id;
		while (set[root] != root)
			root = set[root];

		//路径压缩，将沿路的结点直接连到根节点上
		while (set[id] != root) {
			int t = id;
			id = set[id];
			set[t] = root;
		}

		return root;
	}

	//合并两个集合，返回是否进行了合并操作
	bool unionSet(int p, int q)
	{
		int i = quickFind(p), j = quickFind(q);
		if (i == j)
			return false;

		count--;
		if (weight[i] < weight[j]) {
			set[i] = j;
			weight[j] += weight[i];
		}
		else {
			set[j] = i;
			weight[i] += weight[j];
		}

		return true;
	}

	//返回集合数
	int setCount() const { return count; }
private:
	//禁止复制(重点在算法，减少其它方面的代码)
	UnionFindSet(const UnionFindSet& set);
	UnionFindSet& operator=(const UnionFindSet& set);
};

//查找路径，返回是否查找到至终点的路径
bool findPath(int x, int y)
{
	if (maze.grid[y][x] == BLOCK_BLANK) {
		maze.grid[y][x] = BLOCK_PATH;

		if ((x == maze.gridNum - 2) && (y == maze.gridNum - 2))
			return true;

		//搜索四个方向
		for (int i = 0; i < DIRECTION_NUM; i++) {
			if (findPath(x + dx[i], y + dy[i]))
				return true;
		}

		maze.grid[y][x] = BLOCK_BLANK;
	}
	return false;
}

//迷宫初始化
void initMaze()
{
	//初始化
	for (int i = 0; i < maze.gridNum; i++) {
		for (int j = 0; j < maze.gridNum; j++) {
			maze.grid[i][j] = BLOCK_WALL;
		}
	}

	for (int i = 1; i < maze.gridNum; i += 2) {
		for (int j = 1; j < maze.gridNum; j += 2) {
			maze.grid[i][j] = BLOCK_BLANK;
		}
	}

	//随机开始地点(空格)
	xCur = rand() % maze.size;
	yCur = rand() % maze.size;

	//不出现在右下角，避免出现过于简单的情况
	if ((xCur >= maze.size / 2) && (yCur >= maze.size / 2)) {
		xCur -= maze.size / 2;
		yCur -= maze.size / 2;
	}

	//对应到实际的数组坐标
	xCur = xCur * 2 + 1;
	yCur = yCur * 2 + 1;


	//随机拆墙，创建迷宫

	//创建一个随机的拆墙顺序
	//空格左右的可拆墙编号为0 ~ maze.size * (msze.size-1) - 1
	//空格上下的可拆墙编号为maze.size * (msze.size-1) ~ 2 * maze.size * (msze.size-1) - 1
	//这两种墙有点不同，所以分开来

	const int WALL_SIZE = 2 * maze.size * (maze.size - 1);	//所有可拆墙数目
	int* randWall = new int[WALL_SIZE];

	for (int i = 0; i < WALL_SIZE; i++) {
		randWall[i] = i;
	}

	//随机打乱
	shuffle(randWall, WALL_SIZE);

	//并查集
	UnionFindSet ufSet(maze.size * maze.size);
	
	//被简化过
	//根据randWall中的顺序连通所有空格，连通时拆除两个空格之间的墙
	for (int i = 0; i < WALL_SIZE; i++) {

		//如果已全部连通，退出
		if (ufSet.setCount() <= 1)
			break;

		//下面代码压缩过，通过编号计算出墙的索引，两边空格的索引。

		int xWall, yWall, width, tx = 0, ty = 0;

		//空格左右的可拆墙
		if (randWall[i] < WALL_SIZE / 2) {
			width = maze.size - 1;
			tx = 1;
		}
		//空格上下的可拆墙
		else {
			randWall[i] -= WALL_SIZE / 2;
			width = maze.size;
			ty = 1;
		}

		//通过编号计算墙在grid数组中的实际索引
		xWall = randWall[i] % width;
		yWall = randWall[i] / width;

		//墙两边的空格在grid数组中的实际索引
		int x1 = xWall, y1 = yWall, x2 = xWall + tx, y2 = yWall + ty;

		//如果进行了连通操作，那么拆墙
		if (ufSet.unionSet(y1 * maze.size + x1, y2 * maze.size + x2)) {
			maze.grid[yWall + y2 + 1][xWall + x2 + 1] = BLOCK_BLANK;
		}
	}

	delete[] randWall;
}


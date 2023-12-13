#include <bits/stdc++.h>
#include <graphics.h>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
//�����ĸ�������н�����
#define DIRECTION_NUM 4
int dx[DIRECTION_NUM] = { -1, 0, 1, 0 };
int dy[DIRECTION_NUM] = { 0, -1, 0, 1 };

//�Զ�����ɫ
const int COLOR_BLUE  = EGERGB(5, 224, 218);

//�Թ���С����
const int MAZE_INC_SIZE = 8;						//�Թ���С�仯����
const int MAZE_MAX_SIZE = 5 * MAZE_INC_SIZE;		//�Թ���С���ֵ
const int MAZE_MIN_SIZE = MAZE_INC_SIZE;			//�Թ���С��Сֵ
const int GRID_MAX_NUM = 2 * MAZE_MAX_SIZE + 1;		//�Թ����������ֵ(ÿ��)

//�Թ�
typedef struct Maze
{
	int size;			//�Թ���С
	int gridNum;		//������(ÿ��)
	int gridWidth;		//���ӿ��
	int grid[GRID_MAX_NUM][GRID_MAX_NUM];	//��������
	bool visited[GRID_MAX_NUM][GRID_MAX_NUM];		//�ж���������Ƿ񵽴�� 
}Maze;

//�Թ�����
Maze maze;

int xCur, yCur;
int scrWidth = 600, scrHeight = 600;
int cnt=0; //bfs ����
string xx;
char c[10];
int ok=0,op=1;

//������
enum Direction {
	LEFT  = 0,
	UP    = 1,
	RIGHT = 2,
	DOWN  = 3
};

//������
enum BlockType {
	BLOCK_BLANK = 0,	//�ո�
	BLOCK_WALL,			//ǽ
	BLOCK_PATH,			//·��
};

void createMaze(int size);
void initMaze();
void drawMaze(bool enablePath);
bool findPath(int x, int y);

void drawHelpTip();

void shuffle(int a[], int length);

class fireball //�̻�������
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
        //ģ����������˶�
        setx(getx() + vx);
        sety(gety() + vy);
        vy += 0.3f;
        fillellipse(x, y, r, r);
    }
};
class firework //�̻���
{
    private: fireball f[80]; //��80����������Ϊ�̻�����Ӷ���
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
void fireworkscene(int num) //�����ɸ��̻����һ���̻�����
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
            fillellipse(500, 50, 20, 20); //���ɫ������
            for (int i = 0; i < 30; i++) {
                fillellipse((i * i * 34 + i * 8 * 8 * i * i - 3) % 640, (i * i * i * 28 + i * 8 + i * i - 232) % 240, 1, 1); //����������
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
	setfillcolor(BLACK); // ���������ɫΪ��ɫ
	ege_fillrect(100, 825, 300, 50); // ���ƾ���
	outtextxy(120, 845, c);
	ok=0;
    while (!q.empty()) {
        int si=q.size();
        cnt++;
        xx=get(cnt); 	
		strcpy(c,xx.c_str());
		setfillcolor(BLACK); // ���������ɫΪ��ɫ
		ege_fillrect(100, 825, 300, 50); // ���ƾ���
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
	setcaption("�Թ�");
	setbkmode(TRANSPARENT);

	bool flag_showPath = false;			//·����ʾ��־λ
	bool redraw = false;					//�ػ��־λ

	srand((unsigned)time(0));

	drawMaze(false);				//�����Թ�
	op=0;
	while (is_run()) {
		key_msg msg = getkey();

		int d = -1;
		if (msg.msg == key_msg_down) {
			//�����ƶ�
			switch (msg.key) {
			case key_left:	d = LEFT;	break;
			case key_up:	d = UP;		break;
			case key_right:	d = RIGHT;	break;
			case key_down:	d = DOWN;	break;

			//���ܼ�

			case key_enter:	//�س���������·��
				findPath(xCur, yCur);
				flag_showPath = true;	//ͬʱ������ʾ·��
				redraw = true;
				break;

			case key_esc:	//ESC�������¿�ʼ
				initMaze();
				redraw = true;
				break;
				
			case key_space: //�ո��������bfs����·��
				op=1;
				setfillcolor(BLACK); 
				ege_fillrect(0, 825, 300, 50); 
				setfont(20, 0, "����");
				outtextxy(10, 845, "bfs����:");
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
			    setfont(20, 0, "����");
				outtextxy(10, 845, "��С����:");
				xx=get(cnt); 	
				strcpy(c,xx.c_str());
				outtextxy(120, 845, c);
		}
		//�������ƶ�(�����ƶ�����) 
		if (d != -1) {
			//�ֱ���㰴ָ�������н�һ����н������λ��
			int xNext1 = xCur + dx[d],     yNext1 = yCur + dy[d];
			int xNext2 = xCur + 2 * dx[d], yNext2 = yCur + 2 * dy[d];

			//�ж��Ƿ���԰�ָ�������ƶ�(Ŀ�귽������ǽ�񵲼����ƶ�)
			if (0 <= xNext1 && xNext1 < maze.gridNum && 0 <= yNext1 && yNext1 < maze.gridNum
				&& (maze.grid[yNext1][xNext1] != BLOCK_WALL)) {

				//����·���ϵĸ������ͣ��޸�·����ʽ
				switch (maze.grid[yNext1][xNext1]) {
				case BLOCK_PATH: //Ŀ��ص�Ϊ·����������·���ϵ�·����ǣ��߹��ط�����Ϊ�ո�
					maze.grid[yCur][xCur] = BLOCK_BLANK;
					maze.grid[yNext1][xNext1] = BLOCK_BLANK;
					break;

				case BLOCK_BLANK: //Ŀ��ص�Ϊ�ո���·���ϵĸ�������Ϊ��ǰ��ֵ
					maze.grid[yNext1][xNext1] = maze.grid[yCur][xCur];
					maze.grid[yNext2][xNext2] = maze.grid[yCur][xCur];
					break;
				}

				//�ƶ���Ŀ��λ��
				xCur = xNext2;
				yCur = yNext2;

				//�ж��Ƿ��յ�(���½�)
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

		//�ػ�
		if (redraw) {
			redraw = false;
			drawMaze(flag_showPath);
		}
	}
	closegraph();
	return 0;
}

//�����Թ�
void createMaze(int size)
{
	if ((size > MAZE_MAX_SIZE) || (maze.size == size))
		return;

	maze.size = size;
	maze.gridNum = 2 * size + 1;

	//Ԥ�贰�ڿ��Ϊ800����
	maze.gridWidth = (int)ceil(800.0f / maze.gridNum);	

	initMaze();

	//�������ڴ�С
	scrWidth = maze.gridNum * maze.gridWidth;
	scrHeight = maze.gridNum * maze.gridWidth;
	initgraph(scrWidth, scrHeight+50);
}


//�������
void shuffle(int a[], int length)
{
	for (int i = length - 1; i > 0; i--) {
		int r = rand() % i + 1;
		int temp = a[i];
		a[i] = a[r];
		a[r] = temp;
	}
}

//���ƴ�·�����Թ�
void drawMaze(bool enablePath)
{
	setbkcolor_f(BLACK);
	cleardevice();

	//�����ڲ���Ե��϶��ȣ�ȡ���ӿ��1/8
	int padding = maze.gridWidth / 8;

	setcolor(WHITE);
	setlinewidth(2);
	//��Χǽ
	for (int i = 0; i < maze.gridNum; i += 2) {
		for (int j = 1; j < maze.gridNum; j += 2) {
			if (maze.grid[i][j] == BLOCK_WALL)
				line((j - 1) * maze.gridWidth + maze.gridWidth / 2, i * maze.gridWidth + maze.gridWidth / 2,
					(j + 1) * maze.gridWidth + maze.gridWidth / 2, i * maze.gridWidth + maze.gridWidth / 2);
		}
	}
	//��Χǽ
	for (int i = 1; i < maze.gridNum; i += 2) {
		for (int j = 0; j < maze.gridNum; j += 2) {
			if (maze.grid[i][j] == BLOCK_WALL)
				line(j * maze.gridWidth + maze.gridWidth / 2, (i - 1) * maze.gridWidth + maze.gridWidth / 2,
					j * maze.gridWidth + maze.gridWidth / 2, (i + 1) * maze.gridWidth + maze.gridWidth / 2);
		}
	}

	//���Ƶ��յ��·��
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

	//���Ƶ�ǰλ��
	setfillcolor(RED);

	bar(xCur * maze.gridWidth + padding, yCur * maze.gridWidth + padding,
		(xCur + 1) * maze.gridWidth - padding, (yCur + 1) * maze.gridWidth - padding);

}

//��Ȩ��·��ѹ�����鼯
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

		//·��ѹ��������·�Ľ��ֱ���������ڵ���
		while (set[id] != root) {
			int t = id;
			id = set[id];
			set[t] = root;
		}

		return root;
	}

	//�ϲ��������ϣ������Ƿ�����˺ϲ�����
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

	//���ؼ�����
	int setCount() const { return count; }
private:
	//��ֹ����(�ص����㷨��������������Ĵ���)
	UnionFindSet(const UnionFindSet& set);
	UnionFindSet& operator=(const UnionFindSet& set);
};

//����·���������Ƿ���ҵ����յ��·��
bool findPath(int x, int y)
{
	if (maze.grid[y][x] == BLOCK_BLANK) {
		maze.grid[y][x] = BLOCK_PATH;

		if ((x == maze.gridNum - 2) && (y == maze.gridNum - 2))
			return true;

		//�����ĸ�����
		for (int i = 0; i < DIRECTION_NUM; i++) {
			if (findPath(x + dx[i], y + dy[i]))
				return true;
		}

		maze.grid[y][x] = BLOCK_BLANK;
	}
	return false;
}

//�Թ���ʼ��
void initMaze()
{
	//��ʼ��
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

	//�����ʼ�ص�(�ո�)
	xCur = rand() % maze.size;
	yCur = rand() % maze.size;

	//�����������½ǣ�������ֹ��ڼ򵥵����
	if ((xCur >= maze.size / 2) && (yCur >= maze.size / 2)) {
		xCur -= maze.size / 2;
		yCur -= maze.size / 2;
	}

	//��Ӧ��ʵ�ʵ���������
	xCur = xCur * 2 + 1;
	yCur = yCur * 2 + 1;


	//�����ǽ�������Թ�

	//����һ������Ĳ�ǽ˳��
	//�ո����ҵĿɲ�ǽ���Ϊ0 ~ maze.size * (msze.size-1) - 1
	//�ո����µĿɲ�ǽ���Ϊmaze.size * (msze.size-1) ~ 2 * maze.size * (msze.size-1) - 1
	//������ǽ�е㲻ͬ�����Էֿ���

	const int WALL_SIZE = 2 * maze.size * (maze.size - 1);	//���пɲ�ǽ��Ŀ
	int* randWall = new int[WALL_SIZE];

	for (int i = 0; i < WALL_SIZE; i++) {
		randWall[i] = i;
	}

	//�������
	shuffle(randWall, WALL_SIZE);

	//���鼯
	UnionFindSet ufSet(maze.size * maze.size);
	
	//���򻯹�
	//����randWall�е�˳����ͨ���пո���ͨʱ��������ո�֮���ǽ
	for (int i = 0; i < WALL_SIZE; i++) {

		//�����ȫ����ͨ���˳�
		if (ufSet.setCount() <= 1)
			break;

		//�������ѹ������ͨ����ż����ǽ�����������߿ո��������

		int xWall, yWall, width, tx = 0, ty = 0;

		//�ո����ҵĿɲ�ǽ
		if (randWall[i] < WALL_SIZE / 2) {
			width = maze.size - 1;
			tx = 1;
		}
		//�ո����µĿɲ�ǽ
		else {
			randWall[i] -= WALL_SIZE / 2;
			width = maze.size;
			ty = 1;
		}

		//ͨ����ż���ǽ��grid�����е�ʵ������
		xWall = randWall[i] % width;
		yWall = randWall[i] / width;

		//ǽ���ߵĿո���grid�����е�ʵ������
		int x1 = xWall, y1 = yWall, x2 = xWall + tx, y2 = yWall + ty;

		//�����������ͨ��������ô��ǽ
		if (ufSet.unionSet(y1 * maze.size + x1, y2 * maze.size + x2)) {
			maze.grid[yWall + y2 + 1][xWall + x2 + 1] = BLOCK_BLANK;
		}
	}

	delete[] randWall;
}


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <graphics.h> // EGE图形库
#include <cmath>

using namespace std;
MUSIC music;
const int MAX_CHILD = 26; // 假设只包含小写字母

struct TrieNode {
    TrieNode* children[MAX_CHILD];
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < MAX_CHILD; ++i) {
            children[i] = nullptr;
        }
    }
};

void DrawVertex(int x, int y, char* label) {
    setcolor(0x66CCFF);
    setfillcolor(0x66CCFF);
    circle(x, y, 15);
    floodfill(x, y, 0x66CCFF);
    setbkmode(TRANSPARENT);
    setcolor(0xEE0000);
    setfont(18, 0, "宋体"); // 设置字体为宋体，字号为18
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    outtextxy(x , y , label); // 在节点上显示字母，根据具体显示效果微调偏移量
}

//画出每条带权值的边
void DrawArrowLine(int x1, int y1, int x2, int y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    double ds = sqrt(dx * dx + dy * dy);
    double a = dy / ds * 5;
    double b = dx / ds * 5;
    double c = dx / ds * 5;
    double d = dy / ds * 5;
    double x_begin = x1 - a - c;
    double y_begin = y1 + b - d;
    double x_end = x2 - a + c;
    double y_end = y2 + b + d;
    double arrow_base_x = x_end + c;
    double arrow_base_y = y_end + d;
    double arrow_out_x = x_end - a + c;
    double arrow_out_y = y_end + b + d;
    setcolor(0xEE0000);
    line(x_begin, y_begin, x_end, y_end);
    line(x_end, y_end, arrow_base_x, arrow_base_y);
    line(x_end, y_end, arrow_out_x, arrow_out_y);
    line(arrow_base_x, arrow_base_y, arrow_out_x, arrow_out_y);
    double arrow_center_x = (arrow_base_x + arrow_out_x + x_end) / 3;
    double arrow_center_y = (arrow_base_y + arrow_out_y + y_end) / 3;
    setfillcolor(0xEE0000);
    floodfill(arrow_center_x, arrow_center_y, 0xEE0000);
    double x_center = (x_begin + x_end) / 2 - a * 2;
    double y_center = (y_begin + y_end) / 2 + b * 2;
    setfont(18, 0, "黑体");
}

class Trie {
private:
    TrieNode* root;
    map<string, int> wordIndex; // 用于记录单词在输入列表中的索引顺序

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;

        // 记录单词在输入列表中的索引顺序
        if (wordIndex.find(word) == wordIndex.end()) {
            wordIndex[word] = wordIndex.size();
        }
    }

    TrieNode* getRoot() {
        return root;
    }

    // 用于绘制Trie树
    void drawTrie(TrieNode* node, int x, int y, char label, bool isEndOfWord, int dx, int dy) {
        if (node == nullptr) return;

        // 绘制当前节点并显示字母
        char label_str[2] = {label, '\0'}; // 将当前节点的字母转换为字符串
        DrawVertex(x, y, label_str);
		Sleep(500);
        int newY = y + dy; // 调整节点之间的垂直间距
        for (int i = 0; i < MAX_CHILD; ++i) {
            if (node->children[i] != nullptr) {
                string currentWord = string(1, char('a' + i));
                int newX = x + (wordIndex.size() - 1) * dx / 2 - wordIndex.size() / 2 * dx + wordIndex[currentWord] * dx;
                // 绘制边
                DrawArrowLine(x, y + 10, newX, newY);
				Sleep(500);
                drawTrie(node->children[i], newX, newY, char('a' + i), node->children[i]->isEndOfWord, dx, dy);
				Sleep(500);
                // 在单词结束节点处绘制特殊标记
                if (node->children[i]->isEndOfWord) {
                	// 调整特殊标记（红色小圆圈）的位置
                	int specialMarkX = newX + 20; // 右移20个单位
                	int specialMarkY = newY;

                	// 在此处添加你的特殊标记绘制代码，比如绘制一个小圆圈或其他标志
                	setcolor(RED);
                	circle(specialMarkX, specialMarkY, 5); // 示例：绘制一个红色的小圆圈作为标记
                	floodfill(specialMarkX, specialMarkY, RED);
            	}
            }
        }
    }
};

int main() {
	music.OpenFile("C:\\Users\\lenovo\\Desktop\\bgm.mp3");
	music.Play();
    Trie trie;
    vector<string> words;
    string str;
    int n;
    cin >> n;
    while (n--) {
        cin >> str;
        words.push_back(str);
    }
    // 插入单词到Trie树
    for (const string& word : words) {
        trie.insert(word);
    }
    initgraph(1920, 1080); // 初始化绘图窗口
    int startX = 960; // 设置图形的起始 X 坐标
    int startY = 50; // 设置图形的起始 Y 坐标
    int nodeSpacingX = 200; // 节点之间的水平间距
    int nodeSpacingY = 100; // 节点之间的垂直间距

    TrieNode* root = trie.getRoot();
    trie.drawTrie(root, startX, startY, '\0', false, nodeSpacingX, nodeSpacingY); // '\0' 表示根节点为空字母，结束标志设为 false

    getch(); // 等待用户按下任意键
    closegraph(); // 关闭绘图窗口

    return 0;
}

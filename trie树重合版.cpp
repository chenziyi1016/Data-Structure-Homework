#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <graphics.h> // EGEͼ�ο�
#include <cmath>

using namespace std;
MUSIC music;
const int MAX_CHILD = 26; // ����ֻ����Сд��ĸ

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
    setfont(18, 0, "����"); // ��������Ϊ���壬�ֺ�Ϊ18
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    outtextxy(x , y , label); // �ڽڵ�����ʾ��ĸ�����ݾ�����ʾЧ��΢��ƫ����
}

//����ÿ����Ȩֵ�ı�
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
    setfont(18, 0, "����");
}

class Trie {
private:
    TrieNode* root;
    map<string, int> wordIndex; // ���ڼ�¼�����������б��е�����˳��

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

        // ��¼�����������б��е�����˳��
        if (wordIndex.find(word) == wordIndex.end()) {
            wordIndex[word] = wordIndex.size();
        }
    }

    TrieNode* getRoot() {
        return root;
    }

    // ���ڻ���Trie��
    void drawTrie(TrieNode* node, int x, int y, char label, bool isEndOfWord, int dx, int dy) {
        if (node == nullptr) return;

        // ���Ƶ�ǰ�ڵ㲢��ʾ��ĸ
        char label_str[2] = {label, '\0'}; // ����ǰ�ڵ����ĸת��Ϊ�ַ���
        DrawVertex(x, y, label_str);
		Sleep(500);
        int newY = y + dy; // �����ڵ�֮��Ĵ�ֱ���
        for (int i = 0; i < MAX_CHILD; ++i) {
            if (node->children[i] != nullptr) {
                string currentWord = string(1, char('a' + i));
                int newX = x + (wordIndex.size() - 1) * dx / 2 - wordIndex.size() / 2 * dx + wordIndex[currentWord] * dx;
                // ���Ʊ�
                DrawArrowLine(x, y + 10, newX, newY);
				Sleep(500);
                drawTrie(node->children[i], newX, newY, char('a' + i), node->children[i]->isEndOfWord, dx, dy);
				Sleep(500);
                // �ڵ��ʽ����ڵ㴦����������
                if (node->children[i]->isEndOfWord) {
                	// ���������ǣ���ɫСԲȦ����λ��
                	int specialMarkX = newX + 20; // ����20����λ
                	int specialMarkY = newY;

                	// �ڴ˴������������ǻ��ƴ��룬�������һ��СԲȦ��������־
                	setcolor(RED);
                	circle(specialMarkX, specialMarkY, 5); // ʾ��������һ����ɫ��СԲȦ��Ϊ���
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
    // ���뵥�ʵ�Trie��
    for (const string& word : words) {
        trie.insert(word);
    }
    initgraph(1920, 1080); // ��ʼ����ͼ����
    int startX = 960; // ����ͼ�ε���ʼ X ����
    int startY = 50; // ����ͼ�ε���ʼ Y ����
    int nodeSpacingX = 200; // �ڵ�֮���ˮƽ���
    int nodeSpacingY = 100; // �ڵ�֮��Ĵ�ֱ���

    TrieNode* root = trie.getRoot();
    trie.drawTrie(root, startX, startY, '\0', false, nodeSpacingX, nodeSpacingY); // '\0' ��ʾ���ڵ�Ϊ����ĸ��������־��Ϊ false

    getch(); // �ȴ��û����������
    closegraph(); // �رջ�ͼ����

    return 0;
}

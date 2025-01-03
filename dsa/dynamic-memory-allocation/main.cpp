#include <iostream>
#include <stack>

using namespace std;

// Họ Tên: Tô Xuân Tùng
// MSSV: 23210312
// Đề 1: 12 % 3 + 1 = 1;

struct Node
{
    float data;
    Node *pLeft;
    Node *pRight;
};

Node *initNode(float value)
{
    Node *p = new Node;
    p->data = value;
    p->pLeft = nullptr;
    p->pRight = nullptr;
    return p;
}

struct Tree
{
    Node *pRoot;
};

void initTree(Tree &t)
{
    t.pRoot = nullptr;
}

void printTreeLNR(Tree t)
{
    Node *p = t.pRoot;
    stack<Node *> s;
    while (p != nullptr || s.empty() == false)
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        cout << p->data << " ";
        p = p->pRight;
    }
    cout << endl;
}

/* Câu 1: Chèn Node chứa giá trị vào cây, trùng giá trị thì BỎ QUA, Chèn thành công thì trả về 1, thất bại thì -1
Input:
    + &t: Tree
    + p: Node*
Output:
    + int : 1 hoặc -1
*/

int addNode(Tree &t, Node *p)
{
    if (t.pRoot == NULL)
    {
        t.pRoot = p;
        return 1;
    }

    Node *pGoTo = t.pRoot;
    Node *pLoca = nullptr;

    while (pGoTo != nullptr)
    {
        pLoca = pGoTo;

        if (p->data < pGoTo->data)
            pGoTo = pGoTo->pLeft;

        else if (p->data > pGoTo->data)
            pGoTo = pGoTo->pRight;
        else // Duplicate value
            return -1;
    }

    // Insert as left or right child based on value
    if (p->data > pLoca->data)
        pLoca->pRight = p;
    else if (p->data < pLoca->data)
        pLoca->pLeft = p;
    return 1;
}
/**
 *
 * Câu 2: Viết hàm khỏi tạo cây nhị phân tìm kiếm từ mảng 1 chiều
 * Input:
 * + &t: Tree
 * + a[] : float
 * + n : int
 * Output:
 * + Tree t mới
 */
void initTreeArrray(Tree &t, float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        addNode(t, initNode(a[i]));
    }
}

/**
 * Câu 3: Viết hàm duyệt cây (tự chọn cách duyệt)
 * Input:
 * + t: Tree
 * Output:
 * + count: int // đếm các phần tử trong cây
 */
int TongNode(Tree t)
{
    int count = 0;
    stack<Node *> s;
    Node *p = t.pRoot;
    while (p != nullptr || s.empty() == false)
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        count = count + 1;
        p = p->pRight;
    }
    return count;
}
/**
 * Câu 4: Viết hàm tìm kiếm Node có giá trị X trong cây, tìm thấy trả về -1 , không thấy trả về 1
 * Input:
 * + t: Tree
 * + X : float
 * Output:
 * + -1 / 1 : int
 */

int FindValue(Tree t, float X)
{
    Node *p = t.pRoot;

    while (p != nullptr)
    {
        if (p->data == X)
            return -1;
        if (X < p->data)
            p = p->pLeft;
        else if (X > p->data)
            p = p->pRight;
    }
    return 1;
}

/**
 * Câu 5: Viết hàm đếm Node không phải là node lá của cây
 * Input:
 * + t: Tree
 * Output:
 * + count : int
 */

int CountNodeNoLeaf(Tree t)
{
    int count = 0;
    stack<Node *> s;
    Node *p = t.pRoot;
    while (p != nullptr || s.empty() == false)
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        if (p->pLeft != nullptr || p->pRight != nullptr)
        {
            count = count + 1;
        }
        p = p->pRight;
    }
    return count;
}

/**
 * Câu 6: Viết hàm đếm các Node chỉ có 2 nhánh con
 * Input:
 * + t: Tree
 * Output:
 * + count: int
 */

int CountNodeHaveTwoNodes(Tree t)
{
    int count = 0;
    stack<Node *> s;
    Node *p = t.pRoot;
    while (p != nullptr || s.empty() == false)
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        if (p->pLeft != nullptr && p->pRight != nullptr)
        {
            count = count + 1;
        }
        p = p->pRight;
    }
    return count;
}

/**
 * Câu 7: Viết hàm tìm giá trị max, min (viết trên 1 hàm, không dùng đệ quy)
 * Input:
 * + t: Tree
 * + &maxx: float
 * + &min: float
 * Output:
 * + maxx: float
 * + min: float
 */
void FindMaxMin(Tree t, float &maxx, float &minn)
{

    stack<Node *> s;
    Node *p = t.pRoot;
    maxx = p->data;
    minn = p->data;
    while (p != nullptr || s.empty() == false)
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        if (p->data < minn)
        {
            minn = p->data;
        }
        else if (p->data > maxx)
        {
            maxx = p->data;
        }
        p = p->pRight;
    }
}

/**
 * Câu 8: Viết hàm tính giá trị trung bình các Node trong cây.
 * Input:
 * + t: Tree
 * Output:
 * + giatritrungbinh: float
 */

float MeanNode(Tree t)
{
    float tong = 0;
    int tongnode = TongNode(t);
    stack<Node *> s;
    Node *p = t.pRoot;
    while (p != nullptr || !s.empty())
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->pLeft;
        }
        p = s.top();
        s.pop();
        tong += p->data;
        p = p->pRight;
    }
    return tong / tongnode;
}

/**
 * Câu 9: Viết hàm khởi tạo 2 cây nhị phân tìm kiếm mới theo yêu cầu.
 * Input:
 * + t: Tree
 * + &t1: Tree / cây bên trái
 * + &t2: Tree / cây bên phải
 * Output:
 * + t1': Tree / cây bên trái mới
 * + t2': Tree / cây bên phải mới
 */

void initnewtree(Tree t, Tree &t1, Tree &t2)
{
    t1.pRoot = t.pRoot->pLeft;
    t2.pRoot = t.pRoot->pRight;
}

int main()
{
    // Cài đặt cây nhị phân tìm kiếm
    Tree t;
    initTree(t);

    // Câu 1: Chèn Node vào cây, trùng giá trị thì BỎ QUA, Chèn thành công thì trả về 1, thất bại thì -1
    cout << "Ket qua chen node 9.1: " << addNode(t, initNode(9.1)) << endl;
    cout << "Ket qua chen node 9.2: " << addNode(t, initNode(9.2)) << endl;
    cout << "Ket qua chen node 9.3: " << addNode(t, initNode(9.3)) << endl;
    cout << "Ket qua chen node 8.6: " << addNode(t, initNode(8.6)) << endl;
    cout << "Ket qua chen node 9.2 (trung): " << addNode(t, initNode(9.2)) << endl;
    cout << "Ket qua chen node 9.2 (trung): " << addNode(t, initNode(9.2)) << endl;

    cout << "Cay sau khi chen:" << endl;
    printTreeLNR(t);

    // Câu 2: Khởi tạo cây nhị phân tìm kiếm từ mảng 1 chiều
    cout << "\nTest cau 2: Ham khoi tao cay tu mang 1 chieu:" << endl;
    Tree t1;
    initTree(t1);

    float a[] = {50.1, 70.1, 60.2, 30.4, 70.7, 90.5, 75.2, 25.3, 30.4, 10.5, 90.5};
    int n = 11;
    initTreeArrray(t1, a, n);
    cout << "Cay sau khi khoi tao tu mang:" << endl;
    printTreeLNR(t1);

    // Câu 3: Viết hàm duyệt cây (tự chọn các duyệt)
    cout << "\nTest cau 3: Tong so Node trong cay t1:" << endl;
    cout << TongNode(t1) << " Node." << endl;

    // Câu 4: Tìm kiếm Node có giá trị X
    cout << "\nTest cau 4: Tim gia tri X trong cay t1:" << endl;
    float X = 90.5;
    int kq = FindValue(t1, X);

    if (kq == -1)
        cout << "Tim thay gia tri " << X << " trong cay!" << endl;
    else
        cout << "Khong tim thay gia tri " << X << " trong cay!" << endl;

    // Câu 5: Đếm Node không phải node lá
    cout << "\nTest cau 5: So Node khong phai Node la trong cay t1:" << endl;
    cout << CountNodeNoLeaf(t1) << " Node." << endl;

    // Câu 6: Đếm Node có 2 nhánh con
    cout << "\nTest cau 6: So Node chi co 2 nhanh con trong cay t1:" << endl;
    cout << CountNodeHaveTwoNodes(t1) << " Node." << endl;

    // Câu 7: Tìm giá trị max, min
    cout << "\nTest cau 7: Gia tri lon nhat va nho nhat trong cay t1:" << endl;
    float maxx = 0, minn = 0;
    FindMaxMin(t1, maxx, minn);

    cout << "Gia tri lon nhat la: " << maxx << endl;
    cout << "Gia tri be nhat la: " << minn << endl;

    // Câu 8: Tính giá trị trung bình các Node
    cout << "\nTest cau 8: Gia tri trung binh cac Node trong cay t1:" << endl;
    cout << "Gia tri trung binh: " << MeanNode(t1) << endl;

    // Câu 9: Khởi tạo 2 cây nhị phân tìm kiếm mới
    cout << "\nTest cau 9: Tao hai cay tu cay t1:" << endl;
    Tree t2, t3;
    initTree(t2);
    initTree(t3);

    initnewtree(t1, t2, t3);

    cout << "Cay thu nhat (cay con ben trai): ";
    printTreeLNR(t2);

    cout << "Cay thu hai (cay con ben phai): ";
    printTreeLNR(t3);

    return 0;
}

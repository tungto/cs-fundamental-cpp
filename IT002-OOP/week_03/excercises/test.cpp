#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CDonThuc
{
private:
    int heso;
    vector<pair<char, int>> bienMu; // Vector lưu cặp biến và số mũ

public:
    friend istream &operator>>(istream &is, CDonThuc &a);
    friend ostream &operator<<(ostream &os, const CDonThuc &a);
    CDonThuc();
    CDonThuc(int, vector<pair<char, int>>);
    CDonThuc(const CDonThuc &);
    ~CDonThuc();
    CDonThuc &operator=(const CDonThuc &);
    CDonThuc operator*(const CDonThuc &x) const;
    CDonThuc operator/(const CDonThuc &x) const;
    CDonThuc &operator*=(const CDonThuc &x);
    CDonThuc &operator/=(const CDonThuc &x);
};

istream &operator>>(istream &is, CDonThuc &a)
{
    cout << "Nhap he so: ";
    is >> a.heso;
    int numBien;
    cout << "Nhap so luong bien: ";
    is >> numBien;
    a.bienMu.resize(numBien);
    for (int i = 0; i < numBien; ++i)
    {
        cout << "Nhap bien thu " << i + 1 << ": ";
        is >> a.bienMu[i].first;
        cout << "Nhap so mu cua bien " << a.bienMu[i].first << ": ";
        is >> a.bienMu[i].second;
    }
    return is;
}

ostream &operator<<(ostream &os, const CDonThuc &a)
{
    os << a.heso;
    for (const auto &bm : a.bienMu)
    {
        os << bm.first << "^" << bm.second << " ";
    }
    return os;
}

CDonThuc::CDonThuc() : heso(0) {}

CDonThuc::CDonThuc(int h, vector<pair<char, int>> bm) : heso(h), bienMu(bm) {}

CDonThuc::CDonThuc(const CDonThuc &a) : heso(a.heso), bienMu(a.bienMu) {}

CDonThuc::~CDonThuc() {}

CDonThuc &CDonThuc::operator=(const CDonThuc &a)
{
    if (this != &a)
    {
        heso = a.heso;
        bienMu = a.bienMu;
    }
    return *this;
}

CDonThuc CDonThuc::operator*(const CDonThuc &a) const
{
    CDonThuc temp;
    temp.heso = heso * a.heso;
    temp.bienMu = bienMu;

    for (const auto &bm : a.bienMu)
    {
        bool found = false;
        for (auto &tbm : temp.bienMu)
        {
            if (tbm.first == bm.first)
            {
                tbm.second += bm.second;
                found = true;
                break;
            }
        }
        if (!found)
        {
            temp.bienMu.push_back(make_pair(bm.first, bm.second));
        }
    }
    return temp;
}

CDonThuc CDonThuc::operator/(const CDonThuc &a) const
{
    CDonThuc temp;
    temp.heso = heso / a.heso;
    temp.bienMu = bienMu;

    for (const auto &bm : a.bienMu)
    {
        bool found = false;
        for (auto &tbm : temp.bienMu)
        {
            if (tbm.first == bm.first)
            {
                tbm.second -= bm.second;
                found = true;
                break;
            }
        }
        if (!found)
        {
            temp.bienMu.push_back(make_pair(bm.first, -bm.second));
        }
    }
    return temp;
}

CDonThuc &CDonThuc::operator*=(const CDonThuc &a)
{
    *this = *this * a;
    return *this;
}

CDonThuc &CDonThuc::operator/=(const CDonThuc &a)
{
    *this = *this / a;
    return *this;
}

int main()
{
    CDonThuc a, b;
    cout << "Nhap don thuc thu nhat:\n";
    cin >> a;
    cout << "Nhap don thuc thu hai:\n";
    cin >> b;
    cout << "In don thuc: " << endl;
    cout << a << endl;
    cout << b << endl;

    CDonThuc ketqua_toantunhan = a * b;
    CDonThuc ketqua_toantuchia = a / b;
    CDonThuc ketqua_toantunhanbang = a *= b;
    CDonThuc ketqua_toantuchiabang = a /= b;

    cout << "Ket qua nhan la: " << ketqua_toantunhan << endl;
    cout << "Ket qua chia la: " << ketqua_toantuchia << endl;
    cout << "Ket qua nhan bang la: " << ketqua_toantunhanbang << endl;
    cout << "Ket qua chia bang la: " << ketqua_toantuchiabang << endl;

    return 0;
}

// *, /, *=, /=
 
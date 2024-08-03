#include <string>
#include <iostream>
using namespace std;

#ifndef HOCSINH_H
#define HOCSINH_H

#pragma once

class HocSinh
{

private:
    string HoTen, DiaChi;
    float Toan, Van;

public:
    HocSinh();  // khoi tao
    ~HocSinh(); // pha huy
    void Nhap();
    void Xuat();
};

#endif
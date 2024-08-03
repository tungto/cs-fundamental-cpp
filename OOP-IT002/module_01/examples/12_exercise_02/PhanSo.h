#ifndef PHANSO_H
#define PHANSO_H

#pragma once

class PhanSo
{

private:
    int TuSo, MauSo;

public:
    PhanSo Cong(PhanSo);
    PhanSo Tru(PhanSo);
    PhanSo Nhan(PhanSo);
    PhanSo Chia(PhanSo);
    void Nhap();
    void Xuat();
    PhanSo();
    ~PhanSo();
};

#endif
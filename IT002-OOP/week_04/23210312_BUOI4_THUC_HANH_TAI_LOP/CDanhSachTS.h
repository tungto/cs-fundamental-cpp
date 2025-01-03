#ifndef CDANHSACHTS_H
#define CDANHSACHTS_H

#include "CThiSinh.h"

class CDanhSachTS
{
private:
	CThiSinh DanhSachTS[100];
	int n; // số lượng thí sinh

public:
	CDanhSachTS();
	void Nhap();
	void XuatDSTheoDK(); // Xuất DS thí sinh có tổng điểm > 15
	void SapXepTheoToan();
	void SapXepTheoVan();
	void SapXepTheoAnh();
	void SapXep(int &chon);
	~CDanhSachTS();
};

#endif

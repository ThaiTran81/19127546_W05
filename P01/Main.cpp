#include"Geometry.h"

int main()
{
	QuanLyHinhHoc p;
	p.AddHinh(new HinhVuong);
	p.AddHinh(new HinhChuNhat);
	p.AddHinh(new HinhTron);
	p.AddHinh(new TamGiacDeu);
	p.AddHinh(new HinhCau);
	p.AddHinh(new HinhLapPhuong);
	cout << endl;
	cout << endl;
	cout << "Thong tin cac hinh vua nhap" << endl;
	cout << endl;
	p.Print(cout);
	return 0;
}
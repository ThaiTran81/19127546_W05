#include"Geometry.h"
void HinhVuong::Nhap()
{
	cout << "nhap canh Hinh Vuong: ";
	cin >> this->edge;
}

void HinhVuong::ChuVi()
{
	m_chuvi = this->edge * 4;
}

void HinhVuong::DienTich()
{
	m_dientich = this->edge * this->edge;
}
void HinhVuong::Print(ostream& out) const
{
	out << "Hinh Vuong(a = " << this->edge << ") co S = " << m_dientich << " va P = " << m_chuvi;
}

void HinhChuNhat::Nhap()
{
	cout << "nhap lan luot chieu dai va rong cua Hinh Chu Nhat: ";
	cin >> this->dai;
	cin >> this->rong;
}

void HinhChuNhat::ChuVi()
{
	m_chuvi = (this->dai + this->rong) * 2;
}

void HinhChuNhat::DienTich()
{
	m_dientich = this->dai * this->rong;
}

void HinhChuNhat::Print(ostream& out) const
{
	out << "Hinh Chu Nhat(chieu dai = " << this->dai << ") va chieu rong = " << rong << ") co S = " << m_dientich << " va P = " << m_chuvi;
}

void TamGiacDeu::Nhap()
{
	cout << "nhap canh cua tam giac deu: ";
	cin >> this->edge;
}

void TamGiacDeu::ChuVi()
{
	m_chuvi = this->edge * 3;
}

void TamGiacDeu::DienTich()
{
	m_dientich = pow(edge, 2) * sqrt(3) / 4.0;
}

void TamGiacDeu::Print(ostream& out) const
{
	out << "Tam Giac Deu(a = " << this->edge << ") co S = " << m_dientich << " va P = " << m_chuvi;
}

void HinhTron::Nhap()
{
	cout << "nhap ban kinh cua hinh Tron: ";
	cin >> this->edge;
}

void HinhTron::ChuVi()
{
	m_chuvi = 2.0 * edge * pi;
}

void HinhTron::DienTich()
{
	m_dientich = pow(edge, 2) * pi;
}

void HinhTron::Print(ostream& out) const
{
	out << "Hinh Tron(r = " << this->edge << ") co S = " << m_dientich << " va P = " << m_chuvi;
}


void HinhCau::Nhap()
{
	cout << "nhap ban kinh Hinh Cau: ";
	cin >> this->radius;
}

void HinhCau::TheTich()
{
	m_thetich = (4.0 / 3.0) * pi * pow(radius, 3);
}

void HinhCau::DienTich()
{
	m_dientich = 4.0 * pi * pow(radius, 2);
}

void HinhCau::Print(ostream& out) const
{
	out << "Hinh Cau(r = " << this->radius << ") co S = " << m_dientich << " va V = " << m_thetich;
}

void HinhLapPhuong::Nhap()
{
	cout << "nhap canh Hinh Lap Phuong: ";
	cin >> this->edge;
}

void HinhLapPhuong::TheTich()
{
	m_thetich = pow(this->edge, 3);
}

void HinhLapPhuong::DienTich()
{
	m_dientich = 4.0 * pow(this->edge, 2);
}

void HinhLapPhuong::Print(ostream& out) const
{
	out << "Hinh Lap Phuong(a = " << this->edge << ") co S = " << m_dientich << " va V = " << m_thetich;
}
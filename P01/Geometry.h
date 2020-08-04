#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include<iostream>
#include<vector>
#include<math.h>
#define pi 3.14159265359
using namespace std;

class HinhHoc
{
protected:
	float m_dientich, m_chuvi, m_thetich;
public:
	HinhHoc() :m_dientich(0), m_chuvi(0), m_thetich(0) {};
	virtual void Print(ostream& out) const {};
	virtual void Nhap() {};
	virtual void DienTich() {};
	virtual void ChuVi() {};
	virtual  void TheTich() {};
	friend ostream& operator <<(ostream& out, const HinhHoc& obj)
	{
		obj.Print(out);
		return out;
	};
};


class HinhVuong :public HinhHoc
{
private:
	float edge;
public:
	HinhVuong() :edge(0) {};
	HinhVuong(const float& edge)
	{
		this->edge = edge;
	};
	void Print(ostream& out) const;
	void Nhap();
	void DienTich();
	void ChuVi();
};

class HinhChuNhat :public HinhHoc
{
private:
	float dai, rong;
public:
	HinhChuNhat() :dai(0), rong(0) {};
	HinhChuNhat(const float& dai, const float& rong)
	{
		this->dai = dai;
		this->rong = rong;
	}
	void Print(ostream& out) const;
	void Nhap();
	void ChuVi();
	void DienTich();
};

class TamGiacDeu :public HinhHoc
{
private:
	float edge;
public:
	TamGiacDeu() :edge(0) {};
	TamGiacDeu(const float& edge)
	{
		this->edge = edge;
	}
	void Print(ostream& out) const;
	void Nhap();
	void ChuVi();
	void DienTich();
};

class HinhTron :public HinhHoc
{
private:
	float edge;
public:
	HinhTron() :edge(0) {};
	HinhTron(const float& edge)
	{
		this->edge = edge;
	}
	void Print(ostream& out) const;
	void Nhap();
	void ChuVi();
	void DienTich();
};

class HinhCau :public HinhHoc
{
private:
	float radius;
public:
	HinhCau() :radius(0) {};
	HinhCau(const float& r)
	{
		this->radius = r;
	}
	void Print(ostream& out) const;
	void Nhap();
	void TheTich();
	void DienTich();
};

class HinhLapPhuong : public HinhHoc
{
private:
	float edge;
public:
	HinhLapPhuong() :edge(0) {};
	HinhLapPhuong(const float& edge)
	{
		this->edge = edge;
	}
	void Print(ostream& out) const;
	void Nhap();
	void DienTich();
	void TheTich();
};

class QuanLyHinhHoc
{
private:
	vector<HinhHoc*>vt_geo;
public:
	QuanLyHinhHoc()
	{
		vt_geo.resize(0);
	}

	void AddHinh(HinhHoc* obj)
	{
		obj->Nhap();
		obj->DienTich();
		obj->ChuVi();
		obj->TheTich();
		vt_geo.push_back(obj);
	}

	void Print(ostream& out)
	{
		for (vector<HinhHoc*>::iterator it = vt_geo.begin(); it != vt_geo.end(); it++)
		{
			out << (**it) << endl;
		}
	}
};
#endif // !_GEOMETRY_H_

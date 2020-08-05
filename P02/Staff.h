#ifndef _STAFF_H_
#define _STAFF_H_

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NV
{
protected:
	int m_id;
	string m_name;
	float m_salary;
	string m_typestaff;
	static int ID;
public:
	NV() :m_id(ID++), m_name(""), m_salary(0), m_typestaff("") {};
	virtual void CountSalary() = 0;
	virtual void SetName() = 0;
	string	GetTypeStaff()
	{
		return m_typestaff;
	}
	string GetName()
	{
		return m_name;
	}
};

class NVSanXuat:public NV
{
private:
	int m_numProduct;
public:
	NVSanXuat() :m_numProduct(0)
	{
		m_typestaff = "Nhan vien san xuat";
	};
	void SetName() override;
	void CountSalary() override;
};

class NVCongNhat:public NV
{
private:
	int m_workday;
public:
	NVCongNhat() :m_workday(0)
	{
		m_typestaff = "Nhan vien cong Nhat";
	};
	void CountSalary() override;
	void SetName() override;
};

class NVQuanLy:public NV
{
private:
	float m_basicSalary;
	float m_coeSalary;
public:
	NVQuanLy() :m_basicSalary(0), m_coeSalary(0)
	{
		m_typestaff = "Nhan vien quan ly";
	};
	void SetName() override;
	void CountSalary() override;
};

class CTy
{
private:
	vector<NV*>vt_nv;
public:
	CTy()
	{
		vt_nv.resize(0);
	}

	void ImportListStaff();
	void AddNewStaff();
	void PrintNumOfStaff()
	{
		cout << "Tong so nhan vien co trong cong ty la " << vt_nv.size() << " nhan vien" << endl;
	}
	int NumOfManagers();
	void PrintNumOfManager()
	{
		cout << "So nhan vien quan ly trong cong ty la " << this->NumOfManagers() << " nhan vien" << endl;
	}
	void PrintNVSanXuat();
	void PrintNVCongNhat();
	void PrintNVQuanLy();
	void PrintAllStaff();
	void NhapDanhSach();
};

void Menu();
#endif

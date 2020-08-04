#include "Staff.h"

int NV::ID = 0;

void NVSanXuat::SetName()
{
	cout << "Nhap ten nhan vien san xuat:";
	getline(cin, m_name);
}

void NVSanXuat::CountSalary()
{
	m_salary = m_numProduct * 20000.0;
}

void NVCongNhat::CountSalary()
{
	m_salary = m_workday * 50000.0;
}

void NVCongNhat::SetName()
{
	cout << "Nhap ten Nhan vien cong Nhat:";
	getline(cin, m_name);
}

void NVQuanLy::SetName()
{
	cout << "Nhap ten Nhan vien quan ly:";
	getline(cin, m_name);
}

void NVQuanLy::CountSalary()
{
	m_salary = m_basicSalary * m_coeSalary;
}

void CTy::AddNewStaff()
{
	cout << endl;
	cout << "What Type of staff?" << endl;
	cout << "		1.Nhan vien san xuat   2. Nhan vien cong Nhat   3. Nhan vien quan ly" << endl;
	int choice;
	do
	{
		cout << "your choice:";
		cin >> choice;
		if (choice < 1 || choice>3)
		{
			cout << "ERROR!!! PLS TRY AGAIN" << endl;
		}
	} while (choice < 1 || choice>3);

	cin.ignore();
	NV* temp;
	
	if (choice==1)
	{
		temp = new NVSanXuat;
		temp->SetName();
	}
	else if (choice==2)
	{
		temp = new NVCongNhat;
		temp->SetName();
	}
	else
	{
		temp = new NVQuanLy;
		temp->SetName();
	}
	vt_nv.push_back(temp);
}

int CTy::NumOfManagers()
{
	int count = 0;
	for (auto it=vt_nv.begin();it!=vt_nv.end();it++)
	{
		if ((*it)->GetTypeStaff()=="Nhan vien quan ly")
		{
			count++;
		}
	}
	return count;
}

void CTy::PrintNVSanXuat()
{
	int count = 0;
	cout << "Nhan vien san xuat:" << endl;
	for (auto it = vt_nv.begin(); it != vt_nv.end(); it++)
	{
		if ((*it)->GetTypeStaff() == "Nhan vien san xuat")
		{
			count++;
			cout << " " << (*it)->GetName() << endl;
		}
	}
	if (count == 0) cout << "(emtry)" << endl;
}

void CTy::PrintNVCongNhat()
{
	int count = 0;
	cout << "Nhan vien cong Nhat" << endl;
	for (auto it = vt_nv.begin(); it != vt_nv.end(); it++)
	{
		if ((*it)->GetTypeStaff() == "Nhan vien cong Nhat:")
		{
			count++;
			cout << " " << (*it)->GetName() << endl;
		}
	}
	if (count == 0) cout << "(emtry)" << endl;
}

void CTy::PrintNVQuanLy()
{
	int count = 0;
	cout << "Nhan vien quan ly:" << endl;
	for (auto it = vt_nv.begin(); it != vt_nv.end(); it++)
	{
		if ((*it)->GetTypeStaff() == "Nhan vien quan ly")
		{
			count++;
			cout << " " << (*it)->GetName() << endl;
		}
	}
	if (count == 0) cout << "(emtry)" << endl;
}

void CTy::PrintAllStaff()
{
	cout << ">>Nhan vien trong cong ty:" << endl << endl;
	this->PrintNVSanXuat();
	this->PrintNVCongNhat();
	this->PrintNVQuanLy();
}

void Menu()
{
	system("cls");
	cout << "    >>>>>>MENU<<<<<" << endl;
	cout << "1. Import List of staffs" << endl;
	cout << "2. Add a new staff" << endl;
	cout << "3. Print list of all staffs in company" << endl;
	cout << "4. Number of staff in company" << endl;
	cout << "5. Number of manager" << endl;
	cout << "press 0 to exit" << endl;
}

#include "Machine.h"

void ChiTiet::GetInfo()
{
	cout << "Chi tiet [" << _id << "]" << endl;
	cout << ">>Trong luong: " << _weight << "kg" << endl;
	cout << "Gia thanh: " << _price << "vnd" << endl;
}

void ChiTietDon::Set()
{
	cout << "Nhap ma cua chi tiet don:";
	getline(cin, _id);
	cout << "Nhap trong luong cua chi tiet don[" << _id << "]: ";
	cin >> _weight;
	cout << "Nhap gia thanh cua chi tiet don[" << _id << "]: ";
	cin >> _price;
}

void ChiTietPhuc::Set()
{
	int choice;
	float phukien, laprap;
	cout << "Nhap ma cua chi tiet phuc:";
	getline(cin, _id);
	cout << "Ban co muon them chi tiet nao vao chi tiet [" << _id << "] khong?(bam 0 de thoat)" << endl;
	do
	{
		cout << "1. Them chi tiet phuc" << endl;
		cout << "2. Them chi tiet don" << endl;
		cout << "Lua chon cua ban:";
		cin >> choice;
		if (choice != 0) cin.ignore();
		if (choice == 1)
		{
			this->AddPhuc();
		}
		else if (choice == 2)
		{
			this->AddDon();
		}
		cout << "Ban co muon them chi tiet nao vao chi tiet ["<<_id<<"] nua khong?(yes<1>/no<0>) :";
		cin >> choice;
	} while (choice != 0);
	cout << "Nhap trong luong cua phu kien ket noi cua chi tiet phuc [" << _id << "] :";
	cin >> phukien;
	_weight += 0.1 * phukien;
	cout << "Nhap tien cong lap rap cua chi tiet phuc [" << _id << "] :";
	cin >> laprap;
	_price += 0.2 * laprap;
}

void ChiTietPhuc::AddPhuc()
{
	ChiTietPhuc* newphuc = new ChiTietPhuc;
	newphuc->Set();
	_weight += newphuc->GetWeight();
	_price += newphuc->GetPrice();
	vt_chitiet.push_back(newphuc);
}

void ChiTietPhuc::AddDon()
{
	ChiTietDon* newdon = new ChiTietDon;
	newdon->Set();
	this->_weight += newdon->GetWeight();
	this->_price += newdon->GetPrice();
	vt_chitiet.push_back(newdon);
}

ChiTiet* ChiTietPhuc::TimChiTiet(string name)
{
	if (name == _id) return this;
	for(auto it:vt_chitiet)
	{
		ChiTiet* p = it->TimChiTiet(name);
		if (p != NULL) return p;
	}
	return NULL;
}

void ChiTietPhuc::Menu()
{
	int choice;
	do
	{
		system("cls");
		cout << ">>>>MENU<<<<" << endl;
		cout << "0. Thoat" << endl;
		cout << "1. Nhap vao cac chi tiet cau thanh nen co may" << endl;
		cout << "2. Tinh trong luong co may" << endl;
		cout << "3. Tinh gia thanh co may" << endl;
		cout << "4. Tim chi tiet theo id" << endl;
		cout << "Lua chon cua ban:";
		cin >> choice;
		if (choice==1)
		{
			cin.ignore();
			cout << endl;
			this->NhapChiTietMay();
		}
		else if(choice==2)
		{
			cout << "Trong luong cua co may la: " << _weight << " kg" << endl;
			system("pause");
		}
		else if (choice==3)
		{
			cout << "Gia thanh cua co may la: " << _price << " vnd" << endl;
			system("pause");
		}
		else if (choice==4)
		{
			string name;
			cin.ignore();
			cout << "Nhap id chi tiet can tim:";
			getline(cin, name);
			ChiTiet* p = TimChiTiet(name);
			if(p==NULL)
			{
				cout << "Khong tim thay chi tiet[" << name << "]" << endl;
				system("pause");
			}
			else
			{
				p->GetInfo();
				system("pause");
			}
		}
	}
	while (choice!=0);
	
}

void ChiTietPhuc::NhapChiTietMay()
{
	int choice;
	do
	{
		cout << "Nhap chi Tiet may:" << endl;
		cout << "1. Nhap chi don" << endl;
		cout << "2. Nhap chi tiet phuc" << endl;
		cout << "0. Tro ve" << endl;
		cout << "Lua chon cua ban:";
		cin >> choice;
		if (choice != 0) cin.ignore();
		if (choice==1)
		{
			this->AddDon();
		}
		if (choice==2)
		{
			this->AddPhuc();
		}
		cout << "Ban co muon nhap tiep khong?(yes<1>/no<0>)" << endl;
		cout << "Lua chon cua ban:";
		cin >> choice;
		if (choice != 0) cin.ignore();
	}
	while (choice!=0);
	
}

#include "Machine.h"

void ChiTietDon::Set()
{
	cout << "Nhap ma cua chi tiet don:";
	getline(cin, _id);
	cout << "Nhap trong luong cua chi tiet don:";
	cin >> _weight;
	cout << "Nhap gia thanh cua chi tiet don:";
	cin >> _price;
}

void ChiTietPhuc::Set()
{
	int choice;
	cout << "Nhap ma cua chi tiet phuc:";
	getline(cin, _id);
	cout << "Ban co muon them chi tiet nao vao chi tiet [" << _id << "] khong?(bam 0 de thoat)" << endl;
	cout << "1. Them chi tiet phuc" << endl;
	cout << "2. Them chi tiet don" << endl;
	cout << "Lua chon cua ban:";
	cin >> choice;
	if (choice != 0) cin.ignore();
	if (choice==1)
	{
		
	}
}

void ChiTietPhuc::AddPhuc()
{
	ChiTietPhuc* newphuc = new ChiTietPhuc;
	newphuc->Set();
	_weight += newphuc->GetWeight();
	vt_chitiet.push_back(newphuc);
}

void ChiTietPhuc::AddDon()
{
	ChiTietDon* newdon = new ChiTietDon;
	newdon->Set();
	this->_weight += newdon->GetWeight();
	vt_chitiet.push_back(newdon);
}

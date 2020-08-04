#ifndef _MACHINE_H_
#define _MACHINE_H_

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ChiTiet
{
protected:
	string _id;
	float _price;
	float _weight;
public:
	ChiTiet() :_id(""), _price(0), _weight(0) {};
	virtual void Set() = 0;
	string GetId() const
	{
		return _id;
	}
	float GetPrice() const
	{
		return _price;
	}
	float GetWeight() const
	{
		return _weight;
	}
	
};

class ChiTietDon:public ChiTiet
{
public:
	void Set() override;
};

class ChiTietPhuc:public ChiTiet
{
private:
	vector<ChiTiet*>vt_chitiet;
public:
	ChiTietPhuc():ChiTiet()
	{
		vt_chitiet.resize(0);
	}
	void Set() override;
	void AddPhuc();
	void AddDon();
};
#endif


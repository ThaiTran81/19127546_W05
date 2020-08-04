#ifndef _FOLDER_H_
#define _FOLDER_H_

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

class StorageUnit
{
protected:
	string _name;
	float _size;
	string type;
	int _level = 0;
public:
	StorageUnit() :_name(""), _size(0), type("") {};
	virtual void Set() = 0;
	float GetSize()
	{
		return _size;
	}
	string GetName()
	{
		return _name;
	}
	string GetType()
	{
		return type;
	}
	virtual void Print() = 0;
	virtual int GetNumFile()
	{
		return 0;
	}
	virtual int GetNumFolder()
	{
		return 0;
	}
	void SetLevel(const int& level)
	{
		_level = level;
	}
	int GetLevel()
	{
		return _level;
	}
};


class File :public StorageUnit
{
private:
public:
	File() :StorageUnit()
	{
		type = "file";
	};
	void Set() override;
	void Print() override;
};

class Folder :public StorageUnit
{
private:
	vector<StorageUnit*>vt_folder;
	static vector<StorageUnit*>s_vt_folder;
	int _numfile = 0;
	int _numfolder = 0;
public:
	Folder() :StorageUnit()
	{
		type = "folder";
	};
	void Set() override;
	void Print() override;
	void AddFile();
	void AddFolder();
	void Option();
	int GetNumFile()
	{
		return _numfile;
	}
	int GetNumFolder()
	{
		return _numfolder;
	}
	StorageUnit* findFolder(const string& name);
};
#endif


#include "Folder.h"

void File::Set()
{
	cout << "Nhap ten file(ex1.txt....):";
	getline(cin, _name);
	cout << "Nhap thong tin kich thuoc(don vi byte):";
	cin >> _size;
}

void File::Print()
{
	cout << _name << "      " << _size << " B";
}

void Folder::Set()
{
	cout << "Nhap ten folder:";
	getline(cin, _name);
	int choice;
	do
	{
		cout << "Ban co muon tao them folder hay luu them file du lieu nao vao thu muc [" << _name << "] khong?(bam 0 de tro ve)" << endl;
		cout << "1. Tao Folder" << endl;
		cout << "2. Luu file" << endl;
		cout << "Lua chon cua ban:";
		cin >> choice;
		if (choice == 1)
		{
			cin.ignore();
			this->AddFolder();

		}
		else if (choice == 2)
		{
			cin.ignore();
			this->AddFile();
		}
	} while (choice != 0);
}

void Folder::Print()
{
	cout << "[" << _name << "]" << endl;
	for (auto it = vt_folder.begin(); it != vt_folder.end(); it++)
	{
		for (int i = 0; i < (*it)->GetLevel(); i++)
		{
			cout << "       ";
		}
		(*it)->Print();
		cout << endl;
	}
}

void Folder::AddFile()
{
	File* new_file = new File;
	new_file->SetLevel(_level + 1);
	new_file->Set();
	_size += new_file->GetSize();
	vt_folder.push_back(new_file);
	_numfile++;
}

void Folder::AddFolder()
{
	Folder* newfolder = new Folder;
	newfolder->SetLevel(_level + 1);
	newfolder->Set();
	_size += newfolder->GetSize();
	vt_folder.push_back(newfolder);
	_numfolder++;
}

void Folder::Option()
{
	int choice;
	do
	{
		system("cls");
		cout << "       >>>>>>>>MENU<<<<<<<<" << endl;
		cout << "1. Tao cay thu muc tap tin" << endl;
		cout << "2. Xuat cay thu muc tap tin tu thu muc goc" << endl;
		cout << "3. Dem so tap tin va thu muc co trong mot thu muc" << endl;
		cout << "4. Tinh kich thuoc mot thu muc co ten cho truoc" << endl;
		cout << "Lua chon cua ban:";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cin.ignore();
			this->Set();
			cout << "Done" << endl;
			system("pause");
			break;
		}
		case 2:
		{
			this->Print();
			cout << endl;
			system("pause");
			break;
		}
		case 3:
		{
			string namefolder;
			cin.ignore();
			cout << "Nhap ten thu muc ban can tim:";
			getline(cin, namefolder);
			StorageUnit* p = findFolder(namefolder);
			if (p == NULL)
			{
				cout << "Rat tiec khong tim thay thu muc ban can tim" << endl;
			}
			else
			{
				cout << "Thu muc " << namefolder << "  co " << p->GetNumFile() << " tap tin va " << p->GetNumFolder() << " thu muc" << endl;
			}
			system("pause");
			break;
		}
		case 4:
		{
			string namefolder;
			cin.ignore();
			cout << "Nhap ten thu muc ban can tim:";
			getline(cin, namefolder);
			StorageUnit* p = findFolder(namefolder);
			if (p == NULL)
			{
				cout << "Rat tiec khong tim thay thu muc ban can tim" << endl;
			}
			else
			{
				cout << "Thu muc " << namefolder << " co kich thuoc " << p->GetSize() << " B" << endl;
			}
			system("pause");
			break;
		}
		}
	} while (choice != 0);

}

StorageUnit* Folder::findFolder(const string& name)
{
	if (name == _name) return this;
	for (auto it : vt_folder)
	{
		StorageUnit* p = (it)->findFolder(name);
		if ( p!= NULL)
		{
			return (p);
		}
	}
	return NULL;
}

Folder::~Folder()
{
	for (auto it:vt_folder)
	{
		delete it;
	}
}

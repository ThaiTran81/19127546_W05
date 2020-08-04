#include "Staff.h"

int main()
{
	CTy company;
	int choice;
	do
	{
		Menu();
		cout << "Your choice:";
		cin >> choice;
		if(choice ==1)
		{
			
		}
		else if(choice ==2)
		{
			company.AddNewStaff();
		}
		else if(choice==3)
		{
			company.PrintAllStaff();
			system("pause");
		}
		else if (choice==4)
		{
			company.PrintNumOfStaff();
			system("pause");
		}
		else if (choice==5)
		{
			company.PrintNumOfManager();
			system("pause");
		}
	}
	while (choice!=0);
	return 0;
}
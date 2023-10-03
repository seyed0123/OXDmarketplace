#include <bits/stdc++.h>
#include <windows.h>
#include <fstream>
using namespace std;

struct good
{
    string name;
    int price;
    string brand;
    int numbersInStock;
};
void createfile();
void readfile(good* &arr,int& ,int& ,string);
void showMenu(good* &,string [],int &,int&);
void enterData(good* &, int &,int&);
void report(good* &, int& );
void resize(good* & , int&);
void enterOldData(good* &list ,int &size);
bool compareTwoGood(good , good );
int main()
{
	int capacity=2,size=0;
	good* arr=new good [2];
	cout<<"Do you have save txt with our format? no 0 / yes 1\n";
	int l;
	cin>>l;
	if(l==1)
	{
		cout<<"enter you file name:\n";
		string fileName;
		cin>>fileName;
		readfile(arr,capacity,size,fileName);
	}
	string input[]={"enter data","report","exit"},p;
	getline(cin,p);
	showMenu(arr,input,capacity,size);
    return 0;

}
void readfile(good* &arr,int &capacity,int &size,string fileName)
{
	string line;
	fileName+=".hasan";
  	ifstream myfile (fileName);
	if (myfile.is_open())
	{
		getline (myfile,line);
		while (getline(myfile,line))
		{
			//cout<<line<<endl;
			size++;
			if(size==capacity)
			{
				resize(arr,capacity);
			}
			int index,iter=0;
			if(line[0]==' ')
			{
				iter++;
			}
			bool flag=0;
			for (int i = iter; i < line.size(); ++i)
			{
				
				if(line[i]==' ' && flag==0)
				{
					flag=1;
					index=stoi(line.substr(iter,i));

				}
				if(flag)
				{
					if(line[i]!=' ')
					{
						iter=i;
						break;
					}
				}
			}
			//cout<<index<<"*"<<iter<<endl;
			flag=0;
			for (int i = iter; i < line.size(); ++i)
			{
				//cout<<flag<<'-'<<iter<<'-'<<i<<'-'<<line[i]<<'-'<<endl;
				if(line[i]==' ' && flag==0)
				{
					flag=1;
					arr[index].name=line.substr(iter,i-iter);
				}
				if(flag)
				{
					if(line[i]!=' ')
					{
						iter=i;
						break;
					}
				}
			}
			//cout<<arr[index].name<<"*"<<iter<<endl;
			flag=0;
			for (int i = iter; i < line.size(); ++i)
			{
				if(line[i]==' ' && flag==0)
				{
					flag=1;
					arr[index].price=stoi(line.substr(iter,i-iter));
				}
				if(flag && line[i]!=' ')
				{
					iter=i;
					break;
				}
			}
			//cout<<arr[index].price<<"*"<<iter<<endl;
			flag=0;
			for (int i = iter; i < line.size(); ++i)
			{
				if(line[i]==' ' && flag==0)
				{
					flag=1;
					arr[index].brand=line.substr(iter,i-iter);
				}
				if(flag && line[i]!=' ')
				{
					iter=i;
					break;
				}
			}
			//cout<<arr[index].brand<<"*"<<iter<<endl;
			flag=0;
			for (int i = iter; i < line.size(); ++i)
			{
				if((line[i]==' ' && flag==0) || i==line.size()-1)
				{
					flag=1;
					arr[index].numbersInStock=stoi(line.substr(iter,i-iter));
					break;
				}
			}
			//cout<<arr[index].numbersInStock<<"*"<<iter<<endl;
		}
	myfile.close();
	}
}
void createfile(good* &arr,int size)
{
	if(size==0)
	{
		return;
	}
	ofstream file;
	file.open("save.hasan");
	 sort( arr+1, arr + size, compareTwoGood);
	 file << "Num"
     << "----"
     << "Name"
     << "- ";
    file << "price"
     << "--"
     << "barnd"
     << "-"
     << "count\n";
 
    // Display details of Students
    for (int i = 1; i <= size; i++) 
    {
        file << setw(2)<<i << " ";
        file << setw(8)<<arr[i].name << " ";
        file << setw(3) << arr[i].price << " " << setw(8)<<arr[i].brand << " "<< setw(3)<<arr[i].numbersInStock << "       ";
        file << "\n";
    }
	file.close();
}
void resize(good* &dynamicArray, int &capacity)
{
    good* array2 = new good[2*capacity];
    for(int i = 0 ; i < capacity ; i++)
    {
    	array2[i]=dynamicArray[i];
	}
	delete []dynamicArray;
	dynamicArray = array2;
	capacity *= 2;
	return;
}
void showMenu(good* &list,string menuItem[] , int &capacity , int &size)
{
	cout<<"----hasan market----\n";
   for(int i = 0 ; i <= 2 ; i++)
   {
   	cout<<menuItem[i] << endl;
   }
   string input;
   getline(cin,input);
   if(input=="new good")
   {
   		system("cls");
   		string menu[]={"enter data","report","exit"};
   		enterData(list,capacity,size);
   		showMenu(list,menu,capacity,size);
   }
   else if(input=="enter data")
   {
   		system("cls");
   		string menu[]={"new good","old good","back"};
   		showMenu(list,menu,capacity,size);
   }
   else if(input=="old good")
   {
   		system("cls");
   		string menu[]={"enter data","report","exit"};
   		enterOldData(list,size);
   		showMenu(list,menu,capacity,size);
   }else if(input=="back")
   {
   		system("cls");
   		string menu[]={"enter data","report","exit"};
   		showMenu(list,menu,capacity,size);
   }else if(input=="exit")
   {
   		createfile(list,size);
   		exit(0);
   }else if(input=="report")
   {   	
   		system("cls");
   		string menu[]={"enter data","report","exit"};
   		report(list,size);
   		showMenu(list,menu,capacity,size);
   }else
   {
   		string menu[]={"enter data","report","exit"};
   		cout<<"this input isn't vaild\n";
   		showMenu(list,menu,capacity,size);
   }
}
void enterOldData(good* &arr ,int &size)
{
	// getinputs
	string name,brand;
	int count,price;
	cout << "enter good name:\n";
	getline(cin,name);
	cout<< "enter good new count\n";
	cin>>count;
	cout << "enter good new price\n";
	cin>>price;
	cout << "enter good brand\n";
	getline(cin,brand);
	getline(cin,brand);
	//find the old good
	int index=-1;
	for (int i = 0 ; i <= size ; i++)
	{
		if(arr[i].name==name && arr[i].brand==brand) 
		{
			index=i;
		}
	}
	if(index==-1)
	{
		cout<<"the name or brand isn't vaild\n";
		return;
	}
	// save them
	arr[index].name=name;
	arr[index].price=price;
	arr[index].brand=brand;
	arr[index].numbersInStock=count;
	return;
}
void enterData(good* &arr ,int &capacity ,int &size )
{
	// getinputs
	string name,brand;
	int count,price;
	cout << "enter good name:\n";
	getline(cin,name) ;
	cout<< "enter good count\n";
	cin>>count;
	cout << "enter good price\n";
	cin>>price;
	cout << "enter good brand\n";
	getline(cin,brand) ;
	getline(cin,brand);
	// save them
	size++;
	if(size==capacity)
	{
		resize( arr ,capacity);
	}
	arr[size].name=name;
	arr[size].price=price;
	arr[size].brand=brand;
	arr[size].numbersInStock=count;
	return;
}
bool compareTwoGood(good a, good b)
{
    // If name are not same then
    // returns true for higher name
    if (a.name != b.name)
        return a.name > b.name;
    // same as up
    if (a.price != b.price)
        return a.price > b.price;
 
    if (a.brand != b.brand)
        return a.brand > b.brand;
 
    return (a.numbersInStock > b.numbersInStock);
}
void report(good* &arr , int &size )
{
	if(size==0)
	{
		cout<<"we dont have any thing :( \n";
		return;
	}
	 sort( arr+1, arr + size, compareTwoGood);
	 cout << "Num"
     << "----"
     << "Name"
     << "- ";
    cout << "price"
     << "--"
     << "barnd"
     << "-"
     << "count\n";
 
    // Display details of Students
    for (int i = 1; i <= size; i++) 
    {
        cout << setw(2)<<i << " ";
        cout << setw(8)<<arr[i].name << " ";
        cout << setw(3) << arr[i].price << " " << setw(8)<<arr[i].brand << " "<< setw(3)<<arr[i].numbersInStock << "       ";
        cout << "\n";
    }
}
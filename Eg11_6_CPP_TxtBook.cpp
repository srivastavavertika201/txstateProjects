#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct InventoryItem{
	int partNum;
	string desctription;
	int onHand;
	double price;
};
	void getItem(InventoryItem&);
	void showItem(InventoryItem&);
	
int main(){
	InventoryItem part;
	getItem(part);
	showItem(part);
	return 0;
}

void getItem(InventoryItem &p){
	cout << "Enter partNumber of item: " << '\n';
	cin >> p.partNum;
	cout << '\n';
	cout << "Enter description : " << '\n';
	cin.ignore();
	getline(cin,p.desctription);
	cout <<'\n';
	cout << "Enter uniots per hand: " << '\n';
	cin >> p.onHand;
	cout <<'\n';
	cout << "Enter price of Items: " <<'\n';
	cin >> p.price;
	cout <<'\n';
}

void showItem(InventoryItem &p){
	cout << fixed << showpoint << setprecision(2);
	cout << "PartNumber of Item" << p.partNum <<'\n';
	cout << '\n';
	cout << "Description of Item" << p.desctription <<'\n';
	cout << '\n';
	cout << "Unit on hand of Item" << p.onHand <<'\n';
	cout << '\n';
	cout << "Price of Item" << p.price <<'\n';
	cout << '\n';
}

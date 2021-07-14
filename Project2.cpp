#include<iostream>
#include"PROJECT.h"
#include<iomanip>
#include <stdio.h>
#include "conio.h"
#include <iostream>
#include <windows.h>
using namespace std;

// CLASS PASSWORD
void Password::setPassword(string Pass) {
	if (Pass.length() == 12)
	{
		password = Pass;
	}
	else
		cout << "Password length is not 12" << endl << "\terror\t\n";
}
string Password::checkPassword() const {
	return password;
}
string Password::passwordHint() {
	string pass;
	pass = password;
	return pass.replace(2, 7, "*******");
}
string Password::getPassword() const {
	return password;
}
bool Password::Pass() {
	//string pass;
	char pass[12];
	cout << "\n\n\n\t\t\tEnter Your password : ";
	for (int i = 0; i < 12; i++)
	{
		pass[i] = _getch();
		cout << "*";
	}
	cout << "\n\n\n";
	string test="============";
	for (int i = 0; i < 12; i++)
	{
		test[i]=pass[i];
	}
	if (test == password)
		return 1;
	else {
		return 0;
	}
}


//CLASS EMPLOYEE
void Employee::setSalary(int sal) { salary = sal; }
int Employee::totalSalary() const { return salary; }
void Employee::setId(int n) {
	id = n;
}
int Employee::getId()const {
	return id;
}
int Employee::getAttendence() const { return attendence; }

void Employee::markAttendence() {
	attendence++;
}
ostream& operator<<(ostream& os, Employee e)
{
	os << "NAME : " << e.getName() << "\nID : " << e.getId() << "\nSalary : " << e.totalSalary() << "\nAttendence : " << e.getAttendence() << endl;
	return os;
}
Employee::Employee()
{
	salary = 0;
	name = "";
	id = 0000;
	attendence = 0;
}
Employee::~Employee()
{
}

// CLASS STAFF
void StaffOfEmployees::addStaffMember(string name, int id, int sal) {
	for (int i = 0; i < capacity; i++)
	{
		if (emp[i].getId() == 0000) {
			emp[i].setName(name);
			emp[i].setId(id);
			emp[i].setSalary(sal);
			break;
		}
	}
}
void  StaffOfEmployees::deleteStaffMember(int id) {
	for (int i = 0; i < capacity; i++)
	{
		if (emp[i].getId() == id) {
			emp[i].setId(0000);
			break;
		}
	}
}
void  StaffOfEmployees::displayStaff() {
	for (int i = 0; i < capacity; i++)
	{
		if (emp[i].getId() != 0000) {
			cout << emp[i] << endl;
		}
	}
}
void   StaffOfEmployees::changeName(int id, string n) {
	for (int i = 0; i < capacity; i++)
	{
		if (emp[i].getId() == id) {
			emp[i].setName(n);
			break;
		}
	}

}
void  StaffOfEmployees::changeSalaries(int id, int n) {
	for (int i = 0; i < capacity; i++)
	{
		if (emp[i].getId() == id) {
			emp[i].setSalary(n);
			break;
		}
	}
}
void  StaffOfEmployees::setCapacity(int c) { capacity = c; }
void  StaffOfEmployees::emptyStaff() {
	for (int i = 0; i < capacity; i++)
	{
		emp[i].setName("");
		emp[i].setSalary(0);
		emp[i].setId(0000);
	}
}
void   StaffOfEmployees::displayStaffMember(int id) {
	for (int i = 0; i < capacity; i++)
	{
		if (emp[i].getId() == id) {
			cout << emp[i] << endl;
			break;
		}
	}
}
bool  StaffOfEmployees::chkId(int id) {
	for (int i = 0; i < capacity; i++)
	{
		if (emp[i].getId() == id) {
			return 1;
			break;
		}
	}
	return 0;
}
bool  StaffOfEmployees::markAttendence(int id) {
	for (int i = 0; i < capacity; i++)
	{
		if (emp[i].getId() == id) {
			emp[i].Employee::markAttendence();
			return 1;
			break;
		}
	}
	return 0;
}

StaffOfEmployees::StaffOfEmployees()
{
	capacity = 10;
	emp = new Employee[capacity];
	if (capacity >= 3) {
		emp[0].setName("Waleed");
		emp[0].setId(200677);
		emp[0].setSalary(100000);
		emp[1].setName("Raza");
		emp[1].setId(200656);
		emp[1].setSalary(120000);
		emp[2].setName("Talha");
		emp[2].setId(200641);
		emp[2].setSalary(110000);
		emp[3].setName("Mahd");
		emp[3].setId(200658);
		emp[3].setSalary(100000);
		emp[4].setName("Tayyab");
		emp[4].setId(200657);
		emp[4].setSalary(120000);
		emp[5].setName("Yousaf");
		emp[5].setId(696969);
		emp[5].setSalary(110000);
	}
}
StaffOfEmployees::~StaffOfEmployees()
{
}

//CLASS PRICE
int Price::totalPrice() const { return TPrice; }
void Price::setPrice(int p) { price = p; }
void Price::setTax(int tax) { this->tax = tax; }
void Price::setProfit(int p) { profit = p; }
double Price::totalPriceIfMember() { return (TPrice -= TPrice * (0.10)); }
void Price::calculateTotal() { TPrice = price + (price * (tax / 100)) + profit; }
int Price::getProfit() { return profit; }
Price::Price()
{
	tax = 0;
	price = 0;
	profit = 0;
	TPrice = 0;
}

Price::~Price()
{
}

//CLASS ReturnAndSoldStock

ReturnAndSoldStock::ReturnAndSoldStock()
{
	soldPdts = new Product[100];
	returnPdts = new Product[100];
}

ReturnAndSoldStock::~ReturnAndSoldStock()
{
}
void ReturnAndSoldStock::setSoldPdts(string N, int q) {
	for (int i = 0; i < 100; i++)
	{
		if (soldPdts[i].getName() == "")
		{
			soldPdts[i].setName(N);
			soldPdts[i].setQuantity(q);
			break;
		}
	}
}
void ReturnAndSoldStock::setReturnPdts(string N, int q) {
	for (int i = 0; i < 100; i++)
	{
		if (soldPdts[i].getName() == "")
		{
			returnPdts[i].setName(N);
			returnPdts[i].setQuantity(q);
			break;
		}
	}
}
void ReturnAndSoldStock::displaySoldPdts() {
	for (int i = 0; i < 100; i++)
	{
		if (soldPdts[i].getName() != "")
		{
			cout << "Product Name : " << soldPdts[i].getName() << "\nProduct Quantity : " << soldPdts[i].getQuantity() << endl << endl;
		}
	}
}
void ReturnAndSoldStock::displayReturnPdts() {
	for (int i = 0; i < 100; i++)
	{
		if (returnPdts[i].getName() != "")
			cout << "Product Name : " << returnPdts[i].getName() << "\nProduct Quantity : " << returnPdts[i].getQuantity() << endl << endl;
	}
}


//CLASS PRODUCT
void Product::setName(string x) {
	name = x;
}
void Product::setExpiry(string x) {
	expiry = x;
}
void Product::setQuantity(int x) {
	quantity = x;
}
string Product::getName()const {
	return name;
}
string Product::getExpiry()const {
	return expiry;
}
int Product::getQuantity()const {
	return quantity;
}
ostream& operator<<(ostream& os, Product p) {
	os << "\t\t" << p.name << "\t\t\t" << p.quantity << "\t\t\t" << p.expiry << "\t\t\t" << p.totalPrice() << "\t\t" << endl;
	return os;
}
Product::Product(string n , string e , int q)
{
	name = n;
	expiry = e;
	quantity = q;
}

Product::~Product()
{
}
int Product::totalPrice() const
{
	return prise.totalPrice();
}

void Product::setPrice(int p)
{
	prise.setPrice(p);
}

void Product::setTax(int tax)
{
	prise.setTax(tax);
}

void Product::setProfit(int p)
{
	prise.setProfit(p);
}

double Product::totalPriceIfMember()
{
	return prise.totalPriceIfMember();
}

void Product::calculateTotal()
{
	prise.calculateTotal();
}

int Product::getProfit()
{
	return prise.getProfit();
}

// CLASS STOCK
void Stock::setProduct(int i,string N, int Q, string E, int Pri, int pro, int T)
{
	prod[i].setName(N);
	prod[i].setQuantity(Q);
	prod[i].setExpiry(E);
	prod[i].setPrice(Pri);
	prod[i].setProfit(pro);
	prod[i].setTax(T);
	prod[i].calculateTotal();
}
bool Stock::addProduct(string N, int Q, string E, int Pri, int pro, int T) {
	for (int i = 0; i < 100; i++)
	{
		if (prod[i].getName() == "")
		{
			setProduct(i,N,Q,E,Pri,pro,T);
			return 1;
			break;
		}

	}
	return 0;
}
bool Stock::deleteProduct(string N) {
	for (int i = 0; i < 100; i++)
	{
		if (prod[i].getName() == N)
		{
			setProduct(i, "", 0, "", 0, 0, 0);
			return 1;
			break;
		}
	}
	return 0;
}
double Stock::productPrice(string N, int quan, bool m, bool r) {
	for (int i = 0; i < 100; i++)
	{
		if (prod[i].getName() == N)
		{
			if (m)
			{
				prod[i].calculateTotal();
				if (r)
				{
					earning = earning - quan * (prod[i].totalPriceIfMember());
				}
				else {
					earning += quan * (prod[i].totalPriceIfMember());
				}
				return quan * (prod[i].totalPriceIfMember());
			}
			else {
				prod[i].calculateTotal();
				if (r)
				{
					earning = earning - quan * (prod[i].totalPrice());
				}
				else {
					earning += quan * (prod[i].totalPrice());
				}
				return (quan * (prod[i].totalPrice()));
			}
			break;
		}
	}
}
double Stock::getEarning()const { return earning; }

void Stock::displayProduct() {
	for (int i = 0; i < 100; i++)
	{
		if (prod[i].getName() == "" || prod[i].getQuantity() <= 0) {

			setProduct(i, "", 0, "", 0, 0, 0);
		}
	}

	int x = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
		{
			if (prod[i].getName() == prod[j].getName() && j != i) {
				x = prod[j].getQuantity();
				x += prod[i].getQuantity();
				prod[i].setQuantity(x);
				setProduct(j, "", 0, "", 0, 0, 0);
			}
		}
	}
	cout << "\n\t\t===============================================================================\n";
	cout << "\t\tNAME\t\t\tQUANTITY\t\tEXPIRY\t\t\tPRICE\t\t\t\n";
	cout << "\t\t===============================================================================\n\n";
	for (int i = 0; i < 100; i++)
	{
		if (prod[i].getName() != "" && prod[i].getQuantity() > 0) {
			cout << prod[i] << endl;
		}
	}
	cout << "\t\t===============================================================================\n\n\n\n\n\n\t\t";
}
void Stock::emptyStock() {
	for (int i = 0; i < 100; i++)
	{
		setProduct(i, "", 0, "", 0, 0, 0);
	}
}
bool Stock::IfProd(string n) {
	for (int i = 0; i < 100; i++)
	{
		if (prod[i].getName() == n) {
			return 1;
		}
	}
	return 0;
}
bool Stock::decQuan(string N, int n) {
	int x;
	for (int i = 0; i < 100; i++)
	{
		if (prod[i].getName() == N) {
			x = prod[i].getQuantity();
			x -= n;
			if (x >= 0) {
				prod[i].setQuantity(x);
				return 1;
			}
			break;
		}
	}
	return 0;
}
void Stock::incQuan(string N, int n) {
	int x;
	for (int i = 0; i < 100; i++)
	{
		if (prod[i].getName() == N) {
			x = prod[i].getQuantity();
			x += n;
			prod[i].setQuantity(x);
			break;
		}
	}
}
double Stock::earning = 0;
Stock::Stock()
{
	prod = new Product[100];
	{
		setProduct(0, "Pencils", 100, "No", 10, 2, 20);
		setProduct(1, "Milk", 150, "3 days", 100, 10, 15);
		setProduct(2, "Tenis", 150, "no", 50, 50, 20);
		setProduct(3, "Juices", 200, "2022", 50, 50, 13);
		setProduct(4, "Lamps", 30, "No", 1000, 200, 12);
	}
	chkOutProd = new Product[500];

}

void Stock::setChkOutProd(string n,int q,string t)
{
	for (int i = 0; i < 500; i++)
	{
		if (chkOutProd[i].getName() == "")
		{
			chkOutProd[i].setName(n);
			chkOutProd[i].setQuantity(q);
			chkOutProd[i].setExpiry(t);
			break;
		}
	}
}

void Stock::destroyChkOutProd()
{
	for (int i = 0; i < 500; i++)
	{
			chkOutProd[i].setName("");
			chkOutProd[i].setQuantity(0);
	}
}
void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void Stock::displayChkOut()
{
	system("cls");
	int x;
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			if (chkOutProd[i].getName() == chkOutProd[j].getName() && chkOutProd[j].getExpiry() == chkOutProd[i].getExpiry() && i != j)
			{
				x = chkOutProd[j].getQuantity();
				x += chkOutProd[i].getQuantity();
				chkOutProd[i].setQuantity(x);
				chkOutProd[j].setName("");
				chkOutProd[j].setQuantity(0);
				chkOutProd[j].setExpiry("");
			}

		}
	}
	int b = 201;
	cout << setw(24) << "     " << (char)b;
	for (int y = 0; y <= 30; y++)
	{
		b = 205;
		cout << (char)b;
	}
	b = 187;
	cout << (char)b << endl;
	b = 186;
	cout << setw(44) << "YOUR BILL" << endl;
	b = 200;
	cout << setw(24) << "     " << (char)b;
	for (int y = 0; y <= 30; y++)
	{
		b = 205;
		cout << (char)b;
	}
	b = 188;
	cout << (char)b << endl;
	b = 201;
	cout << setw(20) << (char)b;
	for (int y = 0; y <= 13; y++)
	{
		b = 205;
		cout << (char)b;
	}
	cout << " WRTM STORE ";
	for (int y = 0; y <= 13; y++)
	{
		b = 205;
		cout << (char)b;
	}
	b = 187;
	cout << (char)b << endl;
	b = 186;
	cout << setw(20) << (char)b << setw(41) << (char)b << endl;
	b = 186;
	for (int i = 0; i < 9; i++)
	{
		cout << setw(20) << "\t\t\t\t\t\t    " << (char)b << endl;
	}
	cout << setw(20) << (char)b << setw(41) << (char)b << endl;
	b = 204;
	cout << setw(20) << (char)b;
	for (int y = 0; y <= 39; y++)
	{
		b = 205;
		cout << (char)b;
	}
	b = 185;
	cout << (char)b << endl;
	b = 186;
	cout << setw(20) << (char)b << setw(41) << (char)b << endl;
	b = 200;
	cout << setw(20) << (char)b;
	for (int y = 0; y <= 39; y++)
	{
		b = 205;
		cout << (char)b;
	}
	b = 188;
	cout << (char)b << endl;

	b = 186;
	int Y = 5;
	gotoxy(7, Y);
	cout << "\t\t   " << (char)b << "    PRODUCT  \tType  \t Quantity\n\n";
	Y++;
	Y++;
	for (int i = 0; i < 500; i++)
	{
		if (chkOutProd[i].getName() != "")
		{
			gotoxy(7, Y);
			cout << "\t\t   " << (char)b << "  [" << i + 1 << "]  " << chkOutProd[i].getName() << " \t" << chkOutProd[i].getExpiry() << "  \t" << chkOutProd[i].getQuantity() << endl;
			Y++;

		}
	}
	Y = 5;
	for (int i = 0; i < 9; i++)
	{
		gotoxy(7, Y);
		cout << "\t\t   " << (char)b << endl;
		Y++;
	}
	gotoxy(24, 1);
	cout << (char)b;
	gotoxy(56, 1);
	cout << (char)b;
	gotoxy(7, 16);
	cout << "\t\t\tYOUR TOTAL IS :\t" ;
	gotoxy(19, 20);
	destroyChkOutProd();
}

Stock::~Stock()
{
}

// CLASS CUSTOMER
bool Customer::buyProduct(string n, int quan, bool m) {
	if (stock.decQuan(n, quan))
	{
		amount += stock.productPrice(n, quan, m, 0);
		return 1;
	}
	return 0;
}
void Customer::returnProduct(string n, int quan, bool m) {
	amount -= stock.productPrice(n, quan, m, 1);
	stock.incQuan(n, quan);
}
void Customer::setPrice(double p) { amount = p; }
double Customer::getPrice()const {
	return amount;
}
Customer::Customer() {
	amount = 0.0;
	word.setPassword("customer1234");
}
Customer::Customer(string p)
{
	amount = 0.0;
	word.setPassword(p);
}

// Class Administration

Administration::Administration()
{
	word.setPassword("admin1234567");
}
Administration::~Administration()
{
}

// CLASS DEALER
Dealer::Dealer()
{
	word.setPassword("dealer123456");
}

Dealer::~Dealer()
{
}

//MENU

int menu(string head, string* x, int size, int screen) {
	system("cls");
	int choice;
	int b = 201;
	cout << setw(24) << "     " << (char)b;
	for (int y = 0; y <= 30; y++)
	{
		b = 205;
		cout << (char)b;
	}
	b = 187;
	cout << (char)b << endl;
	b = 186;
	if (screen == 1 || screen == 5)
		cout << setw(52) << head << endl;
	else if (screen == 2 || screen == 3)
		cout << setw(46) << head << endl;
	else if (screen == 4)
		cout << setw(50) << head << endl;
	else if (screen == 6)
		cout << setw(47) << head << endl;
	else if (screen == 7)
		cout << setw(48) << head << endl;
	b = 200;
	cout << setw(24) << "     " << (char)b;
	for (int y = 0; y <= 30; y++)
	{
		b = 205;
		cout << (char)b;
	}
	b = 188;
	cout << (char)b << endl;
	b = 201;
	cout << setw(20) << (char)b;
	for (int y = 0; y <= 13; y++)
	{
		b = 205;
		cout << (char)b;
	}
	cout << " WRTM STORE ";
	for (int y = 0; y <= 13; y++)
	{
		b = 205;
		cout << (char)b;
	}
	b = 187;
	cout << (char)b << endl;
	b = 186;
	cout << setw(20) << (char)b << setw(41) << (char)b << endl;
	b = 186;
	for (int i = 0; i < 9; i++)
	{
		cout << setw(20)  << "\t\t\t\t\t\t    " << (char)b << endl;
	}
	cout << setw(20) << (char)b << setw(41) << (char)b << endl;
	b = 204;
	cout << setw(20) << (char)b;
	for (int y = 0; y <= 39; y++)
	{
		b = 205;
		cout << (char)b;
	}
	b = 185;
	cout << (char)b << endl;
	b = 186;
	cout << setw(20) << (char)b << setw(41) << (char)b << endl;
	b = 200;
	cout << setw(20) << (char)b;
	for (int y = 0; y <= 39; y++)
	{
		b = 205;
		cout << (char)b;
	}
	b = 188;
	cout << (char)b << endl;

	b = 186;
	int Y = 5;
	for (int i = 0; i < size; i++)
	{
		gotoxy(7, Y);
		cout << "\t\t   " << (char)b << "  [" << i + 1 << "]  " << x[i] << endl;
		Y++;
	}
	Y = 5;
	for (int i = 0; i < 9; i++)
	{
		gotoxy(7, Y);
		cout << "\t\t   " << (char)b << endl;
		Y++;
	}
	gotoxy(24, 1);
	cout << (char)b;
	gotoxy(56, 1);
	cout << (char)b;

	gotoxy(7, 16);
	cout << "\t\t\tENTER YOUR CHOICE :\t"; cin >> choice;
	system("cls");
	return choice;
}

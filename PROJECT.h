#pragma once
#include<string>
using namespace std;

void gotoxy(int , int );

class Password
{
public:
	void setPassword(string Pass);
	string checkPassword() const;
	string passwordHint();
	string getPassword() const;
	bool Pass();
private:
	string password;
};

class Employee
{
public:
	Employee();
	~Employee();
	void setName(string n) { name = n; }
	string getName()const { return name; }
	void setId(int n);
	int getId()const;
	void setSalary(int sal);
	int totalSalary() const;
	int getAttendence() const;
	void markAttendence();
	friend ostream& operator << (ostream& os, Employee e);
private:
	int attendence;
	string name;
	int id;
	int salary;
};

class StaffOfEmployees
{
public:
	StaffOfEmployees();
	~StaffOfEmployees();
	void addStaffMember(string name, int id, int sal);
	void deleteStaffMember(int id);
	void displayStaff();
	void changeName(int id, string n);
	void changeSalaries(int id, int n);
	void setCapacity(int c);
	void emptyStaff();
	void displayStaffMember(int id);
	bool chkId(int id);
	bool markAttendence(int id);

private:
	Employee* emp;
	int capacity;
};

class Price
{
public:
	Price();
	~Price();
	int totalPrice() const;
	void setPrice(int p);
	void setTax(int tax);
	void setProfit(int p);
	double totalPriceIfMember();
	void calculateTotal();
	int getProfit();
private:
	int tax;
	int price;
	int profit;
	double TPrice;
};

class Product
{
public:
	Product(string, string, int);
	Product(){
		name = "";
		expiry = "";
		quantity = 0;
	}
	~Product();
	void setName(string x);
	void setExpiry(string x);
	void setQuantity(int x);
	string getName()const;
	string getExpiry()const;
	int getQuantity()const;

	int totalPrice() const;
	void setPrice(int p);
	void setTax(int tax);
	void setProfit(int p);
	double totalPriceIfMember();
	void calculateTotal();
	int getProfit();

	friend ostream& operator<<(ostream& os, Product p);
private:
	string name;
	string expiry;
	int quantity;
	Price prise;
};

class ReturnAndSoldStock
{
public:
	ReturnAndSoldStock();
	~ReturnAndSoldStock();
	void setSoldPdts(string N, int q);
	void setReturnPdts(string N, int q);
	void displaySoldPdts();
	void displayReturnPdts();
private:
	Product* soldPdts;
	Product* returnPdts;
};

class Stock: public ReturnAndSoldStock
{
public:
	Stock();
	~Stock();
	bool addProduct(string N, int Q, string E, int Pri, int pro, int T);
	bool deleteProduct(string N);
	double productPrice(string N, int quan, bool m, bool r);
	double getEarning()const;
	void displayProduct();
	void emptyStock();
	bool IfProd(string n);
	bool decQuan(string N, int n);
	void incQuan(string N, int n);
	void setChkOutProd(string , int,string);
	void setProduct(int ,string , int , string , int , int , int );
	void displayChkOut();
	void destroyChkOutProd();
private:
	Product* prod;
	Product* chkOutProd;
	static double earning;
};

class Customer
{
public:
	Customer(string p);
	Customer();
	bool buyProduct(string n, int quan, bool m);
	void returnProduct(string n, int quan, bool m);
	void setPrice(double p);
	double getPrice()const;
	bool addProduct(string N, int Q, string E, int Pri, int pro, int T) {
		return stock.addProduct(N, Q, E, Pri, pro, T);
	}
	bool deleteProduct(string N) {
		return stock.deleteProduct(N);
	}
	void displayProduct() {
		stock.displayProduct();
	}
	Password getWord()const { return word; }
	void resetStock() {
		stock.emptyStock();
	}
	double getEarning()const {
		return stock.getEarning();
	}
	bool IfProd(string n) {
		return stock.IfProd(n);
	}
	Stock getStock()const { return stock; }
private:
	double amount;
	Password word;
	Stock stock;
};

class Dealer
{
public:
	Dealer();
	~Dealer();

	Password getWord()const { return word; }
private:
	Password word;
};

class Administration
{
public:
	Administration();
	~Administration();
	Password getWord()const { return word; }
private:
	Password word;
};

class User :public Administration , public Dealer , public Customer, public StaffOfEmployees
{
public:
	~User() {
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\tMade By Mahd Bin Naeem\n\n\n\n\n\n\n\n";
		system("pause");
	}
};


int menu(string head, string* x, int size, int screen);
#include<iostream>
using namespace std;
#include"PROJECT.h"

int main() {
	system("color 75");
	int choice = 1;

	User user;
	bool x=0;
	cout << "\n\n\n\n\t\t\t\t\"WELLCOME TO STORE MANAGEMENT SYSTEM\"\n\n\n"<<
		"PASSWORDS:\n\n\tDEALER : dealer123456\n\tADMINISTRATION : admin1234567\n\tMEMBER CUSTOMER : customer1234\n\n\n\n\n\n\n\n\n\n\n\n\n"; system("pause");

	string mainMenu[5] = { "Dealer","Customer","Administration","Staff Member","Exit" };

	while (choice == 1) {

		switch (menu("WELLCOME TO OUR STORE", mainMenu, 5, 1)) {

		case 1: {
			choice = 2;
			string deal_[4] = { "Add Products","Check Products","Delete products","Back" };
			if (user.Dealer::getWord().Pass())
			{
				while (choice == 2)
				{
					system("cls");
					switch (menu("Dealer Menu", deal_, 4, 2)) {
					case 1: {
												cout << "\t\t\t\tAdding new product\n-------------------------------------------------------------------------------\n";
												string name, expiry; int quantity, price, tax, profit; cin.ignore();
												cout << "Enter Product name : "; getline(cin, name);
												cout << "Enter Product expiry : "; cin >> expiry; cin.ignore();
												cout << "Enter Product quantity : "; cin >> quantity;
												cout << "Enter Product price : "; cin >> price;
												cout << "Enter Product profit over price : "; cin >> profit;
												cout << "Enter Product tax : "; cin >> tax;
												if (user.addProduct(name, quantity, expiry, price, profit, tax)) {
													system("cls");
													cout << "\n\n\t\t\tAdded successfully\n\n";
												}
												else
												{
													system("cls");
													cout << "\n\n\t\t\tOperation failed\n\n";
												}
												system("pause");
												choice = 2;
												break;
					}
					case 2: {

												cout << "\t\t\t\t\t\tProducts Available\n\t\t-------------------------------------------------------------------------------\n\n";
												user.displayProduct();
												system("pause");
												choice = 2;
												break;
					}
					case 3: {
												cout << "\t\t\t\tDeleting Product\n-------------------------------------------------------------------------------\n";
												string name;
												cout << "Enter Product name : "; cin >> name;
												if (user.deleteProduct(name)) {
													system("cls");
													cout << "\n\n\t\t\tDeleted successfully\n\n";
												}
												else
												{
													system("cls");
													cout << "\n\n\t\t\tOperation failed\n\n";
												}
												system("pause");
												choice = 2;
												break;
					}
					case 4: {
												choice = 1;
												break;
					}
					default:
						break;
					}
				}
			}
			else
			{
				system("cls");
				cout << "\t\t\t\tINVALID PASSWORD\n" << "\t\t\tPassword hint :" << user.Dealer::getWord().passwordHint() << "\n\n\n\n";
				system("pause");
			}
			choice = 1;
			break;

		}

		case 2: {

			system("cls");

			string member[3] = { "Member","Not a Member","Back" };

			string cusr[5] = { "Display Product","Buy Product","Return product","Check Out","Back" };

			choice = 2;

			while (choice == 2)
			{
				switch (menu("CUSTOMER MENU", member, 3, 3))
				{
				case 1:

					system("cls");

					if (user.Customer::getWord().Pass()) {

						choice = 3;

						while (choice == 3)
						{

							switch (menu("MEMBER CUSTOMER MENU", cusr, 5, 4))
							{

							case 1: {

								cout << "\t\t\t\t\t\tDisplay Products\n\t\t-------------------------------------------------------------------------------\n\n";

								user.displayProduct();

								system("pause");

								choice = 3;

								break;
							}
							case 2: {

								cout << "\t\t\tBuy Products\n-----------------------------------------------------------------\n\n";

								string n; int quan;

								cout << "Enter Name of the product you want to buy : "; cin >> n;

								cout << "Enter Quantity of Product : "; cin >> quan;

								if (user.IfProd(n)) {

									if (user.buyProduct(n, quan, 1)) {

										cout << "\n\n\t\t\t\tPurchase Succesful\n\n\n";
										x = 1;
										user.getStock().setSoldPdts(n, quan);
										user.getStock().setChkOutProd(n, quan,"Sold    ");
									}

									else

										cout << "\n\n\t\t\t\tPurchase Failed\n\n\n";

								}

								else

									cout << "Product not available";

								system("pause");

								choice = 3;

								break;

							}
							case 3: {

								cout << "\t\t\tReturn Product\n-----------------------------------------------------------------\n\n";

								string n; int quan;

								cout << "Enter Name of the product you want to return : "; cin >> n;

								cout << "Enter Quantity of Product : "; cin >> quan;

								if (user.IfProd(n)) {

									user.returnProduct(n, quan, 1);
									x = 1;
									cout << "\n\n\t\t\t\tReturn Succesful\n\n\n";
									user.getStock().setReturnPdts(n, quan);
									user.getStock().setChkOutProd(n, quan,"Returned");
								}

								else

									cout << "We have no such product";

								system("pause");

								choice = 3;

								break;

							}
							case 4: {
								
								do{
									system("cls");

									cout << "\t\t\tCheckout\n-----------------------------------------------------------------\n\n";

									double n, y;
									user.getStock().displayChkOut();
									gotoxy(47, 16);
									cout << user.getPrice();
									gotoxy(19, 20);
									if (user.getPrice() > 0) {

										cout << "\nEnter amount : "; cin >> n;
										if (n > user.getPrice())
										{
											x = 1;
										}
										else {
											x = 0;
										}
									}

									else if (user.getPrice() < 0) {

										cout << "\nPick Up You Money\n\n";
										x = 1;
									}
									else {

										cout << "\nYou havn't bought anything yet\n\n";
										x = 1;
									}
									if (x == 1) {
										system("cls");
										cout << "\n\n\t\t\t\tThank You For Shopping\n\n\n";
										system("pause");
										user.setPrice(0);
									}
									else
									{
										cout << "\n\n\t\t\t\tInvalid amount Enter\n";
										cout << "\t\t\t\t\tEnter Again\n\n\n";
									}
									system("pause");
									choice = 2;

								} while (x == 0);

								x = 0;
								break;

							}
							case 5: {
								if (x == 0)
								{
									choice = 2;
								}
								else {
									system("cls");
									cout << "\n\n\n\t\t\t\tFirst check-out to proceed\n\n\n\n\n\n\n\n";
									system("pause");
								}
								break;

							}
							default: {

								system("cls");

								cout << "\n\n\t\t\t\t\tInvalid Input \n\t\t\t\t\t Enter Again\n\n" << endl;

								system("pause");

								choice = 2;
								break;
							}

							}

						}

					}
					else
					{

						system("cls");

						cout << "\t\t\t\tINVALID PASSWORD\n"
							<< "\t\t\tPassword hint :" << user.Customer::getWord().passwordHint() << "\n\n\n\n";
						system("pause");
					}
					break;

				case 2:
					choice = 3;
					while (choice == 3)
					{
						switch (menu("NON MEMBER CUSTOMER MENU", cusr, 5, 5))
						{
						case 1: {
							cout << "\t\t\t\t\t\tDisplay Products\n\t\t-------------------------------------------------------------------------------\n\n";
							user.displayProduct();
							system("pause");
							choice = 3;
							break;
						}
						case 2: {
							cout << "\t\t\tBuy Products\n-----------------------------------------------------------------\n\n";
							string n; int quan;
							cout << "Enter Name of the product you want to buy : "; cin >> n;
							cout << "Enter Quantity of Product : "; cin >> quan;
							if (user.IfProd(n)) {
								if (user.buyProduct(n, quan, 0)) {

									cout << "\n\n\t\t\t\tPurchase Succesful\n\n\n";
									x = 1;
									user.getStock().setSoldPdts(n, quan);
									user.getStock().setChkOutProd(n, quan,"Buy    ");
								}

								else
									cout << "\n\n\t\t\t\tPurchase Failed\n\n\n";
							}
							else {
								cout << "Product not available";
							}
							system("pause");
							choice = 3;
							break;
						}
						case 3: {
							cout << "\t\t\tReturn Product\n-----------------------------------------------------------------\n\n";
							string n; int quan;
							cout << "Enter Name of the product you want to return : "; cin >> n;
							cout << "Enter Quantity of Product : "; cin >> quan;
							if (user.IfProd(n)) {
								user.returnProduct(n, quan, 0);
								cout << "\n\n\t\t\t\tReturn Succesful\n\n\n";
								x = 1;
								user.getStock().setReturnPdts(n, quan);
								user.getStock().setChkOutProd(n,quan,"Returned");
							}
							else
								cout << "We have no such product";
							system("pause");
							choice = 3;
							break;
						}
						case 4: {

							do {
								system("cls");

								cout << "\t\t\tCheckout\n-----------------------------------------------------------------\n\n";

								double n, y;
								user.getStock().displayChkOut();
								gotoxy(47, 16);
								cout << user.getPrice();
								gotoxy(19, 20);

								if (user.getPrice() > 0) {

									cout << "\nEnter amount : "; cin >> n;
									if (n > user.getPrice())
									{
										x = 1;
									}
									else {
										x = 0;
									}
								}

								else if (user.getPrice() < 0) {

									cout << "\nPick Up You Money\n\n";
									x = 1;
								}
								else {

									cout << "\n\t\t\tYou havn't bought anything yet\n\n";
									x = 1;
								}
								if (x == 1) {
									system("pause");
									system("cls");
									cout << "\n\n\t\t\t\tThank You For Shopping\n\n\n";
									user.setPrice(0);
								}
								else
								{
									cout << "\n\n\t\t\t\tInvalid amount Enter\n";
									cout << "\t\t\t\t\tEnter Again\n\n\n";
								}

								system("pause");
								choice = 2;

							} while (x == 0);
							x = 0;
							break;
						}
						case 5: {
							if (x == 0)
							{
								choice = 2;
							}
							else {
								system("cls");
								cout << "\n\n\n\t\t\t\tFirst check-out to proceed\n\n\n\n\n\n\n\n";
								system("pause");
							}
							break;
						}
						default: {
							system("cls");
							cout << "\n\n\t\t\t\t\tInvalid Input \n\t\t\t\t\t Enter Again\n\n" << endl;
							system("pause");
							choice = 2;
							break;
						}
							   
						}
					}
					break;
				case 3:
					choice = 1;
					break;
				default: {
					system("cls");
					cout << "\n\n\t\t\t\t\tInvalid Input \n\t\t\t\t\t Enter Again\n\n" << endl;
					system("pause");
					choice = 2;
				}
					   break;

				}
			}
			break;

		}

		case 3: {
					system("cls");
					if (user.Administration::getWord().Pass()) {
						choice = 2;
						while (choice == 2) {
							string list[9] = { "Add Employee","Delete Employee","Check for employees","Change Employee Name","Change Employee Salaries","Sales Update","System Reset","Back","Exit" };
							switch (menu("Administration", list, 9,6))
							{
							case 1: {
								string name; int id; int s;
								cout << "\t\t\t\tADDING NEW EMPLOYEE\n-------------------------------------------------------------------------------\n";
								cout << "\nEnter name : "; cin >> name;
								cout << "\nEnter Id : "; cin >> id;
								cout << "\nEnter Initial Salary : "; cin >> s;
								user.addStaffMember(name, id, s);
								system("pause");
								choice = 2;
								break;
							}
							case 2: {
								cout << "\t\t\t\tDELETING EMPLOYEE\n-------------------------------------------------------------------------------\n";
								int id;
								cout << "Enter id of the Employee : "; cin >> id;
								user.deleteStaffMember(id);
								system("pause");
								choice = 2;
								break;
							}
							case 3: {
								cout << "\t\t\t\tEMPLOYEE DATA\t\t\n-------------------------------------------------------------------------------\n";
								user.displayStaff();
								system("pause");
								choice = 2;
								break;
							}
							case 4: {
								cout << "\t\t\t\tCHANGING NAME \n-------------------------------------------------------------------------------\n";
								int id; string n;
								cout << "Enter id of the Employee : "; cin >> id;
								cout << "Enter Name to Change : "; cin >> n;
								user.changeName(id, n);
								system("pause");
								choice = 2;
								break;
							}
							case 5: {
								cout << "\t\t\t\tCHANGING SALARIES \n-------------------------------------------------------------------------------\n";
								int id, n;
								cout << "Enter id of the Employee : "; cin >> id;
								cout << "Enter Amount to Change : "; cin >> n;
								user.changeSalaries(id, n);
								system("pause");
								choice = 2;
								break;
							}
							case 6: {
								cout << "The total Earned money untill now is of ruppees : " << user.getEarning() << "\n\n\n\n";
								cout << "\t\t\t\t\n===============================================================================\n";
								cout << "\t\t\t\tSALES UPDATES \n===============================================================================\n";
								user.getStock().displaySoldPdts();
								cout << "\t\t\t\t\n===============================================================================\n";
								cout << "\t\t\t\tRETURN UPDATES \n===============================================================================\n";
								user.getStock().displayReturnPdts();
								cout << "\n\n\n\n";
								system("pause");
								break;
							}
							case 7: {
								user.emptyStaff();
								user.resetStock();
								cout << "\t\t\t\tSystem Reseted\n-------------------------------------------------------------------------------\n\n\n\n";
								system("pause");
								break;
							}
							case 8: {
								choice = 1;
								break;
							}
							case 9: {
								return 0;
							}
							default: {
								system("cls");
								cout << "\n\n\t\t\t\t\tInvalid Input \n\t\t\t\t\t Enter Again\n\n" << endl;
								system("pause");
								choice = 2;
							}
							}
						}
					}
		else
		{
		system("cls");
		cout << "\t\t\t\tINVALID PASSWORD\n"
			<< "\t\t\tPassword hint :" << user.Administration::getWord().passwordHint() << "\n\n\n\n";
		system("pause");
		}
		choice = 1;
		break;
		}

		case 4: {
			  			
			system("cls");
			  			
			string staff[3] = { "Personal info","Attendence","Back" };
			  			
			choice = 2;
			  			
			while (choice == 2)
			  			
			{
			  				
				switch (menu("STAFF MEMBER MENU", staff, 3,7)) {
			  				
				case 1:
			  					
					int id;
			  					
					cout << "\t\t\t\tStaff Member Detail\n-------------------------------------------------------------------------------\n";
			  					
					cout << "\n\nEnter id of member to be displayed : "; cin >> id;
			  					
					if (user.chkId(id)) {
			  						
						user.displayStaffMember(id);
			  					
					}
			  					
					else
			  						
						cout << "\n\n\t\t\t\tINVALID ID\n\n";
			  					
					system("pause");
			  					
					choice = 2;
			  					
					break;
			  				
				case 2:
			  					
					cout << "\t\t\t\tStaff Attendence\n-------------------------------------------------------------------------------\n";
			  					
					cout << "\n\nEnter id of member to mark attendence : "; cin >> id;
			  					
					if (user.markAttendence(id)) {
			  						
						cout << "\n\n\t\t\t\tMarked\n\n";
			  					
					}
			  					
					else
			  						
						cout << "\n\n\t\t\t\tINVALID ID\n\n";
			  					
					system("pause");
			  					
					choice = 2;
			  					
					break;
			  				
				case 3:
			  					
					choice = 1;
			  					
					break;
			  				
				default:
			  					
					system("cls");
			  					
					cout << "\n\n\t\t\t\tINVALID CHOICE\n\n";
			  					
					system("pause");
			  					
					choice = 2;
			  					
					break;
			  				
				}
			  
			  			
			}
		break;
		}

		case 5: {
						
			return 0;
					
		}
					
		default:{
						
			system("cls");
						
			cout << "\n\n\t\t\t\t\tInvalid Input \n\t\t\t\t\t Enter Again\n\n" << endl;
						
			system("pause");
						
			choice = 1;
					
		}

		}
	}
	return 0;
}
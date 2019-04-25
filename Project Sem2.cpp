// Mohd Izzat Bin Mohd Azhar A16CS0086
// Aishah Aini Binti Norazam A16CS0010

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <conio.h>
#include <fstream>

using namespace std;

// GLOBAL MENU VARIABLE
const string menuSet[3] = {"COMBO SET A ", "COMBO SET B ", "COMBO SET C "};
int qtySet[3] = {30, 30, 30};
const double menuPrice[3] = {10, 12, 13};
double setTotal[3] = {0, 0, 0};

string promocode[3] = {"JattKacak", "AishahCantik", "Boomboompaw"};
double promoVal[3] = {10, 15, 25};


int attempt = 3;

class custInfo{
	private:
		string name;
		string contactNumber;
	public:
		custInfo(){ ;}
		custInfo(string Name, string contact)
		{
			name = Name;
			contactNumber = contact;
		}
		
		void setName(string Name){
			name = Name;
		}
		void setContact(string contact){
			contactNumber = contact;
		}
		
		string getName(){
			return name;
		}
		string getContact(){
			return contactNumber;
		}
		void print()
		{
			cout << "		                   Name		: " << name << endl
				 << "		                   Contact No	: " << contactNumber;
		}
};

class infoTakeAway{
	private:
		custInfo info;
		string address;
	public:
		infoTakeAway(string Name, string contact, string addr)
		{
			info.setName(Name);
			info.setContact(contact);
			address = addr;
		}
		string getAddress(){
			return address;
		}
		void print()
		{
			cout << "		                   Name		: " << info.getName() << endl
				 << "		                   Contact No	: " << info.getContact() << endl
				 << "		                   Address	: " << address;
		}
};

// FUNCTION DECLARATION
void customerSec();
void staffSec();
void staffLogin(int *);
void order();
void yourOrder();
void menu();
void updatePromocode();

int main()
{
	cout << endl << endl << endl << endl
		 << "		==============================================================================\n"
		 << "		                                                                              \n"
		 << "		                              WELCOME TO AJ BURGER.CO                         \n"
		 << "		                                   ONLINE SYSTEM                              \n"
		 << "		                                                                              \n"
		 << "		                           306, KOLEJ TUN DR ISMAIL, UTM                      \n"
		 << "		                                 SKUDAI, JOHOR, MY                            \n"
		 << "		                                                                              \n"
		 << "		                          For Any Inquiries +607-554 8941                     \n"
		 << "		                                                                              \n"
		 << "		==============================================================================\n"
		 << "		";
		system("pause");
	menu();
	return 0;
}

void menu()
{
	char opt;	 
	do{
		system("cls");
		cout << endl << endl
			 << "		================================= AJBURGER.CO ================================\n"
			 << "		                                                           >> [ MAIN MENU ] <<\n"
			 << endl 
			 << "		       1. Staff Login                                                         \n"
			 << "		       2. Customer Login                                                      \n"
			 << "		       3. Exit                                                                \n"
			 << endl
			 << "		       Choose your option >> ";
		opt = getch();
		if (opt > '3' || opt < '1')
		{
			cout << endl 
				 << "		       Wrong code. Please Reenter!" << endl
				 << "		       ";
			system("pause");
		}
		if (opt == '0') attempt = 3;
	}while (opt > '3' || opt < '1');
		
	if (opt == '1') staffLogin(&attempt);
	else if (opt == '2') customerSec();
	else exit(1);
}

void staffLogin(int *at)
{
	char adminId[10], adminPw[10], ab;
	do{
		fflush(stdin);
		system("cls");
		cout << endl << endl
			 << "		================================= AJBURGER.CO ================================\n"
			 << "		You have [" << *at << "] Attempt // Enter 99 to Menu                 >> [ STAFF LOGIN ] <<\n"
			 << endl;
		if (*at <= 0) { break; }
		if (*at != 3) { cout <<"		       Your ID/Password does not match. Please reenter.\n";}
		cout << "		       Enter Staff ID		: ";
		cin.getline(adminId, 10);
		if (strcmp(adminId, "99") == 0) { menu(); }
		(*at)--;
		cout << "		       Enter Staff Password	: ";
		for(int mincount=0;mincount<4;mincount++){
			ab = getch();
  			adminPw[mincount] = ab;
  			ab = '*' ;
  			cout << ab;
 		}
 		// adminPw[mincount] = '\0';
 		
		} while ((strcmp(adminId, "Izzat") != 0 && strcmp(adminId, "Aishah") != 0) || strcmp(adminPw, "Pass") != 0);
		
		if ((strcmp(adminId, "Izzat") == 0 || strcmp(adminId, "Aishah") == 0) && strcmp(adminPw, "Pass") == 0){
		attempt = 3;
		staffSec();
		}
			
		else {
		cout << "		       You have exceeded the 3 attempt.\n"
			 << "		       Please consult the person in charge.\n"
			 << endl
			 << "		";
		system ("pause");
		menu ();
		}	
}

void staffSec()
{
	char opt, yesNo;
	int count;
	do{
		system("cls");
		cout << endl << endl
			 << "		================================= AJBURGER.CO ================================\n"
			 << "		                                                       >> [ STAFF SECTION ] <<\n"
			 << endl 
			 << "		       1. Monitor Sale                                                        \n"
			 << "		       2. Promocode                                                           \n"
			 << "		       3. Logout                                                              \n"
			 << endl
			 << "		       Choose your option >> ";
		opt = getch();
		if (opt > '3' || opt < '1')
		{
			cout << endl 
				 << "		       Wrong code. Please Reenter!" << endl
				 << "		       ";
			system("pause");
		}
	}while (opt > '3' || opt < '1');
	
	if (opt == '1')
	{
		system("cls");
		cout << endl << endl
			 << "		================================= AJBURGER.CO ================================\n"
			 << "		                                        >> [ STAFF SECTION / MONITOR SALE ] <<\n"
			 << endl
			 << "		                                 TOTAL EARNING                                \n"
			 << "		     =================================================================        \n"
			 << "		      ITEM                   QTY             PRICE       EARNED MONEY         \n"
			 << "		     =================================================================        \n";
		count = 0;
		do{
			cout << setprecision(2) << fixed << left
				 << "		      " 
				 << setw(24) << menuSet[count] 
				 << setw(12) << qtySet[count] 
				 << "RM " << setw(15) << menuPrice[count] 
				 << "RM " << right << setw(6) << setTotal[count] 
				 << endl;
			count++;
		}while(count < 3);
		cout << "		     =================================================================        \n"
			 << "		                                                    TOTAL   RM " << setw(6) << setTotal[0]+setTotal[1]+setTotal[2] << endl
			 << "		     =================================================================        \n"
			 << "		";
		system ("pause");
		staffSec();
	}
	
	else if (opt == '2')
	{
		updatePromocode();
	}
	else menu();
}

void updatePromocode()
{
	int count, promo, val;
	char yesNo;
	string promoName;
	system ("cls");
		cout << endl << endl
			 << "		================================= AJBURGER.CO ================================\n"
			 << "		                                           >> [ STAFF SECTION / PROMOCODE ] <<\n"
			 << endl
			 << "		                          NO. PROMOCODE      VALUE(%) \n"
			 << "		                         =============================\n";
		count = 0;
		do{
			cout << "		                         " << setw(3) << right << count+1 << ". " << setw(15) << left << promocode[count] << promoVal[count] << endl;
			count++;
		}while(count < 3);
		
		
		do{
		cout << endl
			 << "		                          Update Promocode? [Y]-YES / [N]-NO  " << endl
			 << "		                          >> ";
		yesNo = getch();
		cout << yesNo << endl;
		if (yesNo != 'Y' && yesNo != 'y' && yesNo != 'n' && yesNo != 'N') 
			cout << endl << "		                          Wrong code. Please Reenter!" << endl;
		}while(yesNo != 'Y' && yesNo != 'y' && yesNo != 'n' && yesNo != 'N');
		
		if (yesNo =='y' || yesNo == 'Y' ){
			do{
				cout << endl
					 << "		                          Which slot >> ";
				cin >> promo;
				if (promo < 1 || promo > 3) 
					cout << "		                          Wrong code. Please Reenter!" << endl;
			}while(promo < 1 || promo > 3);
			--promo;
			cout << "		                          Your New Promocode >> ";
			fflush(stdin);
			getline(cin, promoName);
			promocode[promo] = promoName;
			cout << "		                          Your New Promo Value >> ";
			cin >> val;
			promoVal[promo] = val;
			updatePromocode();			
		}
		else staffSec();
		
}

void customerSec()
{
	char opt;
	string name, address, contact;
	
	do{
		system("cls");
		cout << endl << endl
			 << "		================================= AJBURGER.CO ================================\n"
			 << "		Enter 0 to Menu                                    >> [ CUSTOMER SECTION ] <<\n"
			 << endl 
			 << "		       1. Dine In                                                             \n"
			 << "		       2. Delivery                                                            \n"
			 << endl
			 << "		       Choose your option >> ";
		opt = getch();
		if (opt == '0') menu();
		if (opt > '2' || opt < '1')
		{
			cout << endl 
				 << "		       Wrong code. Please Reenter!" << endl
				 << "		       ";
			system("pause");
		}
	}while (opt > '2' || opt < '1');
	
	system("cls");
	cout << endl << endl
		 << "		================================= AJBURGER.CO ================================\n";
	if (opt == '1')
		cout << "		                                                             >> [ DINE IN ] <<\n";
	else
		cout << "		                                                            >> [ DELIVERY ] <<\n";
			 
	cout << "		       Enter Name >> ";
	getline(cin, name);
	cout << "		       Enter Contact Number >> ";
	cin >> contact;
	fflush(stdin);
	if (opt == '2')
	{
		cout << "		       Enter Address >> ";
		getline(cin, address);
	}
	
	if(opt == '1')
	{
		custInfo cust (name, contact);
		order();
		system("cls");
		cout << endl << endl
			 << "		================================= AJBURGER.CO ================================\n"
			 << "		                                                >> [ DINE IN / YOUR ORDER ] <<\n"
			 << endl;
		cust.print();
		yourOrder();
		
	}
	
	else
	{
		infoTakeAway cust(name, contact, address);
		order();
		system("cls");
		cout << endl << endl
			 << "		================================= AJBURGER.CO ================================\n"
			 << "		                                              >> [ DELIVERY / YOUR ORDER ] <<\n"
			 << endl;
		cust.print();
		yourOrder();
		
	}
	
}

void order()
{
	int opt, qty=0;
	double total=0;
	char yesNo;
	
	fstream inFile ("order.txt", ios::out);
	
	cout << endl 
		 << "		==============================================================================\n"
		 << "		                                                             >> [ ORDERING] <<\n"
		 << endl
		 << "		        No.  Name                                            Price     \n"
		 << "		       ================================================================\n"
		 << "		         1.  Combo Set A                                     RM 10.00  \n"
		 << "		               Beef Burger + Fries + Drink                             \n"
		 << "		                                                                       \n"
		 << "		         2.  Combo Set B                                     RM 12.00  \n"
		 << "		               Chicken Burger + Fries + Drink                          \n"
		 << "		                                                                       \n"
		 << "		         3.  Combo Set C                                     RM 13.00  \n"
		 << "		               Fried Chicken + Fries + Drink                           \n"
		 << "		       ================================================================\n"
		 << "		                     All of the set above is Medium sized              \n"
		 << " 		                  Add on RM 1.60 to upgrade for a Large size           \n"
		 << "		       ================================================================\n";
	do{	 
		do{
			cout << endl
				 << "		       What do you want to order?" << endl
				 << "		       Enter code number >> ";
			cin >> opt;
			if (opt < 1 | opt > 3) cout << "		       Wrong code. Please Reenter!" << endl;
			if(qtySet[opt-1] <= 0) cout << "		       Sorry, " << menuSet[opt-1] << "is currently not in stock." << endl;
		}while (opt < 1 | opt > 3 | (qtySet[opt-1] <= 0));
		opt--;
		cout << endl
			 << "		       You have choose " << menuSet[opt] << "."<< endl;
		
		do{
			cout << "		       How many do you want? >> ";
			cin >> qty;
			if(qty > qtySet[opt]) cout << "		       Sorry, " << menuSet[opt] << "have " << qtySet[opt] << " left." << endl;
		}while (qty > qtySet[opt]);
		
		qtySet[opt] -= qty;
		
		do{
			cout << "		       Upgrade to Large? [Y-yes / N-no] >> ";
			yesNo = getch();
			if (yesNo != 'Y' && yesNo != 'y' && yesNo != 'n' && yesNo != 'N') cout << endl << "		       Wrong code. Please Reenter!" << endl;
		}while(yesNo != 'Y' && yesNo != 'y' && yesNo != 'n' && yesNo != 'N');
		cout << yesNo;
		inFile << opt+1 << " " << qty << " ";
		if (yesNo =='y' || yesNo == 'Y' ) inFile << 1 << "\n";
		else inFile << 0  << "\n";
			
		cout << endl << endl 
			 << "		       Add Order? [Y-yes / N-no] >> ";
		yesNo = getch();
		cout << endl;
		if (yesNo != 'Y' && yesNo != 'y' && yesNo != 'n' && yesNo != 'N') cout << endl << "		       Wrong code. Please Reenter!" << endl;
	}while(yesNo == 'Y' || yesNo == 'y');
		

}

void yourOrder()
{
	int set, qty, size, i;
	double price, total = 0;
	char yesNo;
	string promo;
	fstream outFile ("order.txt");
	cout << endl << endl
		 << "		                    QTY ITEM                          PRICE\n"
		 << "		                   ========================================\n";
	while(outFile >> set >> qty >> size)
	{
		price = (menuPrice[set-1]*qty);
		total += price;
		setTotal[set-1] += price;
		cout << setprecision(2) << fixed
			 << "		                   " << right << setw(4) << qty  << " " << setw(21) << left << menuSet[set-1] << setw(9) << right << "RM " << price
			 << endl;
		if(size==1){
		cout << "		                         +LARGE" << setw(24) << "RM " << qty*1.60 << endl;
		total += (qty*1.60);
		setTotal[set-1] += (qty*1.60);
		}
	}
	cout << "		                   ========================================\n"
		 << "		                   SERVICE TAX (3%)" << right << setw(20) << "RM " << total*0.3 << endl;
	setTotal[set-1] += (total*0.3);
	total *= 1.3;
	cout << "		                   TOTAL" << right << setw(30) << "RM " << total 
		 << endl;
	do{
		cout << endl
			 << "		                   DO YOU HAVE PROMOCODE [Y]-YES / [N]-NO  \n"
			 << "		                   >> ";
		yesNo = getch();
		if (yesNo != 'Y' && yesNo != 'y' && yesNo != 'n' && yesNo != 'N') 
			cout << endl << "		                   Wrong code. Please Reenter!" << endl;
		}while(yesNo != 'Y' && yesNo != 'y' && yesNo != 'n' && yesNo != 'N');

	if (yesNo =='y' || yesNo == 'Y' ){
		int tru;
		do{
			cout << endl
			 	 << "		                   Enter Promocode >> ";
			fflush(stdin);
			getline(cin, promo);
			i=0;
			
			do{
				if(promo == promocode[i]){
					tru = 1;
				break;
				}
				i++;
			}while(i<3);
	
			if(tru == 1){
				total *= (1-promoVal[i]/100);
				cout << "		                   ========================================\n"
			 		 << "		                   TOTAL AFTER PROMO" << right << setw(18) << "RM " << total
			 		 << endl;
			}
			
			else{
				cout << "		                   Wrong Promocode. Please Reenter! Or 00 to cancel." << endl;
			}
			
		}while(tru != 1);
	}
		
	
	cout << endl << "		                   ";
		system("pause");
	menu();
}

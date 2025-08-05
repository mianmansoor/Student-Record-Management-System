#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

struct Student {

	int enroll;
	int fee = 0;
	double n1 = 0;
	double n2 = 0;
	double n3 = 0;
	double n4 = 0;
	double per = 0;
	double total = 0;
	string name, address, phone, cnic, section;
	Student* left;
	Student* right;

};
Student* root = NULL;

Student* GetNewNode(int enroll,string name,string address,string phone,string cnic,string section)
{
	Student* newNode = new Student();
	newNode->enroll = enroll;
	newNode->name = name;
	newNode->address = address;
	newNode->phone = phone;
	newNode->cnic = cnic;
	newNode->section = section;
	newNode->left = newNode->right = NULL;
	return newNode;
}




Student* Insert(Student*& root, int enroll, string name, string address, string phone, string cnic, string section) 
{

	if (root == NULL) { 
		root = GetNewNode(enroll, name, address, phone, cnic,section);
	}
	else if (enroll == root->enroll)
	{
		cout << "Enrollment Already Exists, Try Again " << endl;
		system("pause");
	}
	else if (enroll < root->enroll) {
		root->left = Insert(root->left, enroll, name, address, phone, cnic,section);
	}
	else {
		root->right = Insert(root->right, enroll, name, address, phone, cnic, section);
	}
	return root;
}

bool Search(Student* root, int enroll) {
	if (root == NULL) {
		return false;
	}
	else if (root->enroll == enroll) {
		cout << "Enrollment: " << root->enroll << endl;  
		cout << "Name: " << root->name << endl;
		cout << "Enrollment: " << root->address << endl;
		cout << "Phone Number: " << root->phone << endl;
		cout << "CNIC: " << root->cnic << endl;
		cout << "---------------------------------------------" << endl;
		cout << "----------------- Results ----------------" << endl;
		cout << "Maths: " << root->n1 << endl;
		cout << "English: " << root->n2 << endl;
		cout << "Science: " << root->n3 << endl;
		cout << "Urdu: " << root->n4 << endl;
		cout << "Total Marks: " << root->total <<" /400"<< endl;
		cout << "Percentage: " << root->per << endl;
		cout << endl;
		system("pause");
		return true;
	}
	else if (enroll <= root->enroll) {
		return Search(root->left, enroll);
	}
	else {
		return Search(root->right, enroll);
	}
}
 Student* Delete(Student *root, int enroll) {
	if (root == NULL) return root;
	else if (enroll < root->enroll) root->left = Delete(root->left, enroll);
	else if (enroll > root->enroll) root->right = Delete(root->right, enroll);
	else {
		// No childs
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
			cout << "Record deleted succesfully!" << endl;
			system("pause");
		}
		// One child 
		else if (root->left == NULL) {
			struct Student *temp = root;
			root = root->right;
			delete temp;
			cout << "Record deleted succesfully!" << endl;
			system("pause");
		}
		else if (root->right == NULL) {
			struct Student *temp = root;
			root = root->left;
			delete temp;
			cout << "Record deleted succesfully!" << endl;
			system("pause");
		}
		// Two child
		else {
			struct Student *temp1 = root->right;
			while (temp1->left != NULL)
				temp1 = temp1->left;
			struct Student *temp = temp1;
			root->enroll = temp->enroll;
			root->right = Delete(root->right, temp->enroll);
		}
	}
	return root;
}

 void ShowAll(Student *root) {
	 if (root == NULL)
	 {
		 return;
	 }

		 ShowAll(root->left);
		 cout << "Enrollment: " << root->enroll << endl;
		 cout << "Name: " << root->name << endl;
		 cout << "Address: " << root->address << endl;
		 cout << "Phone Number: " << root->phone << endl;
		 cout << "CNIC: " << root->cnic << endl;
		 cout << "Section: " << root->section << endl;
		 cout << endl;
		 ShowAll(root->right);

 }
 void Input()
 {
	 int enroll;
	 string name, address, phone, cnic,section;
	 cout << "Enter Enrollment ";
	 cin >> enroll;
	 cin.ignore();
	 cout << "Enter Name: ";
	 getline(cin, name);

	 cout << "Enter Address: ";
	 getline(cin, address);

	 cout << "Enter Phone Number: ";
	 getline(cin, phone);
	 

	 cout << "Enter CNIC: ";
	 getline(cin, cnic);

	 cout << "Enter Section: ";
	 getline(cin, section);
	 cout << endl;
	 Insert(root, enroll, name, address, phone, cnic, section);

 }

bool Result(Student* root, int enroll) {
	 if (root == NULL) {
		 cout << "No Record Found!" << endl;
		 return false;
	 }
	 else if (root->enroll == enroll) {
		 double n1, n2, n3, n4, total, per;
		 cout << "Enter The Result for Roll No. " << root->enroll << endl;  
		 cout << "Enter marks for Maths out of 100: ";
		 cin >> n1;
		 while (n1 > 100)
		 {
			 cout << "Invalid,Enter Marks out of 100: ";
			 cin >> n1;
		 }
		 cout << "Enter marks for English out of 100: ";
		 cin >> n2;
		 while (n2 > 100)
		 {
			 cout << "Invalid,Enter Marks out of 100: ";
			 cin >> n2;
		 }
		 cout << "Enter marks for Science out of 100: ";
		 cin >> n3;
		 while (n3 > 100)
		 {
			 cout << "Invalid,Enter Marks out of 100: ";
			 cin >> n3;
		 }
		 cout << "Enter marks for Urdu out of 100: ";
		 cin >> n4;
		 while (n4 > 100)
		 {
			 cout << "Invalid,Enter Marks out of 100: ";
			 cin >> n4;
		 }
		 total = n1 + n2 + n3 + n4;
		 per = total / 400 * 100;
		 root->n1 = n1;
		 root->n2 = n2;
		 root->n3 = n3;
		 root->n4 = n4;
		 root->total = total;
		 root->per = per;
		 return true;
	 }
	 else if (enroll <= root->enroll) {
		 return Result(root->left, enroll);
	 }
	 else {
		 return Result(root->right, enroll);
	 }
 }

bool Challan(Student* root, int enroll) {
	if (root == NULL) {
		cout << "No Record Found!" << endl;
		return false;
	}
	else if (root->enroll == enroll) {
		int fee, d, m, y, charge;
		cout << "Enter Amount: ";
		cin >> fee;
		root->fee = fee;
		cout << "Enter Due Date in dd/mm/yy format: " << endl;
		cout << "day:" << endl;
		cin >> d;
		cout << "month:" << endl;
		cin >> m;
		cout << "year:" << endl;
		cin >> y;
		cout << "Enter Late submission Fee: ";
		cin >> charge;
		system("cls");
		cout << setw(25) << "******************************** FEE CHALLAN ********************************" << endl;
		cout << setw(50) << "------------ LEADER HIGH SCHOOL ------------" << endl;
		cout << "Enrollment: " << root->enroll << endl;  
		cout << "Name: " << root->name << endl;
		cout << "Phone Number: " << root->phone << endl;
		cout << "CNIC: " << root->cnic << endl;
		cout << "Section: " << root->section << "\n \n" << endl;
		cout << "Amount Payable: " << root->fee << endl;
		cout << "Amount Payable after Due date: " << root->fee + charge << endl << endl;
		cout << "Due Date:  " << d << "/ " << m << "/ " << y << endl;
		cout << "----------------------------------------------------------" << endl;
		system("pause");
		return true;
	}
	else if (enroll <= root->enroll) {
		return Challan(root->left, enroll);
	}
	else {
		return Challan(root->right, enroll);
	}
}
int login(string u, string p)
{
	string u1, p1;
	cout << setw(50) << "------------ LEADER HIGH SCHOOL ------------" << endl;
	cout << "******* STUDENT RECORD MANAGEMENT SYSTEM ********" << endl;
	cout << "Please Enter Your Username / Password to Login:  (Username: user --- Password: asd123  ) " << endl; 
	cout << "Username: ";
	getline(cin, u1);
	int x = u1.compare(u);
	while (x != 0)
	{
		cout << "Invalid Username,Try Again " << endl;
		cout << "Username: ";
		getline(cin, u1);
		x = u1.compare(u);
	}
	    cout << "Password: ";
		getline(cin, p1);
		int x1 = p1.compare(p); 
		while (x1 != 0)
		{
			
			cout << "Invalid Password,Try Again " << endl;
			cout << "Password: ";
			getline(cin, p1);
			x1 = p1.compare(p);
		}
		if (x == 0 && x1 == 0)
		{
			cout << "Login Approved" << endl;
			system("pause");
			system("cls");
			return 1;
		}
}

bool Modify(Student* root, int enroll) {
	if (root == NULL) {
		return false;
	}
	else if (root->enroll == enroll) {
		string name, address, phone, cnic, section;
		cout << "Enter Name: ";
		cin.ignore();
		getline(cin, name);

		cout << "Enter Address: ";
		getline(cin, address);

		cout << "Enter Phone Number: ";
		getline(cin, phone);


		cout << "Enter CNIC: ";
		getline(cin, cnic);

		cout << "Enter Section: ";
		getline(cin, section);
		cout << endl;
		root->name = name;
		root->address = address;
		root->phone = phone;
		root->cnic = cnic;
		root->section = section;
		system("pause");
		return true;
	}
	else if (enroll <= root->enroll) {
		return Modify(root->left, enroll);
	}
	else {
		return Modify(root->right, enroll);
	}
}
int main() {
	int no;
	int x = 0;
	int option = 0;
	string user = "user";
	string pass = "asd123";
	x = login(user, pass);

	while (option != 8 || x != 0)
	{
		cout << setw(50) << "------------ LEADER HIGH SCHOOL ------------" << endl;
		cout << "******* STUDENT RECORD MANAGEMENT SYSTEM ********" << endl;
		cout << "1. Add a Student Record" << endl;
		cout << "2. Search For Records/Results" << endl;
		cout << "3. Delete Node" << endl;
		cout << "4. Display All Records" << endl;
		cout << "5. To Enter Result marks" << endl;
		cout << "6. To generate Fee Challan" << endl;
		cout << "7. To Modify Existing Record" << endl;
		cout << "8. Exit Program" << endl;
		cout << " Enter Your Choice: ";
		cin >> option;
		cout << "----------------------------------------------------------\n" << endl;
		switch (option)
		{
		case 1: 
			Input(); break;
		case 2:
			cout << "Enter enrollment to search: ";
			cin >> no;
			if (Search(root, no) == true) 
				cout << "Found" << endl;
			else cout << "No Record Found" << endl;
			break;
		case 3:
			cout << "Enter Enrollment to Delete: ";
			cin >> no;
			root=Delete(root, no);
			break;
		case 4:
			ShowAll(root);
			system("pause");
			break;
		case 5:
			cout << "Enter a valid Enrollment: ";
			cin >> no;
			Result(root, no);
			break;
		case 6:
			cout << "Enter a valid Enrollment: ";
			cin >> no;
			Challan(root, no);
			break;
		case 7:
			cout << "Enter enrollment to Modify: ";
			cin >> no;
			if (Modify(root, no) == true)
				cout << "Record Modified Succesfully" << endl;
			else cout << "No Record Found" << endl;
			break;
		case 8:
			x = 0;
			break;
		default:
			cout << "Invalid Input, Enter Again!" << endl;
			break;

		}
		system("cls");
	}

	system("pause");
}
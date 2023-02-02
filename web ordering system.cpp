// ------------------------web ordering system------------------
//--------------------------------------------------------------
// group members :
// registration no:                        name:
// 20-NTU-CS-1162                         M . AHMAD
// 20-NTU-CS-1158                         MOEEN ALI
// 20-NTU-CS-1181                         UMAIR ZAHEER
//---------------------------------------------------------------

#include<iostream>
using namespace std;
int createaccount()
{
	string username;
	string password;
		cout<<"Create  account and login \n\n";
		cout<<"please enter a username : ";
		cin>>username;
		cout<<"please enter your password : ";
		cin>>password;
		if(username == "ahmad" && password == "1234"){
			
		}
		else
		{
			cout<<" your username or password is not correct \n";
		}
	}
	void menu()
	{
		cout<<"\n\n\t\t|----------------------------------------|";
		cout<<"\n\t\t\tWELCOME TO OUR RESTURANT";
		cout<<"\n\t\t|----------------------------------------|";
       cout<<" \n\t\twhat would you like to eat? Here this is our delicious menu for you !!!!\n\n";
       cout<<"\t\t1.Burger            ---->: 150\n";
       cout<<"\t\t2.Sandwich          ---->: 100\n";
       cout<<"\t\t3.Biryiani          ---->: 250\n";
       cout<<"\t\t4.Rosted chicken    ---->: 200\n";
       cout<<"\t\t5.Samosa            ---->: 50\n";
       cout<<"\t\t6.Chips             ---->: 50\n";
       cout<<"\t\t7.Shoarma           ---->: 150\n";
       cout<<"\t\t8.Drinks            ---->: 150\n";
       cout<<"\t\t0.FOR ANOTHER MENU \n";
       cout<<"\t\t9.Exit \n";
       
       cout<<"please enter your choice----> : ";
	}
class FoodOrder
{
private:
	int order_id;
	int quantity;
    int total_bill;

public:
void SetID(int order_id)
	{
		this->order_id = order_id;
	}
void Setquantity(int quantity)
	{
		this->quantity = quantity;
	}
void Settotal_bill(int total_bill)
{
	this->total_bill =total_bill;
}
	  FoodOrder()
	{
		order_id=0;
		quantity=0;
		total_bill=0;
	}
FoodOrder(int order_id, int quantity, int total_bill)
	{
		this->order_id =order_id;
		this->quantity = quantity;
		this->total_bill =total_bill;
	}
int GetID()
	{
		return order_id;
	}
	
void GetInfo()
	{
		cout<<"order_id    :   \t" << order_id << endl;
		cout<<"quantity    :   \t" << quantity << endl;
		cout<<"total bill   :  \t" <<total_bill <<endl;
	}
};

class Node
{
private:
	FoodOrder* _data;
	Node* next;

public:
	Node()
	{
		_data = NULL;
		next = NULL;
	}
	void SetData(FoodOrder* Ord)
	{
		_data = Ord;
	}
	void SetNext(Node* next)
	{
		this->next = next;
	}
	FoodOrder* GetData()
	{
		return _data;
	}
	Node* GetNext()
	{
		return next;
	}
};

class LinkList
{
private:
	Node* head;

public:
	LinkList()
	{
		head = NULL;
	}
bool Insert(FoodOrder* Ord)
	{
		Node* newNode = new Node();
		newNode->SetData(Ord);
		newNode->SetNext(NULL);

		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			Node* temp = head;
			while (temp->GetNext() && (temp->GetData())->GetID() != Ord->GetID())
			{
				temp = temp->GetNext();
			}

			if (temp->GetData()->GetID() == Ord->GetID())
			{
				return false;
			}
			else
			{
				temp->SetNext(newNode);
			}
		}
		return true;
	}
bool Delete(int order_id)
	{
		if (head == NULL)
		{
			return false;
		}
		else
		{
			Node* prev = NULL;
			Node* temp = head;
			while (temp && temp->GetData()->GetID() != order_id)
			{
				prev = temp;
				temp = temp->GetNext();
			}
			if (!temp)
				return false;
			if (!prev)
			{
				head = head->GetNext();
			}
			else
			{
				prev->SetNext(NULL);
			}
			delete temp;
			return true; 
		}
	}
void Print()
	{
		if (!head)
		{
			cout << "No order here\n";
			return;
		}
		else
		{
			Node* temp = head;
			while (temp)
			{
				temp->GetData()->GetInfo();
				temp = temp->GetNext();
			}
		}
	}
};
void SetOrder(LinkList* list)
{
	int order_id=0;
   int quantity;
   	int total_bill;
   		
   		cout<<"enter a order_id   : ";
	        cin>>order_id;
	        cout<<"Enter quantity     : ";
	        cin >> quantity;
	        cout<<"\n total bill = "<<150* quantity;
   	 
FoodOrder* Ord = new FoodOrder(order_id,quantity,total_bill);
	if (list->Insert(Ord))
	{
		cout << "\n\nOrder Successfully Done !!!!\n";
		cout<<"\nDelivered you in just 10 minutes !!!please wait !!\n";
		cout<<"\n--------------------------------------------\n";
	}
	else
	{
		cout << "NOT DONE !!!\n";
	}
}
void Cancelorder(LinkList* list)
{
	int order_id;
	cout << "Enter order_id  to  cancel the order: ";
	cin >> order_id;

	if (list->Delete(order_id))
	{
		cout << "order cancel Successfully\n";
	}
	else
	{
		cout << "No ID Found\n";
	}
}
void Print(LinkList* list)
{
	list->Print();
}

int main()
{
	cout<<"\t\t|-------------------------------------------|\n";
	cout<<"\t\t\tWEB ORDERING SYSTEM \n";
	cout<<"\t\t|-------------------------------------------|\n";
	createaccount();
	
	LinkList* list = new LinkList();
	char op;

	int quantity;
     int choice;
     
	while (1)
	{
		system("cls");
		menu();
		cin >> op;

		if (op == '1')
		{    
		system("cls");
			cout<<"\n you have order a burger ---> 150\n";
			cout<<"\n---------------------------------------------\n";
			SetOrder(list);
			
		}
	else if (op == '2')
		{
			system("cls");
			cout<<"\n you have order a sandwich ---> 100\n";
			cout<<"\n---------------------------------------------\n";
			SetOrder(list);
		}
		else if(op == '3')
		{
			system("cls");
		cout<<"\n you have order a Biryiani  ---> 250\n";
		cout<<"\n---------------------------------------------\n";
		SetOrder(list);
		}
		else if(op == '4')
		{
			system("cls");
			cout<<"\n you have order a Rosted chicken  ---> 200\n";
			SetOrder(list);
		}
			else if(op == '5')
		{
			system("cls");
			cout<<"\n you have order a Samosa  ---> 50\n";
			cout<<"\n---------------------------------------------\n";
			SetOrder(list);
		}
			else if(op == '6')
		{
			system("cls");
			cout<<"\n you have order a Chips  ---> 50\n";
			cout<<"\n---------------------------------------------\n";
			SetOrder(list);
		}
			else if(op == '7')
		{
			system("cls");
			cout<<"\n you have order a Shoarma  ---> 150\n";
			cout<<"\n---------------------------------------------\n";
			SetOrder(list);
		}
			else if(op == '8')
		{
			system("cls");
			cout<<"\n you have order a Drinks  ---> 150\n";
			cout<<"\n---------------------------------------------\n";
			SetOrder(list);
		}
			else if(op == '0')
		{
            system("cls");
          cout<<"\t\t1. Cancel the order \n \t\t2. Review the orders\n";
          cin>>choice;
          switch(choice)
     {
     	case 1:
     	Cancelorder(list);
     	break;
     	case 2:
     		Print(list);
     		break;
     		
     		
	 }
		}
		else if(op == '9')
		{
			exit(0);
		}
		
		else
		{
			cout<<"invalid choice !!!!";
		}
		system("pause");
		
		
	}
}

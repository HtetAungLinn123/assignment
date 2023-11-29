#include <iostream>
using namespace std;
void admin();
void customerall();
void guest();
void mainmenu();
int totalcustomer=0;
class Admin
{
	public:
	int total_plan=3;
	string admin_plan[10];
	float admin_plan_price[10], admin_plan_week[10];
	string private_plan;
	float private_cost;
	string compet_plan;
	float compet_cost;
	void getplan()
	{
		for(int i=0;i<total_plan;i++)
		{
			cout<<"enter plan : ";
			cin>>admin_plan[i];
			cout<<"enter price : ";
			cin>>admin_plan_price[i];
			cout<<"enter session : ";
			cin>>admin_plan_week[i];
		}
	}
	void viewplan()
	{
		for(int i=0;i<total_plan;i++)
		{		
				cout<<i+1<<". "<<admin_plan[i]<<"    "<<admin_plan_week[i]<<" sessions per week              "<<admin_plan_price[i]<<endl;	
		}
	}
	void getPrivatePlan()
	{
		cout<<"enter name for tution ::";
		cin>>private_plan;
		cout<<"enter cost ::";
		cin>>private_cost;
	}
	void showPrivatePlan()
	{
		cout<<private_plan<<"   "<<private_cost<<endl;
	}	
	void getCompetPlan()
	{
		cout<<"enter name for competation ::";
		cin>>compet_plan;
		cout<<"enter fee ::";
		cin>>compet_cost;
	}
	void showCompetPlan()
	{
		cout<<compet_plan<<"   "<<compet_cost<<endl;
	}
	
	void update()
	{
		int updatePlan;
		cout<<"choose 1 2 3 to update"<<endl;
		cin>>updatePlan;
		for(int i=updatePlan-1;i<updatePlan;i++)
		{
			cout<<"enter plan :";
			cin>>admin_plan[i];
			cout<<"enter price :";
			cin>>admin_plan_price[i];
			cout<<"enter week :";
			cin>>admin_plan_week[i];
		}
	}
	void ndelete()
	{
		int deletePlan;
    	cout << "Choose the plan number to delete: ";
    	cin >> deletePlan;

    	if (deletePlan <= total_plan && deletePlan >= 1) 
		{        
        	for (int i = deletePlan - 1; i < total_plan - 1; ++i) 
			{
            	admin_plan[i] = admin_plan[i + 1];
            	admin_plan_price[i] = admin_plan_price[i + 1];
            	admin_plan_week[i] = admin_plan_week[i + 1];
        	}
        	total_plan--;
        	cout << "Plan " << deletePlan << " deleted successfully." << endl;
    	} 
		else 
		{
        	cout << "Invalid plan number. No plan deleted." << endl;
    	}
		
	}
};
Admin Admin1;

class Customer:public Admin
{
	public:
		string customer_name;
		int customer_choice_plan;
		float private_week,compet_time,customer_weight,customer_total_cost;
		char participate;
		void getCustomerInfo()
		{
			cout<<"enter your name ";
			cin>>customer_name;
		}
		void showCustomerName()
		{
			cout<<customer_name<<endl;
		}
		void customerPlanChoose(int choice_plan)//give back to training paln 123.
		{
			customer_choice_plan=choice_plan;
		}
		void showCustomerPlan()//show customer what he takes
		{
			cout<<Admin1.admin_plan[customer_choice_plan-1]<<"      price "<<Admin1.admin_plan_price[customer_choice_plan-1]<<"       sessions "<<Admin1.admin_plan_week[customer_choice_plan-1]<<endl;
		}
		void plusTrainPlan()
		{
			customer_total_cost+=Admin1.admin_plan_price[customer_choice_plan-1];
		}
		void plusPrivate()
		{
			char take_private;
			cout<<"do you want to take private tution y for yes :: n for no = ";
			cin>>take_private;
			if(take_private=='y')
			{
				cout<<"enter how many hour private tution note:you can only take 5hours per week"<<endl;
				cin>>private_week;
				if(private_week<=5)
				{
					customer_total_cost+=(Admin1.private_cost*private_week);
				}
				else
				plusPrivate();
			}
			else if(take_private=='n')
			{
				customer_total_cost+=0;
			}
		}
		void showPrivate()
		{
			cout<<"private hour "<<private_week<<endl;
		}
		void getCustomerWeight()
		{
			cout<<"enter your weight ";
			cin>>customer_weight;
			cout<<"do you want to participate y for yes :: n for no ";
			cin>>participate;
			if(participate=='y')
			{
				if(customer_choice_plan==1)
				{
					cout<<"sorry beginner can't participate competation "<<endl;
					Cost();
					totalcustomer++;
					customerall();
				}
				else
				{
					cout<<"\n               Weight Categories\n"<<"Categories                    Upper weight limit (kg)\n"<<"Heavyweight                   Unlimited (Over 100)\n"<<"Light-Heavyweight             100\n"
					<<"Middleweight                  90\n"<<"Light-Middleweight            81\n"<<"Lightweight                   73\n"<<"Flyweight                     66\n"<<endl;
					if(customer_weight>100)
					{
						cout<<"You get Heavyweight"<<endl;
					}
					else if(customer_weight==100)
					{
						cout<<"You get Light-Heavyweight"<<endl;
					}
					else if(customer_weight>=90)
					{
						cout<<"You get Middleweight"<<endl;
					}
					else if(customer_weight>=81)
					{
						cout<<"You get Light-Middleweight"<<endl;
					}
					else if(customer_weight>=73)
					{
						cout<<"You get Lightweight"<<endl;
					}
					else if(customer_weight>=66)
					{
						cout<<"You get Flyweight"<<endl;
					}
				}
			}
			else if(participate=='n')
			{
				cout<<"Ok"<<endl;
				Cost();
				totalcustomer++;
				customerall();
			}
		}
		void showCustomerCompet()
		{
			if(customer_choice_plan==1)
			{
				cout<<customer_weight<<"      "<<" no competition "<<endl;
			}
			else if(customer_choice_plan>1)
			{
				if(customer_weight>100)
					{
						cout<<"weight "<<customer_weight<<"      "<<" Heavyweight"<<endl;
					}
					else if(customer_weight==100)
					{
						cout<<"weight "<<customer_weight<<"      "<<"Light-Heavyweight"<<endl;
					}
					else if(customer_weight>=90)
					{
						cout<<"weight "<<customer_weight<<"      "<<"Middleweight"<<endl;
					}
					else if(customer_weight>=81)
					{
						cout<<"weight "<<customer_weight<<"      "<<"Light-Middleweight"<<endl;
					}
					else if(customer_weight>=73)
					{
						cout<<"weight "<<customer_weight<<"      "<<"Lightweight"<<endl;
					}
					else if(customer_weight>=66)
					{
						cout<<"weight "<<customer_weight<<"      "<<" Flyweight"<<endl;
					}
			}
		}
		void plusCompet()
		{
			cout<<"enter how many competation 1 per "<<Admin1.compet_cost<<endl;
			cin>>compet_time;
			customer_total_cost+=(Admin1.compet_cost*compet_time);
		}
		void showPlusCompet()
		{
			if(customer_choice_plan==1)
			{
				cout<<"no competataion "<<endl;
			}
			else
			{
				cout<<"competation cost= "<<Admin1.compet_cost<<" :: number of competition "<<compet_time<<endl;
			}
		}
		void Cost()
		{
			cout<<"total cost= "<<customer_total_cost<<endl;
		}
};
Customer Customerall[10];
Customer Customer1;
void admin()
{
	int num1;
	cout<<"1.insert\n"<<"2.update\n"<<"3.delete\n"<<"4.view all plan\n"<<"5.menu\n";
	cin>>num1;
	if(num1==1)
	{
		Admin1.getplan();
		Admin1.getPrivatePlan();
		Admin1.getCompetPlan();
		admin();
	}
	else if(num1==2)
	{
		Admin1.update();
		admin();
	}
	else if(num1==3)
	{
		Admin1.ndelete();
		admin();
	}
	else if(num1==4)
	{
		Admin1.viewplan();
		Admin1.showPrivatePlan();
		Admin1.showCompetPlan();
		admin();
	}
	else if(num1==5)
	{
		mainmenu();
	}
}
void countingSortByCost(Customer arr[], int n) 
{
    // Find the maximum cost to determine the range of counting array
    float maxCost = arr[0].customer_total_cost;
    for (int i = 1; i < n; ++i) 
	{
        if (arr[i].customer_total_cost > maxCost) 
		{
            maxCost = arr[i].customer_total_cost;
        }
    }

    // Create a counting array to store the count of each cost
    int range = static_cast<int>(maxCost) + 1;
    int* count = new int[range]();
    Customer* output = new Customer[n];

    // Store count of each cost in the counting array
    for (int i = 0; i < n; ++i) 
	{
        count[static_cast<int>(arr[i].customer_total_cost)]++;
    }

    // Modify the count array to store the actual position of the costs in output array
    for (int i = 1; i < range; ++i) 
	{
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; --i) 
	{
        output[count[static_cast<int>(arr[i].customer_total_cost)] - 1] = arr[i];
        count[static_cast<int>(arr[i].customer_total_cost)]--;
    }

    // Copy the sorted customers back to the original array
    for (int i = 0; i < n; ++i) 
	{
        arr[i] = output[i];
    }

    // Cleanup memory
    delete[] count;
    delete[] output;
}

void customerall()
{
	int customerNum,customer_choose;
	char new_customer;
	cout<<"1.customer info\n"<<"2.view plan\n"<<"3.menu\n"<<"4.info\n"<<endl;
	cin>>customerNum;
	if(customerNum==1)
	{
		for(int i=totalcustomer;i<=totalcustomer;i++)
		{
			Customerall[i].getCustomerInfo();
		}
		  
		Admin1.viewplan();
		cout<<"choose what u like ";
		cin>>customer_choose;
		Customerall[totalcustomer].customerPlanChoose(customer_choose);
		Customerall[totalcustomer].showCustomerPlan();
		Customerall[totalcustomer].plusTrainPlan();
		Customerall[totalcustomer].plusPrivate();
		Customerall[totalcustomer].showPrivate();
		Customerall[totalcustomer].getCustomerWeight();
		Customerall[totalcustomer].showCustomerCompet();
		Customerall[totalcustomer].plusCompet();
		Customerall[totalcustomer].showPlusCompet();
		Customerall[totalcustomer].Cost();	
		totalcustomer++;
		cout<<"new customer y for yes :: n for no "	<<endl;
		cin>>new_customer;
		if(new_customer=='y')
		customerall();
		else if(new_customer=='n')
		mainmenu();
	}
	else if(customerNum==2)
	{
		Admin1.viewplan();
		Admin1.showPrivatePlan();
		Admin1.showCompetPlan();
		customerall();
	}
	else if(customerNum==3)
	{
		mainmenu();
	}
	else if(customerNum==4)
	{
		for(int i=0;i<totalcustomer;i++)
		{
			countingSortByCost(Customerall, totalcustomer);
			Customerall[i].showCustomerName();
			Customerall[i].showCustomerPlan();
			Customerall[i].showPrivate();
			Customerall[i].showCustomerCompet();
			Customerall[i].showPlusCompet();
			Customerall[i].Cost();
			cout<<endl;
			
		}
		customerall();
	}
}
void guest()
{
	Admin1.viewplan();
	Admin1.showPrivatePlan();
	Admin1.showCompetPlan();
	mainmenu();
}
void mainmenu()
{
	int num1;
	cout<<"1.admin\n"<<"2.customer\n"<<"3.guest\n";
	cin>>num1;
	if (num1==1)
	{
		admin();
	}
	else if(num1==2)
	{
		customerall();
	}
	else if(num1==3)
	{
		guest();
	}
}
int main()
{
	mainmenu();
}
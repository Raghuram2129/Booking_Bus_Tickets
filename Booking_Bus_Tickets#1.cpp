#include<bits/stdc++.h>
using namespace std;
class booking_bus_tickets{
	public:
		string name;
		int age;
		string seat;
		string gender;
		void details(string n,int a,string g,string s)
		{
			name=n;
			age=a;
			seat=s;
			gender=g;
		}
};
int main()
{
	vector<booking_bus_tickets>booking_details;
	vector<string>left_side_window_seats{"36"};
			int lw=3,a=0;
			while(lw<32)
			{
				if(lw%3==0)
				{
					left_side_window_seats.push_back(to_string(lw+a));
					a++;
				}
				lw++;
			}
			vector<string>left_side_seats{""};
			int ls=1;
			while(ls<33)
			{
				if(ls%4==0)
				{
					left_side_seats.push_back(to_string(ls));
				}
				ls++;
			}
			vector<string>right_side_seats;
			int rs=1,b=0;
			while(rs<30)
			{
				right_side_seats.push_back(to_string(rs));
				rs+=4;
			}
			right_side_seats.push_back("34");
			vector<string>right_side_window_seats;
			int rw=2;
			while(rw<31)
			{
				right_side_window_seats.push_back(to_string(rw));
				rw+=4;
			}
			right_side_window_seats.push_back("35");
			vector<string>middle_seat;
			int ms=4;
			while(ms<37)
			{
				if(ms%4==0 && ms<33)
				{
					middle_seat.push_back("   ");
				}
				else if(ms%4==0 && ms==36)
				{
					middle_seat.push_back("33");
				}
				ms++;
			}
			vector<vector<string>>bus_layout;
			
			for(int i=0;i<9;i++)
			{
				bus_layout.push_back({left_side_window_seats[i],left_side_seats[i],middle_seat[i],right_side_seats[i],right_side_window_seats[i]});
			}
			set<string>selected_seats;
	int number;
	do{
		cout<<"*******ENTER A NUMBER AS PER YOUR REQUIRMENTS*******\n";
		cout<<"\nENTER 1 TO BOOK YOUR SEAT\n";
		cout<<"\nENTER 2 TO CHECK YOUR BOOKING DETAILS\n";
		cout<<"\nENTER 3 TO EXIT\n";
		cout<<"\n*********************************************\n";
		cout<<"\nENTER THE NUMBER\n";
		cin>>number;
		cin.ignore();
		if(number>4)
		{
			cout<<"\nINVALID NUMBER CHECK AGAIN AND ENTER\n";
		}		
		if(number==1)
		{
			cout<<"\n*******BUS LAYOUT******\n";
			for (auto row : bus_layout)
		    {
		        for (auto seat : row)
		        {
		            cout << setw(4) << seat;
		        }
		        cout << endl;
		    }
		    cout<<"\nENTER NUMBER OF SEATS YOU WISH TO BOOK\n";
		    int number_of_seats;
		    cin>>number_of_seats;
		    cin.ignore();
		    vector<string>selecting_seats;
		    for(int i=0;i<number_of_seats;i++)
		    {
			   	cout<<"\nENTER SEAT NUMBER\n";
		    	string seat_number;
		    	cin>>seat_number;
			   	cin.ignore();
			   	if(stoi(seat_number)>36)
			   	{
			    	cout<<"\nINVALID SEAT NUMBER SELECT AGAIN NUMBER 1 TO 36 \n";
			    	i--;
				}
				if (selected_seats.count(seat_number))
			    {
			        cout << "\nYOU HAVE ALREADY SELECTED THIS SEAT. CHOOSE ANOTHER.\n";
			        i--;
			        continue;
			    }
			   	for(auto& row:bus_layout)
			   	{
			   		for(auto& seat:row)
			   		{
			   			if(seat == seat_number)
			            {
			                seat = "XX";
			                cout << "\nBOOKED SUCCESSFULLY\n";
			                selecting_seats.push_back(seat_number);
			        	}
			        	selected_seats.insert(seat_number);
			        }
				}
			}
			cout<<"\nFILL YOUR DETAILS\n";
			for(int i=0;i<selecting_seats.size();i++)
			{
				cout<<"\nSeat Number : "<<selecting_seats[i]<<endl;
				cout<<"\nENTER NAME\n";
				string name;
				getline(cin,name);
				cout<<"\nENTER AGE\n";
				int age;
				cin>>age;
				cin.ignore();
				cout<<"\nENTER GENDER\n";
				string gender;
				cin>>gender;
				booking_bus_tickets passengers;
				passengers.details(name,age,gender,selecting_seats[i]);
				booking_details.push_back(passengers);
			}
		}
		if(number==2)
		{
			cout<<"\n*******YOUR BOOKING DETAILLS*******\n";
			if(booking_details.empty())
			{
				cout<<"\nNO BOOKING\n";
			}
			else
			{
				for(auto& bd:booking_details)
				{
					cout<<"Seat Number : "<<bd.seat<<"|| Name : "<<bd.name<<"|| Age : "<<bd.age<<"|| Gender : "<<bd.gender<<endl;
				}
			}
		}
		if(number==3)
		{
			cout<<"\nTHANKS FOR BOOKING\n";
			cout<<"\n**********HAPPY JOURNEY**********\n";
		}
	}while(number!=3);
}
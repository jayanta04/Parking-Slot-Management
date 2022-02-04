//CAR PARKING LOT 
//USING C++

#include<bits/stdc++.h>
using namespace std;
class CarParking
{
    int totalslot,totalcar;
    string carNoValidation()
    {                                                                                   //  CAR  NUMBER VALIDATION 
        int c=1;
        string carno;
        while(c)
        {
            cout<<" \t\t\tEnter car no :";                                       // CAR NUMBER FORMAT KA-04-TY-3469
            cin>>carno;
            if(carno.size()==13)
            {
                for(int i=0;i<13;i++)
                {
                    if(i<2 || (i>5 && i<8 ))
                    {
                        if(carno[i]>64 && carno[i]<=90)
                        {
                            c=0;
                        }
                        else
                        {
                            c=1;
                            cout<<"\n\t\t\tWrong Car no\n";
                            break;
                        }
                    }
                    if((i>2 && i<5 ) || i>8)
                    {
                        if(carno[i]>47 && carno[i]<=57)
                        {
                            c=0;
                        }
                        else
                        {
                            c=1;
                            cout<<"\n\t\t\tWrong Car no\n";
                            break;
                        }
                    }
                    if(i==2 || i==5 || i==8)
                    {
                        if(carno[i]=='-')
                        {
                            c=0;
                        }
                        else
                        {
                            c=1;
                            cout<<"\n\t\t\tWrong Car no\n";
                            break;
                        }
                    }
                }
            }
            else
            {
                cout<<"\n\t\t\tWrong Car no\n";
            }
        }
        
        return carno;
    }
    void carEntry(vector<string>&carsNo,vector<int>&carsSlot,vector<string>&carsColor)                  //  NEW CAR ENTRY 
    {
        if(totalcar<totalslot)
        {
            int c=1;
            string carno;
            string color;
            while(c)
            {
                c=0;
                carno=carNoValidation();
                for(int i=0;i<totalslot;i++)
                {
                    if(carno==carsNo[i])
                    {
                        c=1;
                        cout<<"\n \t\t\tCar already in Parking Area \n";
                        return;
                    }
                }
            }
            cout<<"\n \t\t\tEnter Color : ";
            cin>>color;
            for(int i=0;i<totalslot;i++)
            {
                if(carsSlot[i]==0)
                {
                    carsSlot[i]=i+1;
                    carsNo[i]=carno;
                    carsColor[i]=color;
                    totalcar++;
                    string key=carno+color;
                    cout<<"\n\t\t\tTicket number is "<<key<<"\n";
                    cout<<"\n\t\t\tSlot number is "<<i+1<<"\n";
                    break;
                }
            }
        }
        else
        {
            cout<<"\n\t\t\tParking area is Full\n";
        }
    }
    void LeaveCar(vector<string>&carsNo,vector<int>&carsSlot,vector<string>&carsColor)        // CAR UN PARKING OR LEAVING PARKING AREA
    {
        string carkey,carno,color;
        carno="";
        color="";
        cout<<"Select options.. \n 1 for using Slot no \n 2 for using Key no \n";
        cout<<"\t\t\tEnter  : ";
        int c1;
        cin>>c1;
        if(c1==1)
        {
            cout<<"Enter Slot no : ";
            int sltno;
            cin>>sltno;
            if(sltno<=totalslot && sltno>0)
            {
                if(carsSlot[sltno-1]!=0)
                {
                    totalcar--;
                    carsNo[sltno-1]="";
                    carsColor[sltno-1]="";
                    carsSlot[sltno-1]=0;
                    cout<<"\n\t\t\tCar Leave Successfully..\n";
                }
                else
                {
                    cout<<"Slot is already Empty";
                }
            }
            else
            {
                cout<<"\n\t\tSlot is not Exisist\n";
            }
        }
        else if(c1==2)
        {
            cout<<"\t\t\tEnter Car kye : ";
            cin>>carkey;
                if(carkey.size()>15)
            {
                for(int i=0;i<carkey.size();i++)
                {
                    if(i<13)                           //KA-01-HH-1234
                    {
                        carno+=carkey[i];
                    }
                    else
                    {
                        color+=carkey[i];
                    }
                }
            }
            else
            {
                cout<<"\n\t\t\tWrong Carkey\n";
                return;
            }
            //cout<<"\n car no : "<<carno<<"\n color :"<<color<<"\n";
            int f;
            for(int i=0;i<totalslot;i++)
            {
                if(carsNo[i]==carno)
                {
                    //cout<<"\n"<<carsColor[i]<<"\n";
                    string s1=color;
                    string s2=carsColor[i];
                    if(s1==s2)
                    {
                        
                        totalcar--;
                        carsNo[i]="";
                        carsColor[i]="";
                        carsSlot[i]=0;
                        cout<<"\n\t\t\tCar Leave Successfully..\n";
                        cout<<"\n\t\t\tSlot Number : "<<i+1;
                        f=1;
                        break;
                    }
                    else
                    {
                        cout<<"\n\t\t\tColor Not Matched\n";
                        break;
                    }
                }
                else
                {
                    f=0;
                }
            }
            if(f==0)
            {
                cout<<"\n\t\t\tWrong Car Number\n";
            }
        }
        else
        {
            cout<<"\nWrong Input\n";
        }
        
    }
    void Availability()                                                                 // CHECK PARKING AREA IS FULL OR NOT
    {
        int val=0;
        (totalslot-totalcar>0)?cout<<"\n \t\t\tAvailable number of slots : "<<(totalslot-totalcar)<<"\n":cout<<"\n\t\t\tParking Area is full\n";
        
    }
    void SearchCar(vector<string>&carsNo,vector<int>&carsSlot,vector<string>&carsColor)                  
    {
         string carkey,carno,color;
        carno="";
        color="";
        cout<<"\n\n\t\tSelect options.. \n\t\t\t 1 for using Slot no \n\t\t\t 2 for using Key no \n";
        cout<<"\t\t\tEnter  : ";
        int c1;
        cin>>c1;                                                                            // SEARCHING CAR AND SLOT NUMBER
        if(c1==1)
        {
            cout<<"\t\t\tEnter Slot no : ";
            int sltno;
            cin>>sltno;
            if(sltno<=totalslot && sltno>0)
            {
                if(carsSlot[sltno-1]!=0)
                {
                    cout<<"\n\t\t\tCar Founded..\n";
                    cout<<"\n\t\t\tCar Number is : "<<carsNo[sltno-1];
                }
                else
                {
                    cout<<"\t\t\tSlot is already Empty";
                }
            }
            else
            {
                cout<<"\n\t\tSlot is not Exisist\n";
            }
        }
        else if(c1==2)
        {
            cout<<"\t\t\tEnter Car kye : ";
            cin>>carkey;
                if(carkey.size()>15)
            {
                for(int i=0;i<carkey.size();i++)
                {
                    if(i<13)                           //KA-01-HH-1234
                    {
                        carno+=carkey[i];
                    }
                    else
                    {
                        color+=carkey[i];
                    }
                }
            }
            else
            {
                cout<<"\n\t\t\tWrong Carkey\n";
                return;
            }
            //cout<<"\n car no : "<<carno<<"\n color :"<<color<<"\n";
            int f;
            for(int i=0;i<totalslot;i++)
            {
                if(carsNo[i]==carno)
                {
                    //cout<<"\n"<<carsColor[i]<<"\n";
                    string s1=color;
                    string s2=carsColor[i];
                    if(s1==s2)
                    {
                        cout<<"\n\t\t\tCar Founded..\n";
                        cout<<"\n\t\t\tSlot Number : "<<i+1;
                        f=1;
                        break;
                    }
                    else
                    {
                        cout<<"\n\t\t\tColor Not Matched\n";
                        break;
                    }
                }
                else
                {
                    f=0;
                }
            }
            if(f==0)
            {
                cout<<"\n\t\t\tWrong Car Number\n";
            }
        }
        else
        {
            cout<<"\nWrong Input\n";
        }


    }
    void ListofCars(vector<string>&carsNo,vector<int>&carsSlot,vector<string>&carsColor)              // LIST OF CAR IN THE PARKING AREA
    {
        if(totalcar!=0)
        {                                                       //Reg No. | Color | Slot No
            cout<<"\nSlot No\tReg No\t\tColor\tkey\n";
            for(int i=0;i<totalslot;i++)
            {
                if(carsSlot[i]!=0)
                {
                    cout<<"\n"<<carsSlot[i]<<"\t"<<carsNo[i]<<"\t"<<carsColor[i]<<"\t"<<carsNo[i]<<carsColor[i];
                }
            }
            cout<<"\n";
        }
        else
        {
            cout<<"\n \t\t\tParking is Empty\n";
        }
        
    }
    set<int> getRandSlots(int n, int m)                             // RANDOM SLOTS SELLECTION
    {
        set<int>rv;
        while(rv.size()!=m)
        {
            int x=rand()%n;
            rv.insert(x);
        }
        return rv;
        
    }
    string getColor()
    {
        string Colors[] = {"Black", "White", "Blue", "Red"};                // RANDOM COLOR SELLECTION
        int m = rand();
        m = m % 4;
        return Colors[m];
    }
    //to get random reg no
    char getRanChar()
    {
        int m = rand();         
        m = m % 26;
        char ch = 65 + m;
        return ch;
    }
    int getRandigit()
    {
        return rand() % 10;
    }
    string getRegNo(vector<string>carsNo)
    {
        int c=1;
        string res;
        while(c)                                                    // Format : KA-01-HH-1234
        {
            c=0;                                                    // RANDOM CAR NUMBER GENREATION
            for (int i = 1; i <= 2; i++)
            {
                res.push_back(getRanChar());
            }
            res.push_back('-');

            for (int i = 1; i <= 2; i++)
            {
                int x = getRandigit();
                res += to_string(x);
            }
            res.push_back('-');
            for (int i = 1; i <= 2; i++)
            {
                res.push_back(getRanChar());
            }
            res.push_back('-');
            for (int i = 1; i <= 4; i++)
            {
                int x = getRandigit();
                res += to_string(x);
            }
            for(int i=0;i<totalslot;i++)
            {
                if(res==carsNo[i])
                {
                    c=1;
                }
            }
        }
        return res;
    }
    public:
    void control(int n,int m)                                                // CONTROLLING FUNCTION
    {
        totalcar=m;
        totalslot=n;
        int c=1;
        vector<string>carsNo(n,"");
        vector<string>carsColor(n,"");
        vector<int>carsSlot(n,0);
        set<int>rv=getRandSlots(n,m);
        set<int>::iterator itr;
        for (itr = rv.begin(); itr != rv.end(); itr++)
        {
            string cno=getRegNo(carsNo);
            string clr=getColor();
            carsNo[*itr]=cno;
            carsColor[*itr]=clr;
            carsSlot[*itr]=*itr+1;
        }
        while(c)
        {
            cout<<"\n\n......  Your Choice   .......\n\n";
            cout<<" 1 -> for Car Entry\n";
            cout<<" 2 -> for Leave\n";
            cout<<" 3 -> for Check Availability\n";
            cout<<" 4 -> for Search Car\n";
            cout<<" 5 -> for List of the cars\n";
            cout<<" 6 -> for Exit\n";
            cout<<"Enter Your Choice :  ";
            int choice;
            cin>>choice;
            switch(choice)
            {
                case 1 :
                    carEntry(carsNo,carsSlot,carsColor);
                    break;
                case 2 :
                    LeaveCar(carsNo,carsSlot,carsColor);
                    break;
                case 3 :
                    Availability();
                    break;
                case 4 :
                    SearchCar(carsNo,carsSlot,carsColor);
                    break;
                case 5 :
                    ListofCars(carsNo,carsSlot,carsColor);
                    break;
                case 6 :
                    c=0;
                    break;
                default :
                    cout<<"\n\t\t\t Input is Wrong";
                    break;
                
            }
        }
    }
};

int main()                                                                              // MAIN
{
    int n,m;
    cout<<"\n\n\n\t\tEnter Total no of spacr : ";
    cin>>n;
    cout<<"\t\tEnter initial number of car  : ";
    cin>>m;
    CarParking p;
    if(n>m)                                                         
        p.control(n,m);
    else
        cout<<"\nInitial number of Slots can not be grater then Total slots\n";
    cout<<"\n\t\t\t............Thank You...........";
    return 0;
}
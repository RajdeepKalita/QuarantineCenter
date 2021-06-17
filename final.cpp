#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//Declaring a structure.
struct patient{
string name,address,coming_from,going_to,arrival_date;
int age,alloted_room_no;



};
//Applying binary search algorithm.
 int binarySearch(vector<patient> arr, string x,int n)
    {
        int l = 0 ;
        int r = n - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;

        int res;
        if (x == (arr[m].name))
            res = 0;


            // Check if x is present at mid
            if (res == 0)
                return m;

            // If x greater, ignore left half
            if (x > (arr[m].name))
                l = m + 1;

            // If x is smaller, ignore right half
            else
                r = m - 1;
        }

        return -1;
    }
    //Applying sorting algorithm.
bool compareroom(patient r1,patient r2){
if(r1.alloted_room_no<r2.alloted_room_no){
    return 1;
}
return 0;


}




int main(){
    bool ok=true;
    string temp;
    queue<int>q1;                 //q1 is the queue where the room numbers are stored.
    for(int i=89;i<=588;i++){
        q1.push(i);
    }
    queue<patient>q2;                //q2 is the queue where the details of the present patient are stored.
    int a[589]={0};                  // a is the array where the no of days of being quarantined is being stored
    patient p;
    vector<patient>v;               //v is the vector where details of all patients are stored.
    vector<patient>sor;              //sor is the vector used for sorting according to room no.
    int index=0;
    while(ok==true){
            for(int i=0;i<589;i++){
                if(a[i]!=0&&a[i]<14){      //checking if the quarantine period is over
                    a[i]++;
                }
                else if(a[i]>=14){
                    q1.push(i);
                    q2.pop();
                    a[i]=0;
                }
            }
            int d,m,y;
            char ch='/';
            cout<<"Enter today's date"<<endl;
            cin>>d>>ch>>m>>ch>>y;
            cout<<"Do you want to enter more patients"<<endl;
            string ans1;
            cin>>ans1;
            if(ans1=="yes"){
                cout<<"How many patients do you want to enter"<<endl;
                int n1;
                cin>>n1;
                for(int i=0;i<n1;i++){
                    cout<<"Enter the patient's name"<<endl;
                    cin>>p.name;
                    cout<<"Enter the patient's age"<<endl;
                    cin>>p.age;
                    if(q1.size()==0){
                        cout<<"Not sufficient rooms"<<endl;
                    }
                    else{
                    p.alloted_room_no=q1.front();
                    cout<<"Alloted room no is: ";
                    cout<<p.alloted_room_no<<endl;
                    a[p.alloted_room_no]++;
                    q1.pop();
                    q2.push(p);
                    v.push_back(p);
                    sor.push_back(p);
                    cout<<"Enter the Arrival date "<<endl;
                    cin>>p.arrival_date;
                    cout<<"Enter the location patient is coming from"<<endl;
                    cin>>p.coming_from;
                    cout<<"Enter the location the patient was going to"<<endl;
                    cin>>p.going_to;

                    }}



                cout<<"So the alloted rooms are"<<endl;
                for(int i=0;i<589;i++){                    //displaying the allocated rooms
                    if(a[i]>0){
                        cout<<i<<endl;
                    }
                }
            }
            cout<<"Do want to know which rooms are empty?"<<endl;
            string ans6;
            cin>>ans6;
            if(ans6=="yes"){
                cout<<"The empty rooms are"<<endl;
                for(int i=89;i<=588;i++){
                    if(a[i]==0){                      //displaying the empty rooms
                        cout<<i<<endl;
                    }
                }
            }

                cout<<"Do you want to search for someone's details"<<endl;
                string ans2;
                cin>>ans2;
                if(ans2=="yes"){
                       for(int i=0;i<v.size();i++){
                            for(int j=i+1;j<v.size();j++){
                                if(v[i].name>v[j].name){
                                    temp = v[i].name;
                                    v[i].name = v[j].name;
                                    v[j].name = temp;
                                }
                            }
                        }

                    cout<<"Enter the patient's name"<<endl;
                    string ans3;
                    cin>>ans3;

                    int result=binarySearch(v, ans3,v.size()); //calling for binary search function
                    if(result==-1){
                        cout<<"The mentioned patient is/was not present in our quarantine centre"<<endl;
                    }

                    cout<<"The patient's name is "<<'\n'<<v[result].name<<'\n'<<"The patient's age is"<<'\n'
                    <<v[result].age<<'\n'<<"The patient's alloted room no is "<<'\n'<<v[result].alloted_room_no<<'\n'<<
                    "The arrival date of the patient was "<<'\n'<<v[result].arrival_date<<'\n'<<"The patient was coming from"<<'\n'
                    <<v[result].coming_from<<'\n'<<"The patient was going to"<<'\n'<<v[result].going_to<<endl;


                }

                    cout<<"Do you want to sort the patient's details according to room no"<<endl;
                    string ans4;
                    cin>>ans4;
                    if(ans4=="yes"){
                        cout<<"Okay here's the sorted names of patients according to room no "<<endl;
                        sort(sor.begin(),sor.end(),compareroom);   //sorting patient's name according to room number allocated
                        for(int i=0;i<sor.size();i++){
                            cout<<sor[i].name<<endl;
                        }

                    }

                        cout<<"Do you want to turn off the software"<<endl;
                        string ans5;
                        cin>>ans5;
                        if(ans5=="yes"){            //asking if user wants to continue for the next day
                            ok=false;
                        }
                        else
                            ok=true;
                    }

                }





























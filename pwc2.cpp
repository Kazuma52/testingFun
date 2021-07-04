#include <iostream>
#include <thread>

using namespace std;

void incomeTax (float& income) {
	float federalTax = income*.084;
	float cantonalCommunal = income*.1604;

	cout<<"Federal Tax owed is: "<<federalTax<<endl;
	cout<<"Cantonal and Communal Tax owed is: "<<cantonalCommunal<<endl; 

	income = federalTax+cantonalCommunal;
}

void capitalTax (float& equity) {
	float equityTax = equity*.0017;
	cout<<"Capital Tax owed is: "<<equityTax<<endl;

	equity = equityTax; 
}

int main(int argc, char* argv[]){
	float income = atof(argv[1])-atof(argv[1])*.206946;
	float equity = atof(argv[2])-atof(argv[1])*.206946+10000000;

    cout<<"\nYour taxes if the 10m is classified under Equity:"<<endl;
    cout<<"\nTotal tax expenses: "<<atof(argv[1])*.206946<<endl;
    
    thread cap (capitalTax, ref(equity));
    thread inc (incomeTax, ref(income)); 

    inc.join();
    cap.join();
    
    cout<<"Totaling: "<<income+equity<<endl;

    cout<<"----------------------------------------------"<<endl;

    cout<<"\nYour taxes if the 10m is classified under Income:"<<endl;

    income = (atof(argv[1])+10000000)-(atof(argv[1])+10000000)*.206946;
	equity = atof(argv[2])-atof(argv[1])*.206946;

    cout<<"\nTotal tax expenses: "<<(atof(argv[1])+10000000)*.206946<<endl;
    
    thread cap2 (capitalTax, ref(equity));
    thread inc2 (incomeTax, ref(income)); 

    inc2.join();
    cap2.join();
    
    cout<<"Totaling: "<<income+equity<<endl;

    
    return 0;
}

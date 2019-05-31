#include <iostream>
#include <cmath> 
#include <stack> 
#include <cstdlib>

using namespace std;

main() {
    int *wait = new int[500];
    double averagewaiting = 0;
    int allwait = 0;
    int P[60] = { } ;
    int A = 60*70/100;
    int B = 60*20/100;
    int C = 60*10/100;
    int a =0,b=0,c=0;
    int Time = 4;
    cout << A << " " << B << " " << C << endl;
    int i = 0;
    while(1){
        int k = rand()%3;
        if(k == 0 && a < A){
            P[i] = 2 + (rand()%6) + 1  ;
            a++;
            i++;
        }else if(k == 1 && b < B){
            P[i] = 20 + (rand()%10) + 1 ;     
            b++;
            i++;
        }else if(k == 2 && c < C){
            P[i] = 35 + (rand()%5) + 1 ;   
            c++;
            i++;
        }else if(a+b+c == 60){
            break;
        }else{
            continue;
        }
    }

    i = 0;
    int j = 0;
    while (1) 
    { 
        int sum = 0;
        if( i >= 60 ){
            i = 0;
            continue;
        }
        if(P[i] <= 0 ){
            i++;
            continue;
        }
        if(P[i] >= Time){
            wait[j] = Time;
        }else{
            wait[j] = P[i];
        }
        
        cout << "P" << i <<" : "<< P[i] ;
        P[i] -= wait[j];
        averagewaiting += allwait;
        cout  << " wait : "<< allwait << " milisec" << endl; 
        allwait += wait[j];
        i++;
        j++;
        for(int k = 0 ; k < 60 ; k++){
        	sum += P[k];
        	cout << P[k] << " " ;
		}
		cout <<" " <<  sum << endl;
		if(sum == 0){
			break;
		}
    } 
        cout << averagewaiting << endl;
    averagewaiting /= 60;
    cout <<"Average waiting time = " << averagewaiting << " milisec";
}

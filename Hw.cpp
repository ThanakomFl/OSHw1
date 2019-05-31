#include <iostream>
#include <cmath> 
#include <stack> 
#include <cstdlib>
#include <iterator> 
#include <map> 
#include <algorithm> 
#include <time.h>      

using namespace std;

typedef pair<int, int> MyPairType;
struct CompareSecond
{
    bool operator()(const MyPairType& left, const MyPairType& right) const
    {
        return left.second < right.second;
    }
};

void FCFS(stack <int> P,int Process){
    int waiting[Process];
    double averagewaiting = 0;
    int allwait = 0;
    int s = 0;
    s = P.size();
    int i = 0;
    while (!P.empty()) 
    { 
        waiting[i] = P.top();
        averagewaiting += allwait;
        //cout << "P" << i <<" : "<< P.top()  << " wait : "<< allwait << " milisec" << endl; 
        allwait += waiting[i];
        i++;
        P.pop();
    } 
    averagewaiting /= s;
    cout <<"(FCFS) Average waiting time = " << averagewaiting << " milisec" << endl;
}

void SJF(map<int, int> P){
    int waiting[60];
    double averagewaiting = 0;
    int allwait = 0;
    int s = 0;

    s = P.size();
    while(P.size() != 0){ 
    	pair<int, int> min = *min_element(P.begin(), P.end(), CompareSecond());
    	averagewaiting += allwait;
        //cout << "P" << min.first <<" : "<< min.second  << " wait : "<< allwait <<" milisec" << endl; 
        allwait += min.second;
        P.erase(min.first);
    } 
    
    averagewaiting /= s;
    cout <<"(SJF) Average waiting time = " << averagewaiting << " milisec" << endl;
}

void RB(int P[],int Process){
    int *wait = new int[500];
    double averagewaiting = 0;
    int allwait = 0;
    int Time = 4;
    int i = 0;
    int j = 0;
    while (1) 
    { 
        int sum = 0;
        if( i >= Process ){
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
        
        //cout << "P" << i <<" : "<< P[i] ;
        P[i] -= wait[j];
        averagewaiting += allwait;
        //cout  << " wait : "<< allwait << " milisec" << endl; 
        allwait += wait[j];
        i++;
        j++;
        for(int k = 0 ; k < Process ; k++){
        	sum += P[k];
        	//cout << P[k] << " " ;
		}
        //cout << endl;
		if(sum == 0){
			break;
		}
    } 
    averagewaiting /= Process;
    cout <<"(RB) Average waiting time = " << averagewaiting << " milisec";
}

main() {
    stack <int> P1 ;
    map<int, int> P2; 
    int Process = 60;
    int P3[Process] = {25, 36, 25, 7, 24, 35, 28, 2, 35, 40, 6, 4, 5, 25, 30, 40, 23, 4, 23, 2, 28, 39, 3, 27, 30, 37, 37, 5, 26, 4, 6, 5, 7, 8, 8, 3, 3, 8, 7, 6};
    int A = Process*50/100;  /// Process A
    int B = Process*30/100;  /// Process B
    int C = Process*20/100;  /// Process C
    int a =0,b=0,c=0;
    int i = 0;
    srand (time(0));
    //cout << A << " " << B << " " << C << endl;
    /*while(1){
        int k = rand()%3;
        if(k == 0 && a < A){
            P1.push(2 + (rand()%6) + 1 ) ;
            P2.insert(pair<int, int>(a+b+c,2 + (rand()%10) + 1));
            P3[i] = 2 + (rand()%6) + 1  ;
            a++;
            i++;
        }else if(k == 1 && b < B){
            P1.push(20 + (rand()%10) + 1) ;     
            P2.insert(pair<int, int>(a+b+c,20 + (rand()%10) + 1));
            P3[i] = 20 + (rand()%10) + 1 ;   
            b++;
            i++;
        }else if(k == 2 && c < C){
            P1.push(35 + (rand()%5) + 1 );   
            P2.insert(pair<int, int>(a+b+c,35 + (rand()%10) + 1));
            P3[i] = 35 + (rand()%5) + 1 ;   
            c++;
            i++;
        }else if(a+b+c == Process){
            break;
        }else{
            continue;
        }
    }*/
    cout << "Dataset : " ;
    for(int k = 0 ; k < Process ; k++){
        	cout << P3[k] << " " ;
        	P1.push(P3[k]);
        	P2.insert(pair<int, int>(k,P3[k]));
	}
    cout << endl ;
    FCFS(P1,Process);
    SJF(P2);
    RB(P3,Process);
}

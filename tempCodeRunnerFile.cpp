#include <iostream>
#include <cmath> 
#include <iterator> 
#include <map> 
#include <cstdlib>
#include <algorithm> 

using namespace std;

typedef pair<int, int> MyPairType;
struct CompareSecond
{
    bool operator()(const MyPairType& left, const MyPairType& right) const
    {
        return left.second < right.second;
    }
};

main() {
    int waiting[60];
    double averagewaiting = 0;
    int allwait = 0;
    map<int, int> P; 
    int s = 0;
    int A = 60*70/100;
    int B = 60*20/100;
    int C = 60*10/100;
    int a =0,b=0,c=0;
    cout << A << " " << B << " " << C << endl;
    while(1){
        int k = rand()%3;
        if(k == 0 && a < A){
            P.insert(pair<int, int>(a+b+c,2 + (rand()%10) + 1));
            a++;
        }else if(k == 1 && b < B){
            P.insert(pair<int, int>(a+b+c,20 + (rand()%10) + 1));
            b++;
        }else if(k == 2 && c < C){
            P.insert(pair<int, int>(a+b+c,35 + (rand()%10) + 1));
            c++;
        }else if(a+b+c == 60){
            break;
        }else{
            continue;
        }
    }
    s = P.size();
    while(P.size() != 0){ 
    	pair<int, int> min = *min_element(P.begin(), P.end(), CompareSecond());
    	averagewaiting += allwait;
        cout << "P" << min.first <<" : "<< min.second  << " wait : "<< allwait <<" milisec" << endl; 
        allwait += min.second;
        P.erase(min.first);
    } 
    
    averagewaiting /= s;
    cout <<"Average waiting time = " << averagewaiting << " milisec";
}

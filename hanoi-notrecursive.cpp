#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> t[3];
    int n;
    cout << "Please enter a number of rings to move: ";
    cin >> n;
    //intitialize the 3 towers
    for(int i=n+1;i>=1;i--)
        t[0].push_back(i);
    t[1].push_back(n+1);
    t[2].push_back(n+1);
    int from=0;
    int to;
    int disk=1;
    int move = 0;
    if(n % 2 == 1){ //odd number of rings
        to = 1;
        while ((t[1].size()<n+1)){
            cout <<"move number "<<++move<<": Transfer ring " << disk
		<<" from tower "<< from<<" to tower "<< to << endl;
            t[from].pop_back();
            t[to].push_back(disk);
            if(t[(to+1) % 3].back() < t[(to+2) % 3].back())
                from = (to + 1) % 3;
            else
                from = (to + 2) % 3;
            // get next “to tower”
            if(t[from].back() < t[(from + 1) % 3].back() )
                to= (from + 1) % 3;
            else
                to= (from + 2) % 3;
            //get next candidate
            disk = t[from].back();
        }
    }
    else{ // even number of rings
        to = 2;
        while ((t[1].size()<n+1)){
            cout <<"move number "<<++move<<": Transfer ring " << disk <<"from tower "<< from<<" to tower "<<to<<endl;
            t[from].pop_back();
            t[to].push_back(disk);
            if(t[(to+1) % 3].back() < t[(to+2) % 3].back())
                from = (to + 1) % 3;
            else
                from = (to + 2) % 3;
            // get next “to tower”
            if(t[from].back() < t[(from + 2) % 3].back() )
                to= (from + 2) % 3;
            else
                to= (from + 1) % 3;
            //get next candidate
            disk = t[from].back();
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << "Tower " << i << " has ";
        if (t[i].size() == 1) cout << "zero rings";
        for (unsigned long j = t[i].size(); j > 1; j--) {
            cout << "ring "<<t[i].back() << " ";
            t[i].pop_back();
        }
        cout << endl;
    }
}

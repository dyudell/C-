#include <iostream>
using namespace std;

bool okay(int q[], int c) {
	int mp[3][3] = {{0,2,1}, {0,2,1}, {1,2,0}};
	int wp[3][3] = {{2,1,0}, {0,1,2}, {2,0,1}};
	
    for (int i = 0; i < c ; i++)
		if (q[c] == q[i]) return false;
	for (int i = 0; i < c; i++) {	
		if (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < 
wp[q[c]][c])
			return false;
		if (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < 
wp[q[i]][i])
			return false;
	}
	return true;
}

int main () {
	int q[3] = {0}, c = 0;
	int solution = 0;
NC: 
	c++; 
	if (c == 3)
		goto print;
	q[c] = -1;
NR:
	q[c]++;
	if (q[c] == 3)
		goto backtrack;
	
	if(!okay(q,c)) 
		goto NR;
	
	goto NC;

backtrack:
	c--;
	if (c == -1)
		return 0;
	goto NR;

print:
	solution++;
	cout << "Solution Number " << solution << ":" << endl;
	cout << "Man - Woman" << endl;
	for (int i = 0; i < 3; i++) 
		cout << i << " ----- " << q[i] << endl;;
	cout << endl;
	
	goto backtrack;
}



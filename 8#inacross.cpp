#include <iostream>
using namespace std;

bool okay(int q[], int c) {
	static int a[8][5] = 
		{{-1},
		 {0,-1},
		 {0,1,-1},
		 {0,2,-1},
		 {1,2,-1},
		 {1,2,3,4,-1},
		 {2,3,5,-1},
		 {4,5,6,-1}};
	for (int i = 0; i < c; i++) {
		if (q[i] == q[c])
			return false;
	}
	for (int i = 0; a[c][i] != -1; i++) {
		int k = a[c][i];
		if ((q[k] - q[c] == 1) || (q[k] - q[c] == -1))
			return false;
	}
	return true;
}

int main () {
	int cross[8] = {0}, c = 0;
	cross[0] = 1;
	
NC:
	c++;
	if (c == 8) 
		goto print;
	cross[c] = -1;
NR:
	cross[c]++;
	if (cross[c] == 8) 
		goto backtrack;
	
	if (!okay(cross, c))
			goto NR;

	goto NC;

backtrack:
	c--;
	if (c == -1) 
		return 0;
	goto NR;

print:
	cout << " " << cross[1]+1 << cross[4]+1 << endl;
	cout << cross[0]+1 << cross[2]+1 << cross[5]+1 << cross[7]+1 << endl;
	cout << " " << cross[3]+1 << cross[6]+1 << endl;
	cout << endl;	
	goto backtrack;
}	 



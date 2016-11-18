#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int q[8] = {0}, c = 0;
	q[0] = 0;
	int solution=1;
NC: 
	c++;
	if (c == 8) 
		goto print;
	q[c] = -1;
NR:
	q[c]++;
	if (q[c] == 8)
		goto backtrack;
	for (int i = 0; i < c; i++) {
		if (q[c] == q[i] ||  (c-i) == abs(q[c] - q[i]))
			goto NR;
	}
	goto NC;

backtrack:
	c--;
	if (c == -1) 
		return 0;
	goto NR;

print:
	cout << "Solution Number " << solution << ":" << endl;
	for (int i = 0; i < 8; i++) 
		cout << q[i];
	cout << endl << endl;
    solution++;
	goto backtrack;
}



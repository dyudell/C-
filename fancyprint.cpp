#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
	for (int i = 0; i < c; i++) {
		if (q[c] == q[i] || (c-i) == abs(q[c]-q[i]))
			return false;
	}
	return true;
}


int main () {
int q[8] = {0}, c = 0;
int i, j, k, l;
int solution = 0;

q[0] = 0;

NC:
	c++;
	if (c == 8)
		goto print;
	q[c] = -1;
NR:
	q[c]++;
	if (q[c] == 8) 
		goto backtrack;
	
	if(!ok(q,c))
		goto NR;
	goto NC;

backtrack:
	c--;
	if (c == -1) 
		return 0;
	goto NR;

print:
	solution++;
	cout << "Solution number " << solution << ":" << endl;
	
	typedef char box[5][7]; 
	box bb,wb,bq,wq,*board[8][8]; 
	
	for(i=0;i<5;i++) 
		for( j=0;j<7;j++){
			wb[i][j]=' '; 
			bb[i][j]=char(219);
			wq[i][j]= ' ';
			bq[i][j]=char(219);
		}
	
	wq[1][1]=char(219);
	wq[2][1]=char(219);
	wq[3][1]=char(219);
	wq[4][2]=char(219);
	wq[1][3]=char(219);
	wq[2][3]=char(219);
	wq[3][3]=char(219);
	wq[4][3]=char(219);
	wq[4][4]=char(219);
	wq[1][5]=char(219);
	wq[2][5]=char(219);
	wq[3][5]=char(219);

	bq[1][1]=' ';
	bq[2][1]=' ';
	bq[3][1]=' ';
	bq[4][2]=' ';
	bq[1][3]=' ';
	bq[2][3]=' ';
	bq[3][3]=' ';
	bq[4][3]=' ';
	bq[4][4]=' ';
	bq[1][5]=' ';
	bq[2][5]=' ';
	bq[3][5]=' ';

	for (i = 0; i <8; i++){
		for (j = 0; j <8; j++){
			if ((i+j)%2 == 0){
				if (q[j] == i)
					board[i][j] = &wq;
				else 
					board[i][j] = &wb;
			}
			else {
				if (q[j] == i) 
					board[i][j] =&bq;
				else
					board[i][j] =&bb;
			}
		}
	}

	cout << " ";
		for (i = 0; i < 7*8;i++)
			cout << '_';
		cout << endl;
	for (i = 0; i < 8; i++)
		for (k = 0; k < 5; k++) {
			cout << " " << char(179);
			for (j = 0; j < 8; j++) 
				for (l = 0; l <7; l++) 
				cout << (*board[i][j])[k][l];
			cout << char(179) << endl;
		}
	cout << " ";
	for (i = 0; i < 7*8; i++)
		cout << char(196);
		cout << endl;
	
	goto backtrack;
} 


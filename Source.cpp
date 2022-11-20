#include <iostream>
using namespace std;

int main() {
	int numProcesses, numResources;
	int i, j, k;

	numProcesses = 5;
	numResources = 3;
	
	int allocation[5][3] = { {0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2} };
	int max[5][3] = { {7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3} };
	int available[3] = { 3,3,2 };

	int arr[5], answer[5], independent = 0;

	for (k = 0; k < numProcesses; k++) {
		arr[k] = 0;
	}

	int need[5][3];

	for (i = 0; i < numProcesses; i++) {
		for (j = 0; j < numResources; j++) {
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}

	int y = 0;

	for (k = 0; k < 5; k++) {
		for (i = 0; i < numProcesses; i++) {
			if (arr[i] == 0) {
				int value = 0;
				for (j = 0; j < numResources; j++) {
					if (need[i][j] > available[j]) {
						value = 1;
						break;
					} // end if
				}
				if (value == 0) {
					answer[independent++] = i;
					for (y = 0; y < numResources; y++) {
						available[y] += allocation[i][y];
					}
					arr[i] = 1;
				}
			}
		}
	}
	int value = 1;

	for (int i = 0; i < numProcesses; i++) { // checking sequence
		if (arr[i] == 0) {
			value = 0;
			cout << "Sequence is NOT safe.";
			break;
		}
	}

	if (value == 1) {
		cout << "Sequence is safe." << endl;
		for (i = 0; i < numProcesses - 1; i++) {
			cout << "P" << answer[i] << ", ";
		}
		cout << "P" << answer[numProcesses - 1] << endl;
	}
} // end main
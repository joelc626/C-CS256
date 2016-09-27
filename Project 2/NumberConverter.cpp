//Joel Castro
//CS 256
//Project 2 Task 3: Number Converter

//This program asks the user for numbers and converts them to
//Binary, Octal and Hexa.

#include<iostream>
#include <string>

using namespace std;

class stack {
	private:
		int arr[100];
		int rem;
		int i;
		int sum;
		int count;
		int binary, octal, hex;

	public:
		stack() {
			count = 0;
		}

		void push(int *p, int arr[], int insert) {
			//Going to add an element
			count++;

			//If array is full, print message and exit program
			if (check_full(arr)) {
				cout << "Array is full"<< endl;
				exit(0);
			}
			//Insert the element
			arr[*p] = insert;
		}

		//Check if the array is full
		bool check_full(int arr[]) {
			if (count < 100)
				return false;
			else
				return true;
		}
		
		//Convert numbers to Binary, Octal and Hexa
		void pop(int arr[], int *p) {
			//If array is empty, print message and exit program
			if (check_empty(arr)) {
				cout << "Array is empty" << endl;
				exit(0);
			}
			//Print numbers in Binary
			i = 1;
			sum = 0;
			int temp = arr[*p];
			cout << temp << " in Binary: ";
			 do {
				rem = temp % 2;
				sum += (i * rem);
				temp /= 2;
				i = i * 10;
			} while(temp > 0);
			cout << sum << "\n\n";

			//Resets to convert to Octal
			i = 1;
			sum = 0;
			temp = arr[*p];


			//Print in Octal
			cout << temp << " in Octal: ";
			 do {
				rem = temp % 8;
				sum += (i * rem);
				temp /= 8;
				i = i * 10;
			} while(temp > 0);
			cout << sum << "\n\n";

			//Resets to convert to Hexa and add two new variables
			i = 0;
			sum = 0;
			temp = arr[*p];
			int rem[50];
			int length = 0;

			//Print in Hexa
			cout << temp << " in Hexa: ";
			while(temp > 0) {
				rem[i] = temp % 16;
				temp /= 16;
				i++;
				length++;
			}

			//Print appropriate letter/number
			for(i = length - 1; i >= 0; i--) {
				switch(rem[i]) {
					case 10:
						cout << "A";
						break;
					case 11:
						cout << "B";
						break;
					case 12:
						cout << "C";
						break;
					case 13:
						cout << "D";
						break;
					case 14:
						cout << "E";
						break;
					case 15:
						cout << "F";
						break;
					default :
						cout << rem[i];
				}
			}
			cout << endl;
		}

		//Check if the array is empty
		bool check_empty(int arr[]) {
			if (count != 0)
				return false;
			else
				return true;
		}
};

int main()
{
	stack st;
	int arr[100];
	int index = -1;
	int *p; //holds the subscript value of the array is a pointer to stack
	int insert;

	do {
		cout << "Enter number to convert (enter -1 to stop): ";
		cin >> insert;

		//If no more numbers wanted to be entered
		if (insert == -1)
			break;
		
		//Point the front of the array
		p = &(++index);

		//Add "insert" in "arr" at location "p"
		st.push(p, arr, insert);
	}
	while (insert != -1);

	//If no elements where added end program
	if (index == -1)
		return 0;

	cout << "\nElements:\n\n";

	//Pop all elements
	do {
		st.pop(arr, p);
		p = &(--index);
		cout << "----------------------------------\n";
	}
	while (index != -1);

	system("pause");
	return 0;
}
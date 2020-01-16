#include <iostream>

using namespace std;
const int MAX = 36;

void print(int *a,int sz) {               
	for(int i = 0; i < sz; i++){
		cout<<i+1<<".- ";
        cout << a[i] <<endl; 
        
    }
	cout << endl;
}

void RadixSortLSD(int *a, int arraySize)
{
	int i, bucket[MAX], maxVal = 0, digitPosition =1 ;
	for(i = 0; i < arraySize; i++) {
		if(a[i] > maxVal) maxVal = a[i];
	}

	int pass = 1;  // used to show the progress
	/* maxVal: this variable decide the while-loop count 
	           if maxVal is 3 digits, then we loop through 3 times */
	while(maxVal/digitPosition > 0) {
		/* reset counter */
		int digitCount[10] = {0};

		/* count pos-th digits (keys) */
		for(i = 0; i < arraySize; i++)
			digitCount[a[i]/digitPosition%10]++;

		/* accumulated count */
		for(i = 1; i < 10; i++)
			digitCount[i] += digitCount[i-1];

		/* To keep the order, start from back side */
		for(i = arraySize - 1; i >= 0; i--)
			bucket[--digitCount[a[i]/digitPosition%10]] = a[i];

		/* rearrange the original array using elements in the bucket */
		for(i = 0; i < arraySize; i++)
			a[i] = bucket[i];

		/* at this point, a array is sorted by digitPosition-th digit */
		cout << "paso #" <<pass++ << ": "<<endl;
		print(a,arraySize);
		cout<<endl;

		/* move up the digit position */
		digitPosition *= 10;
	}   
 }
 
int main()
{
	int a[] = {73,63,95,256,141,82,47,124,621,52,364,169,86,75,116,205,65,159,334,93,812,9,361,728,37,892,45,350,224,156,69,773,801,900,199,28};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	cout << "paso #0: "<<endl;
	print(a,sz);
	cout<<endl;
	RadixSortLSD(&a[0],sz);
	system("PAUSE");
	return 0;
}

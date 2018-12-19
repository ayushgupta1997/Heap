/*
Intution Behind the Algorithm : author : ayushgupta1997 (Courtesy : GeeksForGeeks)

We will try to maintain two buckets, one bucket will hold the numbers greater than the median
and the other bucket holds, numbers lesser than the found median.

-->We try to maintain the difference of size of buckets, at any point should not be greater than equal to 2.
-->The buckets are maintained using heaps(implemented by priority queue), so that the elements get ordered internally.
-->We maintained two heaps 
  1. MinHeap :: stores elements greater than the median.
  2. MaxHeap :: stores elements smaller than the median.

*/

#include <bits/stdc++.h>
using namespace std;
int main () {
	priority_queue<double> maxheap;  // used to store small elements than the median
	priority_queue<double,vector<double>, greater<double>> minheap; // used to store the elements greater than the median
	int n;
	cin >> n;
	double arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	maxheap.push(arr[0]);
	double median  = arr[0];
	cout << median << " ";
	for (int i = 1; i < n; i++) {
		double curr = arr[i];
		if(maxheap.size() > minheap.size()) {
			if(curr > median) { // need to store element in the min heap
				minheap.push(curr);
			}
			else { // store curr in maxheap
				minheap.push(maxheap.top());
				maxheap.pop();
				maxheap.push(curr);

			}
			median = (double)(maxheap.top()+minheap.top())/2.0;

		}
		else if(maxheap.size() == minheap.size()) {
				if(curr>median) {
					minheap.push(curr);
					median = minheap.top();
				}
				else {
					maxheap.push(curr);
					median = maxheap.top();
				}
		}
		else if(maxheap.size() < minheap.size()) {
			if(curr>median) {
				maxheap.push(minheap.top());
				minheap.pop();
				minheap.push(curr);
			}
			else {
				maxheap.push(curr);
			}
			median = (double)(maxheap.top()+minheap.top())/2.0;
		}
		cout << median << " ";
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int kthLargest(int stream[], int n, int k) {
	priority_queue<int, vector<int>, greater<int>> pq;
	for ( int i = 0; i < k-1; i++) {
		pq.push(stream[i]);
		cout << "_ ";
	}
	pq.push(stream[k-1]);	
	for ( int i = k; i < n; i++) {
		if(i<n-1) {
			cout << pq.top() << " ";
		}
		if(pq.top() < stream[i]) {
			pq.pop();
			pq.push(stream[i]);
		}
	}
	cout << pq.top();
}

int main() {
	 // #ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
	int n;
	n = 8;
	int arr[] = {10, 20, 11, 70, 50, 40, 100, 55};
	int k = 3;
	kthLargest(arr, n, k);
	return 0;

}

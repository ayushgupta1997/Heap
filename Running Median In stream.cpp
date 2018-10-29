#include <bits/stdc++.h>

using namespace std;
double med = 0;
priority_queue<double> s;                                                     // stores elements smaller than med MAX-HEAP
priority_queue<double, vector<double>, greater<double>> g;                    // stores elements greater than med MIN-HEAP  

int main() {
    int n;
    cin >> n;
    double a[n];
    for ( int i = 0; i < n; i++) {
        cin >> a[i];
    }
   
    med = a[0];      //Median = First element
    s.push(a[0]);
    cout << med << "\n";
    for (int i = 1; i < n; i++) {
        int x = a[i];
        if(s.size() > g.size()) {
            if(x > med) {
                g.push(x);
              
            }
            else {
                 g.push(s.top());
                 s.pop();
                 s.push(x);
            }
              med = (double)(g.top()+s.top())/2.0;
        }
        else if(s.size() < g.size()) {
            if(x > med) {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else {
                s.push(x);
            }
              med = (double)(g.top()+s.top())/2.0;
            
        }
        else {
            if(x > med) {
                g.push(x);
                med =(double) g.top();
            }
            else {
                s.push(x);
                med = (double)s.top();
            }
        }
        cout << fixed << setprecision(2) << med << "\n";
    }
    return 0;
}

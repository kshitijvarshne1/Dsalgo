/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 25-Oct-20
*   Time: 1:22 PM
*   File: BucketSort.cpp
*/
# include<iostream>
# include<climits>
# include<cmath>
# include<algorithm>
# include<bits/stdc++.h>
# include<cstring>
# include<iomanip>
# include<vector>

using namespace std;

class Student {
public:
    int marks;
    string name;
};

void bucketSort(Student s[], int n) {
    //Assuming marks are in range 0-100
    vector<Student> v[101];

    //O(N)
    for (int i = 0; i < n; i++) {
        int m = s[i].marks;
        v[m].push_back(s[i]);
    }
    //iterate over the vector and the print the students
    for (int i = 100; i >= 0; i--) {
        for (vector<Student>::iterator it = v[i].begin(); it != v[i].end(); it++) {
            cout << (*it).marks << " " << (*it).name << endl;
        }
    }

}

int main() {
    Student s[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].marks >> s[i].name;
    }
    bucketSort(s, n);
    return 0;
}


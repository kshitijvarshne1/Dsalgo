/*  
*   Created by CLion IDE.
*   Author: Kshitij Varshney (kshitijvarshne1)
*   Date: 30-Nov-20
*   Time: 12:08 AM
*   File: IsPrimeOrNotOfAnyLargestNumber.cpp
*/
# include<iostream>
# include<bits/stdc++.h>
# include<climits>
# include<cmath>
# include<algorithm>
# include<cstring>
# include<iomanip>
# include<vector>
# include<stack>
# include<queue>
# include<map>
# include<unordered_map>
# include<unordered_set>

# define modValue 1e9 + 7
# define ll long long int
using namespace std;
const int n = 10000000;
bitset<10000005> b;
vector<int> primes;

void sieve() {
    b.set(); //set 1,1,1,1,1..........
    b[0] = b[1] = 0;
    for (ll i = 2; i <= n; i++) {
        if (b[i]) {
            primes.push_back(i);
            for (ll j = i; j <= n; j = j + i) {
                b[j] = 0;
            }
        }
    }
}

bool isPrime(ll no) {
    if (no <= n) {
        return b[no] == 1 ? true : false;
    }
    for (int i = 0; primes[i] * primes[i] <= no; i++) {
        if (no % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    */
    sieve();
    /*for (int i = 0; i <= 100; i++) {
        cout << primes[i] << " ";
    }*/
    ll no;
    cin >> no;
    if (isPrime(no)) {
        cout << "yes ";
    } else {
        cout << "No";
    }
    return 0;
}

/*
const int n = 10000000;
bitset<10000005> b;
vector<int> primes;


For checking no is prime or not using b array
void sieve() {
    b.set(); //set 1,1,1,1,1..........
    b[0] = b[1] = 0;
    for (ll i = 2; i <= n; i++) {
        if (b[i]) {
            for (ll j = i*i; j <= n; j = j + i) {
                b[j] = 0;
            }
        }
    }
}*/

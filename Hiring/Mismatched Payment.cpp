


/* 


    Solution by Rahul Surana
    
    ***********************************************************



CleverTap sends out invoices to all clients on the first day of each month, billed for the last month. For example, March’s invoice will be generated on the 1st of April. Some of the clients have their credits cards on file (billed automatically), and some choose to pay via cheques (posted to our office).

Our finance team needs to verify whether the cheque amount matches the due amount on the invoice generated or not.

Implement an efficient algorithm which is capable of handling 100,000,000 accounts. There will be no duplicate accounts.

Function description

You will be given all the account names and their dues (invoice amounts). You will also be given all the account names which have paid nu cheques and the amount that they paid.
You will have to write a function countMismatchedPayments. The function must return an integer denoting the number of accounts which haven’t paid the exact invoice amount.

countMismatchedPayments has the following parameters:

accountNames: an array of n strings, where each accountNames[i] is the name of an account
dues: an array of n integers, where each dues[i] is the invoiced amount for accountNames[i]
accountsPayingByCheques: an array of m strings containing the name of each account which pays by a cheque
chequeAmounts: An array of m integers, where each chequeAmounts[j] contains the cheque amount presented by accountsPayingByCheques[j].
Input

A number n denoting the number of accounts, followed by n lines - each containing the account name
A number n denoting the number of dues (same as the previous n), followed by n lines - each containing the account dues
A number m denoting accounts that have paid, followed by m lines - each containing account name
A number m denoting the amounts (same as previous m), followed by m lines - each containing the amount paid
Output

Number of accounts whose dues don’t match the paid amount





    ***********************************************************

*/











#include<bits/stdc++.h>
using namespace std;

int countMismatchedPayments (int n, vector<string> accountNames, vector<int> dues, int m, vector<string> accountsPayingByCheques, vector<int> chequeAmounts) {
   map<string,int> ma;
   for(int i = 0; i<n; i++) { ma[accountNames[i]] = dues[i]; }
   map<string,int> ma2;
   for(int i = 0; i<m; i++) { ma2[accountsPayingByCheques[i]] = chequeAmounts[i]; }
   int ans = 0;
   for(int i = 0; i<m;i++){
      if(ma2[accountsPayingByCheques[i]] != ma[accountsPayingByCheques[i]]) ans++;
      
   }
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    vector<string> accountNames(n);
    for(int i_accountNames = 0; i_accountNames < n; i_accountNames++)
    {
    	getline(cin, accountNames[i_accountNames]);
    }
    cin>>n;
    vector<int> dues(n);
    for(int i_dues = 0; i_dues < n; i_dues++)
    {
    	cin >> dues[i_dues];
    }
    int m;
    cin >> m;
    cin.ignore();
    vector<string> accountsPayingByCheques(m);
    for(int i_accountsPayingByCheques = 0; i_accountsPayingByCheques < m; i_accountsPayingByCheques++)
    {
    	getline(cin, accountsPayingByCheques[i_accountsPayingByCheques]);
    }
    cin>>m;
    vector<int> chequeAmounts(m);
    for(int i_chequeAmounts = 0; i_chequeAmounts < m; i_chequeAmounts++)
    {
    	cin >> chequeAmounts[i_chequeAmounts];
    }

    int out_;
    out_ = countMismatchedPayments(n, accountNames, dues, m, accountsPayingByCheques, chequeAmounts);
    cout << out_;
}
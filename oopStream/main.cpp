#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include "Bank.h"

using namespace std;

int main()
{
	Bank* bank = new Bank(10, 10);

	Client* c1 = bank->CreateClient(1, "One");
	Client* c2 = bank->CreateClient(2, "Two");
	Client* c3 = bank->CreateClient(3, "Three");
	Client* c4 = bank->CreateClient(4, "Four");
	Client* c5 = bank->CreateClient(5, "Five");
	Client* c6 = bank->CreateClient(5, "Six");

	Account* ac1 = bank->CreateAccount(11, c5, bank->GetClient(2), 1.8 / 100);
	Account* ac2 = bank->CreateAccount(22, c1);
	Account* ac3 = bank->CreateAccount(33, c2, 2.9 / 100);
	Account* ac4 = bank->CreateAccount(44, c3, c4);
	Account* ac5 = bank->CreateAccount(55, c5);

	ac4->Deposit(189);

	cout << bank->GetAccount(44)->CanWithdraw(98) << endl;
	cout << ac4->GetBalance() << endl;
	cout << bank->GetAccount(44)->Withdraw(55) << endl;
	cout << ac4->GetBalance() << endl;
	cout << Client::GetObjectsCountClient() << endl;
	cout << ac3->GetInterestRate() << endl;
	Client* c7 = bank->CreateClient(77, "Seven");
	Account* ac7 = bank->CreateAccount(4, c7);

	system("pause");
}

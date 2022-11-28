#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

void ins()
{

    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        cout << "Thread 1 :" << i << endl;
    }
}
void ins2()
{
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        cout << "Thread 2 :" << i << endl;
    }
}

int main()
{
    thread t1(ins);
    thread t2(ins2);
    t1.join();
    t2.join();
    return 0;
}
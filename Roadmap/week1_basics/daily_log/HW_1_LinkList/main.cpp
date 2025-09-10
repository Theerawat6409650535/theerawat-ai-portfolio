#include <iostream>
#include "ModifiedLinkedList.h"

using namespace std;
#include <math.h>
int main(int argc, char **argv)
{
    int counter = 0;
    int mid = 0;
    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        counter++;
        index++;
        if (counter % 2 == 0 || counter == 1)
        {
            mid = index;
            for (int i = 1; i < round(counter / 2.0); i++)
            {
                mid--;
            }
        }
        cout << mid << endl;
    }
    return 0;
}
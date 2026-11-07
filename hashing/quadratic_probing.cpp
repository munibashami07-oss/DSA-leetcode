// A hash table has size 11 and uses quadratic probing to resolve collisions. The hash function is h(key) = key % 11. On collision, the next positions are checked using:

// h(key, i) = (h(key) + i²) % 11, where i = 1, 2, 3, ...
// Insertion order: 22, 33, 44, 15
// Insert the keys in order using quadratic probing. Show each index checked and the final table. [3]
// Explain how quadratic probing differs from linear probing.
#include <iostream>
#include <iomanip>
using namespace std;
const int    EMPTY = -1; 
const int  DELETED = -2;
class hashchain{
public:
int size ; 
int * table ; 
int hash(int key)
{
    return key%size;
}
hashchain(int s ){
    size = s ;
    table = new int [size];
    for ( int i = 0 ; i< size ; i++)
    {
        table[i] = EMPTY;
    }
}
bool insert (int key)
{
    int i = hash(key);
    for ( int j = 0 ; j<size ; j++)
    {
        if(table[i] != EMPTY || table[i] != DELETED)
        {
            int pos = hash(key) + j*j % size ; 
            if(table[pos]==EMPTY || table[pos]==DELETED)
            {
                table[pos]= key ;
                return true;
            }
        }
    }
    return false;
}
void display(){
    for(int i = 0 ; i <size ; i++)
    {
        cout<<i<<":"<<table[i]<<endl;
    }
}
} ;
int main()
{
    hashchain h(11);
    int keys[]={22,33,44,15};
    for (int i = 0 ; i <4 ; i++)
    {
       h.insert(keys[i]);
    }
    h.display();

    return 0;
}
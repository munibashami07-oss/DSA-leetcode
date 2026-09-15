#include <iostream>
#include <iomanip>
using namespace std;
class student{
    public:
    string name;
    int roll_no;
    void display()
    {
        cout<<name<<endl;
        cout<<roll_no<<endl;
    }
};
int main()
{
  student s1,s2,s3,s4;
  s1.name="ALi";
  s1.roll_no=101;
  s2.name="ALi";
  s2.roll_no=102;
    s3.name="ALi";
  s3.roll_no=103;
  s4.name="ALi";
  s4.roll_no=104;
    return 0;
}
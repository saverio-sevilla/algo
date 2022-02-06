#include <iostream>
using namespace std;
 
class Person{
    int age;
    char* pName;
public:
    Person(): pName(0),age(0){
        }
    Person(char* pName, int age): pName(pName), age(age){
        }
    ~Person(){
        }
    void Display(){
        printf("Name = %s Age = %d \n", pName, age);
        }
    void Shout(){
        printf("Ooooooooooooooooo");
        } 
};


 
class RefCount{
private:
    int count = 0; // Reference count
public:

    void AddRef()
    {
        count++; //Add reference
    }
    
    int ReadCount()
    {
        cout << "Count: " << count << "\n";
    }

    int Release()
    {
        return --count;
    }
};
 
// A generic smart pointer class
template <class T>
class SmartPtr {
    T* ptr;
    RefCount* refptr; 
public:
    explicit SmartPtr(T* p = NULL) { 
        ptr = p; 
        refptr = new RefCount();
        refptr->AddRef();
        cout << "Built new smart pointer, count: ";
        refptr->ReadCount();
        
    }
    
    SmartPtr(const SmartPtr<T>& sp) : ptr(sp.ptr), refptr(sp.refptr)
    {
        // Copy constructor
        refptr->AddRef();
        cout << "Copied smart pointer, count: ";
        refptr->ReadCount();
        cout << endl;
    }
    
    
    ~SmartPtr() {
        if (refptr->Release() == 0){
            cout << "Deleted smart pointer, ";
            refptr->ReadCount();
            delete (ptr);
            delete (refptr);
        }
    }
 
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    
        
        
    SmartPtr<T>& operator = (const SmartPtr<T>& sp)
    {
        // Assignment operator
        if (this != &sp) // Avoid self assignment
        {
            
            cout << "Assigned smart pointer, ";
            refptr->ReadCount();
            cout << endl;
            // if reference become zero delete the old data
            if(refptr->Release() == 0)
            {
                delete ptr;
                delete refptr;
            }

            ptr = sp.ptr;
            refptr = sp.refptr;
            refptr->AddRef();
        }
        return *this;
    }
};
 
int main()
{
    SmartPtr<Person> p(new Person("Scott", 25));
    p->Display();
    {
        //SmartPtr<Person> q = p;
        //q->Display();
        SmartPtr<Person> r;
        r = p;
        r->Display();
        // Destructor of r and p will be called here.
    }
    p->Display();
    // Destructor of p will be called here 
}
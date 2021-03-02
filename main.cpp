/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* w) : value(v), name(w) {} //1
    int value; //2
    std::string name;//3
};

struct Tcomparison                                //4
{
    T* compare(T& a, T& b) //5
    {
        {
            if( a.value < b.value ) return &a;
            if( a.value > b.value ) return &b;
        }
        return nullptr;
    }
};

struct U
{
    float val1 { 0 }, val2 { 0 };
    float staticFunction(float& updatedVal)      //12
    {
        {
            std::cout << "U's val1 value: " << this->val1 << std::endl;
            this->val1 = updatedVal;
            std::cout << "U's val1 updated value: " << this->val1 << std::endl;

            while( std::abs(this->val2 - this->val1) > 0.001f )
            {
                this->val2 += this->val1 / 3;
            }

            std::cout << "U's val2 updated value: " << this->val2 << std::endl;

        }
        return this->val2 * this->val1;
    }
};

struct S
{
    static float staticFunction(U& that, float& updatedVal)        //10
    {
        {
            std::cout << "U's val1 value: " << that.val1 << std::endl;
            that.val1 = updatedVal;
            std::cout << "U's val1 updated value: " << that.val1 << std::endl;
        
            while( std::abs(that.val2 - that.val1) > 0.001f )
            {
                /*
                write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                */
                that.val2 += that.val1 / 3;
            }
            
            std::cout << "U's val2 updated value: " << that.val2 << std::endl;
        }
        return that.val2 * that.val1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(22 , "First name");                                             //6
    T t2(21 , "Second name");                                             //6
    
    Tcomparison f;                                            //7
    auto* smaller = f.compare(t1, t2);                              //8
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << S::staticFunction(u1, updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.staticFunction(updatedValue) << std::endl;
}

        
        
        
        
        
        
        


#include<map>
#include<iostream>

using namespace std;
typedef void* (*CreateFunction)(void);

class ClassFactory
{
    private:
        static map<string, CreateFunction> m_clsMap;

    public:
        static void* GetClassByName(string name)
        {
            map<string, CreateFunction>::const_iterator it;
            it = m_clsMap.find(name);
            if(it == m_clsMap.end())
                return NULL;
            else
                return it->second;
        }
    
        static  void RegistClass(string name, CreateFunction method)
        {
            m_clsMap.insert(make_pair(name,method));

        }
        
};

map<string, CreateFunction> ClassFactory::m_clsMap;

class RegistClass
{
    public:
        RegistClass(string name, CreateFunction method)
        {
            ClassFactory::RegistClass(name, method);
        }
};


template<class T, const char name[]>
class Register
{
    public:
        static const RegistClass rc;

    Register()
    {
        const RegistClass tmp = rc;

    }

    static void* CreateInstance()
    {
        return new T;
    }
};

template<class T, const char name[]>
const RegistClass Register<T,name>::rc(name, Register<T, name>::CreateInstance);


#define DEFINE_CLASS(class_name) \
    char NameArray[]= #class_name; \
    class class_name : public Register<class_name, NameArray>

#define DEFINE_CLASS_EX(class_name, father_class) \
                         char NameArray[]=#class_name;\
                 class class_name:public Register<class_name, NameArray>,public father_class

DEFINE_CLASS(CG)
{
    public:
        void Display()
        {
            cout <<"I am Here.\n";
        }
};


int main(int tt)
{
    CG* tmp = (CG*)ClassFactory::GetClassByName("CG");
    tmp->Display();
    return 0;
}

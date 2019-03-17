#include <iostream> 
#include <string.h>
using namespace std;
struct Node
{
    string author,title,publisher;
    int year,isbn;
    Node *next;
};
class LinkedList
{
private:
    Node *head,*tail;
    int num;
public:
    LinkedList();
    ~LinkedList();
    bool create_node(string author,string title,int isbn,string publisher,int year);
    bool search_isbn(int isb);
    void del_isbn(int isb);
    void del_title(string titl);
    void display_all();
    
};
LinkedList::LinkedList()
{
    head=tail=NULL;
}

LinkedList::~LinkedList()
{
    if(head)
    {
        Node *t = head;
        head=head->next;
        while(head !=NULL)
        {
            delete t;
            t=head;
            head=head->next;
        }
    }
}
bool LinkedList::search_isbn(int isb)
{
    Node *t = head;
    int book=1;
    while(t != NULL)
    {
        if(t->isbn == isb)
        {
            cout<<" BOOK: "<<book<<endl;
            cout<<" Author: "<<t->author<<endl;
            cout<<" Title: "<<t->title<<endl;
            cout<<" Publisher: "<<t->publisher<<endl;
            cout<<" Year: "<<t->year<<endl;
            cout<<" ISBN: "<<t->isbn<<endl;
            return true;
        }
        t=t->next;
        book++;
    }
    
    return false;
}

void LinkedList::del_title(string titl)
{
    Node *temp=head;
    int i=0;
    while(temp!=NULL)
    {
        if(temp->next->title==titl)
        {
            temp->next=temp->next->next;
            i++;
        }
        temp=temp->next;
    }
    if (i>0)
    {
        cout<<"Book deleted";
    }
    else
    {
        cout<<"Book is not in the list";
    }
}

void LinkedList::del_isbn(int isb)
{
    Node *temp=head;
    int i=0;
    while(temp!=NULL)
    {
        if(temp->next->isbn==isb)
        {
            temp->next=temp->next->next;
            i++;
        }
        temp=temp->next;
    }
    if (i>0)
    {
        cout<<"Book deleted";
    }
    else
    {
        cout<<"Book is not in the list";
    }
}

bool LinkedList::create_node(string author,string title,int isbn,string publisher,int year)
{
    Node *temp=new Node;
    temp->author=author;
    temp->title=title;
    temp->isbn=isbn;
    temp->publisher=publisher;
    temp->year=year;
    temp->next=NULL;
    
    if(!head)
    {
        head=tail=temp;
        temp=NULL;
        return true;
    }
    else
    {
        tail->next=temp;
        tail=tail->next;
        temp=NULL;
        return true;
    }			
    return false;
}

void LinkedList::display_all()
{
    if (!head)
    {
        cout<<"Linked List does not exist"<<endl;
    }
    else
    {
        Node *t=head;
        int book=1;
        while(t!=NULL)
        {
            cout<<" BOOK: "<<book<<endl;
            cout<<" Author: "<<t->author<<endl;
            cout<<" Title: "<<t->title<<endl;
            cout<<" Publisher: "<<t->publisher<<endl;
            cout<<" Year: "<<t->year<<endl;
            cout<<" ISBN: "<<t->isbn<<endl;
            cout<<"**************************"<<endl<<endl;
            t=t->next;
            book++;
        }
    }
}

int main()
{
    string aut,tit,pub;
    int num,yr,num1,num2;
    string t;
    LinkedList obj;
    int choice;
    obj.create_node("Thomas H. Cormen","Introduction To Algorithms",262032937,"MIT Press(MA)",2001);
    obj.create_node("Harold Abelson","Structure and Interpretation of Computer Programs",262510871,"MIT Press",1996);
    obj.create_node("Brian W. Kernighan","The C Programming Language",131103628,"MIT Press",1988);
    obj.create_node("Andrew Hunt","The Pragmatic Programmer: From Journeyman to Master",020161622,"Addison-Wesley Professional",1999);
    obj.create_node("Donald Ervin Knuth","The Art of Computer Programming",201485419,"Addison-Wesley Professional",1998);
    obj.create_node("Erich Gamma","Design Patterns: Elements of Reusable Object-Oriented Software",201633612,"Addison-Wesley Professional",1994);
    obj.create_node("Michael Sipser","Introduction to the Theory of Computation",534950973,"Course Technology",2005);
    obj.create_node("Frederick P. Brooks Jr.","The Mythical Man-Month: Essays on Software Engineering",201835959,"Addison-Wesley Professional",1995);
    obj.create_node("Charles Petzold","The Hidden Language of Computer Hardware and Software",735611319,"Microsoft Press",2000);
    obj.create_node("Stuart Russell, Peter Norvig","Artificial Intelligence: A Modern Approach",130803022,"Pearson Education",2003);
    obj.create_node("Steve McConnell","Code Complete",735619670,"Pearson Education",2004);
    obj.create_node("W. Richard Stevens","The Protocols",201633469,"Addison-Wesley Professional",1993);
    obj.create_node("W. Richard Stevens","Advanced Programming in the UNIX Environment",201563177,"Addison-Wesley Professional",1992);
    obj.create_node("Edsger W. Dijkstra","A Discipline of Programming",13215871,"Prentice Hall(Inc)",1976);
    obj.create_node("Jeffrey D. Ullman","Introduction to Automata Theory, Languages, and Computation",201441241,"Addison Wesley",2000);
    do
    {
        cout<<endl<<"\t\t **************************"<<endl;
        cout<<endl<<"\t\t WELCOME TO THE UBIT LIBRARY";
        cout<<endl<<endl<<"\t\t **************************"<<endl;
        cout<<"\t\t MENU:- SELECT YOUR OPTIONS "<<endl;
        cout<<"\t\t ************************** "<<endl;
        cout<<"\t\t 1- ADD A BOOK TO THE LIST  "<<endl;
        cout<<"\t\t 2- DELETE A BOOK BASED ON TITLE "<<endl;
        cout<<"\t\t 3- DELETE A BOOK BASED ON ISBN  "<<endl;
        cout<<"\t\t 4- SEARCH FOR A BOOK BY ISBN    "<<endl;
        cout<<"\t\t 5- LIST ALL BOOKS               "<<endl;
        cout<<"\t\t 6- LIST ALL BOOKS BY AN AUTHER  "<<endl;
        cout<<"\t\t 7- QUIT                         "<<endl;
        cout<<"\t\t ********************************"<<endl<<endl;
        cout<<"\t\t ENTER YOUR CHOICE --->   ";
        cin>>choice;
        if(choice>=1 && choice <=6)
        {
            switch(choice)
            {
                case 1:
                    cout<<" ENTER AUTHOR'S NAME :- ";
                    cin>>aut;
                    cout<<endl<<" ENTER TITLE OF BOOK :- ";
                    cin>>tit;
                    cout<<endl<<" ENTER ISBN :- ";
                    cin>>num;
                    cout<<endl<<" ENTER PUBLISHER OF THE BOOK :- ";
                    cin>>pub;
                    cout<<endl<<" ENTER THE PUBLISHED YEAR :- ";
                    cin>>yr;
                    obj.create_node(aut,tit,num,pub,yr);
                    break;
                case 2:
                    cout<<endl<<" ENTER THE TITLE TO DELETE :- ";
                    cin>>t;
                    obj.del_title(t);
                    break;
                case 3:
                    cout<<endl<<" ENTER THE ISBN TO DELETE :- ";
                    cin>>num1;
                    obj.del_isbn(num1);
                    break;
                case 4:
                    cout<<endl<<" ENTER ISBN :- ";
                    cin>>num2;
                    obj.search_isbn(num2);
                    break;
                case 5:
                    obj.display_all();
                    break;
                case 6:
                    cout<<"\t\t AUTHOR'S ARE AS FOLLOWS:- "<<endl;
                    cout<<"\t\t Thomas H. Cormen "<<endl;
                    cout<<"\t\t Harold Abelson "<<endl;
                    cout<<"\t\t Brian W. Kernighan "<<endl;
                    cout<<"\t\t Andrew Hunt "<<endl;
                    cout<<"\t\t Donald Ervin Knuth "<<endl;
                    cout<<"\t\t Erich Gamma "<<endl;
                    cout<<"\t\t Michael Sipser "<<endl;
                    cout<<"\t\t Frederick P. Brooks Jr. "<<endl;
                    cout<<"\t\t Charles Petzold "<<endl;
                    cout<<"\t\t Stuart Russell, Peter Norvig "<<endl;
                    cout<<"\t\t Steve McConnell "<<endl;
                    cout<<"\t\t W. Richard Stevens "<<endl;
                    cout<<"\t\t W. Richard Stevens "<<endl;
                    cout<<"\t\t Edsger W. Dijkstra "<<endl;
                    cout<<"\t\t Jeffrey D. Ullman "<<endl;
                    break;
            }
        }
        else
        {
            cout<<"\t\t INVALID CASE"<<endl<<"\tt KINDLY ENTER AGAIN"<<endl;
        }
    }
    while (choice !=7 );
    return 0;
}

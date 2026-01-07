///////////////////////////////////////////////////////////////
//    GENERALIZED DATA STRUCTURE LIBRARY                     //
///////////////////////////////////////////////////////////////

/*
--------------------------------------------------------------------------------------------
Type                 Name of class for node                 Name of class for Functionality
--------------------------------------------------------------------------------------------           
Singly Linear        SinglyLLLnode                          SinglyLLL          Done
Singly Circular      SinglyCLLnode                          SinglyCLL          
Doubly Linear        DoublyLLLnode                          DoublyLLL          Done
Doubly Circular      DoublyCLLnode                          DoublyCLL           
---------------------------------------------------------------------------------------------   
*/

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////
//   Singly Linear LinkedList using Generic Approach
//////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLnode
{
    public:
        T data;
        SinglyLLnode<T> *next;
        
        SinglyLLnode(T no)
        {
            this->data=no;
            this->next=NULL;
        }
};
template <class T>
class SinglyLLL
{
    private:        
        SinglyLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
    
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);    
};
template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Singly Linear Linked List gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertFirst
// Input:           Data of node
// Output:          Nothing
// Description:     Use to insert node at first position
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLnode<T> *  newn = NULL;

    newn = new SinglyLLnode<T>(no);
    
    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertLast
// Input:           Data of node 
// Output:          Nothing
// Description:     Inserts a new node at the end of the singly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLnode<T> *  newn = NULL;
    SinglyLLnode<T> *  temp = NULL;

    newn = new SinglyLLnode<T>(no);

    if(this->iCount == 0) 
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteFirst
// Input:           Nothing
// Output:          Nothing
// Description:     Deletes the first node of the singly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLnode<T> *  temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteLast
// Input:           Nothing
// Output:          Nothing
// Description:     Deletes the last node of the singly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLnode<T> *  temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Display
// Input:           Nothing
// Output:          Displays linked list elements
// Description:     Displays all nodes of the singly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLnode<T> *  temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Count
// Input:           Nothing
// Output:          Returns number of nodes in the Linked List
// Description:     Returns the total count of nodes in singly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertAtPos
// Input:           Data of node, Position
// Output:          Nothing
// Description:     Inserts a new node at the specified position in singly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyLLnode<T> *  temp = NULL;
    SinglyLLnode<T> *  newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteAtPos
// Input:           Position (int)
// Output:          Nothing
// Description:     Deletes a node from the specified position in singly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLnode<T> *  temp = NULL;
    SinglyLLnode<T> *  target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////
//   Doubly Linear LinkedList using Generic Approach
////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
    T data;
    DoublyLLLnode *next;
    DoublyLLLnode *prev;
    
    DoublyLLLnode(T no)
    {
        this->data=no;
        this->next=NULL;
        this->prev=NULL;
    } 
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> *first;
        int iCount;
    
    public:
        DoublyLLL();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    
    void Display();
    int Count();
 
};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Doubly Linear Linked List gets created.\n";
    this->first=NULL;
    this->iCount=0;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertFirst
// Input:           Data of node 
// Output:          Nothing
// Description:     Inserts a new node at the beginning of the doubly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>:: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    
    newn = new DoublyLLLnode<T>(no);
    
    if(this->first==NULL)
    {
        this->first=newn;
    }
    else
    {
        newn->next=this->first;
        this->first->prev=newn;
        this->first=newn;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertLast
// Input:           Data of node 
// Output:          Nothing
// Description:     Inserts a new node at the end of the doubly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;
    
    newn = new DoublyLLLnode<T>(no);
    
    if(this->first==NULL)
    {
        this->first=newn;
    }
    else
    {
        temp=this->first;
        
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        temp->next=newn;
        newn->prev=temp;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertAtPos
// Input:           Data of node , Position
// Output:          Nothing
// Description:     Inserts a node at specified position in doubly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp=NULL;
    DoublyLLLnode<T> *newn=NULL;
    
    int iCnt=0;
    
    if((pos<1) ||(pos>this->iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }
    
    if(pos==1)
    {
        this->InsertFirst(no);
    }
    
    else if(pos==this->iCount+1)
    {
        this->InsertLast(no);
    }
    
    else
    {
        newn =new DoublyLLLnode<T>(no);
        
        temp=this->first;
        
        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        
        newn->next=temp->next;
        temp->next->prev=newn;
        
        temp->next=newn;
        newn->prev=temp;
        
        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteFirst
// Input:           Nothing
// Output:          Nothing
// Description:     Deletes the first node of the doubly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)     
    {
        return;
    }
    
    else if(this->first->next == NULL)   
    {
        delete(this->first);
        this->first=NULL;
    }
    
    else                                 
    {
       this->first=this->first->next;
       delete this->first->prev;
       this->first->prev=NULL;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteLast
// Input:           Nothing
// Output:          Nothing
// Description:     Deletes the last node of the doubly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>:: DeleteLast()
{
    DoublyLLLnode<T> *temp=NULL;
    if(this->first == NULL)      
    {
        return;
    }
    
    else if(this->first->next == NULL)   
    {
        delete(this->first);
        this->first=NULL;
    }
    
    else                                  
    {
        temp=this->first;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteAtPos
// Input:           Position (int)
// Output:          Nothing
// Description:     Deletes a node from specified position in doubly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////


template<class T>
void  DoublyLLL<T> ::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp=NULL;
    int iCnt=0;
    
    if((pos<1) ||(pos>this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }
    
    if(pos==1)
    {
        this->DeleteFirst();
    }
    
    else if(pos==this->iCount)
    {
        this->DeleteLast();
    }
    
    else
    {
        temp=this->first;
        
        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
        
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Display
// Input:           Nothing
// Output:          Displays linked list elements
// Description:     Displays all nodes of the doubly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> *temp = NULL;
    
    temp=this->first;
    
    cout<<"\nNULL<=>";
    while(temp!=NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Count
// Input:           Nothing
// Output:          Returns number of nodes in linked list
// Description:     Returns the total number of nodes in doubly linear linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//          Singly Circular LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyCLLnode
{
    public:
    
        T data;
        SinglyCLLnode<T> *next;
        
        SinglyCLLnode(T no)
        {
            this->data=no;
            this->next=NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Singly Circular Linked List gets created.\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertFirst
// Input:           Data of node 
// Output:          Nothing
// Description:     Inserts a node at the beginning of the singly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL) 
    {
        this->first = newn;
        this->last = newn;

        this->last->next = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;

        this->last->next = this->first;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertLast
// Input:           Data of node 
// Output:          Nothing
// Description:     Inserts a node at the end of the singly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL) 
    {
        this->first = newn;
        this->last = newn;

        this->last->next = this->first;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;

        this->last->next = this->first;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteFirst
// Input:           Nothing
// Output:          Nothing
// Description:     Deletes the first node of the singly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first -> next;
        delete this->last->next;

        this->last->next = this->first;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteLast
// Input:           Nothing
// Output:          Nothing
// Description:     Deletes the last node of the singly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp -> next != this->last)
        {
            temp = temp -> next;
        }

        delete this->last;
        this->last = temp;

        this->last->next =this-> first;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Display
// Input:           Nothing
// Output:          Displays linked list elements
// Description:     Displays all nodes of the singly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::Display()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    SinglyCLLnode<T> * temp = this->first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != this->last ->next);
    
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Count
// Input:           Nothing
// Output:          Returns number of nodes in linked list
// Description:     Returns the total number of nodes in singly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteAtPos
// Input:           Position 
// Output:          Nothing
// Description:     Deletes a node from specified position in singly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;
    
    int iCnt = 0;
    
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertAtPos
// Input:           Data of node , Position 
// Output:          Nothing
// Description:     Inserts a node at specified position in singly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        this->iCount++;
    }
}

///////////////////////////////////////////////////////////////////////
//          Doubly Circular LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode *next;
        DoublyCLLnode *prev;
        
    DoublyCLLnode(T no)
    {
        this->data=no;
        this->next=NULL;
        this->prev=NULL;
    }
};

template <class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public:
        DoublyCLL();
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
       
        void Display();
        int Count();
        
};

template <class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Doubly Circular Linked List gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertFirst
// Input:           Data of node 
// Output:          Nothing
// Description:     Inserts a node at the beginning of the doubly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    
    newn = new DoublyCLLnode<T>(no);
    
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;
    
    if((this->first == NULL) && (this->last == NULL) )
    {
        this->first=newn;
        this->last=newn;
    }
    
    else
    {
        newn->next=this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    
    this->last->next = this->first;
    this->first->prev=this->last;
    
        this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertLast
// Input:           Data of node (T)
// Output:          Nothing
// Description:     Inserts a node at the end of the doubly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    
    newn = new DoublyCLLnode<T>(no);
    
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;
    
    if((this->first == NULL) && (this->last == NULL) )
    {
        this->first=newn;
        this->last=newn;
    }
    
    else
    {
        this->last->next=newn;
        newn->prev=this->last;
        this->last=newn;
    }
    
    this -> last -> next = this -> first;
    this -> first -> prev = this -> last;
    
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  InsertAtPos
// Input:           Data of node (T), Position (int)
// Output:          Nothing
// Description:     Inserts a node at specified position in doubly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void  DoublyCLL<T> ::InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *newn = NULL;
    
    int iCnt = 0;
    
    if((pos < 1) || (pos > this -> iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }
    
    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    
    else if(pos == this -> iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);
         
        temp=this->first;
        
        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        
        newn->next = temp->next;
        newn->next->prev=newn;
        
        temp->next=newn;
        newn->prev=temp;
        
        this->iCount++;
    }
    
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteFirst
// Input:           Nothing
// Output:          Nothing
// Description:     Deletes the first node of the doubly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T>:: DeleteFirst()
{
    if(this->first == NULL && this->last == NULL) 
    {
        return;
    }
    else if(this->first == this->last)    
    {
        delete(this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first=this->first->next;
        delete(this->first->prev);
        
        this->last->next = this->first;
        this->first->prev=this->last;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteLast
// Input:           Nothing
// Output:          Nothing
// Description:     Deletes the last node of the doubly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
        if(this->first == NULL && this->last == NULL) 
    {
        return;
    }
    else if(this->first == this->last)   
    {
        delete(this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last=this->last->prev;
        delete(this->last->next);
        
        this->last->next = this->first;
        this->first->prev=this->last;
        
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DeleteAtPos
// Input:           Position 
// Output:          Nothing
// Description:     Deletes a node from specified position in doubly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    
    int iCnt = 0;
    
    if((pos<1) || (pos>this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }
    
    if(pos==1)
    {
        DeleteFirst();
    }
    
    else if(pos==this->iCount)
    {
        DeleteLast();
    }
    else
    {
        
        temp=this->first;
        
        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        
        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev=temp;
        
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Display
// Input:           Nothing
// Output:          Displays linked list elements
// Description:     Displays all nodes of the doubly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLnode<T> *temp=NULL;
    
    if(first == NULL && last == NULL) 
    {
        cout<<"Linked List is empty\n";
        return;
    }

    temp=first;
    
    cout<<" <=> ";
    
    do
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp-> next;
    }while(temp != this->first);
    
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Count
// Input:           Nothing
// Output:          Returns number of nodes in linked list
// Description:     Returns the total number of nodes in doubly circular linked list
// Author:          Sakshi Ravindra Darandale
// Date:            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////END OF LIBRARY///////////////////////////////////////

int main()
{
    SinglyLLL<int> *obj=new SinglyLLL<int>;
   

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    cout<<"Number of nodes are : "<<obj->Count()<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);
    
    obj->Display();

    cout<<"Number of nodes are : "<<obj->Count()<<"\n";
    
    obj->DeleteFirst();
    obj->Display();

    cout<<"Number of nodes are : "<<obj->Count()<<"\n";
    
    obj->DeleteLast();

    obj->Display();
    
    cout<<"Number of nodes are : "<<obj->Count()<<"\n";
    
    obj->InsertAtPos(105,4);

    obj->Display();

    cout<<"Number of nodes are : "<<obj->Count()<<"\n";
    
    obj->DeleteAtPos(4);

    obj->Display();

    cout<<"Number of nodes are : "<<obj->Count()<<"\n";
    
    delete obj;
    
    /////////////////////////////////////////////////////////////////////////////
    
    DoublyLLL<char> *dobj = new DoublyLLL<char>();
    
    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');
    
    dobj->Display();
    
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";
    
    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');
    
    dobj->Display();
    
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";
    
    dobj->DeleteFirst();
    
    dobj->Display();
    
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";
    
    dobj->DeleteLast();
    
    dobj->Display();
    
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";
    
    dobj->InsertAtPos('$',4);
    
    dobj->Display();
    
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";
    
    dobj->DeleteAtPos(4);
    
    dobj->Display();
    
    cout<<"Number of elements are :"<<dobj->Count()<<"\n";
    
    delete dobj;
    
    ///////////////////////////////////////////////////////////////////////
    
    SinglyCLL<int> *sobj = new SinglyCLL<int>();
    
    sobj->InsertFirst(51);
    sobj->InsertFirst(21);
    sobj->InsertFirst(11);
    
    sobj->Display();
    
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    sobj->InsertLast(101);
    sobj->InsertLast(111);
    sobj->InsertLast(121);
    
    sobj->Display();
    
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    sobj->DeleteFirst();

    sobj->Display();
    
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";

    sobj->DeleteLast();

    sobj->Display();
    
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    sobj->InsertAtPos(105,4);

    sobj->Display();
    
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";

    sobj->DeleteAtPos(4);

    sobj->Display();
    
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    /////////////////////////////////////////////////////////////////////////

    DoublyCLL<int> *dcobj=new DoublyCLL<int>();
    
    dcobj->InsertFirst(51);
    dcobj->InsertFirst(21);
    dcobj->InsertFirst(11);

    dcobj->Display();

    cout<<"Number of nodes are : "<<dcobj->Count()<<"\n";

    dcobj->InsertLast(101);
    dcobj->InsertLast(111);
    dcobj->InsertLast(121);
    
    dcobj->Display();

    cout<<"Number of nodes are : "<<dcobj->Count()<<"\n";
    
    dcobj->DeleteFirst();
    dcobj->Display();
    
    cout<<"Number of nodes are : "<<dcobj->Count()<<"\n";
    
    dcobj->DeleteLast();

    dcobj->Display();

    cout<<"Number of nodes are : "<<dcobj->Count()<<"\n";
    
    dcobj->InsertAtPos(105,4);

    dcobj->Display();

    cout<<"Number of nodes are : "<<dcobj->Count()<<"\n";
    
    dcobj->DeleteAtPos(4);

    dcobj->Display();

    cout<<"Number of nodes are : "<<dcobj->Count()<<"\n";

    return 0;
}

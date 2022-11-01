using namespace std;
class List;

class Node{
    int data;
    
public:
    Node* next;
    
    Node(int d):data(d),next(NULL){}    

    int getData(){
        return data;
    }    

    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }

    friend class List;
};

class List{
    Node * head;
    Node * tail;

    int searchHelper(Node* start,int key){
        if(start==NULL){
            return -1;
        }
        if(start->data==key){
            return 0;
        }

        int subidx=searchHelper(start->next,key);
        if(subidx==-1){
            return -1;
        }
        return subidx+1;
    }

public:
    List():head(NULL),tail(NULL){}

    Node* begin(){
        return head;
    }

    void push_front(int data){
        if(head==NULL){
            Node * n=new Node(data);
            head=tail=n;
            return ;
        }

        else{
            Node * n=new Node(data);
            n->next=head;
            head=n;
        }
    }

    void push_back(int data){
        if(head==NULL){
            Node * n=new Node(data);
            head=tail=n;
            return ;
        }

        else{
            Node * n=new Node(data);
            tail->next=n;
            tail=n;
        }

    }

    void insert(int data,int pos){
        if(pos==0){
            push_front(data);
            return;
        }

        Node* temp=head;
        for(int jump=1;jump<=pos-1;jump++){
            temp=temp->next;
        }
        Node* n=new Node(data);
        n->next=temp->next;
        temp->next=n;

    }

    int search(int key){
        Node* temp=head;
        int idx=0;

        while (temp!=NULL)
        {
            if(temp->data==key){
                return idx;
            }
            idx++;
            temp=temp->next;
        }
        return -1;
        
    }

    int recsearch(int key){
        int idx=searchHelper(head,key);
        return idx;
    }

    void pop_front(){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    /*void pop_back(){
        if(head==NULL){
            return ;
        }
        if(head->next=NULL){
            delete head;
            return;
        }
        Node* temp=head;
        while(temp->next->next !=NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
        return;
    }

    void remove(int pos){
        if(head==NULL){
            return;
        }

        Node* temp=head;
        if(pos==1){
            head=temp->next;
            delete temp;
            return;
        } 

        for(int i=2;temp!=NULL && i<pos-1;i++){
            temp=temp->next;
        }

        if(temp==NULL || temp->next==NULL){
            return;
        }

        Node* next=temp->next->next;
        delete temp->next;
        temp->next=next;
    }*/


    ~List(){
        if(head!=NULL){
            delete head;
            head=NULL;
        }
    }
};
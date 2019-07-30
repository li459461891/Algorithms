#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node(int d):data(d), next(nullptr){}
    Node():data(0), next(nullptr){}
};

class FindCircl
{
public:
    FindCircl(Node* list):list_(list){}
    bool hasCircle()
    {
        int slowerStep, fasterStep ;
        Node* faster = list_;
        Node* slower = list_;
        slowerStep = fasterStep = 0; 
        while(nullptr != faster)
        {
            if (moveFasterPtr(faster, slower, fasterStep))
            {
                circleLen_ = fasterStep - slowerStep;
                return true;
            }
            moveSlowerPtr(slower, slowerStep);
        }
        return false;
    }
    int circleLen()
    {
        return circleLen_;
    }
private:
    bool moveFasterPtr(Node*& faster, Node*& slower, int& step)
    {
        for (int index = 0 ; index <= 1 ; index++)
        {
            faster = faster->next;
            step++;
            std::cout << __func__ << " faster:" << faster << ", slower:" << slower << std::endl;
            if (slower == faster) return true;
        }
        return false;
    }
    void moveSlowerPtr(Node*& slower, int& step)
    {
        slower = slower->next;
        step++;
    }

    Node* list_;
    int circleLen_;
};

Node* createList()
{
    Node* nodeArr[10] = {nullptr};
    nodeArr[0] = new Node(0);
    for(int i = 1 ; i < 10 ; i++)
    {
        nodeArr[i] = new Node(i);
        nodeArr[i-1]->next = nodeArr[i];
    }
    nodeArr[9]->next = nodeArr[0];
    return nodeArr[0]; 
}

void printList(const Node* list)
{
    auto ptr = list;
    while(nullptr != ptr)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

int main()
{
    auto list = createList();
    // printList(list);
    FindCircl findCircle(list);

    if (findCircle.hasCircle())
    {
        std::cout << " Has circle! The length of the circle is:" << findCircle.circleLen() << std::endl;
        return 0;
    }
    std::cout << " Do not have circle!" << std::endl;
    return 0;
}

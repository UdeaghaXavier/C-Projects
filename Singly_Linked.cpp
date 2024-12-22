#include <iostream>
#define LIST_SIZE (10)

class Node
{   
    public:
        int data;
        Node *next;
};

class singlely_Linked{
    private:   
        Node* head; // Make head a pointer for a straight forward initial replacement (first insert call)

    Node* get_newNode(int data){
        // "new" returns d memory location of the object thus the output should be a pointer
        Node *newNode = new Node(); 
        newNode->data = data; // same as (*nextNode).data
        newNode->next = nullptr;

        return newNode;
    }
    
    public:
        void insert(int data){
            Node* newNode = get_newNode(data);

            if (head == nullptr){
                head = newNode;
            }else{
                Node* nextNode = head; // head is a pointer dont forget!
                while (nextNode->next != nullptr){
                    nextNode = nextNode->next; // same as (*nextNode).next 
                }
                nextNode->next = newNode;
            }
        }

        void insert_at(int data, int req_index){
            int max_index = lenght();
            if (req_index < max_index){
                Node* newNode = get_newNode(data);
                int index_of_current_node = 1;

                Node* currentNode = head;
                while (currentNode->next != nullptr && index_of_current_node < max_index){
                    if (index_of_current_node == req_index){
                        Node* nextNode = currentNode->next;
                        newNode->next = nextNode;
                        currentNode->next = newNode;
                    }
                    index_of_current_node++;
                    currentNode = currentNode->next;
                }
            }else if (req_index == max_index){
                insert(data);
            }
        }

        void remove(int index){
            int max_index = lenght();
            if (index < max_index){
                int current_node_index = 0;
                
                Node* previousNode = nullptr;
                Node* currentNode = head;

                while (currentNode->next != nullptr && current_node_index < max_index){
                    if (current_node_index == index){
                        if (current_node_index == 0){
                            if (max_index > 1){
                                head = currentNode->next;
                                previousNode = nullptr;
                                currentNode = head->next;
                                break;
                            }else{
                                head = nullptr;
                                break;
                            }
                        }else if (index < max_index - 1){
                            previousNode->next = currentNode->next;
                            currentNode = previousNode->next;
                            break;
                        }else{
                            currentNode->next = nullptr;
                            break;
                        }
                    }else{
                        previousNode = currentNode;
                        currentNode = currentNode->next;
                    }

                    current_node_index++;
                }
            }
        }

        int get(int index){
            Node* currentNode = head;
            int current_node_index = 0;

            while (currentNode->next != nullptr){
                if (current_node_index == index){
                    return currentNode->data;
                }
                currentNode = currentNode->next;
                current_node_index++;
            }

            return INT_MAX;
        }

        int lenght(){
            int n = 1;
            Node* currentNode = head;
            while (currentNode->next != nullptr){
                n++;
                currentNode = currentNode -> next;
            }
            return n;
        }

        void display_items(){
            Node* nextNode = head;
            int index = 0;
            std::string message = "";
            int last_index = (lenght() - 1);

            while (nextNode != nullptr){
                if(index == 0){
                    message = "[" + std::to_string(nextNode->data) + ", ";
                } else if (index == last_index) {
                    message = std::to_string(nextNode->data) + "]";
                } else{
                    message = std::to_string(nextNode->data) + ", ";
                }

                nextNode = nextNode->next;
                std::cout << message;
                index++;
            }
            std::cout << "" << std::endl;
        }
};

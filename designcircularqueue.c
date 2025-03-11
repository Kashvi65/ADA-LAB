


struct Node{
    int val;
    struct Node *left;
    struct Node *right;
};


typedef struct {
    struct Node* front;
    struct Node* rear;
    int max_size;
    int size;
} MyCircularDeque;

bool myCircularDequeIsEmpty(MyCircularDeque* obj);
bool myCircularDequeIsFull(MyCircularDeque* obj);
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *q = malloc(sizeof(MyCircularDeque));
    q->max_size = k;
    q->size = 0;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj))
        return false;
     struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = value;
    if(obj->size==0){
        newNode->left = newNode;
        newNode->right = newNode;
        obj->rear = newNode;
        obj->front = newNode;
    }else{
        newNode->right = obj->front;
        newNode->left = obj->front->left;
        obj->front->left = newNode;
        newNode->left->right = newNode;
        obj->front = obj->front->left;
    }
    ++obj->size;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj))
        return false;
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = value;
    if(obj->size==0){
        newNode->left = newNode;
        newNode->right = newNode;
        obj->rear = newNode;
        obj->front = newNode;
    }else{
        newNode->left = obj->rear;
        newNode->right = obj->rear->right;
        obj->rear->right = newNode;
        newNode->right->left = newNode;
        obj->rear = obj->rear->right;
    }
    ++obj->size;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
        return false;
    struct Node *tmp = obj->front;
    if(obj->size==1){
        obj->front=NULL;
        obj->rear=NULL;
    }else{
        obj->front = obj->front->right;
        obj->front->left = tmp->left;
        tmp->left->right = obj->front;
    }
    free(tmp);
    --obj->size;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
        return false;
    struct Node *tmp = obj->rear;
    if(obj->size==1){
        obj->front=NULL;
        obj->rear=NULL;
    }else{
        obj->rear = obj->rear->left;
        obj->rear->right = tmp->right;
        tmp->right->left = obj->rear;
    }
    free(tmp);
    --obj->size;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
        return -1;
    return obj->front->val;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
        return -1;
    return obj->rear->val;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj && obj->size==0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj && obj->size==obj->max_size;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    if(!obj)
        return;
    struct Node *cur = obj->front;
    for(int i=0;i<obj->size;++i){
        struct Node *tmp = cur;
        cur = cur->right;
        free(tmp);
    }
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/

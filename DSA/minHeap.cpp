#include <iostream>
#include <climits>

class minHeap{
public:
    minHeap(int32_t l)
    {
        this->size=0;
        this->cap=l;
        heap=new int32_t [l];
    }
    
    void heapify(int32_t);
    
    inline int32_t parent(int32_t i){
        return (i-1)/2;
    }
    
    inline int32_t left(int32_t i){
        return (2*i+1);
    }
    
    inline int32_t right(int32_t i){
        return (2*i+2);
    }

    int32_t extractMinEle();
    
    void decreaseKey(int, int32_t);
    
    inline int32_t getMin(){return heap[0];}

    void deleteKey(int32_t);
    
    void insertKey(int32_t);

private:
    int32_t *heap;// array
    int32_t cap;// max size
    int32_t size;// current size
};

void minHeap::insertKey(int32_t k){
    if(this->size==this->cap){
        std::cout<<"\nOverflow: error!"<<std::endl;
        return ;
    }
    this->size++;
    int i=this->size-1;
    // insert the new key at the end
    heap[i]=k;
    while(i!=0 && heap[parent(i)]>heap[i]){
        std::swap(heap[i], heap[parent(i)]);
        i=parent(i);
    }
}

void minHeap::decreaseKey(int i, int32_t newval){
    heap[i]=newval;
    while(i!=0 && heap[parent(i)] > heap[i]){
        std::swap(heap[i], heap[parent(i)]);
        i=parent(i);
    }
}

int32_t minHeap::extractMinEle(){
    if(this->size <= 0)
        return INT32_MAX;

    if(this->size==1){
        this->size--;
        return heap[0];
    }
    int32_t root=heap[0];
    heap[0]=heap[size - 1];
    size--;
    heapify(0);

    return root;
}

void minHeap::deleteKey(int i){
    decreaseKey(i, INT32_MIN);
    extractMinEle();
}

void minHeap::heapify(int i){
    int l=left(i);
    int r=right(i);
    int smallest=i;//parent
    if(l<size && heap[l]<heap[i])
        smallest=l;
    if(r<size && heap[r]<heap[smallest])
        smallest=r;
    // found the smallest among the left child / right child / parent
    if(smallest!=i){
        // if the smallest is not parent
        std::swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}
int main(int argc, char const *argv[])
{
    minHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);

    std::cout<<h.extractMinEle()<<std::endl;
    std::cout<<h.getMin()<<std::endl;
    h.decreaseKey(2,1);
    std::cout<<h.getMin()<<std::endl;
    remove(argv[0]);
    return 0;
}

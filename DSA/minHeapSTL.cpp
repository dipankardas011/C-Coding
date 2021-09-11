#include <iostream>
#include <queue>
#include <vector>
/*minheap using the stl priority queue*/
void print(std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int32_t>> q){
    while(!q.empty()){
        std::cout<<'\t'<<q.top();
        q.pop();
    }
    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
    std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int32_t>> que;

    que.push(10);
    que.push(30);
    que.push(20);
    que.push(5);
    que.push(1);
    std::cout<<"the priority queue : ";
    print(que);
    std::cout<<"size(): "<<que.size()<<std::endl;
    std::cout<<"top(): "<<que.top()<<std::endl;
    std::cout<<"pop(): ";
    que.pop();
    print(que);
    remove(argv[0]);
    return 0;
}

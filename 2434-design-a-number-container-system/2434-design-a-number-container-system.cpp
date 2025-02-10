class NumberContainers {
public:
    map<int,int> indxEle;
    map<int,set<int>> eleIndx;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        eleIndx[number].insert(index); 
       if(indxEle.count(index)){
            eleIndx[indxEle[index]].erase(index);
            indxEle[index] = number;
            eleIndx[number].insert(index);
       }
       else{
        indxEle[index] = number;
       }
        
    }
    
    int find(int number) {
        if(eleIndx.find(number) != eleIndx.end() && !eleIndx[number].empty()){
            return *eleIndx[number].begin();
        }
        else{
            return -1;
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
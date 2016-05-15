#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <cstdlib>
#include <time.h>


using namespace std;

// Abstract class for data sets
class dataset{
public:
    virtual void populate(void) = 0;
    virtual int size(void) = 0;
    void nothing(void);
};

void dataset::nothing(void){
    return;
}

// Concrete subclass of integer data sets
class integersDataset : dataset{
private:
    multiset<unsigned int> data;
public:
    // concrete instances of the virtual methods
    void populate(void);
    int size(void);
    // new method in this class
    // mode: most frequent element in the dataset
    int mode(void);
};

// Concrete subclass of integer data sets
class doublesDataset : dataset{
private:
    set<double> data;
public:
    // concrete instances of the virtual method
    void populate(void);
    int size(void);
    // new method in this class
    double average(void);
};

// Specialized method populate for subclass integersDataset
void integersDataset::populate(void){
    
    // delete old content
    data.clear();
    
    // Insert a random number of random integers between 0 and 99
    do{
        data.insert(rand()%100);
    }while(rand()%100);
    
}

// Specialized method populate for subclass doublesDataset
void doublesDataset::populate(void){
    
    // delete old content
    data.clear();
    
    // Insert a random number of random doubles between 0 and 99
    do{
        data.insert((double)(rand()%100));
    }while(rand()%100);
    
}

int integersDataset::size(void){
    return data.size();
}

int doublesDataset::size(void){
    return data.size();
}

int integersDataset::mode(){
    
    map<int,int> occurrences;
    int maxOccurrences, mode;
    
    maxOccurrences = 0;
    mode = 0;
    
    for (int x : data)
    {
        cout<<x<<"     original value :" <<occurrences[x]<<endl;
    }
        cout<<"just for Test"<<endl;
    for (int x : data)
    {
        cout<<x<<"     original value :" <<occurrences[x]<<endl;
        occurrences[x]++;
        if (occurrences[x] > maxOccurrences){
            maxOccurrences = occurrences[x];
            mode = x;
        }
    }
    
    return mode;
    
}

double doublesDataset::average(){
    double avg;
    avg = 0.0;
    for(multiset<double>::iterator i=data.begin(); i!=data.end(); i++){
        avg += *i;
    }
    avg = avg/data.size();
    return avg;
}


int main(void){
    integersDataset a;
    doublesDataset b;
    srand(time(NULL));
       
    a.populate();
    cout << "Integer dataset with " << a.size()
    << " elements and mode " << a.mode() << endl;
    
    b.populate();
    cout << "Doubles dataset with " << b.size()
    << " elements and average " << b.average() << endl;
    cout<<rand()<<endl;
    
    return 0;
}




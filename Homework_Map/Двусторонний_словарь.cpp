#include <iostream>
#include <map>
#include <vector>

template<typename T, typename U>
class BidirectionalMap {
    std::map<T, U> mp;
    std::map<U, T> reversed;
public:
    void insert(const T& key, const U& value) {
        if(mp.count(key) || reversed.count(value)) return;
        mp[key] = value;
        reversed[value] = key;
    }
    U getByKey(const T& key) const {
        auto it = mp.find(key);
        if(it != mp.end()) {
            return it->second;
        }
        throw std::exception();
    }
    T getByValue(const U& value) const {
        auto it = reversed.find(value);
        if(it != reversed.end()) {
            return it->second;
        }
        throw std::exception();
    }
    void removeByKey(const T& key) {
        auto it = mp.find(key);
        if(it == mp.end()) return;
        U value = it->second;     
        mp.erase(it);             
        reversed.erase(value);    
    }
};

int main() {
    BidirectionalMap<int, std::string> bm;
    bm.insert(1, "one");
    bm.insert(2, "two");
    std::cout << bm.getByKey(1) << '\n';      
    std::cout << bm.getByValue("two") << '\n'; 
    return 0;
}

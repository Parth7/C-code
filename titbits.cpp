//
// Created by Parth Parakh on 15/06/23.
//

#include<vector>
#include <string>

class PayOff {

private:
    static int f;
public:
    PayOff() = default;
    virtual ~PayOff() = default;

    virtual PayOff operator()(const double& S) const {
        return *this;
    };

    template<class T>
    static auto foo(const T &arg) {
        f = 2;
    }

};

std::vector<char> myvec{
    []{
        std::vector<char> v;
        for(auto i='a';i<='z';i++){
            v.push_back(i);
        }
        return v;
    }()
};

std::vector<char> mvec{
    []{
        std::vector<char> x;
        for(auto i='a';i<='z';i++){
            x.emplace_back(i);
        }
        return x;
    }()
};

class singleton{

private:

    std::string s,p;
    singleton() = default;

    static singleton* instance;

public:

    singleton(const singleton& s) = delete;

    static singleton *getInstance()
    {
        if (instance==nullptr){
            instance = new singleton();
            return instance;
        } else {
            return instance;
        }
    }

    void setValue(const std::string& st, const std::string& pt){
        s = st;
        p = pt;
    }

};

singleton* singleton::instance = nullptr;






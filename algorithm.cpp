//
// Created by Parth Parakh on 14/06/23.
//

#include <array>
#include <vector>
#include <numeric>
#include <iostream>
#include <unordered_set>
#include <random>


template<class T>
decltype(auto) max_value(const std::vector<T> &a) {
    if(a.empty()) {
        return std::numeric_limits<T>::min();
    }
    T m = a[0];
    for(auto &n:a){
        m = std::min(m,n);
    }
    return m;
}

template<class T>
decltype(auto) max_element_idx(const std::vector<T> &a) {
    if(a.empty()) {
        return 0;
    }
    auto m = 0;
    for(auto i=0;i<a.size();i++){
        if(a[i]>a[m]) m = i;
    }

    return m;
}

template<class T>
auto max_element_ptr(T* first, T* last) {
    if(first == last) {
        return last;
    }

    auto m = first;
    for(auto i = m+1; i<last; i++ ){
        if(*i>m) m = i;
    }

    return m;
}


template<class T>
T max_element_iter(T first, T last){
    if(first==last) return last;

    T largest = first;
    ++first;
    while(first!=last) {
        if(*first > *largest) largest = first;
    }

    return largest;
}


template <class T>
std::pair<T,size_t> max_element_iter_count_ops(T first, T last) {
    size_t count = 0;

    if(first==last) return std::make_pair(last,count);

    T largest = first;
    ++first;
    while(first!=last) {
        count ++;
        largest = max(first, largest);
        ++first;
    }

    return {largest,count};
}

template<class T, class IT>
IT max_element_iter(const T& range) {
    return max_element_iter(range.begin(), range.end());
}

template<class GENERATOR, class T>
std::vector<T> generate_vector(size_t n, GENERATOR& g) {
    std::vector<int> result(n);
    std::iota(result.begin(),result.end(),0);
    std::shuffle(result.begin(),result.end(), g);
    return result;
}

int main(){

    std::vector<int> v = { 7,3,5,8,9,3,2,6,7};

    std::cout<< max_value(v)<<std::endl;

    std::cout<<max_element_idx(v)<<std::endl;

    std::cout<<v[max_element_idx(v)]<<std::endl;

    int *p = max_element_ptr(&v[0],&v[v.size()]);
    std::cout<< *p<< std::endl;
    std::cout<< p<< std::endl;

    std::unordered_set<int> s = {6,5,6,7,8,3,4};
    auto it = max_element_iter(s.begin(), s.end());
    std::cout << "*it: " << *it << '\n';

    // Random generator
    std::random_device r;
    unsigned int seed = r();
    std::default_random_engine g(seed);
    v = generate_vector<std::default_random_engine,int>(1000, g);
    auto it2 = max_element_iter(v.begin(), v.end());
    std::cout << "*it2: " << *it2 << '\n';

    std::vector<size_t> sizes = {2,4,8,16,32,64,128,256,512,1024};

    std::vector<std::vector<std::chrono::nanoseconds>> duration;

    constexpr size_t replicates = 300;

    for(const auto &n : sizes) {
        duration.emplace_back(0);
        for(auto i=0;i<replicates;i++) {
            auto tmp = generate_vector<std::default_random_engine,int>(n,g);
            auto start_time = std::chrono::system_clock::now();
            auto max_it = max_element_iter(tmp.begin(),tmp.end());
            auto end_time = std::chrono::system_clock::now();
            auto duration_algorithm = end_time - start_time;
            std::cout<<*max_it<<std::endl;
            duration.back().emplace_back(duration_algorithm);
        }
    }

    for(auto i =0;i<sizes.size();i++){
        auto total_duration = std::accumulate(duration[i].begin(),duration[i].end(),std::chrono::nanoseconds(0));
    }

    std::vector<std::chrono::nanoseconds ::rep > avg_duration;
    for(auto i =0;i<sizes.size();i++) {
        auto total_duration = std::accumulate(duration[i].begin(),duration[i].end(),std::chrono::nanoseconds(0));
        avg_duration.emplace_back(total_duration.count()/replicates);
    }

    std::vector<std::vector<size_t>> count_ops_table;
    for(const auto& n:sizes) {
        count_ops_table.emplace_back(0);
        for (size_t i = 0; i < replicates; ++i) {
            auto tmp = generate_vector<std::default_random_engine ,int>(n, g);
            auto [max_it, count_ops] = max_element_iter_count_ops(tmp.begin(), tmp.end());
            count_ops_table.back().emplace_back(count_ops);
        }
    }

    // Print results
    for (size_t i = 0; i < sizes.size(); ++i) {
        auto total_operations = std::accumulate(count_ops_table[i].begin(), count_ops_table[i].end(), size_t(0));
        std::cout << "Size: " << sizes[i]  << ", " << " Operations: " << total_operations / replicates << '\n';
    }
 
    // Plot results
    std::vector<double> avg_ops;
    for (size_t i = 0; i < sizes.size(); ++i) {
        auto total_operations = std::accumulate(count_ops_table[i].begin(), count_ops_table[i].end(), size_t(0));
        avg_ops.emplace_back(static_cast<double>(total_operations) / replicates);
    }

    return 0;
}


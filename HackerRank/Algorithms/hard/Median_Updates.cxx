#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include<sstream>

using namespace std;
/* Head ends here */

void debug(std::multiset<long long>& ms)
{
    auto it = ms.begin();
    std::cout << "   debug : ";
    while (it != ms.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n";
    it = ms.begin();
    std::cout << "   debug : ";
    while (it != ms.end())
    {
        std::cout << &*it << " ";
        ++it;
    }
    std::cout << "\n";
}
void print_double(double x)
{
    stringstream ss;
    ss << std::fixed << x;
    auto s = ss.str();
    int i = s.size()-1;
    while (s[i] == '0')
    {
        --i;        
    }
    //std::cout << s << "\n";
    //std::cout << "i = " << i <<  std::endl;
    if (s[i] == '.') {
        std::cout << static_cast<long long>(x) << "\n";
    } else {
        std::cout << s.substr(0, i+1) << "\n";
    }   
}

void median(vector<char> s,vector<int> X) {
    std::multiset<long long> S;
    bool invalid = true;
    std::multiset<long long>::iterator it = S.begin();
    for (int i = 0; i < s.size(); ++i) {
        //std::cout << "     " << s[i] << " " << X[i] << "\n";
        if (s[i] == 'r') {
            auto found = S.find(X[i]);
            if (S.size() == 0 || found == S.end())
            {
                std::cout << "Wrong!\n";
                continue;
            } else {
                
                auto to_rm = found;
                if (S.size() % 2 == 0)
                {
                    if (X[i] >= *it) //|| X[i] == *it && S.count(X[i]) == 1)
                    {
                        auto itt = it;
                        itt--;
                        if (X[i] == *it && *itt == X[i])
                        {
                            
                        } else {
                            --it;
                        }
                    }
        
                } else {
                    if (X[i] <= *it)
                    {
                        ++it;
                    }
                }
                S.erase(to_rm);
            }
        } else {
            auto it_inserted = S.insert(X[i]);
            //std::cerr << "inserted at " << &*it_inserted << std::endl;
/*            std::cout << "dist inserted = " << std::distance(S.begin(), it_inserted) << std::endl;
            std::cout << "val at begin  " << *S.begin() << std::endl;
            std::cout << "val at it  " << *it << std::endl;
            std::cout << &*S.begin() << std::endl;
            std::cout << &*it << std::endl;
            std::cout << "dist it " << std::distance(S.begin(), it) << std::endl;
            std::cout << "dist it " << std::distance(S.begin(), S.begin()) << std::endl;*/
            if (invalid == false)
            {
                if (S.size() % 2)
                {
                    if (X[i] < *it)
                    {
                        --it;
                    }
                } else {
                    if (X[i] >= *it) // check if <=
                    {
                        ++it;
                    } 
                }
            }
        }
        
            
        if (S.size() == 0) {
            std::cout << "Wrong!\n";
            invalid = true;
            continue;
        }
        if (invalid)
        {
            it = S.begin();
            std:advance(it, S.size()/2);
            invalid = false;
        }   
        
        //debug(S);
        if (invalid == false) {
            //std::cout << "    it = " << &*it << std::endl;;
            //std::cerr << "    it = " << *it << std::endl;;
            //std::cerr << "    dist = " << std::distance(S.begin(), it) << "\n";
        }
        
     
        
        if (S.size() % 2)
        {
            std::cout << *it << std::endl;;
        } else {
            auto it2 = it;
            it2--;
            if (*it == *it2)
            {
                std::cout << *it << "\n";
            } else if ((*it + *it2) % 2 == 0)
            {
                std::cout << (*it + *it2)/2 << "\n";
                
            } else {
                print_double(static_cast<double>(*it + *it2) / 2);
            }
        }
    }
    
}
int main(void){

//Helpers for input and output
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    
    vector<char> s;
    vector<int> X;
    char temp;
    int tempint;
    for(int i = 0; i < N; i++){
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }
    
    median(s,X);
    return 0;
}


#include <iostream>
#include <cstring>   
#include <string>       
#include <vector>       
#include <list>        
#include <queue>        
#include <stack>        
#include <algorithm>

using namespace std;
struct Snack {
    char nama[50]; 
    string kategori;        
    int harga;
    double rating;

    double rasio() const {
        return rating / harga;
      }
};


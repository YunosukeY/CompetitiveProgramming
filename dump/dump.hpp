// g++ -std=c++11 -pthread
#include<bits/stdc++.h>
#include<boost/core/demangle.hpp>
using namespace std;

/* dump function for
   
    usual variable,
    string literal,
    usual array,

    pair,
    tuple,
    basic_string,

    bitset,
    vector,
    array,
    valarray,
    deque,
    list,
    forward_list,
    map,
    multimap,
    unordered_map,
    unordered_multimap,
    set,
    multiset,
    unordered_set,
    unordered_multimap,

    queue,
    stack,
    priority_queue,

    atomic,
    and mutex.
*/

#define dump(...) {dump_func(#__VA_ARGS__,__VA_ARGS__);cerr<<"["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl<<endl;}

// erase all source in target
template<class C>
basic_string<C> erase_all(basic_string<C> target, basic_string<C> source){
  int pos;
  while((pos = target.find(source)) != -1) target.erase(pos,source.size());
  return target;
}

// erase all ",source<...>" in target
template<class C>
basic_string<C> erase_bracket(basic_string<C> target, basic_string<C> source){
  int fstpos;
  while(1){
    fstpos = target.find(source);
    if(fstpos > 0){
      int endpos = fstpos + source.size() , c = 0;
      for(endpos = fstpos + (int)source.size(); endpos < (int)target.size(); ++endpos){
	if(target[endpos] == '<') c++;
	else if(target[endpos] == '>') c--;
	if(c == 0) break;
      }
      target.erase(fstpos - 1, endpos - fstpos + 2);
    }else{
      break;
    }
  }
  return target;
}

// usual array
template<class C, int size, enable_if_t<not is_same<C,char>::value,nullptr_t> = nullptr>
ostream& operator << (ostream& os, const C (&ar)[size]){
  os << '[';
  for(int i = 0; i < size; i++){
    if(i == 0) os << *ar;
    else os << ", " << *(ar + i);
  }
  os << ']';
  return os;
}

// pair
template<class C, class D>
ostream& operator << (ostream& os, const pair<C, D>& p){
  os << '(' << p.first << ", " << p.second << ')';
  return os;
}

// tuple
template<class... Args, size_t... indexes>
ostream& output_tuple(ostream& os, tuple<Args...> const& t, index_sequence<indexes...>){
  initializer_list<int>{ ((indexes ? os << ", " << get<indexes>(t) : os << get<indexes>(t)), 0)... };
  return os;
}
template<class... Args>
ostream& operator << (ostream& os, const tuple<Args...> t){
  os << '(';
  constexpr size_t n = tuple_size<tuple<Args...>>::value;
  output_tuple(os, t, make_index_sequence<n>());
  os << ')';
  return os;
}

// container
template <class C, enable_if_t<not is_same<C,string>::value,nullptr_t> = nullptr>
auto operator<<(ostream& os, const C& container)
  -> typename conditional<true, ostream&, decltype(container.begin())>::type{
  os << '{';
  for(auto itr = container.begin(); itr != container.end(); ++itr){
    if(itr == container.begin()){
      os << *itr;
    }else{
      os << ", " << *itr;
    }
  }
  os << '}';
  return os;
}

// valarray
template <class C>
ostream& operator<<(ostream& os, const valarray<C>& va){
  os << '{';
  for(auto itr = begin(va); itr != end(va); ++itr){
    if(itr == begin(va)){
      cout << *itr;
    }else{
      cout << ", " << *itr;
    }
  }
  os << '}';
  return os;
}

// queue
template <class C>
ostream& operator<<(ostream& os, const queue<C>& q){
  os << '{';
  int sz = q.size();
  if(sz > 0) os << q.front();
  if(sz > 2) os << ", ... ";
  if(sz > 1) os << ", " << q.back();
  os << '}';
  return os;
}

// stack, priority_queue
template <class C>
auto operator<<(ostream& os, const C& container)
  -> typename conditional<true, ostream&, decltype(container.top())>::type{
  os << '{';
  if(!container.empty()) os << container.top();
  if(container.size() > 1) os << ", ... ";
  os << '}';
  return os;
}

// mutex
template <class C>
auto operator<<(ostream& os, C& mtx)
  -> typename conditional<true, ostream&, decltype(mtx.lock())>::type{
  auto f = [&](){
    bool fl = mtx.try_lock();
    if(fl) mtx.unlock();
    return not fl;
  };
  auto result = async(launch::async,f);
  if(result.get()) os << "locked";
  else os << "unlocked";
  return os;
}

// base part of recursion
void dump_func(string s){
  s = "";
}

// let head be a second argument, and let tail be after third argument recursively
template <class Head, class... Tail> void dump_func(string s, Head&& head, Tail&&... tail){
  // show variable name
  int pos = s.find(",");
  if(pos != -1) cerr << s.substr(0,pos).c_str();
  else cerr << s.c_str();
  
  string nm = boost::core::demangle(typeid(head).name()); // type name of variable
  
  nm = erase_all(nm, string("std::"));     // erase "std::"
  nm = erase_all(nm, string("__debug::")); // erase "__debug::"
  nm = erase_all(nm, string("__cxx11::")); // erase "__cxx11"
  nm = erase_all(nm, string(" "));         // erase " "
  
  nm = erase_bracket(nm, string("allocator"));   // erase ",allocator<...>"
  nm = erase_bracket(nm, string("char_traits")); // erase ",char_traits<...>"
  nm = erase_bracket(nm, string("less"));        // erase ",less<...>"
  nm = erase_bracket(nm, string("greater"));     // erase ",greater<...>"
  nm = erase_bracket(nm, string("equal_to"));    // erase ",equal_to<...>"
  nm = erase_bracket(nm, string("hash"));        // erase ",hash<...>"

  // erase ",vector<...>"
  // comment out when you use priority_queue<vector<...>>
  if(nm.find("priority_queue") == 0) nm = erase_bracket(nm, string("vector"));

  // erase ",deque<...>"
  // comment out when you use queue<deque<...>> or stack<deque<...>>
  if(nm.find("queue") == 0 or nm.find("stack") == 0) nm = erase_bracket(nm, string("deque"));

  cerr << " : " << nm.c_str() << endl << "= " << head << endl;
  
  // through " "
  while(s[pos+1] == ' ') pos++;
  
  dump_func(s.substr(pos+1), move(tail)...);
}

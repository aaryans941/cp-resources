#include <bits/stdc++.h>
using namespace std;

//#define dbg(x) {auto x_=x; auto red = "\e[91m", reset = "\e[39m"; cerr<<red<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<reset<<endl;}
/*
 *template<typename Tp>
 *typename enable_if<is_same<Tp,ostream>::value, Tp&>::type operator<<(Tp& os,  const auto& v){
 *    os<<"[";
 *    for(auto& x:v){os<<x<<", ";}
 *    return os<<"]";
 *}
 *template<typename ...Ts>
 *auto& operator<<(auto& os,  const pair<Ts...>& p){
 *    return os<<p.first<<","<<p.second;
 *}
 */

#define dbg(...) { cerr<<"[ "; __AaryanS__(#__VA_ARGS__, __VA_ARGS__);}
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
	return out<<"("<<x.first<<","<<x.second<<")";
}

template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
	out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
	out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
ostream& operator << (ostream& out, const multiset<Arg1> &a) {
	out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
	out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
void __AaryanS__(const string name, Arg1&& arg1){
		cerr << name << " : " << arg1 << " ] " << endl;
}

template <typename Arg1, typename... Args>
void __AaryanS__(const string names, Arg1&& arg1, Args&&... args){
		const string name = names.substr(0,names.find(','));
		cerr<<name<<" : "<<arg1<<" | ";
		__AaryanS__(names.substr(1+(int)name.size()), args...);
}
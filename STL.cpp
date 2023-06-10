#include<bits/stdc++.h>
using namespace std;

// STL divide into 4 parts
// 1. Algorithms
// 2. Containers
// 3. Functions
// 4. Iterators


// Utility lib
// 1. Pairs


// Pairs
void explainPairs() {
	pair<int, int> p = {1,2};  // creating pair containing both int type values
	cout<<p.first<<" "<<p.second<<endl; // p.first for first value in pair same goes for second

	// Pair of Pair
	pair<int, pair<int, int>> pp = {1, {2,3}};   // nesting of pairs into pairs
	cout<<pp.first<<" "<<pp.second.first<<" "<<pp.second.second<<endl;

	// Array of pairs
	pair<int, int> arr[] = {{1,2}, {3,4}, {5,6}};  // creating an array of pairs
	cout<<arr[0].first<<" "<<arr[1].first<<" "<<arr[1].second<<endl;
}


// Vectors
void explainVectors() {

	// Vectors are dynamic arrays which always doubles theri size if their space gets full
	// and they want to insert a new element into them after getting full
	// then the size of the current array becomes double and the previous values gets copied
	// into this new doubled size array and at last the new value/element gets added

	vector<int> v;  // creating a v vector with no predefined size
	v.push_back(1);   // inserting 1 in v vector
	v.emplace_back(2); // also inserting 2 in v vector but this is faster then push_back

	vector<pair<int, int>> vec;   // creating a vecotr of pair datatype. This array stores pair 
	vec.push_back({1,2});
	vec.emplace_back(1,2);

	vector<int> sizeVector(5); // vector with 5 size predefined
	// output {5 garbage values/ 0 values }

	vector<int> initVector(5, 100); // 5 is size, 100 is value
	// output {100, 100, 100, 100, 100}

	vector<int> v1(5, 10);
	vector<int> v2(v1);  // V2 vector is the copy of the v1 vector. It is totally new created array with same values as v1.

	vector<int>::iterator it = v.begin(); // using an iterator to traverse the vector 
	// iterator always point on the memory address of the container
	// like here it is initialised with v.begin where it is now pointing on the first element 
	// memory address of the v vector
	// if we print it -> result will be the memory address
	// if we print *(it) -> result will be the value stored at it address
	// for more info about address, * read about pointers in c++
	it++;

	cout<<*(it)<<endl;

	it = it+2;
	cout<<*(it)<<endl;

	vector<int>::iterator itend = v.end();  // v.end in iterator always placed right after the last element of an array 
	vector<int>::iterator itrend = v.rend();  // v.rend is reverse end opposite of end
	vector<int>::iterator itrbegin = v.rbegin(); // v.rbegin is reverse begin opposite if begin

	cout<<v[0]<<" "<<v.at(0); // v[0] and v.at(index) is used to fetch the value at the provided index
	cout<<v.back()<<endl; // v.back() provide the value from last or end value


	for(vector<int>::iterator i = v.begin() ; i != v.end() ; i++){
		// we are using the it != v.end() condition because v.end points at the next address of the last 
		// elememt address
		cout<<*(i)<<endl;
	}

	for(auto itt = v.begin() ; itt != v.end() ; itt++){
		cout<<*(itt)<<endl;
	}

	for(auto itr : v) {
		cout<<itr<<endl;
	}

	v.erase(v.begin()+1); // {10,20,30,40} erase 20 from this array
	v.erase(v.begin()+2, v.begin()+4); // {10,20,30,40,50} [start, end)
	// output: {10,20,50}


	// Insert function
	vector<int> v9(5, 100);  // create an array of size 5 with all 100 values (size, value)
	v9.insert(v.begin(), 300);  // insert 300 at the beginning of the array (position, value)
	v9.insert(v.begin()+1, 2, 10); // insert 10 2 times at the position mentioned (position, times, value)

	cout<<v9.size()<<endl; // gives size of the array (current)
	v9.pop_back(); // pop out the last element

	v1.swap(v2); // can swap the two vectors
	v9.clear(); // erase the entire array
	cout<<v.empty()<<endl; // will tell if the array is empty or not return boolean value
}

void explainList() {
	// same as vector 
	// difference is it gives you front operations as well

	list<int> ls;
	ls.push_back(2); // {2}
	ls.emplace_back(4); // {2,4}
	ls.push_front(5); // {5,2,4}
	ls.emplace_front(6); // {6,5,2,4}

	// rest functions same as vector
	// begin, end, rbegin, rend, clear, insert, size, swap, empty


	// For vector singly linked list is maintaned internally  push_back is costly operation 
	// For list doubly linked list is maintained internally  push_front is cheap
}

void explainDeque() {
	deque<int> dq;
	dq.push_back(1);  // {1}
	dq.emplace_back(2);  // {1,2}
	dq.push_front(3);  // {3,1,2}
	dq.emplace_front(4);  // {4,3,1,2}

	dq.pop_back();  // {4,3,1}
	dq.pop_front();  // {3,1}

	dq.back();
	dq.front();

	// rest functions same as vector
	// begin, end, rbegin, rend, clear, insert, size, swap, empty
}

void explainStack() {
	// Follow LIFO principle

	stack<int> st;
	st.push(1); // {1}
	st.push(2); // {2,1}
	st.push(3); // {3,2,1}
	st.push(4); // {4,3,2,1}
	st.emplace(5); // {5,4,3,2,1}

	cout<<st.top()<<endl; // gives the value at the top 5
	st.pop();  // pop out the top element {4,3,2,1}
	cout<<st.size()<<endl; // gives size of the stack
	cout<<st.empty()<<endl; // return bool value, tells is stack is empty or not

	stack<int> st1, st2;
	st1.swap(st2);

	// everytihing will be done in O(1)
}

void explainQueue() {
	// This DS is similar to stack but this is FIFO type.

	queue<int> q;
	q.push(1); // {1}
	q.push(2); // {1,2}
	q.emplace(4); // {1,2,4}
	q.back(); //  gives last number in the queue i.e 4
	q.back() = q.back() + 5;   // prints 9 (4+5)
	q.back() += 5;  // prints 14 (9+5)

	q.front(); // gives the first or front element in the queue
	q.pop(); // pop the front element 

	// size, swap, empty are same as stack
}

void explainPQ() {
	// PQ stands for priority queue
	// PQ is used to simulate the max/min heap DS.
	// Internally a tree is implemented to simulate this DS

	// Max heap
	priority_queue<int> pq; // by default we get max heap which always place largest element on top
	pq.push(5); // {5} O(n)
	pq.push(2); // {5,2}
	pq.push(8); // {8,5,2}
	pq.emplace(10);	// {10,8,5,2}

	cout<<pq.top()<<endl; // gives the top guy i.e 10 O(1)

	pq.pop(); // {8,5,2} pops out the top element i.e 10 O(logn)
	// size, swap, empty are same as others

	// Minimum/Min heap
	priority_queue<int, vector<int>, greater<int>> pq1;
	pq.push(5); // {5}
	pq.push(2); // {2, 5}
	pq.push(8); // {2, 5, 8}
	pq.emplace(10);	// {2,5,8,10}

	cout<<pq.top()<<endl; // gives the top guy i.e 2 (minimum is on top)
}

void explainSet() {
	// sorted + unique
	// internally a tree is maintained 
	// everything happens in logn time O(logn)

	set<int> st;
	st.insert(1); // {1}
	st.insert(2); // {1, 2}
	st.insert(2); // {1, 2}
	st.emplace(4); // {1, 2, 4}
	st.insert(3); // {1, 2, 3, 4}  mainitain in orderly (sorted) fashion and only persist the unique elements

	// same methods can be used as vectors in this DS.

	auto it =  st.find(3); // will find the value for you and return its position/address

	auto it =  st.find(6); // will try to find if not present will return st.end() i.e right after last value position

	st.erase(5); //  this will log time

	int count = st.count(2) // will give occurence if exist i.e 1 always if exist else gives 0

	st.erase(it); // we can give iterator as well to erase the element O(1)

	auto it1 = st.find(2);
	auto it2 = st.find(4);
	st.erase(it1, it2); //  can also erase by giving starting and ending point as well [first, last)

	// lower_bound and upper_bound works same as vector

	auto it3 = st.lower_bound(2);
	auto it4 = st.upper_bound(3);

}

void explainMultiSet() {
	// same as set but also stores duplicate numbers (sorted order follows)

	multiset<int> ms;
	ms.insert(1); // {1}
	ms.insert(1); // {1, 1}
	ms.insert(1); // {1, 1, 1}

	ms.erase(1); // {} all 1's erased from multiset always removes the entire element duplicates too

	int count = ms.count(1); // gives the occurence of the 1 i.e 3 before erase

	ms.erase(ms.find(1)); // only erase the first 1 from all 1's

	ms.erase(ms.find(1), ms.find(1)+2); // here it erase according to the given range

	// rest is same as set
}

void explainUnorderedSet() {
	unordered_set<int> st;

	// lower_bound and upper_bound func does not work because not sorted
	// rest functions are all same as set
	// it does not store in any particular order
	// it has better complexity then set in most cases
	// except some when collisions happens 
	// stores unique values  O(1)
}

void explainMap() {
	// Map is all about storing key value pairs.
	// Map only stores unique keys in sorted order 

	map<int, int> mp;
	map<int, pair<int, int>> mpp;
	map<pair<int, int>, int>> mpi;

	mpp[1] = 2; // 1 is key and 2 is value
	mpp.emplace({3,4});
	mpp.insert({4,5});
	mpi[{2,3}] = 10; // here key is in pair

	for(auto it : mpp) {
		cout<<mpp.first<<" "<<mpp.second<<endl;
	}

	cout<<mpp[1]; // gives value of key 1
	coun<<mpp[5]; // gives value of key 5 if not exist give either 0 or null or garbage value

	auto it = mpp.find(3);
	cout<<*(it).second<<endl; // it gives address, *(it) gives value at that it address

	// it you try to find something that do not exist then it will
	// point at mpp.end() right after the last element

	auto it = mpp.lower_bound(2);
	auto it = mpp.upper_bound(4);

	// erase, swap, size, empty works same as above 
}

void explainMultiMap() {
	// same as map but can also store duplicate/multple keys
	// only mpp[key] acannot use here
	// sorted order
}


void explainUnorderedMap() {
	// same as map but not follow sorting
	// map - O(logn), unorderdMap - O(1)
}

bool comp(pair<int, int>p1, pair<int, int>p2) {
	if(p1.second < p2.second){
		return true;
	}
	else if(p1.second == p2.second){
		if(p1.first > p2.first)
			return true;
	}
	return false;
}

void algorithms() {
	// a[5] = {1,5,6,3,7}

	sort(a, a+n); // n is size of a
	sort(a.begin(), a.end()); // a should be vector here
	sort(a+2, a+4); //  sort in a range 
	sort(a, a+n, greater<int>); // sort in descending order

	// greater<int> is an inbuilt comparator 

	pair<int, int> arr[] = {{1,2}, {2,1}, {4,1}};

	// custom comparator 
	// sort it according to second element
	// if second element is same then
	// sort it according to first element but in descending

	sort(a, a+n, comp); // comp is boolean function 
	// {{4,1}, {2,1}, {1,2}}

	int num = 7;
	int cnt = __builtin_popcount(); //  gives the number of setbits/1's in total of 32 bits

	long long num = 136128367381;
	int cnt = __builtin_popcountll(); // this is used for long long data type

	string s = "123";
	do {
		cout<<s<<endl;
	} while(next_permutation(s.begin(), s.end()));  // print till null when no permutations left 

	int maxi = *max_element(a, a+n);
	int mini = *min_element(a, a+n);
}

int main() {
	string s;
	cin>>s;
	cout<<"Hello "<<s<<endl;


	explainPairs();
	explainVectors();
	explainList();
	explainDeque();
	explainStack();
	explainQueue();
	explainPQ();
	explainMultiSet();
	explainUnorderedSet();
	explainMap();
	algorithms();

	return 0;
}
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

int main() {
	string s;
	cin>>s;
	cout<<"Hello "<<s<<endl;


	explainPairs();
	explainVectors();
	explainList();
	explainDeque();
	explainStack();

	return 0;
}
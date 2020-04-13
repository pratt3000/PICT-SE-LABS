template<class T>
class SetNode{
private:
	T data;
	SetNode<T> *link;
public:
	SetNode();
	SetNode(T);
	
	template<class U>
	friend class Set;
};



template<class T>
class Set{
private:
	SetNode<T> *start;
public:
	Set();
	void print();
	void add(T);
	bool contains(T);
	bool remove(T);
	int size();
	bool isSubset(Set<T>);
	Set<T> unification(Set<T>);
	Set<T> intersection(Set<T>);
	Set<T> difference(Set<T>);
};

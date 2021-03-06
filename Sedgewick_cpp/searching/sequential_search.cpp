#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::cin;

/*TODO
	- make other member functions that Symbol Table needs
	- Keys

DONE
	- Contains, Delete
*/


template <typename Key, typename Value>
class SequentialSearchST
{
public:
	class Node
	{
	private:
	public:
		Key key_;
		Value value_;
		Node * next_;

		Node(Key key, Value value, Node * next) : key_(key), value_(value), next_(next)
		{ }

	};
	Node * first_ = nullptr;

private:
	int num_ = 0;

public:
	SequentialSearchST()
	{}


	Value Get(Key key)
	{
		for(Node * i = first_; i != nullptr; i = i->next_)
			if (i->key_ == key)
				return i->value_;

		throw -1;
	}

	bool Contains(Key key)
	{
		for (Node * i = first_; i != nullptr; i = i->next_)
			if (i->key_ == key)
				return true;

		return false;
	}

	void Put(Key key, Value value)
	{
		for (Node * i = first_; i != nullptr; i = i->next_)
			if (i->key_ == key)
			{ i->value_ = value; return; }

		first_ = new Node(key, value, first_);
		num_++;
		return;
	}

	void Delete(Key key)
	{
		Node * tmp;
		if (first_->key_ == key)
		{
			tmp = first_;
			first_ = first_->next_;
			delete tmp;
			--num_;

			return;
		}

		for (Node * i = first_; i != nullptr; i = i->next_)
		{
			if (i->next_->key_ == key)
			{
				tmp = i->next_;
				i->next_ = i->next_->next_;
				delete tmp;
				--num_;

				return;
			}
		}
	}

	int Size()
	{ return num_; }

	bool IsEmpty()
	{ return num_ == 0; }

	void Keys()
	{
	}


	~SequentialSearchST()
	{
		Node * tmp;

		while (first_ != nullptr)
		{
			tmp = first_;
			first_ = first_->next_;

			delete tmp;
		}
	}
};

int main()
{
	SequentialSearchST<std::string, int> st;

	st.Put("f", 6);
	st.Put("b", 2);
	st.Put("c", 3);
	st.Put("a", 1);
	st.Put("e", 5);
	st.Put("d", 4);
	st.Put("g", 7);
	st.Put("a", 11);

	cout << "a: " << st.Get("a") << endl;
	cout << "b: " << st.Get("b") << endl;

	if (st.Contains("a"))
		cout << "table has key \"a\"" << endl;
	else
		cout << "table doesn't have key \"a\"" << endl;

	st.Delete("a");
	if (st.Contains("a"))
		cout << "table has key \"a\"" << endl;
	else
		cout << "table doesn't have key \"a\"" << endl;

	if (st.IsEmpty())
		cout << "table is empty" << endl;
	else
		cout << "table is not empty" << endl;

	cout << "table size is " << st.Size() << endl;

	for (;;)
	{
		break;
	}

	return 0;
}

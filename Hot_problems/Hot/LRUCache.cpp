//lc_146,LRU缓存机制实现
#include<unordered_map>
#include<iostream>
#include<vector>
#include<list>
using namespace std;

//参考链接：https://github.com/cpselvis/leetcode/blob/master/solution146.cpp

struct LRUNode
{
	int key, value;
	LRUNode *prev, *next;
	LRUNode():key(0),value(0),prev(nullptr),next(nullptr){}
	LRUNode(int _key, int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};

class LRUcache {
private:
	int key, value;
	unordered_map<int, LRUNode*> cache;
	int size;
	int capacity;
	LRUNode* head;
	LRUNode* tail;
public:
	LRUcache(int _capacity) {
		size = 0;
		capacity = _capacity;
		head = new LRUNode();
		tail = new LRUNode();
		head->next = tail;
		tail->prev = head;
	}
	int get(int key) {
		if (!cache.count(key)) {
			return -1;
		}
		LRUNode* node = cache[key];
		moveToHead(node);
		return node->value;
	}
	void put(int key, int value) {
		if (!cache.count(key)) {
			//该点不在，创建新节点
			LRUNode* node = new LRUNode(key, value);
			cache[key] = node;
			addToHead(node);
			++size;
			if (size > capacity) {
				LRUNode* removed = removeTail();
				cache.erase(removed->key);
				delete removed;
				--size;
			}
		}
		else {
			LRUNode* node = cache[key];
			node->value = value;
			moveToHead(node);
		}
	}
	void addToHead(LRUNode* node) {
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
	}
	void removeNode(LRUNode* node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	void moveToHead(LRUNode* node) {
		removeNode(node);
		addToHead(node);
	}
	LRUNode* removeTail() {
		LRUNode* node = tail->prev;
		removeNode(node);
		return node;
	}

};

int main() {
	LRUcache* newCache = new LRUcache(3);
	newCache->put(2, 2);
	newCache->put(1, 2);
	cout << newCache->get(2) << endl;
	newCache->put(4, 1);
	cout << newCache->get(1) << endl;
	return 0;
}
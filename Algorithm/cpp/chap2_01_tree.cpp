#include <iostream>
#include <queue>
using namespace std;

// ���� Ʈ���� �⺻ ���� -> ������ ���� �ٸ� �ΰ��� ���� ��忡 ���� ��ũ�� ������.


class org_tree {
private:
	struct node {
		string position;
		node* first;
		node* second;
	};

	node* root;

public:
	org_tree(const string& pos) {
		this->root = new node{ pos, NULL, NULL };
	}

	node* getRoot() {
		return this->root;
	}

	node* find(node* root, const string& pos) {
		if (root == NULL) return NULL;
		if (root->position == pos) return root;

		auto firstFound = find(root->first, pos);
		if (firstFound != NULL) return firstFound;

		return find(root->second, pos);
	}

	bool addSubordinate(const string& manager, const string& subordinate) {
		auto managerNode = find(root, manager);

		if (!managerNode) {
			cout << manager << "��(��) ã�� �� �����ϴ�." << endl;
			return false;
		}

		if (managerNode->first && managerNode->second) {
			cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��� �� �����ϴ�." << endl;
			return false;
		}

		if (!managerNode->first) managerNode->first = new node{ subordinate, NULL, NULL };
		else managerNode->second = new node{ subordinate, NULL, NULL };

		cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��߽��ϴ�." << endl;
		return true;
	}

	void preOrder(node* start) {
		if (!start) return;

		cout << start->position << ", ";

		preOrder(start->first);
		preOrder(start->second);
	}

	void inOrder(node* start) {
		if (!start) return;

		inOrder(start->first);
		cout << start->position << ", ";
		inOrder(start->second);
	}

	void postOrder(node* start) {
		if (!start) return;

		postOrder(start->first);
		postOrder(start->second);
		cout << start->position << ", ";
	}

	void levelOrder(node* start) {
		if (!start) return;

		queue<node*> q;
		q.push(start);

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				auto current = q.front();
				q.pop();

				cout << current->position << ", ";

				if (current->first) q.push(current->first);
				if (current->second) q.push(current->second);
			}
		}
	}
};

void chap2_tree_test() {
	auto root = new org_tree("CEO");

	root->addSubordinate("CEO", "�λ���");
	root->addSubordinate("�λ���", "IT����");
	root->addSubordinate("�λ���", "�����ú���");
	root->addSubordinate("IT����", "��������");
	root->addSubordinate("IT����", "�۰�������");
	root->addSubordinate("�����ú���", "��������");
	root->addSubordinate("�����ú���", "ȫ������");
	root->addSubordinate("�λ���", "�繫����");
	cout << "\n" << endl;

	root->preOrder(root->getRoot());
	cout << "\n" << endl;

	root->inOrder(root->getRoot());
	cout << "\n" << endl;

	root->postOrder(root->getRoot());
	cout << "\n" << endl;

	root->levelOrder(root->getRoot());
	cout << "\n" << endl;

	delete root;
}

/*
struct org_tree {
	node* root;
	
	// ��Ʈ ��带 �����ϴ� �Լ�
	static org_tree create_org_structure(const string& pos) {
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };

		return tree;
	}

	// Ư�� ��å �̸�(position)�� �ش��ϴ� ��带 ã�Ƽ� ��ȯ�ϴ� �Լ�
	static node* find(node* root, const string& value) {
		if (root == NULL) return NULL;

		if (root->position == value) return root;

		auto firstFound = org_tree::find(root->first, value);
		if (firstFound != NULL) return firstFound;

		return org_tree::find(root->second, value);
	}

	// ���ο� ����(���� ����)�� �߰��ϴ� ���� �Լ�
	bool addSubordinate(const string& manager, const string& subordinate) {
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode) {
			cout << manager << "��(��) ã�� �� �����ϴ�: " << endl;
			return false;
		}

		if (managerNode->first && managerNode->second) {
			cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��� �� �����ϴ�." << endl;
			return false;
		}

		if (!managerNode->first) managerNode->first = new node{ subordinate, NULL, NULL };
		else managerNode->second = new node{ subordinate, NULL, NULL };

		cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��߽��ϴ�." << endl;
		return true;
	}

	static void preOrder(node* start) {
		if (!start) return;

		cout << start->position << ", ";

		preOrder(start->first);
		preOrder(start->second);
	}

	static void inOrder(node* start) {
		if (!start) return;

		inOrder(start->first);
		cout << start->position << ", ";
		inOrder(start->second);
	}

	static void postOrder(node* start) {
		if (!start) return;

		postOrder(start->first);
		postOrder(start->second);
		cout << start->position << ", ";
	}

	// ���� ���� ��ȸ ����� ���� ��忡 ���� ������� ���� ���� �̵�
	// �̷��� ��� ��͸� ������� �ʰ� �����ϴ� ���� �� ����
	static void levelOrder(node* start) {
		if (!start) return;

		queue<node*> q;
		q.push(start);

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				auto current = q.front();
				q.pop();

				cout << current->position << ", ";

				if (current->first) q.push(current->first);
				if (current->second) q.push(current->second);
			}
		}
	}

};

void chap2_tree() {
	auto tree = org_tree::create_org_structure("CEO");

	tree.addSubordinate("CEO", "�λ���");
	tree.addSubordinate("�λ���", "IT����");
	tree.addSubordinate("�λ���", "�����ú���");
	tree.addSubordinate("IT����", "��������");
	tree.addSubordinate("IT����", "�۰�������");
	tree.addSubordinate("�����ú���", "��������");
	tree.addSubordinate("�����ú���", "ȫ������");
	tree.addSubordinate("�λ���", "�繫����");
	cout << "\n" << endl;

	cout << "[ Pre-order Traversal ]" << "\n";
	org_tree::preOrder(tree.root);
	cout << "\n" << endl;

	cout << "[ In-order Traversal ]" << "\n";
	org_tree::inOrder(tree.root);
	cout << "\n" << endl;

	cout << "[ Post-order Traversal ]" << "\n";
	org_tree::postOrder(tree.root);
	cout << "\n" << endl;

	cout << "[ Level-order Traversal ]" << "\n";
	org_tree::levelOrder(tree.root);
	cout << "\n" << endl;
}
*/
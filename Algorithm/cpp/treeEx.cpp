#include <iostream>
#include <queue>
using namespace std;

// ���� Ʈ�� ���� Ŭ����
class tree_ex {
private:
	struct node {
		string pos;
		node* left;
		node* right;
	};

	node* root;

public:
	tree_ex(const string& pos) {
		this->root = new node{ pos, NULL, NULL };
	}

	node* get() { return this->root; }

	node* find(node* nd, const string& pos) {
		if (nd == NULL) return NULL;
		if (nd->pos == pos) return nd;

		node* found = find(nd->left, pos);
		if (found != NULL) return found;

		return find(nd->right, pos);
	}

	bool addSub(const string& man, const string& sub) {
		node* man_node = find(root, man);

		if (!man_node) {
			cout << man << "��(��) ã�� �� ����!" << endl;
			return false;
		}

		if (man_node->left && man_node->right) {
			cout << man << "�� ���� ���־ �߰��� �� ����!" << endl;
			return false;
		}

		if (!man_node->left) man_node->left = new node{ sub, NULL, NULL };
		else man_node->right = new node{ sub, NULL, NULL };

		cout << man << " �Ʒ��� " << sub << "��(��) �߰�!" << endl;
		return true;
	}

	void preorder(node* start) {
		if (!start) return;

		cout << start->pos << " => ";
		preorder(start->left);
		preorder(start->right);
	}

	void inorder(node* start) {
		if (!start) return;

		inorder(start->left);
		cout << start->pos << " => ";
		inorder(start->right);
	}

	void postorder(node* start) {
		if (!start) return;

		postorder(start->left);
		postorder(start->right);
		cout << start->pos << " => ";
	}

	void levelorder(node* start) {
		if (!start) return;

		queue<node*> q;
		q.push(start);

		while (!q.empty()) {
			for (int i = 0; i < q.size(); i++) {
				node* curr = q.front();
				q.pop();

				cout << curr->pos << " => ";

				if (curr->left) q.push(curr->left);
				if (curr->right) q.push(curr->right);
			}
		}
	}
};


void tr_ex() {
	auto tr = new tree_ex("CEO");

	tr->addSub("CEO", "�λ���");
	tr->addSub("�λ���", "IT����");
	tr->addSub("�λ���", "�����ú���");
	tr->addSub("IT����", "��������");
	tr->addSub("IT����", "�۰�������");
	tr->addSub("�����ú���", "��������");
	tr->addSub("�����ú���", "�繫����");

	cout << "\n\n" << endl;

	cout << "[ preorder ]" << endl;
	tr->preorder(tr->get());
	cout << "\n\n" << endl;

	cout << "[ inorder ]" << endl;
	tr->inorder(tr->get());
	cout << "\n\n" << endl;

	cout << "[ postorder ]" << endl;
	tr->postorder(tr->get());
	cout << "\n\n" << endl;

	cout << "[ levelorder ]" << endl;
	tr->levelorder(tr->get());
	cout << endl;

	delete tr;
}
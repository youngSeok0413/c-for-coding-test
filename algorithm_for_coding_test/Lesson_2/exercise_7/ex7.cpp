#include <iostream>
#include <queue>



struct node
{
	std::string position;
	node* first;
	node* second;
};


struct org_tree 
{
	node* root;

	static org_tree create_org_structure(const std::string& pos) 
	{
		org_tree tree;
		tree.root = new node{pos, NULL, NULL};
		return tree;
	}

	static node* find(node* root, const std::string& value) 
	{
		if (root == NULL) return NULL;

		if (root->position == value) return root;

		auto firstFound = org_tree::find(root->first, value);

		if (firstFound != NULL) return firstFound;

		return org_tree::find(root->second, value);
	}

	bool addSubordinate(const std::string& manager, const std::string& subordinate) 
	{
		auto mangerNode = org_tree::find(root, manager);

		if (!mangerNode) 
		{
			std::cout << manager << "��(��) ã�� �� �����ϴ�: " << std::endl;
			return false;
		}

		if (mangerNode->first && mangerNode->second) 
		{
			std::cout << manager << " �Ʒ��� " << subordinate << "�� �߰��� �� �����ϴ�." << std::endl;
			return false;
		}

		if (!mangerNode->first)
			mangerNode->first = new node{subordinate, NULL, NULL};
		else
			mangerNode->second = new node{ subordinate, NULL, NULL };

		std::cout << manager << " �Ʒ��� " << subordinate << "�� �߰��߽��ϴ�." << std::endl;

		return true;
	}
};

int main() 
{
	auto tree = org_tree::create_org_structure("CEO");

	tree.addSubordinate("CEO", "�λ���");
	tree.addSubordinate("�λ���", "IT����");
	tree.addSubordinate("�λ���", "�����ú���");
	tree.addSubordinate("IT����", "��������");
	tree.addSubordinate("IT����", "�۰�������");
	tree.addSubordinate("�����ú���", "��������");
	tree.addSubordinate("�����ú���", "ȫ������");
	tree.addSubordinate("�λ���", "�繫����");

	return 0;
}
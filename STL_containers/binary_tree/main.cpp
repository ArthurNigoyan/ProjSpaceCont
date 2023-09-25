#include <iostream>
class Node 
{
	public:
	int data;
	Node* left;
	Node* right;
	Node()
	{
		left=nullptr;
		right=nullptr;	
	}
};
class Tree : private Node
{
	public:
	Node* root;
	Tree()
	{
		root=nullptr;
		// std::cout<<"Tree constructor"<<std::endl;
	}
	~Tree()
	{
		delete_tree();
		// std::cout<<"Tree destructor"<<std::endl;
	}
	void add(int value)
	{
		if (root == nullptr) {
			
			root = new Node;	
			root->data = value;
			root->left = nullptr;
			root->right=nullptr;
			std::cout<<"root "<<root->data<<std::endl;
		} else if (root != nullptr)
		{
		    std::cout<<"call first add --> value-- "<<value<<std::endl;
			add(value, root);
		}
	}
	void add(int value, Node* LEAF)
	{
		if (value<LEAF->data)
		{
		    std::cout<<"call second1 add --> value-- "<<value <<" "<<LEAF->data<<std::endl;
			if (LEAF->left != nullptr)
			{
			    
				add(value, LEAF->left);
			} else {
				LEAF->left=new Node;
				LEAF->left->data = value;
				LEAF->left->left=nullptr;
				LEAF->left->right=nullptr;
				std::cout<<"left "<<LEAF->left->data<<std::endl;
			}
		} else if (value>=LEAF->data) {
            std::cout<<"call second2 add --> value-- "<<value <<" "<<LEAF->data<<std::endl;
			if (LEAF->right != nullptr)
			{
				add(value, LEAF->right);
			} else {
				LEAF->right=new Node;
				LEAF->right->data = value;
				LEAF->right->left=nullptr;
				LEAF->right->right=nullptr;
				std::cout<<"right "<<LEAF->right->data<<std::endl;
			}
		}
		 
	}
	int maxdepth(Node* LEAF)
	{
		if(LEAF ==nullptr)
		{
			return 0;
		}
		else
		{
			int leftD = maxdepth(LEAF->left);
			int rightD = maxdepth(LEAF->right);
			if (leftD>rightD)
			{
				return (leftD+1);
			}
			else
			{
				return (rightD+1);
			}
		}		
	}
	
	void delete_tree()
	{
		delete_tree(root);
	}
	void delete_tree(Node* LEAF)
	{
		
			delete_tree(LEAF->left);
			delete_tree(LEAF->right);
			delete LEAF;
		}
	

void preorder(Node* obj) {
  
  if (obj != nullptr) {
    std::cout << " " << obj->data;
    preorder(obj->left);
    preorder(obj->right);
  }
  
}
void print_layer_by_layer()
{
	// std::cout << " 11"<<std::endl;;
	layer_by_layer(root);
}
void layer_by_layer(Node* obj)
{
	// std::cout << " 22"<<std::endl;
	int depth=maxdepth(obj);
	std::cout << " depth is: "<<depth<<std::endl;
	if (obj != nullptr)
	{
		for (int i=0; i < depth;i++)
		{
			// std::cout << " 33"<<std::endl;
			print_level(obj,i);
            std::cout << std::endl;
		}
	} 
	else 
	{
		return;
	}
}
void print_level (Node* obj, int level)
{
	// std::cout << " 44--> "<<level<<std::endl;
	if (obj == nullptr)
		return;
	if (level ==0)
	{
		// std::cout << " zzz -->"<<level<<" "<<obj->data<<std::endl;
		std::cout<<" " << obj->data;
	}
	else if (level>0)
	{
		print_level(obj->left,level-1);
		print_level(obj->right,level-1);
	}
}
void inorder(Node* obj) 
{
  
  // std::cout<<"inorder *** "<<std::endl;
  if (obj != nullptr) {
    inorder(obj->left);
    std::cout << " " << obj->data;
    inorder(obj->right);
  }
  // std::cout<<"end inorder *** "<<std::endl;
}

void postorder(Node* obj) 
{
  // std::cout<<"postorder *** "<<std::endl;
  if (obj != nullptr) {
    postorder(obj->left);
    postorder(obj->right);
    std::cout << " " << obj->data;
  }
  // std::cout<<"end postorder *** "<<std::endl;
}
void print_preorder()
{
	// std::cout<<"preorder *** "<<std::endl;
	preorder(root);
	// std::cout<<"end preorder *** "<<std::endl;
}
	void print_inorder()
{
	// std::cout<<"inorder *** "<<std::endl;
	inorder(root);
	// std::cout<<"end inorder *** "<<std::endl;
}
	void print_postorder()
{
	// std::cout<<"postorder *** "<<std::endl;
	postorder(root);
	// std::cout<<"end postorder *** "<<std::endl;
}
};


int main()
{
	
	Tree tree;
	tree.add(5);
	tree.add(2);
	tree.add(3);
	tree.add(1);
	tree.add(10);
	tree.add(7);
	tree.add(11);
	// tree.print_preorder();
	// std::cout<<std::endl;
	// tree.print_inorder();
	// std::cout<<std::endl;
	// tree.print_postorder();
	// std::cout<<std::endl;
	std::cout<<"layer"<<std::endl;
	tree.print_layer_by_layer();
	
	return 0;
}
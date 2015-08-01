typedef enum BRColor { 
    RED = 0, 
    BLACK = 1 
} BRColor;

typedef struct BRNode {
    int value;
    struct BRNode * p;
    struct BRNode * left;
    struct BRNode * right;
    BRColor color;
} BRNode;

typedef struct BRTree {
	struct BRNode * root;
} BRTree;

void LeftRotate(BRTree * T, BRNode * x) {
	if (x->right == NULL) {
		return;
	}
    BRNode * y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->p = x;
    }
    y->p = x->p;
    if (x->p == NULL) {
        T->root = y;
    } else {
        if( x == x->p->left) {
            x->p->left = y;
        } else {
            x->p->right = y;
        }
    }
    y->left = x;
    x->p = y;
}

void RightRotate(BRTree * T, BRNode * x) {
	if (x->left == NULL) {
		return;
	}
    BRNode * y = x->left;
    x->left = y->right;
    if (y->right != NULL) {
        y->right->p = x;
    } 
    y->p = x->p;
    if (x->p == NULL) {
        T->root = y;
    } else {
        if (x == x->p->left) {
            x->p->left = y;
        } else {
            x->p->right = y;
        }
    }
    y->right = x;
    x->p = y;
}

void insertFixup(BRTree * T, BRNode * z) {
	if (z->p == NULL) {
		z->color = BLACK;
		return;
	}
	if (z->p->p == NULL) {
		return;
	}
    BRNode * y;
    //因为插入的结点是红色的，所以只可能违背性质3,即假如父结点也是红色的，要做调整
    while(z->p != NULL && z->p->color == RED) {
    	//如果要插入的结点z是其父结点的左子树
        if(z->p == z->p->p->left) {
        	// y设置为z的叔父结点
            y = z->p->p->right; 
            if(y != NULL && y->color == RED) {
            	//case 1: 如果y的颜色为红色，那么将y与z的父亲同时着为黑色，然后把z的
            	//祖父变为红色，这样子z的祖父结点可能违背性质3,将z上移成z的祖父结点
                z->p->color = BLACK; 
                y->color = BLACK; 
                z->p->p->color = RED; 
                z = z->p->p; 
            } else { 
                if(z == z->p->right) {
                    z = z->p;
                    LeftRotate(T, z);
                }
                //case 3: 如果y的颜色为黑色，并且z是z的父母的左结点，那么将z的
                //父亲的颜色变为黑，将z的祖父的颜色变为红，然后旋转z的祖父
                z->p->color = BLACK;
                z->p->p->color = RED;
                RightRotate(T, z->p->p);
            }
        } else {
        	//与前一种情况对称，要插入的结点z是其父结点的右子树,注释略去
            y = z->p->p->left;
            if(y != NULL && y->color == RED) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            } else {
                if(z == z->p->left) {
                    z = z->p;
                    RightRotate(T,z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                LeftRotate(T, z->p->p);
            }
        }
    }
    T->root->color = BLACK;
}

bool insert(BRTree * T, int val) { 
    if(T == NULL) { 
        T = malloc(sizeof(BRTree));
        T->root = NULL;
    }
    BRNode * y = NULL;
    BRNode * x = T->root;
    while(x != NULL) { 
        y = x;
        if(val < x->value) {
            x = x->left;
        } else if (val > x->value) {
            x = x->right;
        } else {
            return true;
        }
    }
    x = malloc(sizeof(BRNode));
    x->left = x->right = NULL;
    x->color = RED;
    x->value = val;
    x->p = y;
    if (y == NULL) {
    	T->root = x;
	} else {
		if(val < y->value) {
			y->left = x;
		} else {
			y->right = x;
		}
	}
    insertFixup(T, x);
    return false;
}

bool containsDuplicate(int* nums, int numsSize) {
	int i;
    BRTree * tree = malloc(sizeof(BRTree));
	tree->root = NULL;
    for (i = 0; i < numsSize; i++)
    {
        if (insert(tree, nums[i]))
			return true;
    }
    return false;
}
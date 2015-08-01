！！！这个题会出现一个两数相减结果溢出的情况，请注意！！！

typedef enum BRColor { 
    RED = 0, 
    BLACK = 1 
} BRColor;

typedef struct BRNode {
    int value;
    int index;
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
    while(z->p != NULL && z->p->color == RED) {
        if(z->p == z->p->p->left) {
            y = z->p->p->right; 
            if(y != NULL && y->color == RED) {
                z->p->color = BLACK; 
                y->color = BLACK; 
                z->p->p->color = RED; 
                z = z->p->p; 
            } else { 
                if(z == z->p->right) {
                    z = z->p;
                    LeftRotate(T, z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                RightRotate(T, z->p->p);
            }
        } else {
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

BRNode * treeMinimum(BRNode * x) {
	while (x != NULL && x->left != NULL) {
		x = x->left;
	}
	return x;
}

BRNode * treeMaximum(BRNode * x) {
	while (x != NULL && x->right != NULL) {
		x = x->right;
	}
	return x;
}

BRNode * treeSuccessor(BRNode * x) {
	if (x->right != NULL) {
        return treeMinimum(x->right); 
    }
    BRNode * y = x->p;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->p;
    } 
    return y;
}

BRNode * treePredecessor(BRNode * x) {
	if (x->left != NULL) {
        return treeMaximum(x->left); 
    }
    BRNode * y = x->p;
    while (y != NULL && x == y->left) {
        x = y;
        y = y->p;
    } 
    return y;
}

bool traverse(BRNode * x, int k, int t) {
    if (x == NULL) {
        return false;
    }
    BRNode * y = x;
    while ((y = treePredecessor(y)) != NULL) {
        // [-1,2147483647], 1, 2147483647 should cause overflow
        if (abs(x->value - y->value) < 0 || abs(x->value - y->value) > t) {
            break;
        }
        if (abs(x->index - y->index) <= k) {
            return true;
        }
    }
    y = x;
    while ((y = treeSuccessor(y)) != NULL) {
        if (abs(x->value - y->value) < 0 || abs(x->value - y->value) > t) {
            break;
        }
        if (abs(x->index - y->index) <= k) {
            return true;
        }
    }
    return false;
}

bool insert(BRTree * T, int val, int index, int k, int t) { 
    if(T == NULL) { 
        T = malloc(sizeof(BRTree *));
        T->root = NULL;
    }
    BRNode * y = NULL;
    BRNode * x = T->root;
    while(x != NULL) { 
        y = x;
        if(val <= x->value) {
            x = x->left;
        } else if (val > x->value) {
            x = x->right;
        }
    }
    x = malloc(sizeof(BRNode));
    x->left = x->right = NULL;
    x->color = RED;
    x->value = val;
    x->index = index;
    x->p = y;
    if (y == NULL) {
    	T->root = x;
	} else {
		if(val <= y->value) {
			y->left = x;
		} else {
			y->right = x;
		}
	}
    insertFixup(T, x);
    if (traverse(x, k, t)) {
        return true;
    }
    return false;
}

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t) {
    int i;
    BRTree * tree = malloc(sizeof(BRTree));
	tree->root = NULL;
    for (i = 0; i < numsSize; i++) {
        if (insert(tree, nums[i], i, k, t))
			return true;
    }
    return false;
} 
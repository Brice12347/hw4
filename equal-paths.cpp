#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)
#include <iostream>
#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int countL(Node * root){
    if(root == NULL ){
        return 0;
    }
		if(root->right != NULL){
			return 1 + countL(root->right);
		}
		else{
			//return 1+countL(root->left) + countL(root->right);
        return 1 + countL(root->left);
    }

				//return 1+countL(root->left) + countL(root->right);
    	//return 1 + countL(root->left);

	
		
		
}
bool count(Node * root,int& maxlength, int curr){
	if(root == NULL){
		return true;
	}
	if(root->right == NULL && root->left == NULL){
		if(maxlength == -1){
			maxlength = curr;
			return true;
		}
		if(maxlength != -1){
			if(maxlength != curr){
				return false;
			}else{
				return true;
			}
		}
	}
	bool temp1 = count(root ->right, maxlength, curr+1);
	bool temp2 = count(root -> left, maxlength, curr+1);
	
	if(temp1 ==true && temp2 == true){
		return true;
	}else{
		return false;
	}
}



bool equalPaths(Node * root)
{
    // Add your code below

    if(root == NULL){
        return;
    }
    equalPaths(root->left);
    equalPaths(root->right);
    

		if(root == NULL){
			return true;
		}
    int max = -1;
		return count(root, max, 0);

}


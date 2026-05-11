/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;  
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* cook(vector<vector<int>>&grid,int l, int r, int t, int d){
        bool one = false;
        bool zero = false;

        for(int i=t;i<=d;i++){
            for(int j=l;j<=r;j++){
                if(!one) one = (grid[i][j]==1);
                if(!zero) zero = (grid[i][j]==0);

                if(one && zero) break;
            }
        }
        
        if(one && !zero) return new Node(true,true);
        else if(!one && zero) return new Node(false,true);

        Node* curr = new Node(true,false);

        int hmid = (r+l)/2;
        int vmid = (t+d)/2;
        curr->topLeft = cook(grid,l,hmid,t,vmid);
        curr->topRight = cook(grid,hmid+1,r,t,vmid);
        curr->bottomLeft = cook(grid,l,hmid,vmid+1,d);
        curr->bottomRight = cook(grid,hmid+1,r,vmid+1,d);

        return curr;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        return cook(grid,0,m-1,0,n-1);
    }
};

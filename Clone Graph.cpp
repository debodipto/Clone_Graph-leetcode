class Solution {
public:
    unordered_map<Node*, Node*> old2new;
    
    Node* cloneGraph(Node* node) {
        if(!node) return node;

        if(old2new.find(node) != old2new.end())
            return old2new[node];
        
        old2new[node] = new Node(node->val);
        
        for(Node* nei : node->neighbors){
            old2new[node]->neighbors.push_back(cloneGraph(nei));
        }
        
        return old2new[node];
    }
};

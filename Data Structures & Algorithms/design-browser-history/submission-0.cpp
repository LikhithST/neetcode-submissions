class BrowserHistory {
    struct UrlNode{
        string url;
        UrlNode* forward;
        UrlNode* backward;
        UrlNode(string url): url(url), forward(nullptr), backward(nullptr){};
    };

    UrlNode* startpage;
    UrlNode* current;
    int size;
    int current_step;

public:
    
    BrowserHistory(string homepage) {
        startpage = new UrlNode(homepage);
        current = startpage;
        size = 1;
        current_step = 1;
    }
    
    void visit(string url) {
        UrlNode* visitnew = new UrlNode(url);
        current->forward = visitnew;
        visitnew->backward = current;
        current = visitnew;
        current_step++;
        size = current_step;

    }
    
    string back(int steps) {
        if (steps >= current_step) return startpage->url;
        for (int i = 0; i < steps; i++){
            current = current->backward;
            current_step--;
        }
        return current->url;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps; i++){
            if (current->forward == nullptr) return current->url;
            current = current->forward;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
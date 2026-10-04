using namespace std;
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;

    for (int i = 0; i < operations.size(); i++){
        if (operations[i] == "+"){
            int top = stack.back();
            stack.pop_back();
            int newTop = top + stack.back();
            stack.push_back(top);
            stack.push_back(newTop);
        }
        else if (operations[i] == "C"){
            stack.pop_back();
        }
        else if (operations[i] == "D"){
            stack.push_back(stack.back()*2);
        }
        else{
            stack.push_back(stoi(operations[i]));
        }
    }

    int total = 0;

    for (int x : stack) {
        total += x;
    }

return total;

    }
};
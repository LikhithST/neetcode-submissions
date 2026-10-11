class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
int s_no_eat = 0;
        for(int& s: sandwiches){ // loop through the stack of sandwiches
            int found = 0; // since it is a stack, for the stack to proceed, we need to find some student that would eat the sandwich
            for(int i=0; i<students.size(); i++){
                if (students[i] == s){
                    students[i]=-1;
                    found = 1;// if found we update the flag to found which helps the stack loop to decide if it needs to move next in the stack of sandwiches
                    break; // we break the current loop because only one student can have a sandwich in the stack
                }
            }
            if (found!=1){ // we break the stack loop if no student is interested in the sandwich in the top of the stack
                break;
            }
        }

        for(int& i : students){ // count number of the elements that are not marked -1 (where -1 indicates a student eat a sandwich) 
            if (i!=-1){
                s_no_eat++;
            }
        }
        return s_no_eat;

    }
};
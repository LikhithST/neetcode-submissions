class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
int s_no_eat = 0;
        for(int& s: sandwiches){
            int found = 0;
            for(int i=0; i<students.size(); i++){
                if (students[i] == s){
                    students[i]=-1;
                    found = 1;
                    break;
                }
            }
            if (found!=1){
                break;
            }
        }

        for(int& i : students){
            if (i!=-1){
                s_no_eat++;
            }
        }
        return s_no_eat;

    }
};
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        vector<int> cnt(2); // a counter to count the number of students with particular preferences; vector<int> cnt; initializes an empty vector with size 0

        for (int& p: students){
            cnt[p]++;
        }

        for (int& s : sandwiches){
            if (cnt[s]>0){
                cnt[s]--;
            }
            else{
                break; // break the loop when no one in the queue (i.e the no student wants) the sandwich at the top of the stack, since stack has to proceed only when the top element is removed, even though a queue can rotate the, if no one in the queue does not want the sandwich on top of the stack, the students don't get what they want hence we must break as the stack should not proceed
            }
        }
    return cnt.at(0)+cnt.at(1); // the remaining students who don't get to choose what they wanted. at method of vector does bounds-checking, i.e. it is safer and slightly slower.

    }
};
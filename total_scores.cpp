#include <iostream>

int main(void) {
    int score_table[][3] = {
        {100, 100, 100},
        {90, 50, 100}, 
        {60, 70, 80}
    };
    int score_sum[3] = {}; 

    std::cout << "------------------------------\n";
    std::cout << "I have gererated student's score sums.\n";

    std::cout << "The total scores of students: ";
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            score_sum[i] += score_table[i][j];
        }
        std::cout << score_sum[i] << ' ';
    }

    std::cout << "\n------------------------------\n";

    return 0;
}
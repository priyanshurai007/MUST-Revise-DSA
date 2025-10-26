class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0; // we don't need to track twenties

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else { // bill == 20
                // Prefer giving change as 10 + 5 to save $5 bills
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) { // otherwise use three $5 bills
                    five -= 3;
                } else {
                    return false; // cannot make change
                }
            }
        }
        return true;
    }
};

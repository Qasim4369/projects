#include <iostream>
#include <string>
#include <set>
#include <cstring>
//Pseudo code Q#1:
//
//Define constants MAX_Nand MAX_M.
//Declare variables n, m, groups, numsand used.
//Read the value of nand m from the user.
//Read the ingredients for each dishand store them in a set called groups.
//Read the list of available ingredientsand store them in an array called nums.
//Set all the elements of the used array to false.
//Call the search function with i = 0 as the starting point.
//If the search function returns true, output "You have enough ingredients to prepare all dishes".
//Otherwise, output "You do not have enough ingredients to prepare all dishes".
//Time complexity Q#1 :
// 
//The time complexity of the search function is O(n * m * log m), where n is the number of dishesand m is the number of ingredients.
// This is because for each dish, we iterate through all the ingredients in the nums array, which takes O(m) time.Additionally, 
// we use the count method of the set data structure, which takes O(log m) time.Therefore, the overall time complexity of the program is O(n * m * log m).
//


using namespace std;

const int MAX_N = 10;
const int MAX_M = 100;

int n;
int m;
set<string> groups[MAX_N];
string nums[MAX_M];
bool used[MAX_M];

bool search(int i)
{
    if (i == n) {
        return true;
    }
    for (int j = 0; j < m; j++) {
        if (!used[j] && groups[i].count(nums[j])) {
            used[j] = true;
            if (search(i + 1)) {
                return true;
            }
            used[j] = false;
        }
    }
    return false;
}

//int main()
//{
//    cout << "Enter the number of dishes: ";
//    cin >> n;
//    cout << "Enter the number of ingredients: ";
//    cin >> m;
//
//    cout << "Enter the ingredients for each dish:\n";
//    for (int i = 0; i < n; i++) {
//        cout << "Dish " << i + 1 << ": ";
//        string ingredient;
//        while (cin >> ingredient) {
//            groups[i].insert(ingredient);
//            if (cin.get() == '\n') {
//                break;
//            }
//        }
//    }
//
//    cout << "Enter the list of available ingredients:\n";
//    for (int i = 0; i < m; i++) {
//        cin >> nums[i];
//    }
//
//    memset(used, false, sizeof(used));
//
//    if (search(0)) {
//        cout << "You have enough ingredients to prepare all dishes.\n";
//    }
//    else {
//        cout << "You do not have enough ingredients to prepare all dishes.\n";
//    }
//
//    return 0;
//}

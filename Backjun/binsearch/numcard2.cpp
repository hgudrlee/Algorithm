#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int card_num, target_num, num;
vector<int> card;

int main() {
    scanf("%d", &card_num);
    for (int i = 0; i < card_num; i++) {
        scanf("%d", &num);
        card.push_back(num);
    }

    sort(card.begin(), card.end());
    scanf("%d", &target_num);

    for (int i = 0; i < target_num; i++) {
        scanf("%d", &num);
        printf("%d ", (upper_bound(card.begin(), card.end(), num) - card.begin()) - (lower_bound(card.begin(), card.end(), num) - card.begin()));
    }

    return 0;
}
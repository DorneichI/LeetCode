int totalMoney(int n) {
    int money = 0;
    int weeks = n / 7;
    for (int i = 0; i < weeks; i++) {
        money += ((7 + i) * (7 + i + 1)) / 2 - (i * (i + 1)) / 2;
    }
    int leftDays = n % 7;
    money += ((leftDays + weeks) * (leftDays + weeks + 1)) / 2 - (weeks * (weeks + 1)) / 2;
    return money;
}
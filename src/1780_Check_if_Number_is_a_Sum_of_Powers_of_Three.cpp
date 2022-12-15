bool checkPowersOfThree(int n) {
    while (n) {
        if (n % 3 != 2) n /= 3;
        else return false;
    }
    return true;
}
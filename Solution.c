#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long char_to_num(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    return 0;
}

__int128 base_to_decimal(const char* value, int base) {
    __int128 result = 0;
    int len = strlen(value);
    for (int i = 0; i < len; i++) {
        int digit = char_to_num(value[i]);
        result = result * base + digit;
    }
    return result;
}

long long to_long_long(__int128 x) {
    if (x > 9223372036854775807LL) return 9223372036854775807LL;
    if (x < -9223372036854775807LL - 1) return -9223372036854775807LL - 1;
    return (long long)x;
}

typedef struct {
    long long x;
    __int128 y;
} Point;

long long find_secret(Point* points, int k) {
    long double result = 0.0L;
    for (int i = 0; i < k; i++) {
        long double term = (long double)points[i].y;
        for (int j = 0; j < k; j++) {
            if (i != j) {
                term = term * (0.0L - points[j].x) / (points[i].x - points[j].x);
            }
        }
        result += term;
    }
    return (long long)(result > 0 ? result + 0.5L : result - 0.5L);
}

int main() {
    Point test1[] = {
        {1, base_to_decimal("4", 10)},
        {2, base_to_decimal("111", 2)},
        {3, base_to_decimal("12", 10)},
        {6, base_to_decimal("213", 4)}
    };
    long long secret1 = find_secret(test1, 3);
    printf("%lld\n", secret1); 

    Point test2[] = {
        {1, base_to_decimal("13444211440455345511", 6)},
        {2, base_to_decimal("aed7015a346d635", 15)},
        {3, base_to_decimal("6aeeb69631c227c", 15)},
        {4, base_to_decimal("e1b5e05623d881f", 16)},
        {5, base_to_decimal("316034514573652620673", 8)},
        {6, base_to_decimal("2122212201122002221120200210011020220200", 3)},
        {7, base_to_decimal("20120221122211000100210021102001201112121", 3)}
    };
    long long secret2 = find_secret(test2, 7);
    printf("%lld\n", secret2); 
    return 0;
}
